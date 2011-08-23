#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "__autogen_events.h"
#include "config.h"

namespace XCBJS {

using namespace v8;

class Event {
public:

  static void Init(Handle<Object> target) {
    HandleScope scope;
    InitXCB2JSEvents(Persistent<Object>::New(target));
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
    event = xcb_wait_for_event(Config::connection);
    req->data = event;
    return req->result = 0;
  }

};

};
