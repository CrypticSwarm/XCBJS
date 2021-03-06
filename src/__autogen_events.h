#ifndef __AUTOGENCTOJSXCBEVENTS__
#define __AUTOGENCTOJSXCBEVENTS__

static v8::Persistent<v8::Object> t;
namespace XCBJS {

#include <v8.h>

static v8::Persistent<v8::Object> lookup;

void InitXCB2JSEvents(v8::Persistent<v8::Object> tar) {
  t = tar;
  lookup = v8::Persistent<v8::Object>::New(v8::Object::New());
  lookup->Set(v8::String::New("keyPress"), v8::String::New("KeyPress: { detail: Integer\n, time: Integer\n, root: Integer\n, event: Integer\n, child: Integer\n, root_x: Integer\n, root_y: Integer\n, event_x: Integer\n, event_y: Integer\n, state: Integer\n, same_screen: Boolean }")); 
  lookup->Set(v8::String::New("buttonPress"), v8::String::New("ButtonPress: { detail: Integer\n, time: Integer\n, root: Integer\n, event: Integer\n, child: Integer\n, root_x: Integer\n, root_y: Integer\n, event_x: Integer\n, event_y: Integer\n, state: Integer\n, same_screen: Boolean }")); 
  lookup->Set(v8::String::New("motionNotify"), v8::String::New("MotionNotify: { detail: Integer\n, time: Integer\n, root: Integer\n, event: Integer\n, child: Integer\n, root_x: Integer\n, root_y: Integer\n, event_x: Integer\n, event_y: Integer\n, state: Integer\n, same_screen: Boolean }")); 
  lookup->Set(v8::String::New("enterNotify"), v8::String::New("EnterNotify: { detail: Integer\n, time: Integer\n, root: Integer\n, event: Integer\n, child: Integer\n, root_x: Integer\n, root_y: Integer\n, event_x: Integer\n, event_y: Integer\n, state: Integer\n, mode: Integer\n, same_screen_focus: Integer }")); 
  lookup->Set(v8::String::New("focusIn"), v8::String::New("FocusIn: { detail: Integer\n, event: Integer\n, mode: Integer }")); 
  lookup->Set(v8::String::New("keymapNotify"), v8::String::New("KeymapNotify: { }")); 
  lookup->Set(v8::String::New("expose"), v8::String::New("Expose: { window: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, count: Integer }")); 
  lookup->Set(v8::String::New("graphicsExposure"), v8::String::New("GraphicsExposure: { drawable: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, minor_opcode: Integer\n, count: Integer\n, major_opcode: Integer }")); 
  lookup->Set(v8::String::New("noExposure"), v8::String::New("NoExposure: { drawable: Integer\n, minor_opcode: Integer\n, major_opcode: Integer }")); 
  lookup->Set(v8::String::New("visibilityNotify"), v8::String::New("VisibilityNotify: { window: Integer\n, state: Integer }")); 
  lookup->Set(v8::String::New("createNotify"), v8::String::New("CreateNotify: { parent: Integer\n, window: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, border_width: Integer\n, override_redirect: Boolean }")); 
  lookup->Set(v8::String::New("destroyNotify"), v8::String::New("DestroyNotify: { event: Integer\n, window: Integer }")); 
  lookup->Set(v8::String::New("unmapNotify"), v8::String::New("UnmapNotify: { event: Integer\n, window: Integer\n, from_configure: Boolean }")); 
  lookup->Set(v8::String::New("mapNotify"), v8::String::New("MapNotify: { event: Integer\n, window: Integer\n, override_redirect: Boolean }")); 
  lookup->Set(v8::String::New("mapRequest"), v8::String::New("MapRequest: { parent: Integer\n, window: Integer }")); 
  lookup->Set(v8::String::New("reparentNotify"), v8::String::New("ReparentNotify: { event: Integer\n, window: Integer\n, parent: Integer\n, x: Integer\n, y: Integer\n, override_redirect: Boolean }")); 
  lookup->Set(v8::String::New("configureNotify"), v8::String::New("ConfigureNotify: { event: Integer\n, window: Integer\n, above_sibling: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, border_width: Integer\n, override_redirect: Boolean }")); 
  lookup->Set(v8::String::New("configureRequest"), v8::String::New("ConfigureRequest: { stack_mode: Integer\n, parent: Integer\n, window: Integer\n, sibling: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, border_width: Integer\n, value_mask: Integer }")); 
  lookup->Set(v8::String::New("gravityNotify"), v8::String::New("GravityNotify: { event: Integer\n, window: Integer\n, x: Integer\n, y: Integer }")); 
  lookup->Set(v8::String::New("resizeRequest"), v8::String::New("ResizeRequest: { window: Integer\n, width: Integer\n, height: Integer }")); 
  lookup->Set(v8::String::New("circulateNotify"), v8::String::New("CirculateNotify: { event: Integer\n, window: Integer\n, place: Integer }")); 
  lookup->Set(v8::String::New("propertyNotify"), v8::String::New("PropertyNotify: { window: Integer\n, atom: Integer\n, time: Integer\n, state: Integer }")); 
  lookup->Set(v8::String::New("selectionClear"), v8::String::New("SelectionClear: { time: Integer\n, owner: Integer\n, selection: Integer }")); 
  lookup->Set(v8::String::New("selectionRequest"), v8::String::New("SelectionRequest: { time: Integer\n, owner: Integer\n, requestor: Integer\n, selection: Integer\n, target: Integer\n, property: Integer }")); 
  lookup->Set(v8::String::New("selectionNotify"), v8::String::New("SelectionNotify: { time: Integer\n, requestor: Integer\n, selection: Integer\n, target: Integer\n, property: Integer }")); 
  lookup->Set(v8::String::New("colormapNotify"), v8::String::New("ColormapNotify: { window: Integer\n, colormap: Integer\n, new: Boolean\n, state: Integer }")); 
  lookup->Set(v8::String::New("clientMessage"), v8::String::New("ClientMessage: { format: Integer\n, window: Integer\n, type: Integer\n, data: undefined }")); 
  lookup->Set(v8::String::New("mappingNotify"), v8::String::New("MappingNotify: { request: Integer\n, first_keycode: Integer\n, count: Integer }")); 
  lookup->Set(v8::String::New("keyRelease"), v8::String::New("KeyRelease: { detail: Integer\n, time: Integer\n, root: Integer\n, event: Integer\n, child: Integer\n, root_x: Integer\n, root_y: Integer\n, event_x: Integer\n, event_y: Integer\n, state: Integer\n, same_screen: Boolean }")); 
  lookup->Set(v8::String::New("buttonRelease"), v8::String::New("ButtonRelease: { detail: Integer\n, time: Integer\n, root: Integer\n, event: Integer\n, child: Integer\n, root_x: Integer\n, root_y: Integer\n, event_x: Integer\n, event_y: Integer\n, state: Integer\n, same_screen: Boolean }")); 
  lookup->Set(v8::String::New("leaveNotify"), v8::String::New("LeaveNotify: { detail: Integer\n, time: Integer\n, root: Integer\n, event: Integer\n, child: Integer\n, root_x: Integer\n, root_y: Integer\n, event_x: Integer\n, event_y: Integer\n, state: Integer\n, mode: Integer\n, same_screen_focus: Integer }")); 
  lookup->Set(v8::String::New("focusOut"), v8::String::New("FocusOut: { detail: Integer\n, event: Integer\n, mode: Integer }")); 
  lookup->Set(v8::String::New("circulateRequest"), v8::String::New("CirculateRequest: { event: Integer\n, window: Integer\n, place: Integer }")); 
}

v8::Handle<v8::String> eventDocs(v8::Handle<v8::String> what) {
  v8::HandleScope scope;
  return scope.Close(v8::Handle<v8::String>::Cast(lookup->Get(what)));
}

//{ { { BEGIN SYMBOL CREATION 
static v8::Persistent<v8::String> onKeyPressSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onKeyPress"));
static v8::Persistent<v8::String> onButtonPressSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onButtonPress"));
static v8::Persistent<v8::String> onMotionNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onMotion"));
static v8::Persistent<v8::String> onEnterNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onEnter"));
static v8::Persistent<v8::String> onFocusInSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onFocusIn"));
static v8::Persistent<v8::String> onKeymapNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onKeymap"));
static v8::Persistent<v8::String> onExposeSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onExpose"));
static v8::Persistent<v8::String> onGraphicsExposureSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onGraphicsExposure"));
static v8::Persistent<v8::String> onNoExposureSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onNoExposure"));
static v8::Persistent<v8::String> onVisibilityNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onVisibility"));
static v8::Persistent<v8::String> onCreateNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onCreate"));
static v8::Persistent<v8::String> onDestroyNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onDestroy"));
static v8::Persistent<v8::String> onUnmapNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onUnmap"));
static v8::Persistent<v8::String> onMapNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onMap"));
static v8::Persistent<v8::String> onMapRequestSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onMapRequest"));
static v8::Persistent<v8::String> onReparentNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onReparent"));
static v8::Persistent<v8::String> onConfigureNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onConfigure"));
static v8::Persistent<v8::String> onConfigureRequestSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onConfigureRequest"));
static v8::Persistent<v8::String> onGravityNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onGravity"));
static v8::Persistent<v8::String> onResizeRequestSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onResizeRequest"));
static v8::Persistent<v8::String> onCirculateNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onCirculate"));
static v8::Persistent<v8::String> onPropertyNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onProperty"));
static v8::Persistent<v8::String> onSelectionClearSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onSelectionClear"));
static v8::Persistent<v8::String> onSelectionRequestSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onSelectionRequest"));
static v8::Persistent<v8::String> onSelectionNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onSelection"));
static v8::Persistent<v8::String> onColormapNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onColormap"));
static v8::Persistent<v8::String> onClientMessageSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onClientMessage"));
static v8::Persistent<v8::String> onMappingNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onMapping"));
static v8::Persistent<v8::String> onKeyReleaseSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onKeyRelease"));
static v8::Persistent<v8::String> onButtonReleaseSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onButtonRelease"));
static v8::Persistent<v8::String> onLeaveNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onLeave"));
static v8::Persistent<v8::String> onFocusOutSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onFocusOut"));
static v8::Persistent<v8::String> onCirculateRequestSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onCirculateRequest"));

// END SYMBOL CREATION } } }

//{ { { BEGIN EVENT PREP 

template <typename T>
v8::Handle<v8::Object> prepareKeyPressEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("detail"), v8::Integer::New(ev->detail));
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("root"), v8::Integer::New(ev->root));
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("child"), v8::Integer::New(ev->child));
  obj->Set(v8::String::New("root_x"), v8::Integer::New(ev->root_x));
  obj->Set(v8::String::New("root_y"), v8::Integer::New(ev->root_y));
  obj->Set(v8::String::New("event_x"), v8::Integer::New(ev->event_x));
  obj->Set(v8::String::New("event_y"), v8::Integer::New(ev->event_y));
  obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
  obj->Set(v8::String::New("same_screen"), v8::Boolean::New(ev->same_screen));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareButtonPressEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("detail"), v8::Integer::New(ev->detail));
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("root"), v8::Integer::New(ev->root));
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("child"), v8::Integer::New(ev->child));
  obj->Set(v8::String::New("root_x"), v8::Integer::New(ev->root_x));
  obj->Set(v8::String::New("root_y"), v8::Integer::New(ev->root_y));
  obj->Set(v8::String::New("event_x"), v8::Integer::New(ev->event_x));
  obj->Set(v8::String::New("event_y"), v8::Integer::New(ev->event_y));
  obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
  obj->Set(v8::String::New("same_screen"), v8::Boolean::New(ev->same_screen));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareMotionNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("detail"), v8::Integer::New(ev->detail));
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("root"), v8::Integer::New(ev->root));
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("child"), v8::Integer::New(ev->child));
  obj->Set(v8::String::New("root_x"), v8::Integer::New(ev->root_x));
  obj->Set(v8::String::New("root_y"), v8::Integer::New(ev->root_y));
  obj->Set(v8::String::New("event_x"), v8::Integer::New(ev->event_x));
  obj->Set(v8::String::New("event_y"), v8::Integer::New(ev->event_y));
  obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
  obj->Set(v8::String::New("same_screen"), v8::Boolean::New(ev->same_screen));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareEnterNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("detail"), v8::Integer::New(ev->detail));
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("root"), v8::Integer::New(ev->root));
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("child"), v8::Integer::New(ev->child));
  obj->Set(v8::String::New("root_x"), v8::Integer::New(ev->root_x));
  obj->Set(v8::String::New("root_y"), v8::Integer::New(ev->root_y));
  obj->Set(v8::String::New("event_x"), v8::Integer::New(ev->event_x));
  obj->Set(v8::String::New("event_y"), v8::Integer::New(ev->event_y));
  obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
  obj->Set(v8::String::New("mode"), v8::Integer::New(ev->mode));
  obj->Set(v8::String::New("same_screen_focus"), v8::Integer::New(ev->same_screen_focus));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareFocusInEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("detail"), v8::Integer::New(ev->detail));
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("mode"), v8::Integer::New(ev->mode));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareExposeEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(ev->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(ev->height));
  obj->Set(v8::String::New("count"), v8::Integer::New(ev->count));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareGraphicsExposureEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("drawable"), v8::Integer::New(ev->drawable));
  obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(ev->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(ev->height));
  obj->Set(v8::String::New("minor_opcode"), v8::Integer::New(ev->minor_opcode));
  obj->Set(v8::String::New("count"), v8::Integer::New(ev->count));
  obj->Set(v8::String::New("major_opcode"), v8::Integer::New(ev->major_opcode));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareNoExposureEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("drawable"), v8::Integer::New(ev->drawable));
  obj->Set(v8::String::New("minor_opcode"), v8::Integer::New(ev->minor_opcode));
  obj->Set(v8::String::New("major_opcode"), v8::Integer::New(ev->major_opcode));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareVisibilityNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareCreateNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("parent"), v8::Integer::New(ev->parent));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(ev->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(ev->height));
  obj->Set(v8::String::New("border_width"), v8::Integer::New(ev->border_width));
  obj->Set(v8::String::New("override_redirect"), v8::Boolean::New(ev->override_redirect));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareDestroyNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareUnmapNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("from_configure"), v8::Boolean::New(ev->from_configure));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareMapNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("override_redirect"), v8::Boolean::New(ev->override_redirect));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareMapRequestEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("parent"), v8::Integer::New(ev->parent));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareReparentNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("parent"), v8::Integer::New(ev->parent));
  obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
  obj->Set(v8::String::New("override_redirect"), v8::Boolean::New(ev->override_redirect));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareConfigureNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("above_sibling"), v8::Integer::New(ev->above_sibling));
  obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(ev->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(ev->height));
  obj->Set(v8::String::New("border_width"), v8::Integer::New(ev->border_width));
  obj->Set(v8::String::New("override_redirect"), v8::Boolean::New(ev->override_redirect));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareConfigureRequestEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("stack_mode"), v8::Integer::New(ev->stack_mode));
  obj->Set(v8::String::New("parent"), v8::Integer::New(ev->parent));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("sibling"), v8::Integer::New(ev->sibling));
  obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(ev->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(ev->height));
  obj->Set(v8::String::New("border_width"), v8::Integer::New(ev->border_width));
  obj->Set(v8::String::New("value_mask"), v8::Integer::New(ev->value_mask));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareGravityNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareResizeRequestEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("width"), v8::Integer::New(ev->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(ev->height));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareCirculateNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("place"), v8::Integer::New(ev->place));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> preparePropertyNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("atom"), v8::Integer::New(ev->atom));
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareSelectionClearEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("owner"), v8::Integer::New(ev->owner));
  obj->Set(v8::String::New("selection"), v8::Integer::New(ev->selection));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareSelectionRequestEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("owner"), v8::Integer::New(ev->owner));
  obj->Set(v8::String::New("requestor"), v8::Integer::New(ev->requestor));
  obj->Set(v8::String::New("selection"), v8::Integer::New(ev->selection));
  obj->Set(v8::String::New("target"), v8::Integer::New(ev->target));
  obj->Set(v8::String::New("property"), v8::Integer::New(ev->property));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareSelectionNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("time"), v8::Date::New(ev->time));
  obj->Set(v8::String::New("requestor"), v8::Integer::New(ev->requestor));
  obj->Set(v8::String::New("selection"), v8::Integer::New(ev->selection));
  obj->Set(v8::String::New("target"), v8::Integer::New(ev->target));
  obj->Set(v8::String::New("property"), v8::Integer::New(ev->property));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareColormapNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("colormap"), v8::Integer::New(ev->colormap));
  obj->Set(v8::String::New("new"), v8::Boolean::New(ev->_new));
  obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareClientMessageEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("format"), v8::Integer::New(ev->format));
  obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
  obj->Set(v8::String::New("type"), v8::Integer::New(ev->type));
  return scope.Close(obj);
}

