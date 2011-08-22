#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <iostream>
#include <vector>

namespace XCBJS {

using namespace std;
using namespace node;
using namespace v8;

extern xcb_connection_t *connection;
extern Persistent<Object> t;
static Persistent<String> on_map_sym;
static Persistent<String> on_unmap_sym;


class Event : public ObjectWrap {
public:

  static void Init(Handle<Object> target) {
    HandleScope scope;
    on_map_sym = NODE_PSYMBOL("onMap");
    on_unmap_sym = NODE_PSYMBOL("onUnMap");
    t = Persistent<Object>::New(target);
    eio_custom(Event::LookForEvent, EIO_PRI_DEFAULT, Event::EventObtained, NULL);
    ev_ref(EV_DEFAULT_UC);
  }

  static int EventObtained(eio_req *req) {
    eio_custom(Event::LookForEvent, EIO_PRI_DEFAULT, Event::EventObtained, NULL);
    xcb_generic_event_t *ev = (xcb_generic_event_t*)req->data;
    if ((ev->response_type & ~0x80) == XCB_MAP_REQUEST) {
      cout << "Map request -> Deploy?" << endl;
      xcb_map_request_event_t *e = (xcb_map_request_event_t *) ev;
      Local<Value> val = t->Get(on_map_sym);
      if (val->IsFunction()) {
        Local<Function> cb = Local<Function>::Cast(val);
        Local<Value> win[1] = { Integer::New(e->window) };
        cb->Call(t, 1, win);
        delete ev;
      }
    }
    else if ((ev->response_type & ~0x80) == XCB_UNMAP_NOTIFY) {
      xcb_unmap_notify_event_t *e = (xcb_unmap_notify_event_t *)ev;
      Local<Value> val = t->Get(on_unmap_sym);
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
};

};
