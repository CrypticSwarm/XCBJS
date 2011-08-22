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

template <typename T>
int handle_event(T ev, Persistent<String> sym, void (*cb)(const T&, Local<Function>)) { 
  HandleScope scope;
  Local<Value> val = t->Get(sym);
  if (val->IsFunction()) {
    Local<Function> jscb = Local<Function>::Cast(val);
    cb(ev, jscb);
    delete ev;
  }
  return 0;
}

template <typename T>
void giveWindow(const T& ev, Local<Function> cb) {
  Local<Value> win[1] = { Integer::New(ev->window) };
  cb->Call(t, 1, win);
}

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
    switch(ev->response_type & ~0x80) {
      case XCB_MAP_REQUEST:  return handle_event((xcb_map_request_event_t  *) ev, on_map_sym,   giveWindow);
      case XCB_UNMAP_NOTIFY: return handle_event((xcb_unmap_notify_event_t *) ev, on_unmap_sym, giveWindow);
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
