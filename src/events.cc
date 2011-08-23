#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "__autogen_events.h"

namespace XCBJS {

using namespace std;
using namespace node;
using namespace v8;

extern xcb_connection_t *connection;
extern Persistent<Object> t;

class Event {
public:

  static void Init(Handle<Object> target) {
    HandleScope scope;

    t = Persistent<Object>::New(target);
    InitXCB2JSEvents(t);
    eio_custom(Event::LookForEvent, EIO_PRI_DEFAULT, Event::EventObtained, NULL);
    ev_ref(EV_DEFAULT_UC);
  }

  static int EventObtained(eio_req *req) {
    eio_custom(Event::LookForEvent, EIO_PRI_DEFAULT, Event::EventObtained, NULL);
    xcb_generic_event_t *ev = (xcb_generic_event_t*)req->data;
    distributeEvent(ev);
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
