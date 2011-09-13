#ifndef __XCBJS__
#define __XCBJS__

#include <xcb/xcb.h>
#include <node.h>

namespace XCBJS {

class XCBJS : public node::ObjectWrap {
public:
  XCBJS();
  static void Init(v8::Handle<v8::Object> target);
  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> getSetup(const v8::Arguments& args);
  static v8::Handle<v8::Value> getScreen(const v8::Arguments& args);
  static v8::Handle<v8::Value> flush(const v8::Arguments& args);
  static v8::Handle<v8::Value> generateId(const v8::Arguments& args);
  static v8::Handle<v8::Value> createGC(const v8::Arguments& args);
  static v8::Handle<v8::Value> manageWindows(const v8::Arguments& args);
  static v8::Handle<v8::Value> getRoot(const v8::Arguments& args);
  static v8::Handle<v8::Value> help(const v8::Arguments& args);
  static v8::Handle<v8::Value> surfaceTest(const v8::Arguments& args);
  xcb_connection_t *getConnection() { return connection; }
  xcb_screen_t *getScreen() { return screen; }
private:
  static v8::Persistent<v8::FunctionTemplate> constructor;
  static xcb_screen_t *screen;
  xcb_connection_t * connection;
};

};

#endif
