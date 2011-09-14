#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <iostream>
#include <functional>
#include "__autogen_events.h"

namespace XCBJS {

using namespace v8;

class Event : node::ObjectWrap {
private:
  struct EventData {
    xcb_connection_t *connection;
    xcb_generic_event_t *ev;
  };
public:

  static void Init(Handle<Object> target) {
    HandleScope scope;
    InitXCB2JSEvents(Persistent<Object>::New(target));
  }

  Event(xcb_connection_t * c) : connection(c) {
    eio_custom(LookForEvent, EIO_PRI_DEFAULT, EventObtained, PrepEventData(connection));
    ev_ref(EV_DEFAULT_UC);
  }

  static EventData *PrepEventData(xcb_connection_t *connection) {
    EventData *ev = new EventData;
    ev->connection = connection;
    return ev;
  }

  static int EventObtained(eio_req *req) {
    EventData *ev = static_cast<EventData*>(req->data);
    eio_custom(LookForEvent, EIO_PRI_DEFAULT, EventObtained, PrepEventData(ev->connection));
    distributeEvent(ev->ev);
    delete ev;
    return 0;
  }

  static int LookForEvent(eio_req *req) {
    EventData *ev = static_cast<EventData*>(req->data);
    ev->ev = xcb_wait_for_event(ev->connection);
    return req->result = 0;
  }

private:
  xcb_connection_t *connection;

};

};
