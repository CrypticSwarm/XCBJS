#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <iostream>


using namespace std;
using namespace node;
using namespace v8;

static xcb_connection_t *connection;
static xcb_screen_t *screen;

class XCBJS {

public:
  static void Init(Handle<Object> target) {
    HandleScope scope;
    connection = xcb_connect(NULL, NULL);
    const xcb_setup_t      *setup  = xcb_get_setup(connection);
    xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
    screen = iter.data;
    eio_custom(XCBJS::ELoop, EIO_PRI_DEFAULT, XCBJS::Close, NULL);
    ev_ref(EV_DEFAULT_UC);
    NODE_SET_METHOD(target, "drawRect", XCBJS::drawRect);
    NODE_SET_METHOD(target, "flush", XCBJS::flush);
    NODE_SET_METHOD(target, "clearArea", XCBJS::clearArea);
    NODE_SET_METHOD(target, "generateId", XCBJS::generateId);
    NODE_SET_METHOD(target, "createWindow", XCBJS::createWindow);
    NODE_SET_METHOD(target, "createGC", XCBJS::createGC);
    NODE_SET_METHOD(target, "mapWindow", XCBJS::mapWindow);
  }

  static int Close(eio_req *req) {
    return 0;
  }

  static int ELoop(eio_req *req) {
    xcb_generic_event_t *event;
    while (event = xcb_wait_for_event(connection)) {
      switch (event->response_type & ~0x80) {
        case XCB_EXPOSE:
        xcb_flush (connection);

        break;
        default:
        /* Unknown event type, ignore it */
        break;
      }
    }
    return 0;
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
      , height = args[4]->Int32Value();
    int mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    uint32_t values[2]  = {screen->white_pixel, XCB_EVENT_MASK_EXPOSURE};
    xcb_create_window(connection,                    /* Connection          */
      XCB_COPY_FROM_PARENT,          /* depth (same as root)*/
      win,                        /* window Id           */
      screen->root,                  /* parent window       */
      x, y,                          /* x, y                */
      width, height,                      /* width, height       */
      1,                            /* border_width        */
      XCB_WINDOW_CLASS_INPUT_OUTPUT, /* class               */
      screen->root_visual,           /* visual              */
      mask, values );                     /* masks, not used yet */
    
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

private:
};

extern "C" void
init (Handle<Object> target)
{
    HandleScope scope;
    XCBJS::Init(target);
}


