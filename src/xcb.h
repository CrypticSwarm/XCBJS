#ifndef __XCBJS__
#define __XCBJS__

namespace XCBJS {

class XCBJS : public ObjectWrap {
public:
  static void Init(Handle<Object> target);
  static Handle<Value> New(const Arguments& args);
  static Handle<Value> getSetup(const Arguments& args);
  static Handle<Value> getScreen(const Arguments& args);
  static Handle<Value> flush(const Arguments& args);
  static Handle<Value> generateId(const Arguments& args);
  static Handle<Value> createGC(const Arguments& args);
  static Handle<Value> manageWindows(const Arguments& args);
  static Handle<Value> getRoot(const Arguments& args);
  static Handle<Value> help(const Arguments& args);
  static Handle<Value> surfaceTest(const Arguments& args);
private:
  xcb_connection_t * connection;
};

};

#endif
