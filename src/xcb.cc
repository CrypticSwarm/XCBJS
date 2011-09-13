#include "xcb.h"
#include "events.cc"
#include "structs.cc"
#include "__autogen_requests.h"
#include "__autogen_enum.h"
#include <node.h>
#include <iostream>

namespace XCBJS {

using namespace std;
using namespace v8;
using namespace node;
using namespace XCBJS;

void XCBJS::Init(Handle<Object> target) {
  HandleScope scope;
  t = Persistent<Object>::New(target);

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(XCBJS::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("XConnection"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  NODE_SET_PROTOTYPE_METHOD(constructor, "flush", XCBJS::flush);
  NODE_SET_PROTOTYPE_METHOD(constructor, "generateId", XCBJS::generateId);
  NODE_SET_PROTOTYPE_METHOD(constructor, "manageWindows", XCBJS::manageWindows);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getRoot", XCBJS::getRoot);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getScreen", XCBJS::getScreen);
  NODE_SET_PROTOTYPE_METHOD(constructor, "getSetup", XCBJS::getSetup);
  NODE_SET_METHOD(target, "help", XCBJS::help);
  Event::Init(target);
  InitXCB2JSStructs(t);
  Enum::Init(t);
  Request::Init(constructor->PrototypeTemplate());
}

Handle<Value> XCBJS::New(const Arguments& args) {
  HandleScope scope;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Function.")));
  }
  Local<Function> cb = Local<Function>::Cast(args[0]);
  XCBJS *xcbjs = new XCBJS;
  xcbjs->Wrap(args.This());
  Handle<Object> obj = toJS(const_cast<xcb_setup_t *>(xcb_get_setup(xcbjs->getConnection())));
  Handle<Value> params[1] = { obj };
  cb->Call(args.This(), 1, params);
  return Undefined();
}

XCBJS::XCBJS() {
  connection = xcb_connect(NULL, NULL);
  const xcb_setup_t      *setup  = xcb_get_setup(connection);
  xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
  screen = iter.data;
}

Handle<Value> XCBJS::getSetup(const Arguments& args) {
  HandleScope scope;
  xcb_connection_t *connection = ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  return toJS(const_cast<xcb_setup_t *>(xcb_get_setup(connection)));
}

Handle<Value> XCBJS::getScreen(const Arguments& args) {
  HandleScope scope;
  xcb_screen_t *screen = ObjectWrap::Unwrap<XCBJS>(args.This())->getScreen();
  return toJS(screen);
}

Handle<Value> XCBJS::flush(const Arguments& args) {
  HandleScope scope;
  xcb_connection_t *connection = ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_flush(connection);
  return Undefined();
}

Handle<Value> XCBJS::generateId(const Arguments& args) {
  HandleScope scope;
  xcb_connection_t *connection = ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_window_t ret = xcb_generate_id(connection);
  return Integer::New(ret);
}

Handle<Value> XCBJS::createGC(const Arguments& args) {
  HandleScope scope;
  xcb_connection_t *connection = ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  uint32_t        mask       = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
  uint32_t        values[2]  = {screen->black_pixel, 0};
  xcb_gcontext_t black = args[0]->Int32Value();
  xcb_window_t window = args[1]->Int32Value();
  xcb_create_gc(connection, black, window, mask, values);
  
  return Undefined();
}

Handle<Value> XCBJS::manageWindows(const Arguments& args) {
  HandleScope scope;
  xcb_connection_t *connection = ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  uint32_t values[1] = { XCB_EVENT_MASK_STRUCTURE_NOTIFY
                       | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT
                       | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
                       | XCB_EVENT_MASK_KEY_PRESS };
  xcb_void_cookie_t cookie = xcb_change_window_attributes_checked(connection, screen->root, XCB_CW_EVENT_MASK, values);
  xcb_request_check(connection, cookie);
  xcb_flush(connection);
  return Undefined();
}

Handle<Value> XCBJS::getRoot(const Arguments& args) {
  HandleScope scope;
  xcb_screen_t *screen = ObjectWrap::Unwrap<XCBJS>(args.This())->getScreen();
  return scope.Close(Integer::New(screen->root));
}

Handle<Value> XCBJS::help(const Arguments& args) {
  HandleScope scope;
  Handle<String> help = Handle<String>::Cast(args[0]);
  Handle<String> str = Request::Docs(help);
  if (str->Equals(Undefined())) str = eventDocs(help);
  if (str->Equals(Undefined())) str = structDocs(help);
  return scope.Close(str);
}

};

extern "C" void
init (v8::Handle<v8::Object> target)
{
  v8::HandleScope scope;
  XCBJS::XCBJS::Init(target);
}
