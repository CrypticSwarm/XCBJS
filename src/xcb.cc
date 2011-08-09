#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <iostream>
#include <vector>


using namespace std;
using namespace node;
using namespace v8;

static xcb_connection_t *connection;
static xcb_screen_t *screen;
static Persistent<Object> t;
static Persistent<String> on_map_sym;

class XCBJS {

public:
  static void Init(Handle<Object> target) {
    HandleScope scope;
    t = Persistent<Object>::New(target);
    connection = xcb_connect(NULL, NULL);
    const xcb_setup_t      *setup  = xcb_get_setup(connection);
    xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
    screen = iter.data;
    on_map_sym = NODE_PSYMBOL("onMap");
    NODE_SET_METHOD(target, "drawRect", XCBJS::drawRect);
    NODE_SET_METHOD(target, "flush", XCBJS::flush);
    NODE_SET_METHOD(target, "clearArea", XCBJS::clearArea);
    NODE_SET_METHOD(target, "generateId", XCBJS::generateId);
    NODE_SET_METHOD(target, "createWindow", XCBJS::createWindow);
    NODE_SET_METHOD(target, "createGC", XCBJS::createGC);
    NODE_SET_METHOD(target, "mapWindow", XCBJS::mapWindow);
    NODE_SET_METHOD(target, "configureWindow", XCBJS::configureWindow);
    NODE_SET_METHOD(target, "manageWindows", XCBJS::manageWindows);
    eio_custom(XCBJS::LookForEvent, EIO_PRI_DEFAULT, XCBJS::EventObtained, NULL);
    ev_ref(EV_DEFAULT_UC);
  }

  static int EventObtained(eio_req *req) {
    eio_custom(XCBJS::LookForEvent, EIO_PRI_DEFAULT, XCBJS::EventObtained, NULL);
    xcb_generic_event_t *ev = (xcb_generic_event_t*)req->data;
    if ((ev->response_type & ~0x80) == XCB_MAP_REQUEST) {
      cout << "Map request" << endl;
      xcb_map_request_event_t *e = (xcb_map_request_event_t *) ev;
      Local<Value> val = t->Get(on_map_sym);
      if (val->IsFunction()) {
        Local<Function> cb = Local<Function>::Cast(val);
        Local<Value> win[1] = { Integer::New(e->window) };
        cb->Call(t, 1, win);
        delete ev;
      }
    }
    return 0;
  }

  static int LookForEvent(eio_req *req) {
    xcb_generic_event_t *event;
    event = xcb_wait_for_event(connection);
    req->data = event;
    return req->result = 0;
  }

  static Handle<Value> drawRect(const Arguments& args) {
    HandleScope scope;
    const char *usage = "usage: drawRect(window, gcContext, x, y, width, height)";
    if (args.Length() != 6) {
      return ThrowException(Exception::Error(String::New(usage)));
    }
    xcb_window_t window = args[0]->Int32Value();
    xcb_gcontext_t black = args[1]->Int32Value();
    xcb_rectangle_t rects[] =
    { { args[2]->Int32Value()
      , args[3]->Int32Value()
      , args[4]->Int32Value()
      , args[5]->Int32Value()
      } 
    };
    xcb_poly_rectangle(connection, window, black, 1, rects);
    return Undefined();
  }

  static Handle<Value> clearArea(const Arguments& args) {
    HandleScope scope;
    const char *usage = "usage: clearArea(window, x, y, width, height)";
    if (args.Length() != 5) {
      return ThrowException(Exception::Error(String::New(usage)));
    }
    xcb_window_t window = args[0]->Int32Value();
    xcb_clear_area(connection, 0
      , window
      , args[1]->Int32Value()
      , args[2]->Int32Value()
      , args[3]->Int32Value()
      , args[4]->Int32Value()
    );
    return Undefined();
  }

  static Handle<Value> flush(const Arguments& args) {
    HandleScope scope;
    xcb_flush (connection);
    return Undefined();
  }

  static Handle<Value> generateId(const Arguments& args) {
    HandleScope scope;
    xcb_window_t ret = xcb_generate_id(connection);
    return Integer::New(ret);
  }

  static Handle<Value> createWindow(const Arguments& args) {
    HandleScope scope;
    xcb_window_t win = args[0]->Int32Value();
    int x = args[1]->Int32Value()
      , y = args[2]->Int32Value()
      , width = args[3]->Int32Value()
      , height = args[4]->Int32Value()
      , borderWidth = (args.Length() > 5 ? args[5]->Int32Value() : 1);
    int mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    uint32_t values[2]  = {screen->white_pixel, XCB_EVENT_MASK_EXPOSURE};
    xcb_create_window(connection
      , XCB_COPY_FROM_PARENT
      , win
      , screen->root
      , x, y
      , width, height
      , borderWidth
      , XCB_WINDOW_CLASS_INPUT_OUTPUT
      , screen->root_visual
      , mask, values );                     /* masks, not used yet */
    
    return Undefined();
  }

  static Handle<Value> createGC(const Arguments& args) {
    HandleScope scope;
    uint32_t        mask       = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    uint32_t        values[2]  = {screen->black_pixel, 0};
    xcb_gcontext_t black = args[0]->Int32Value();
    xcb_window_t window = args[1]->Int32Value();
    xcb_create_gc(connection, black, window, mask, values);
    
    return Undefined();
  }

  static Handle<Value> mapWindow(const Arguments& args) {
    HandleScope scope;
    xcb_window_t window = args[0]->Int32Value();
    xcb_map_window(connection, window);
    return Undefined();
  }

  static Handle<Value> configureWindow(const Arguments& args) {
    HandleScope scope;
    xcb_window_t window = args[0]->Int32Value();
    uint16_t mask = (uint16_t)args[1]->Int32Value();
    Local<Object> obj = args[2]->ToObject();
    Local<Array> arr = obj->GetPropertyNames();
    int len = arr->Length();
    uint32_t *values = new uint32_t[len];
    for (int i = 0; i < len; ++i) {
      values[i] = obj->Get(arr->Get(i))->Int32Value();
    }
    xcb_configure_window(connection, window, mask, values);
    delete values;
    return Undefined();
  }

  static Handle<Value> manageWindows(const Arguments& args) {
    HandleScope scope;
    uint32_t values[1] = { XCB_EVENT_MASK_STRUCTURE_NOTIFY | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY };
    xcb_void_cookie_t cookie = xcb_change_window_attributes_checked(connection, screen->root, XCB_CW_EVENT_MASK, values);
    xcb_request_check(connection, cookie);
    xcb_flush(connection);
    return Undefined();
  }

private:
};

extern "C" void
init (Handle<Object> target)
{
    HandleScope scope;
    XCBJS::Init(target);
}


