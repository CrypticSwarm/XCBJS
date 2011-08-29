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

namespace XCBJS {

using namespace std;
using namespace v8;
using namespace node;
using namespace XCBJS;

static xcb_screen_t *screen;
Persistent<Object> t;

class XCBJS {

public:
  static void Init(Handle<Object> target) {
    HandleScope scope;
    t = Persistent<Object>::New(target);
    Config::connection = xcb_connect(NULL, NULL);
    const xcb_setup_t      *setup  = xcb_get_setup(Config::connection);
    xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
    screen = iter.data;
    NODE_SET_METHOD(target, "drawRect", XCBJS::drawRect);
    NODE_SET_METHOD(target, "flush", XCBJS::flush);
    NODE_SET_METHOD(target, "clearArea", XCBJS::clearArea);
    NODE_SET_METHOD(target, "generateId", XCBJS::generateId);
    NODE_SET_METHOD(target, "createWindow", XCBJS::createWindow);
    NODE_SET_METHOD(target, "createGC", XCBJS::createGC);
    NODE_SET_METHOD(target, "mapWindow", XCBJS::mapWindow);
    NODE_SET_METHOD(target, "unmapWindow", XCBJS::unmapWindow);
    NODE_SET_METHOD(target, "configureWindow", XCBJS::configureWindow);
    NODE_SET_METHOD(target, "manageWindows", XCBJS::manageWindows);
    NODE_SET_METHOD(target, "getRoot", XCBJS::getRoot);
    NODE_SET_METHOD(target, "getScreen", XCBJS::getScreen);
    NODE_SET_METHOD(target, "help", XCBJS::sDocs);
    Event::Init(target);
  }

  static Handle<Value> getScreen(const Arguments& args) {
    HandleScope scope;
    return toJS(screen);
  }

  static Handle<Value> drawRect(const Arguments& args) {
    HandleScope scope;
    xcbReqPolyRectangle(args[0]->ToObject());
    return Undefined();
  }

  static Handle<Value> clearArea(const Arguments& args) {
    HandleScope scope;
    const char *usage = "usage: clearArea(window, x, y, width, height)";
    if (args.Length() != 5) {
      return ThrowException(Exception::Error(String::New(usage)));
    }
    xcb_window_t window = args[0]->Int32Value();
    xcb_clear_area(Config::connection, 0
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
    xcb_flush(Config::connection);
    return Undefined();
  }

  static Handle<Value> generateId(const Arguments& args) {
    HandleScope scope;
    xcb_window_t ret = xcb_generate_id(Config::connection);
    return Integer::New(ret);
  }

  static Handle<Value> createWindow(const Arguments& args) {
    HandleScope scope;
    xcbReqCreateWindow(args[0]->ToObject());
    return Undefined();
  }

  static Handle<Value> createGC(const Arguments& args) {
    HandleScope scope;
    uint32_t        mask       = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    uint32_t        values[2]  = {screen->black_pixel, 0};
    xcb_gcontext_t black = args[0]->Int32Value();
    xcb_window_t window = args[1]->Int32Value();
    xcb_create_gc(Config::connection, black, window, mask, values);
    
    return Undefined();
  }

  static Handle<Value> mapWindow(const Arguments& args) {
    HandleScope scope;
    xcbReqMapWindow(args[0]->ToObject());
    return Undefined();
  }

  static Handle<Value> unmapWindow(const Arguments& args) {
    HandleScope scope;
    xcbReqUnmapWindow(args[0]->ToObject());
    return Undefined();
  }

  static Handle<Value> configureWindow(const Arguments& args) {
    HandleScope scope;
    xcbReqConfigureWindow(args[0]->ToObject());
    return Undefined();
  }

  static Handle<Value> manageWindows(const Arguments& args) {
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

  static Handle<Value> getRoot(const Arguments& args) {
    HandleScope scope;
    return scope.Close(Integer::New(screen->root));
  }

  static Handle<Value> sDocs(const Arguments& args) {
    HandleScope scope;
    return scope.Close(structDocs(Handle<String>::Cast(args[0])));
  }

private:
};

};

extern "C" void
init (v8::Handle<v8::Object> target)
{
  v8::HandleScope scope;
  XCBJS::XCBJS::Init(target);
}