template <typename T>
v8::Handle<v8::Object> prepareMappingNotifyEvent(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("request"), v8::Integer::New(ev->request));
  obj->Set(v8::String::New("first_keycode"), v8::Integer::New(ev->first_keycode));
  obj->Set(v8::String::New("count"), v8::Integer::New(ev->count));
  return scope.Close(obj);
}

// END EVENT PREP FUNCS } } }

template <typename T>
int handle_event(T ev, v8::Handle<v8::String> sym, v8::Handle<v8::Object> (*cb)(const T&)) {
  v8::HandleScope scope;
  v8::Local<v8::Value> val = t->Get(sym);
  if (val->IsFunction()) {
    v8::Local<v8::Function> jscb = v8::Local<v8::Function>::Cast(val);
    v8::Handle<v8::Object> obj = cb(ev);
    v8::Handle<v8::Value> args[1] = { obj };
    jscb->Call(obj, 1, args);
    delete ev;
  }
  return 0;
}

inline int distributeEvent(xcb_generic_event_t *ev) {
  switch(ev->response_type & ~0x80) {
    case XCB_KEY_PRESS: return handle_event((xcb_key_press_event_t *) ev, onKeyPressSym, prepareKeyPressEvent);
    case XCB_BUTTON_PRESS: return handle_event((xcb_button_press_event_t *) ev, onButtonPressSym, prepareButtonPressEvent);
    case XCB_MOTION_NOTIFY: return handle_event((xcb_motion_notify_event_t *) ev, onMotionNotifySym, prepareMotionNotifyEvent);
    case XCB_ENTER_NOTIFY: return handle_event((xcb_enter_notify_event_t *) ev, onEnterNotifySym, prepareEnterNotifyEvent);
    case XCB_FOCUS_IN: return handle_event((xcb_focus_in_event_t *) ev, onFocusInSym, prepareFocusInEvent);
    case XCB_EXPOSE: return handle_event((xcb_expose_event_t *) ev, onExposeSym, prepareExposeEvent);
    case XCB_GRAPHICS_EXPOSURE: return handle_event((xcb_graphics_exposure_event_t *) ev, onGraphicsExposureSym, prepareGraphicsExposureEvent);
    case XCB_NO_EXPOSURE: return handle_event((xcb_no_exposure_event_t *) ev, onNoExposureSym, prepareNoExposureEvent);
    case XCB_VISIBILITY_NOTIFY: return handle_event((xcb_visibility_notify_event_t *) ev, onVisibilityNotifySym, prepareVisibilityNotifyEvent);
    case XCB_CREATE_NOTIFY: return handle_event((xcb_create_notify_event_t *) ev, onCreateNotifySym, prepareCreateNotifyEvent);
    case XCB_DESTROY_NOTIFY: return handle_event((xcb_destroy_notify_event_t *) ev, onDestroyNotifySym, prepareDestroyNotifyEvent);
    case XCB_UNMAP_NOTIFY: return handle_event((xcb_unmap_notify_event_t *) ev, onUnmapNotifySym, prepareUnmapNotifyEvent);
    case XCB_MAP_NOTIFY: return handle_event((xcb_map_notify_event_t *) ev, onMapNotifySym, prepareMapNotifyEvent);
    case XCB_MAP_REQUEST: return handle_event((xcb_map_request_event_t *) ev, onMapRequestSym, prepareMapRequestEvent);
    case XCB_REPARENT_NOTIFY: return handle_event((xcb_reparent_notify_event_t *) ev, onReparentNotifySym, prepareReparentNotifyEvent);
    case XCB_CONFIGURE_NOTIFY: return handle_event((xcb_configure_notify_event_t *) ev, onConfigureNotifySym, prepareConfigureNotifyEvent);
    case XCB_CONFIGURE_REQUEST: return handle_event((xcb_configure_request_event_t *) ev, onConfigureRequestSym, prepareConfigureRequestEvent);
    case XCB_GRAVITY_NOTIFY: return handle_event((xcb_gravity_notify_event_t *) ev, onGravityNotifySym, prepareGravityNotifyEvent);
    case XCB_RESIZE_REQUEST: return handle_event((xcb_resize_request_event_t *) ev, onResizeRequestSym, prepareResizeRequestEvent);
    case XCB_CIRCULATE_NOTIFY: return handle_event((xcb_circulate_notify_event_t *) ev, onCirculateNotifySym, prepareCirculateNotifyEvent);
    case XCB_PROPERTY_NOTIFY: return handle_event((xcb_property_notify_event_t *) ev, onPropertyNotifySym, preparePropertyNotifyEvent);
    case XCB_SELECTION_CLEAR: return handle_event((xcb_selection_clear_event_t *) ev, onSelectionClearSym, prepareSelectionClearEvent);
    case XCB_SELECTION_REQUEST: return handle_event((xcb_selection_request_event_t *) ev, onSelectionRequestSym, prepareSelectionRequestEvent);
    case XCB_SELECTION_NOTIFY: return handle_event((xcb_selection_notify_event_t *) ev, onSelectionNotifySym, prepareSelectionNotifyEvent);
    case XCB_COLORMAP_NOTIFY: return handle_event((xcb_colormap_notify_event_t *) ev, onColormapNotifySym, prepareColormapNotifyEvent);
    case XCB_CLIENT_MESSAGE: return handle_event((xcb_client_message_event_t *) ev, onClientMessageSym, prepareClientMessageEvent);
    case XCB_MAPPING_NOTIFY: return handle_event((xcb_mapping_notify_event_t *) ev, onMappingNotifySym, prepareMappingNotifyEvent);
    case XCB_KEY_RELEASE: return handle_event((xcb_key_release_event_t *) ev, onKeyReleaseSym, prepareKeyPressEvent);
    case XCB_BUTTON_RELEASE: return handle_event((xcb_button_release_event_t *) ev, onButtonReleaseSym, prepareButtonPressEvent);
    case XCB_LEAVE_NOTIFY: return handle_event((xcb_leave_notify_event_t *) ev, onLeaveNotifySym, prepareEnterNotifyEvent);
    case XCB_FOCUS_OUT: return handle_event((xcb_focus_out_event_t *) ev, onFocusOutSym, prepareFocusInEvent);
    case XCB_CIRCULATE_REQUEST: return handle_event((xcb_circulate_request_event_t *) ev, onCirculateRequestSym, prepareCirculateNotifyEvent);
    default: delete ev;
  }
  return 0;
}

}
#endif