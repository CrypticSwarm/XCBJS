#ifndef __AUTOGENCTOJSXCBEVENTS__
#define __AUTOGENCTOJSXCBEVENTS__
#include <v8.h>

static v8::Persistent<v8::Object> t;

void InitXCB2JSEvents(v8::Persistent<v8::Object> tar) {
	t = tar;
}

//{{{ BEGIN SYMBOL CREATION 

static v8::Persistent<v8::String> onCreateNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onCreate"));
static v8::Persistent<v8::String> onDestroyNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onDestroy"));
static v8::Persistent<v8::String> onMapRequestSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onMap"));
static v8::Persistent<v8::String> onUnmapNotifySym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onUnmap"));
static v8::Persistent<v8::String> onKeyPressSym = v8::Persistent<v8::String>::New(v8::String::NewSymbol("onKeyDown"));

// END SYMBOL CREATION }}}

//{{{ BEGIN EVENT PREP 

template <typename T>
void prepareCreateNotifyEvent(const T& ev, v8::Handle<v8::Function> cb) {
	v8::HandleScope scope;
	v8::Local<v8::Object> obj = v8::Object::New();
	obj->Set(v8::String::New("parent"), v8::Integer::New(ev->parent));
	obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
	obj->Set(v8::String::New("x"), v8::Integer::New(ev->x));
	obj->Set(v8::String::New("y"), v8::Integer::New(ev->y));
	obj->Set(v8::String::New("width"), v8::Integer::New(ev->width));
	obj->Set(v8::String::New("height"), v8::Integer::New(ev->height));
	obj->Set(v8::String::New("border-width"), v8::Integer::New(ev->border_width));
	obj->Set(v8::String::New("override-redirect"), v8::Boolean::New(ev->override_redirect));
	v8::Local<v8::Value> args[1] = { obj };
	cb->Call(obj, 1, args);
}

template <typename T>
void prepareDestroyNotifyEvent(const T& ev, v8::Handle<v8::Function> cb) {
	v8::HandleScope scope;
	v8::Local<v8::Object> obj = v8::Object::New();
	obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
	obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
	v8::Local<v8::Value> args[1] = { obj };
	cb->Call(obj, 1, args);
}

template <typename T>
void prepareMapRequestEvent(const T& ev, v8::Handle<v8::Function> cb) {
	v8::HandleScope scope;
	v8::Local<v8::Object> obj = v8::Object::New();
	obj->Set(v8::String::New("parent"), v8::Integer::New(ev->parent));
	obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
	v8::Local<v8::Value> args[1] = { obj };
	cb->Call(obj, 1, args);
}

template <typename T>
void prepareUnmapNotifyEvent(const T& ev, v8::Handle<v8::Function> cb) {
	v8::HandleScope scope;
	v8::Local<v8::Object> obj = v8::Object::New();
	obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
	obj->Set(v8::String::New("window"), v8::Integer::New(ev->window));
	obj->Set(v8::String::New("from-configure"), v8::Boolean::New(ev->from_configure));
	v8::Local<v8::Value> args[1] = { obj };
	cb->Call(obj, 1, args);
}

template <typename T>
void prepareKeyPressEvent(const T& ev, v8::Handle<v8::Function> cb) {
	v8::HandleScope scope;
	v8::Local<v8::Object> obj = v8::Object::New();
	obj->Set(v8::String::New("root"), v8::Integer::New(ev->root));
	obj->Set(v8::String::New("event"), v8::Integer::New(ev->event));
	obj->Set(v8::String::New("child"), v8::Integer::New(ev->child));
	obj->Set(v8::String::New("same-screen"), v8::Boolean::New(ev->same_screen));
	obj->Set(v8::String::New("root-x"), v8::Integer::New(ev->root_x));
	obj->Set(v8::String::New("root-y"), v8::Integer::New(ev->root_y));
	obj->Set(v8::String::New("event-x"), v8::Integer::New(ev->event_x));
	obj->Set(v8::String::New("event-y"), v8::Integer::New(ev->event_y));
	obj->Set(v8::String::New("detail"), v8::Integer::New(ev->detail));
	obj->Set(v8::String::New("state"), v8::Integer::New(ev->state));
	obj->Set(v8::String::New("time"), v8::Integer::New(ev->time));
	v8::Local<v8::Value> args[1] = { obj };
	cb->Call(obj, 1, args);
}

// END EVENT PREP FUNCS}}}

template <typename T>
int handle_event(T ev, v8::Handle<v8::String> sym, void (*cb)(const T&, v8::Handle<v8::Function>)) {
	v8::HandleScope scope;
	v8::Local<v8::Value> val = t->Get(sym);
	if (val->IsFunction()) {
		v8::Local<v8::Function> jscb = v8::Local<v8::Function>::Cast(val);
		cb(ev, jscb);
		delete ev;
	}
	return 0;
}

inline int distributeEvent(xcb_generic_event_t *ev) {
	switch(ev->response_type & ~0x80) {
		case XCB_CREATE_NOTIFY: return handle_event((xcb_create_notify_event_t *) ev, onCreateNotifySym, prepareCreateNotifyEvent);
		case XCB_DESTROY_NOTIFY: return handle_event((xcb_destroy_notify_event_t *) ev, onDestroyNotifySym, prepareDestroyNotifyEvent);
		case XCB_MAP_REQUEST: return handle_event((xcb_map_request_event_t *) ev, onMapRequestSym, prepareMapRequestEvent);
		case XCB_UNMAP_NOTIFY: return handle_event((xcb_unmap_notify_event_t *) ev, onUnmapNotifySym, prepareUnmapNotifyEvent);
		case XCB_KEY_PRESS: return handle_event((xcb_key_press_event_t *) ev, onKeyPressSym, prepareKeyPressEvent);
		default: delete ev;
	}
	return 0;}

#endif
