#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "config.h"
#include "events.cc"
#include "structs.cc"
#include "__autogen_requests.h"
#include "__autogen_enum.h"

namespace XCBJS {

using namespace std;
using namespace v8;
using namespace node;
using namespace XCBJS;

static Persistent<Object> t;

void XCBJS::Init(Handle<Object> target) {
  HandleScope scope;
  t = Persistent<Object>::New(target);

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(XCBJS::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("XConnection"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  NODE_SET_METHOD(target, "flush", XCBJS::flush);
  NODE_SET_METHOD(target, "generateId", XCBJS::generateId);
  NODE_SET_METHOD(target, "manageWindows", XCBJS::manageWindows);
  NODE_SET_METHOD(target, "getRoot", XCBJS::getRoot);
  NODE_SET_METHOD(target, "getScreen", XCBJS::getScreen);
  NODE_SET_METHOD(target, "getSetup", XCBJS::getSetup);
  NODE_SET_METHOD(target, "help", XCBJS::help);
  NODE_SET_METHOD(target, "surfaceTest", XCBJS::surfaceTest);
  Event::Init(target);
  InitXCB2JSStructs(t);
  Enum::Init(t);
  Request::Init(t);
}

void XCBJS::New(const Arguments& args) {
  HandleScope scope;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Function.")));
  }
  Local<Function> cb = Local<Function>::Cast(args[0]);
  XCBJS *xcbjs = new XCBJS();
  xcbjs->Wrap(args.This());
  Handle<Object> obj = toJS(const_cast<xcb_setup_t *>(xcb_get_setup(Config::connection)));
  Local<Value> params[1] = { obj };
  cb->Call(args.This(), 1, params);
  return Undefined();
}

XCBJS::XCBJS() {
  Config::connection = xcb_connect(NULL, NULL);
  const xcb_setup_t      *setup  = xcb_get_setup(Config::connection);
  xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
  screen = iter.data;
}

Handle<Value> XCBJS::getSetup(const Arguments& args) {
  HandleScope scope;
  return toJS(const_cast<xcb_setup_t *>(xcb_get_setup(Config::connection)));
}

Handle<Value> XCBJS::getScreen(const Arguments& args) {
  HandleScope scope;
  return toJS(screen);
}

Handle<Value> XCBJS::flush(const Arguments& args) {
  HandleScope scope;
  xcb_flush(Config::connection);
  return Undefined();
}

Handle<Value> XCBJS::generateId(const Arguments& args) {
  HandleScope scope;
  xcb_window_t ret = xcb_generate_id(Config::connection);
  return Integer::New(ret);
}

Handle<Value> XCBJS::createGC(const Arguments& args) {
  HandleScope scope;
  uint32_t        mask       = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
  uint32_t        values[2]  = {screen->black_pixel, 0};
  xcb_gcontext_t black = args[0]->Int32Value();
  xcb_window_t window = args[1]->Int32Value();
  xcb_create_gc(Config::connection, black, window, mask, values);
  
  return Undefined();
}

Handle<Value> XCBJS::manageWindows(const Arguments& args) {
  HandleScope scope;
  uint32_t values[1] = { XCB_EVENT_MASK_STRUCTURE_NOTIFY
                       | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT
                       | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
                       | XCB_EVENT_MASK_KEY_PRESS };
  xcb_void_cookie_t cookie = xcb_change_window_attributes_checked(Config::connection, screen->root, XCB_CW_EVENT_MASK, values);
  xcb_request_check(Config::connection, cookie);
  xcb_flush(Config::connection);
  return Undefined();
}

Handle<Value> XCBJS::getRoot(const Arguments& args) {
  HandleScope scope;
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
