#ifndef __AUTOGENCTOJSXCBREQUESTS__
#define __AUTOGENCTOJSXCBREQUESTS__
#include <v8.h>
#include <node.h>
#include "xcb.h"


namespace XCBJS {
  namespace Request {

template <typename R, typename C>
struct Reply {
  C cookie;
  R *reply;
  v8::Persistent<v8::Function> callback;
  xcb_connection_t * connection;
};

//{ { { BEGIN REQUESTS 

v8::Handle<v8::Value> CreateWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t depth = (uint8_t) obj->Get(v8::String::New("depth"))->IntegerValue();
  xcb_window_t wid = (xcb_window_t) obj->Get(v8::String::New("wid"))->IntegerValue();
  xcb_window_t parent = (xcb_window_t) obj->Get(v8::String::New("parent"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  uint16_t border_width = (uint16_t) obj->Get(v8::String::New("border_width"))->IntegerValue();
  uint16_t _class = (uint16_t) obj->Get(v8::String::New("class"))->IntegerValue();
  xcb_visualid_t visual = (xcb_visualid_t) obj->Get(v8::String::New("visual"))->IntegerValue();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  uint32_t *value_list;
  v8::Local<v8::Array> value_mask_valmask = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
  value_list = new uint32_t[value_mask_valmask->Length()];
  for(unsigned int i = 0; i < value_mask_valmask->Length(); ++i) {
    value_list[i] = (uint32_t) value_mask_valmask->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_create_window(connection, depth, wid, parent, x, y, width, height, border_width, _class, visual, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> ChangeWindowAttributes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeWindowAttributes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  uint32_t *value_list;
  v8::Local<v8::Array> value_mask_valmask = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
  value_list = new uint32_t[value_mask_valmask->Length()];
  for(unsigned int i = 0; i < value_mask_valmask->Length(); ++i) {
    value_list[i] = (uint32_t) value_mask_valmask->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_window_attributes(connection, window, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

int GetGetWindowAttributesReply(eio_req *req) {
  Reply<xcb_get_window_attributes_reply_t, xcb_get_window_attributes_cookie_t> *reply = static_cast<Reply<xcb_get_window_attributes_reply_t, xcb_get_window_attributes_cookie_t> *>(req->data);
  reply->reply = xcb_get_window_attributes_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetWindowAttributesReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_window_attributes_reply_t, xcb_get_window_attributes_cookie_t> *reply = static_cast<Reply<xcb_get_window_attributes_reply_t, xcb_get_window_attributes_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("backing_store"), v8::Integer::New(reply->reply->backing_store));
  obj->Set(v8::String::New("visual"), v8::Integer::New(reply->reply->visual));
  obj->Set(v8::String::New("class"), v8::Integer::New(reply->reply->_class));
  obj->Set(v8::String::New("bit_gravity"), v8::Integer::New(reply->reply->bit_gravity));
  obj->Set(v8::String::New("win_gravity"), v8::Integer::New(reply->reply->win_gravity));
  obj->Set(v8::String::New("backing_planes"), v8::Integer::New(reply->reply->backing_planes));
  obj->Set(v8::String::New("backing_pixel"), v8::Integer::New(reply->reply->backing_pixel));
  obj->Set(v8::String::New("save_under"), v8::Boolean::New(reply->reply->save_under));
  obj->Set(v8::String::New("map_is_installed"), v8::Boolean::New(reply->reply->map_is_installed));
  obj->Set(v8::String::New("map_state"), v8::Integer::New(reply->reply->map_state));
  obj->Set(v8::String::New("override_redirect"), v8::Boolean::New(reply->reply->override_redirect));
  obj->Set(v8::String::New("colormap"), v8::Integer::New(reply->reply->colormap));
  obj->Set(v8::String::New("all_event_masks"), v8::Integer::New(reply->reply->all_event_masks));
  obj->Set(v8::String::New("your_event_mask"), v8::Integer::New(reply->reply->your_event_mask));
  obj->Set(v8::String::New("do_not_propagate_mask"), v8::Integer::New(reply->reply->do_not_propagate_mask));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetWindowAttributes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetWindowAttributes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_window_attributes_cookie_t cookie = xcb_get_window_attributes(connection, window);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_window_attributes_reply_t, xcb_get_window_attributes_cookie_t> *reply = new Reply<xcb_get_window_attributes_reply_t, xcb_get_window_attributes_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetWindowAttributesReply, EIO_PRI_DEFAULT, HandleGetWindowAttributesReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> DestroyWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: DestroyWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_destroy_window(connection, window);
  return Undefined();
}

v8::Handle<v8::Value> DestroySubwindows(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: DestroySubwindows(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_destroy_subwindows(connection, window);
  return Undefined();
}

v8::Handle<v8::Value> ChangeSaveSet(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeSaveSet(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_save_set(connection, mode, window);
  return Undefined();
}

v8::Handle<v8::Value> ReparentWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ReparentWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_window_t parent = (xcb_window_t) obj->Get(v8::String::New("parent"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_reparent_window(connection, window, parent, x, y);
  return Undefined();
}

v8::Handle<v8::Value> MapWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: MapWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_map_window(connection, window);
  return Undefined();
}

v8::Handle<v8::Value> MapSubwindows(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: MapSubwindows(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_map_subwindows(connection, window);
  return Undefined();
}

v8::Handle<v8::Value> UnmapWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UnmapWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_unmap_window(connection, window);
  return Undefined();
}

v8::Handle<v8::Value> UnmapSubwindows(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UnmapSubwindows(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_unmap_subwindows(connection, window);
  return Undefined();
}

v8::Handle<v8::Value> ConfigureWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ConfigureWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  uint16_t value_mask = (uint16_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  uint32_t *value_list;
  v8::Local<v8::Array> value_mask_valmask = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
  value_list = new uint32_t[value_mask_valmask->Length()];
  for(unsigned int i = 0; i < value_mask_valmask->Length(); ++i) {
    value_list[i] = (uint32_t) value_mask_valmask->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_configure_window(connection, window, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> CirculateWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CirculateWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t direction = (uint8_t) obj->Get(v8::String::New("direction"))->IntegerValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_circulate_window(connection, direction, window);
  return Undefined();
}

int GetGetGeometryReply(eio_req *req) {
  Reply<xcb_get_geometry_reply_t, xcb_get_geometry_cookie_t> *reply = static_cast<Reply<xcb_get_geometry_reply_t, xcb_get_geometry_cookie_t> *>(req->data);
  reply->reply = xcb_get_geometry_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetGeometryReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_geometry_reply_t, xcb_get_geometry_cookie_t> *reply = static_cast<Reply<xcb_get_geometry_reply_t, xcb_get_geometry_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("depth"), v8::Integer::New(reply->reply->depth));
  obj->Set(v8::String::New("root"), v8::Integer::New(reply->reply->root));
  obj->Set(v8::String::New("x"), v8::Integer::New(reply->reply->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(reply->reply->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(reply->reply->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(reply->reply->height));
  obj->Set(v8::String::New("border_width"), v8::Integer::New(reply->reply->border_width));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetGeometry(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetGeometry(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_geometry_cookie_t cookie = xcb_get_geometry(connection, drawable);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_geometry_reply_t, xcb_get_geometry_cookie_t> *reply = new Reply<xcb_get_geometry_reply_t, xcb_get_geometry_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetGeometryReply, EIO_PRI_DEFAULT, HandleGetGeometryReply, reply);
  }
  return Undefined();
}

int GetQueryTreeReply(eio_req *req) {
  Reply<xcb_query_tree_reply_t, xcb_query_tree_cookie_t> *reply = static_cast<Reply<xcb_query_tree_reply_t, xcb_query_tree_cookie_t> *>(req->data);
  reply->reply = xcb_query_tree_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryTreeReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_tree_reply_t, xcb_query_tree_cookie_t> *reply = static_cast<Reply<xcb_query_tree_reply_t, xcb_query_tree_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("root"), v8::Integer::New(reply->reply->root));
  obj->Set(v8::String::New("parent"), v8::Integer::New(reply->reply->parent));
  v8::Local<v8::Array> children_list = v8::Array::New();
  obj->Set(v8::String::New("children"), children_list);
  xcb_window_t *children_list_ptr = xcb_query_tree_children(reply->reply);
  for(int i = 0; i < xcb_query_tree_children_length(reply->reply); ++i) {
    children_list->Set(i, v8::Integer::New(children_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryTree(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryTree(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_tree_cookie_t cookie = xcb_query_tree(connection, window);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_tree_reply_t, xcb_query_tree_cookie_t> *reply = new Reply<xcb_query_tree_reply_t, xcb_query_tree_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryTreeReply, EIO_PRI_DEFAULT, HandleQueryTreeReply, reply);
  }
  return Undefined();
}

int GetInternAtomReply(eio_req *req) {
  Reply<xcb_intern_atom_reply_t, xcb_intern_atom_cookie_t> *reply = static_cast<Reply<xcb_intern_atom_reply_t, xcb_intern_atom_cookie_t> *>(req->data);
  reply->reply = xcb_intern_atom_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleInternAtomReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_intern_atom_reply_t, xcb_intern_atom_cookie_t> *reply = static_cast<Reply<xcb_intern_atom_reply_t, xcb_intern_atom_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("atom"), v8::Integer::New(reply->reply->atom));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> InternAtom(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: InternAtom(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t only_if_exists = (uint8_t) obj->Get(v8::String::New("only_if_exists"))->BooleanValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_intern_atom_cookie_t cookie = xcb_intern_atom(connection, only_if_exists, name_len, name);
  delete [] name;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_intern_atom_reply_t, xcb_intern_atom_cookie_t> *reply = new Reply<xcb_intern_atom_reply_t, xcb_intern_atom_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetInternAtomReply, EIO_PRI_DEFAULT, HandleInternAtomReply, reply);
  }
  return Undefined();
}

int GetGetAtomNameReply(eio_req *req) {
  Reply<xcb_get_atom_name_reply_t, xcb_get_atom_name_cookie_t> *reply = static_cast<Reply<xcb_get_atom_name_reply_t, xcb_get_atom_name_cookie_t> *>(req->data);
  reply->reply = xcb_get_atom_name_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetAtomNameReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_atom_name_reply_t, xcb_get_atom_name_cookie_t> *reply = static_cast<Reply<xcb_get_atom_name_reply_t, xcb_get_atom_name_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("name"), v8::String::New((char*)xcb_get_atom_name_name(reply->reply)));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetAtomName(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetAtomName(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_atom_t atom = (xcb_atom_t) obj->Get(v8::String::New("atom"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_atom_name_cookie_t cookie = xcb_get_atom_name(connection, atom);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_atom_name_reply_t, xcb_get_atom_name_cookie_t> *reply = new Reply<xcb_get_atom_name_reply_t, xcb_get_atom_name_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetAtomNameReply, EIO_PRI_DEFAULT, HandleGetAtomNameReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> ChangeProperty(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeProperty(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
  xcb_atom_t type = (xcb_atom_t) obj->Get(v8::String::New("type"))->IntegerValue();
  uint8_t format = (uint8_t) obj->Get(v8::String::New("format"))->IntegerValue();
  uint32_t data_len = (uint32_t) obj->Get(v8::String::New("data_len"))->IntegerValue();
  char *data;
  v8::Local<v8::String> data_list = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("data")));
  data = new char[data_list->Length()];
  strcpy(data, *v8::String::AsciiValue(data_list));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_property(connection, mode, window, property, type, format, data_len, data);
  delete [] data;
  return Undefined();
}

v8::Handle<v8::Value> DeleteProperty(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: DeleteProperty(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_delete_property(connection, window, property);
  return Undefined();
}

int GetGetPropertyReply(eio_req *req) {
  Reply<xcb_get_property_reply_t, xcb_get_property_cookie_t> *reply = static_cast<Reply<xcb_get_property_reply_t, xcb_get_property_cookie_t> *>(req->data);
  reply->reply = xcb_get_property_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetPropertyReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_property_reply_t, xcb_get_property_cookie_t> *reply = static_cast<Reply<xcb_get_property_reply_t, xcb_get_property_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("format"), v8::Integer::New(reply->reply->format));
  obj->Set(v8::String::New("type"), v8::Integer::New(reply->reply->type));
  obj->Set(v8::String::New("bytes_after"), v8::Integer::New(reply->reply->bytes_after));
  obj->Set(v8::String::New("value"), v8::String::New((char*)xcb_get_property_value(reply->reply)));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetProperty(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetProperty(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t _delete = (uint8_t) obj->Get(v8::String::New("delete"))->BooleanValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
  xcb_atom_t type = (xcb_atom_t) obj->Get(v8::String::New("type"))->IntegerValue();
  uint32_t long_offset = (uint32_t) obj->Get(v8::String::New("long_offset"))->IntegerValue();
  uint32_t long_length = (uint32_t) obj->Get(v8::String::New("long_length"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_property_cookie_t cookie = xcb_get_property(connection, _delete, window, property, type, long_offset, long_length);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_property_reply_t, xcb_get_property_cookie_t> *reply = new Reply<xcb_get_property_reply_t, xcb_get_property_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetPropertyReply, EIO_PRI_DEFAULT, HandleGetPropertyReply, reply);
  }
  return Undefined();
}

int GetListPropertiesReply(eio_req *req) {
  Reply<xcb_list_properties_reply_t, xcb_list_properties_cookie_t> *reply = static_cast<Reply<xcb_list_properties_reply_t, xcb_list_properties_cookie_t> *>(req->data);
  reply->reply = xcb_list_properties_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleListPropertiesReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_list_properties_reply_t, xcb_list_properties_cookie_t> *reply = static_cast<Reply<xcb_list_properties_reply_t, xcb_list_properties_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> atoms_list = v8::Array::New();
  obj->Set(v8::String::New("atoms"), atoms_list);
  xcb_atom_t *atoms_list_ptr = xcb_list_properties_atoms(reply->reply);
  for(int i = 0; i < xcb_list_properties_atoms_length(reply->reply); ++i) {
    atoms_list->Set(i, v8::Integer::New(atoms_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> ListProperties(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListProperties(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_list_properties_cookie_t cookie = xcb_list_properties(connection, window);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_list_properties_reply_t, xcb_list_properties_cookie_t> *reply = new Reply<xcb_list_properties_reply_t, xcb_list_properties_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetListPropertiesReply, EIO_PRI_DEFAULT, HandleListPropertiesReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> SetSelectionOwner(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetSelectionOwner(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t owner = (xcb_window_t) obj->Get(v8::String::New("owner"))->IntegerValue();
  xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_selection_owner(connection, owner, selection, time);
  return Undefined();
}

int GetGetSelectionOwnerReply(eio_req *req) {
  Reply<xcb_get_selection_owner_reply_t, xcb_get_selection_owner_cookie_t> *reply = static_cast<Reply<xcb_get_selection_owner_reply_t, xcb_get_selection_owner_cookie_t> *>(req->data);
  reply->reply = xcb_get_selection_owner_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetSelectionOwnerReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_selection_owner_reply_t, xcb_get_selection_owner_cookie_t> *reply = static_cast<Reply<xcb_get_selection_owner_reply_t, xcb_get_selection_owner_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("owner"), v8::Integer::New(reply->reply->owner));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetSelectionOwner(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetSelectionOwner(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_selection_owner_cookie_t cookie = xcb_get_selection_owner(connection, selection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_selection_owner_reply_t, xcb_get_selection_owner_cookie_t> *reply = new Reply<xcb_get_selection_owner_reply_t, xcb_get_selection_owner_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetSelectionOwnerReply, EIO_PRI_DEFAULT, HandleGetSelectionOwnerReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> ConvertSelection(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ConvertSelection(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t requestor = (xcb_window_t) obj->Get(v8::String::New("requestor"))->IntegerValue();
  xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
  xcb_atom_t target = (xcb_atom_t) obj->Get(v8::String::New("target"))->IntegerValue();
  xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_convert_selection(connection, requestor, selection, target, property, time);
  return Undefined();
}

v8::Handle<v8::Value> SendEvent(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SendEvent(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t propagate = (uint8_t) obj->Get(v8::String::New("propagate"))->BooleanValue();
  xcb_window_t destination = (xcb_window_t) obj->Get(v8::String::New("destination"))->IntegerValue();
  uint32_t event_mask = (uint32_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
  char *event;
  v8::Local<v8::String> event_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("event")));
  event = new char[event_str->Length()];
  strcpy(event, *v8::String::AsciiValue(event_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_send_event(connection, propagate, destination, event_mask, event);
  delete [] event;
  return Undefined();
}

int GetGrabPointerReply(eio_req *req) {
  Reply<xcb_grab_pointer_reply_t, xcb_grab_pointer_cookie_t> *reply = static_cast<Reply<xcb_grab_pointer_reply_t, xcb_grab_pointer_cookie_t> *>(req->data);
  reply->reply = xcb_grab_pointer_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGrabPointerReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_grab_pointer_reply_t, xcb_grab_pointer_cookie_t> *reply = static_cast<Reply<xcb_grab_pointer_reply_t, xcb_grab_pointer_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("status"), v8::Integer::New(reply->reply->status));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GrabPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t event_mask = (uint16_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
  uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
  uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
  xcb_window_t confine_to = (xcb_window_t) obj->Get(v8::String::New("confine_to"))->IntegerValue();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_grab_pointer_cookie_t cookie = xcb_grab_pointer(connection, owner_events, grab_window, event_mask, pointer_mode, keyboard_mode, confine_to, cursor, time);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_grab_pointer_reply_t, xcb_grab_pointer_cookie_t> *reply = new Reply<xcb_grab_pointer_reply_t, xcb_grab_pointer_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGrabPointerReply, EIO_PRI_DEFAULT, HandleGrabPointerReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> UngrabPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_ungrab_pointer(connection, time);
  return Undefined();
}

v8::Handle<v8::Value> GrabButton(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabButton(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t event_mask = (uint16_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
  uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
  uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
  xcb_window_t confine_to = (xcb_window_t) obj->Get(v8::String::New("confine_to"))->IntegerValue();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  uint8_t button = (uint8_t) obj->Get(v8::String::New("button"))->IntegerValue();
  uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_grab_button(connection, owner_events, grab_window, event_mask, pointer_mode, keyboard_mode, confine_to, cursor, button, modifiers);
  return Undefined();
}

v8::Handle<v8::Value> UngrabButton(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabButton(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t button = (uint8_t) obj->Get(v8::String::New("button"))->IntegerValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_ungrab_button(connection, button, grab_window, modifiers);
  return Undefined();
}

v8::Handle<v8::Value> ChangeActivePointerGrab(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeActivePointerGrab(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  uint16_t event_mask = (uint16_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_active_pointer_grab(connection, cursor, time, event_mask);
  return Undefined();
}

int GetGrabKeyboardReply(eio_req *req) {
  Reply<xcb_grab_keyboard_reply_t, xcb_grab_keyboard_cookie_t> *reply = static_cast<Reply<xcb_grab_keyboard_reply_t, xcb_grab_keyboard_cookie_t> *>(req->data);
  reply->reply = xcb_grab_keyboard_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGrabKeyboardReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_grab_keyboard_reply_t, xcb_grab_keyboard_cookie_t> *reply = static_cast<Reply<xcb_grab_keyboard_reply_t, xcb_grab_keyboard_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("status"), v8::Integer::New(reply->reply->status));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GrabKeyboard(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabKeyboard(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
  uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_grab_keyboard_cookie_t cookie = xcb_grab_keyboard(connection, owner_events, grab_window, time, pointer_mode, keyboard_mode);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_grab_keyboard_reply_t, xcb_grab_keyboard_cookie_t> *reply = new Reply<xcb_grab_keyboard_reply_t, xcb_grab_keyboard_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGrabKeyboardReply, EIO_PRI_DEFAULT, HandleGrabKeyboardReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> UngrabKeyboard(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabKeyboard(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_ungrab_keyboard(connection, time);
  return Undefined();
}

v8::Handle<v8::Value> GrabKey(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabKey(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
  xcb_keycode_t key = (xcb_keycode_t) obj->Get(v8::String::New("key"))->IntegerValue();
  uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
  uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_grab_key(connection, owner_events, grab_window, modifiers, key, pointer_mode, keyboard_mode);
  return Undefined();
}

v8::Handle<v8::Value> UngrabKey(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabKey(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_keycode_t key = (xcb_keycode_t) obj->Get(v8::String::New("key"))->IntegerValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_ungrab_key(connection, key, grab_window, modifiers);
  return Undefined();
}

v8::Handle<v8::Value> AllowEvents(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllowEvents(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_allow_events(connection, mode, time);
  return Undefined();
}

v8::Handle<v8::Value> GrabServer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabServer(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_grab_server(connection);
  return Undefined();
}

v8::Handle<v8::Value> UngrabServer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabServer(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_ungrab_server(connection);
  return Undefined();
}

int GetQueryPointerReply(eio_req *req) {
  Reply<xcb_query_pointer_reply_t, xcb_query_pointer_cookie_t> *reply = static_cast<Reply<xcb_query_pointer_reply_t, xcb_query_pointer_cookie_t> *>(req->data);
  reply->reply = xcb_query_pointer_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryPointerReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_pointer_reply_t, xcb_query_pointer_cookie_t> *reply = static_cast<Reply<xcb_query_pointer_reply_t, xcb_query_pointer_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("same_screen"), v8::Boolean::New(reply->reply->same_screen));
  obj->Set(v8::String::New("root"), v8::Integer::New(reply->reply->root));
  obj->Set(v8::String::New("child"), v8::Integer::New(reply->reply->child));
  obj->Set(v8::String::New("root_x"), v8::Integer::New(reply->reply->root_x));
  obj->Set(v8::String::New("root_y"), v8::Integer::New(reply->reply->root_y));
  obj->Set(v8::String::New("win_x"), v8::Integer::New(reply->reply->win_x));
  obj->Set(v8::String::New("win_y"), v8::Integer::New(reply->reply->win_y));
  obj->Set(v8::String::New("mask"), v8::Integer::New(reply->reply->mask));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_pointer_cookie_t cookie = xcb_query_pointer(connection, window);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_pointer_reply_t, xcb_query_pointer_cookie_t> *reply = new Reply<xcb_query_pointer_reply_t, xcb_query_pointer_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryPointerReply, EIO_PRI_DEFAULT, HandleQueryPointerReply, reply);
  }
  return Undefined();
}

int GetGetMotionEventsReply(eio_req *req) {
  Reply<xcb_get_motion_events_reply_t, xcb_get_motion_events_cookie_t> *reply = static_cast<Reply<xcb_get_motion_events_reply_t, xcb_get_motion_events_cookie_t> *>(req->data);
  reply->reply = xcb_get_motion_events_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetMotionEventsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_motion_events_reply_t, xcb_get_motion_events_cookie_t> *reply = static_cast<Reply<xcb_get_motion_events_reply_t, xcb_get_motion_events_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> events_list = v8::Array::New();
  obj->Set(v8::String::New("events"), events_list);
  int ievents = 0;
  for(xcb_timecoord_iterator_t itr = xcb_get_motion_events_events_iterator(reply->reply); itr.rem; xcb_timecoord_next(&itr), ++ievents) {
    events_list->Set(ievents, toJS(itr.data));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetMotionEvents(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetMotionEvents(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_timestamp_t start = (xcb_timestamp_t) obj->Get(v8::String::New("start"))->IntegerValue();
  xcb_timestamp_t stop = (xcb_timestamp_t) obj->Get(v8::String::New("stop"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_motion_events_cookie_t cookie = xcb_get_motion_events(connection, window, start, stop);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_motion_events_reply_t, xcb_get_motion_events_cookie_t> *reply = new Reply<xcb_get_motion_events_reply_t, xcb_get_motion_events_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetMotionEventsReply, EIO_PRI_DEFAULT, HandleGetMotionEventsReply, reply);
  }
  return Undefined();
}

int GetTranslateCoordinatesReply(eio_req *req) {
  Reply<xcb_translate_coordinates_reply_t, xcb_translate_coordinates_cookie_t> *reply = static_cast<Reply<xcb_translate_coordinates_reply_t, xcb_translate_coordinates_cookie_t> *>(req->data);
  reply->reply = xcb_translate_coordinates_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleTranslateCoordinatesReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_translate_coordinates_reply_t, xcb_translate_coordinates_cookie_t> *reply = static_cast<Reply<xcb_translate_coordinates_reply_t, xcb_translate_coordinates_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("same_screen"), v8::Boolean::New(reply->reply->same_screen));
  obj->Set(v8::String::New("child"), v8::Integer::New(reply->reply->child));
  obj->Set(v8::String::New("dst_x"), v8::Integer::New(reply->reply->dst_x));
  obj->Set(v8::String::New("dst_y"), v8::Integer::New(reply->reply->dst_y));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> TranslateCoordinates(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: TranslateCoordinates(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t src_window = (xcb_window_t) obj->Get(v8::String::New("src_window"))->IntegerValue();
  xcb_window_t dst_window = (xcb_window_t) obj->Get(v8::String::New("dst_window"))->IntegerValue();
  int16_t src_x = (int16_t) obj->Get(v8::String::New("src_x"))->IntegerValue();
  int16_t src_y = (int16_t) obj->Get(v8::String::New("src_y"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_translate_coordinates_cookie_t cookie = xcb_translate_coordinates(connection, src_window, dst_window, src_x, src_y);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_translate_coordinates_reply_t, xcb_translate_coordinates_cookie_t> *reply = new Reply<xcb_translate_coordinates_reply_t, xcb_translate_coordinates_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetTranslateCoordinatesReply, EIO_PRI_DEFAULT, HandleTranslateCoordinatesReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> WarpPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: WarpPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t src_window = (xcb_window_t) obj->Get(v8::String::New("src_window"))->IntegerValue();
  xcb_window_t dst_window = (xcb_window_t) obj->Get(v8::String::New("dst_window"))->IntegerValue();
  int16_t src_x = (int16_t) obj->Get(v8::String::New("src_x"))->IntegerValue();
  int16_t src_y = (int16_t) obj->Get(v8::String::New("src_y"))->IntegerValue();
  uint16_t src_width = (uint16_t) obj->Get(v8::String::New("src_width"))->IntegerValue();
  uint16_t src_height = (uint16_t) obj->Get(v8::String::New("src_height"))->IntegerValue();
  int16_t dst_x = (int16_t) obj->Get(v8::String::New("dst_x"))->IntegerValue();
  int16_t dst_y = (int16_t) obj->Get(v8::String::New("dst_y"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_warp_pointer(connection, src_window, dst_window, src_x, src_y, src_width, src_height, dst_x, dst_y);
  return Undefined();
}

v8::Handle<v8::Value> SetInputFocus(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetInputFocus(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t revert_to = (uint8_t) obj->Get(v8::String::New("revert_to"))->IntegerValue();
  xcb_window_t focus = (xcb_window_t) obj->Get(v8::String::New("focus"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_input_focus(connection, revert_to, focus, time);
  return Undefined();
}

int GetGetInputFocusReply(eio_req *req) {
  Reply<xcb_get_input_focus_reply_t, xcb_get_input_focus_cookie_t> *reply = static_cast<Reply<xcb_get_input_focus_reply_t, xcb_get_input_focus_cookie_t> *>(req->data);
  reply->reply = xcb_get_input_focus_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetInputFocusReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_input_focus_reply_t, xcb_get_input_focus_cookie_t> *reply = static_cast<Reply<xcb_get_input_focus_reply_t, xcb_get_input_focus_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("revert_to"), v8::Integer::New(reply->reply->revert_to));
  obj->Set(v8::String::New("focus"), v8::Integer::New(reply->reply->focus));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetInputFocus(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetInputFocus(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_input_focus_cookie_t cookie = xcb_get_input_focus(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_input_focus_reply_t, xcb_get_input_focus_cookie_t> *reply = new Reply<xcb_get_input_focus_reply_t, xcb_get_input_focus_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetInputFocusReply, EIO_PRI_DEFAULT, HandleGetInputFocusReply, reply);
  }
  return Undefined();
}

int GetQueryKeymapReply(eio_req *req) {
  Reply<xcb_query_keymap_reply_t, xcb_query_keymap_cookie_t> *reply = static_cast<Reply<xcb_query_keymap_reply_t, xcb_query_keymap_cookie_t> *>(req->data);
  reply->reply = xcb_query_keymap_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryKeymapReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_keymap_reply_t, xcb_query_keymap_cookie_t> *reply = static_cast<Reply<xcb_query_keymap_reply_t, xcb_query_keymap_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryKeymap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryKeymap(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_keymap_cookie_t cookie = xcb_query_keymap(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_keymap_reply_t, xcb_query_keymap_cookie_t> *reply = new Reply<xcb_query_keymap_reply_t, xcb_query_keymap_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryKeymapReply, EIO_PRI_DEFAULT, HandleQueryKeymapReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> OpenFont(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: OpenFont(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_font_t fid = (xcb_font_t) obj->Get(v8::String::New("fid"))->IntegerValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_open_font(connection, fid, name_len, name);
  delete [] name;
  return Undefined();
}

v8::Handle<v8::Value> CloseFont(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CloseFont(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_font_t font = (xcb_font_t) obj->Get(v8::String::New("font"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_close_font(connection, font);
  return Undefined();
}

int GetQueryFontReply(eio_req *req) {
  Reply<xcb_query_font_reply_t, xcb_query_font_cookie_t> *reply = static_cast<Reply<xcb_query_font_reply_t, xcb_query_font_cookie_t> *>(req->data);
  reply->reply = xcb_query_font_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryFontReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_font_reply_t, xcb_query_font_cookie_t> *reply = static_cast<Reply<xcb_query_font_reply_t, xcb_query_font_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("min_char_or_byte2"), v8::Integer::New(reply->reply->min_char_or_byte2));
  obj->Set(v8::String::New("max_char_or_byte2"), v8::Integer::New(reply->reply->max_char_or_byte2));
  obj->Set(v8::String::New("default_char"), v8::Integer::New(reply->reply->default_char));
  obj->Set(v8::String::New("draw_direction"), v8::Integer::New(reply->reply->draw_direction));
  obj->Set(v8::String::New("min_byte1"), v8::Integer::New(reply->reply->min_byte1));
  obj->Set(v8::String::New("max_byte1"), v8::Integer::New(reply->reply->max_byte1));
  obj->Set(v8::String::New("all_chars_exist"), v8::Boolean::New(reply->reply->all_chars_exist));
  obj->Set(v8::String::New("font_ascent"), v8::Integer::New(reply->reply->font_ascent));
  obj->Set(v8::String::New("font_descent"), v8::Integer::New(reply->reply->font_descent));
  v8::Local<v8::Array> properties_list = v8::Array::New();
  obj->Set(v8::String::New("properties"), properties_list);
  int iproperties = 0;
  for(xcb_fontprop_iterator_t itr = xcb_query_font_properties_iterator(reply->reply); itr.rem; xcb_fontprop_next(&itr), ++iproperties) {
    properties_list->Set(iproperties, toJS(itr.data));
  }
  v8::Local<v8::Array> char_infos_list = v8::Array::New();
  obj->Set(v8::String::New("char_infos"), char_infos_list);
  int ichar_infos = 0;
  for(xcb_charinfo_iterator_t itr = xcb_query_font_char_infos_iterator(reply->reply); itr.rem; xcb_charinfo_next(&itr), ++ichar_infos) {
    char_infos_list->Set(ichar_infos, toJS(itr.data));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryFont(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryFont(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_fontable_t font = (xcb_fontable_t) obj->Get(v8::String::New("font"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_font_cookie_t cookie = xcb_query_font(connection, font);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_font_reply_t, xcb_query_font_cookie_t> *reply = new Reply<xcb_query_font_reply_t, xcb_query_font_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryFontReply, EIO_PRI_DEFAULT, HandleQueryFontReply, reply);
  }
  return Undefined();
}

int GetQueryTextExtentsReply(eio_req *req) {
  Reply<xcb_query_text_extents_reply_t, xcb_query_text_extents_cookie_t> *reply = static_cast<Reply<xcb_query_text_extents_reply_t, xcb_query_text_extents_cookie_t> *>(req->data);
  reply->reply = xcb_query_text_extents_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryTextExtentsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_text_extents_reply_t, xcb_query_text_extents_cookie_t> *reply = static_cast<Reply<xcb_query_text_extents_reply_t, xcb_query_text_extents_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("draw_direction"), v8::Integer::New(reply->reply->draw_direction));
  obj->Set(v8::String::New("font_ascent"), v8::Integer::New(reply->reply->font_ascent));
  obj->Set(v8::String::New("font_descent"), v8::Integer::New(reply->reply->font_descent));
  obj->Set(v8::String::New("overall_ascent"), v8::Integer::New(reply->reply->overall_ascent));
  obj->Set(v8::String::New("overall_descent"), v8::Integer::New(reply->reply->overall_descent));
  obj->Set(v8::String::New("overall_width"), v8::Integer::New(reply->reply->overall_width));
  obj->Set(v8::String::New("overall_left"), v8::Integer::New(reply->reply->overall_left));
  obj->Set(v8::String::New("overall_right"), v8::Integer::New(reply->reply->overall_right));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryTextExtents(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryTextExtents(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_fontable_t font = (xcb_fontable_t) obj->Get(v8::String::New("font"))->IntegerValue();
  uint32_t string_len = (uint32_t) obj->Get(v8::String::New("string_len"))->IntegerValue();
  xcb_char2b_t *string;
  v8::Local<v8::Array> string_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("string")));
  string = new xcb_char2b_t[string_list->Length()];
  for(unsigned int i = 0; i < string_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(string_list->Get(i)), string + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_text_extents_cookie_t cookie = xcb_query_text_extents(connection, font, string_len, string);
  delete [] string;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_text_extents_reply_t, xcb_query_text_extents_cookie_t> *reply = new Reply<xcb_query_text_extents_reply_t, xcb_query_text_extents_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryTextExtentsReply, EIO_PRI_DEFAULT, HandleQueryTextExtentsReply, reply);
  }
  return Undefined();
}

int GetListFontsReply(eio_req *req) {
  Reply<xcb_list_fonts_reply_t, xcb_list_fonts_cookie_t> *reply = static_cast<Reply<xcb_list_fonts_reply_t, xcb_list_fonts_cookie_t> *>(req->data);
  reply->reply = xcb_list_fonts_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleListFontsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_list_fonts_reply_t, xcb_list_fonts_cookie_t> *reply = static_cast<Reply<xcb_list_fonts_reply_t, xcb_list_fonts_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> names_list = v8::Array::New();
  obj->Set(v8::String::New("names"), names_list);
  int inames = 0;
  for(xcb_str_iterator_t itr = xcb_list_fonts_names_iterator(reply->reply); itr.rem; xcb_str_next(&itr), ++inames) {
    names_list->Set(inames, toJS(itr.data));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> ListFonts(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListFonts(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t max_names = (uint16_t) obj->Get(v8::String::New("max_names"))->IntegerValue();
  uint16_t pattern_len = (uint16_t) obj->Get(v8::String::New("pattern_len"))->IntegerValue();
  char *pattern;
  v8::Local<v8::String> pattern_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("pattern")));
  pattern = new char[pattern_str->Length()];
  strcpy(pattern, *v8::String::AsciiValue(pattern_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_list_fonts_cookie_t cookie = xcb_list_fonts(connection, max_names, pattern_len, pattern);
  delete [] pattern;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_list_fonts_reply_t, xcb_list_fonts_cookie_t> *reply = new Reply<xcb_list_fonts_reply_t, xcb_list_fonts_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetListFontsReply, EIO_PRI_DEFAULT, HandleListFontsReply, reply);
  }
  return Undefined();
}

int GetListFontsWithInfoReply(eio_req *req) {
  Reply<xcb_list_fonts_with_info_reply_t, xcb_list_fonts_with_info_cookie_t> *reply = static_cast<Reply<xcb_list_fonts_with_info_reply_t, xcb_list_fonts_with_info_cookie_t> *>(req->data);
  reply->reply = xcb_list_fonts_with_info_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleListFontsWithInfoReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_list_fonts_with_info_reply_t, xcb_list_fonts_with_info_cookie_t> *reply = static_cast<Reply<xcb_list_fonts_with_info_reply_t, xcb_list_fonts_with_info_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("min_char_or_byte2"), v8::Integer::New(reply->reply->min_char_or_byte2));
  obj->Set(v8::String::New("max_char_or_byte2"), v8::Integer::New(reply->reply->max_char_or_byte2));
  obj->Set(v8::String::New("default_char"), v8::Integer::New(reply->reply->default_char));
  obj->Set(v8::String::New("draw_direction"), v8::Integer::New(reply->reply->draw_direction));
  obj->Set(v8::String::New("min_byte1"), v8::Integer::New(reply->reply->min_byte1));
  obj->Set(v8::String::New("max_byte1"), v8::Integer::New(reply->reply->max_byte1));
  obj->Set(v8::String::New("all_chars_exist"), v8::Boolean::New(reply->reply->all_chars_exist));
  obj->Set(v8::String::New("font_ascent"), v8::Integer::New(reply->reply->font_ascent));
  obj->Set(v8::String::New("font_descent"), v8::Integer::New(reply->reply->font_descent));
  obj->Set(v8::String::New("replies_hint"), v8::Integer::New(reply->reply->replies_hint));
  v8::Local<v8::Array> properties_list = v8::Array::New();
  obj->Set(v8::String::New("properties"), properties_list);
  int iproperties = 0;
  for(xcb_fontprop_iterator_t itr = xcb_list_fonts_with_info_properties_iterator(reply->reply); itr.rem; xcb_fontprop_next(&itr), ++iproperties) {
    properties_list->Set(iproperties, toJS(itr.data));
  }
  obj->Set(v8::String::New("name"), v8::String::New((char*)xcb_list_fonts_with_info_name(reply->reply)));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> ListFontsWithInfo(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListFontsWithInfo(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t max_names = (uint16_t) obj->Get(v8::String::New("max_names"))->IntegerValue();
  uint16_t pattern_len = (uint16_t) obj->Get(v8::String::New("pattern_len"))->IntegerValue();
  char *pattern;
  v8::Local<v8::String> pattern_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("pattern")));
  pattern = new char[pattern_str->Length()];
  strcpy(pattern, *v8::String::AsciiValue(pattern_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_list_fonts_with_info_cookie_t cookie = xcb_list_fonts_with_info(connection, max_names, pattern_len, pattern);
  delete [] pattern;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_list_fonts_with_info_reply_t, xcb_list_fonts_with_info_cookie_t> *reply = new Reply<xcb_list_fonts_with_info_reply_t, xcb_list_fonts_with_info_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetListFontsWithInfoReply, EIO_PRI_DEFAULT, HandleListFontsWithInfoReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> SetFontPath(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetFontPath(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t font_qty = (uint16_t) obj->Get(v8::String::New("font_qty"))->IntegerValue();
  uint32_t path_len = (uint32_t) obj->Get(v8::String::New("path_len"))->IntegerValue();
  char *path;
  v8::Local<v8::String> path_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("path")));
  path = new char[path_str->Length()];
  strcpy(path, *v8::String::AsciiValue(path_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_font_path(connection, font_qty, path_len, path);
  delete [] path;
  return Undefined();
}

int GetGetFontPathReply(eio_req *req) {
  Reply<xcb_get_font_path_reply_t, xcb_get_font_path_cookie_t> *reply = static_cast<Reply<xcb_get_font_path_reply_t, xcb_get_font_path_cookie_t> *>(req->data);
  reply->reply = xcb_get_font_path_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetFontPathReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_font_path_reply_t, xcb_get_font_path_cookie_t> *reply = static_cast<Reply<xcb_get_font_path_reply_t, xcb_get_font_path_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> path_list = v8::Array::New();
  obj->Set(v8::String::New("path"), path_list);
  int ipath = 0;
  for(xcb_str_iterator_t itr = xcb_get_font_path_path_iterator(reply->reply); itr.rem; xcb_str_next(&itr), ++ipath) {
    path_list->Set(ipath, toJS(itr.data));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetFontPath(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetFontPath(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_font_path_cookie_t cookie = xcb_get_font_path(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_font_path_reply_t, xcb_get_font_path_cookie_t> *reply = new Reply<xcb_get_font_path_reply_t, xcb_get_font_path_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetFontPathReply, EIO_PRI_DEFAULT, HandleGetFontPathReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> CreatePixmap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreatePixmap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t depth = (uint8_t) obj->Get(v8::String::New("depth"))->IntegerValue();
  xcb_pixmap_t pid = (xcb_pixmap_t) obj->Get(v8::String::New("pid"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_create_pixmap(connection, depth, pid, drawable, width, height);
  return Undefined();
}

v8::Handle<v8::Value> FreePixmap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreePixmap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_pixmap_t pixmap = (xcb_pixmap_t) obj->Get(v8::String::New("pixmap"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_free_pixmap(connection, pixmap);
  return Undefined();
}

v8::Handle<v8::Value> CreateGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_gcontext_t cid = (xcb_gcontext_t) obj->Get(v8::String::New("cid"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  uint32_t *value_list;
  v8::Local<v8::Array> value_mask_valmask = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
  value_list = new uint32_t[value_mask_valmask->Length()];
  for(unsigned int i = 0; i < value_mask_valmask->Length(); ++i) {
    value_list[i] = (uint32_t) value_mask_valmask->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_create_gc(connection, cid, drawable, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> ChangeGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  uint32_t *value_list;
  v8::Local<v8::Array> value_mask_valmask = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
  value_list = new uint32_t[value_mask_valmask->Length()];
  for(unsigned int i = 0; i < value_mask_valmask->Length(); ++i) {
    value_list[i] = (uint32_t) value_mask_valmask->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_gc(connection, gc, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> CopyGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_gcontext_t src_gc = (xcb_gcontext_t) obj->Get(v8::String::New("src_gc"))->IntegerValue();
  xcb_gcontext_t dst_gc = (xcb_gcontext_t) obj->Get(v8::String::New("dst_gc"))->IntegerValue();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_copy_gc(connection, src_gc, dst_gc, value_mask);
  return Undefined();
}

v8::Handle<v8::Value> SetDashes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetDashes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint16_t dash_offset = (uint16_t) obj->Get(v8::String::New("dash_offset"))->IntegerValue();
  uint16_t dashes_len = (uint16_t) obj->Get(v8::String::New("dashes_len"))->IntegerValue();
  uint8_t *dashes;
  v8::Local<v8::Array> dashes_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("dashes")));
  dashes = new uint8_t[dashes_list->Length()];
  for(unsigned int i = 0; i < dashes_list->Length(); ++i) {
    dashes[i] = (uint8_t) dashes_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_dashes(connection, gc, dash_offset, dashes_len, dashes);
  delete [] dashes;
  return Undefined();
}

v8::Handle<v8::Value> SetClipRectangles(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetClipRectangles(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t ordering = (uint8_t) obj->Get(v8::String::New("ordering"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  int16_t clip_x_origin = (int16_t) obj->Get(v8::String::New("clip_x_origin"))->IntegerValue();
  int16_t clip_y_origin = (int16_t) obj->Get(v8::String::New("clip_y_origin"))->IntegerValue();
  uint32_t rectangles_len = (uint32_t) obj->Get(v8::String::New("rectangles_len"))->IntegerValue();
  xcb_rectangle_t *rectangles;
  v8::Local<v8::Array> rectangles_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("rectangles")));
  rectangles = new xcb_rectangle_t[rectangles_list->Length()];
  for(unsigned int i = 0; i < rectangles_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(rectangles_list->Get(i)), rectangles + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_clip_rectangles(connection, ordering, gc, clip_x_origin, clip_y_origin, rectangles_len, rectangles);
  delete [] rectangles;
  return Undefined();
}

v8::Handle<v8::Value> FreeGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_free_gc(connection, gc);
  return Undefined();
}

v8::Handle<v8::Value> ClearArea(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ClearArea(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t exposures = (uint8_t) obj->Get(v8::String::New("exposures"))->BooleanValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_clear_area(connection, exposures, window, x, y, width, height);
  return Undefined();
}

v8::Handle<v8::Value> CopyArea(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyArea(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t src_drawable = (xcb_drawable_t) obj->Get(v8::String::New("src_drawable"))->IntegerValue();
  xcb_drawable_t dst_drawable = (xcb_drawable_t) obj->Get(v8::String::New("dst_drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  int16_t src_x = (int16_t) obj->Get(v8::String::New("src_x"))->IntegerValue();
  int16_t src_y = (int16_t) obj->Get(v8::String::New("src_y"))->IntegerValue();
  int16_t dst_x = (int16_t) obj->Get(v8::String::New("dst_x"))->IntegerValue();
  int16_t dst_y = (int16_t) obj->Get(v8::String::New("dst_y"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_copy_area(connection, src_drawable, dst_drawable, gc, src_x, src_y, dst_x, dst_y, width, height);
  return Undefined();
}

v8::Handle<v8::Value> CopyPlane(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyPlane(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t src_drawable = (xcb_drawable_t) obj->Get(v8::String::New("src_drawable"))->IntegerValue();
  xcb_drawable_t dst_drawable = (xcb_drawable_t) obj->Get(v8::String::New("dst_drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  int16_t src_x = (int16_t) obj->Get(v8::String::New("src_x"))->IntegerValue();
  int16_t src_y = (int16_t) obj->Get(v8::String::New("src_y"))->IntegerValue();
  int16_t dst_x = (int16_t) obj->Get(v8::String::New("dst_x"))->IntegerValue();
  int16_t dst_y = (int16_t) obj->Get(v8::String::New("dst_y"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  uint32_t bit_plane = (uint32_t) obj->Get(v8::String::New("bit_plane"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_copy_plane(connection, src_drawable, dst_drawable, gc, src_x, src_y, dst_x, dst_y, width, height, bit_plane);
  return Undefined();
}

v8::Handle<v8::Value> PolyPoint(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyPoint(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t coordinate_mode = (uint8_t) obj->Get(v8::String::New("coordinate_mode"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t points_len = (uint32_t) obj->Get(v8::String::New("points_len"))->IntegerValue();
  xcb_point_t *points;
  v8::Local<v8::Array> points_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("points")));
  points = new xcb_point_t[points_list->Length()];
  for(unsigned int i = 0; i < points_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(points_list->Get(i)), points + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_point(connection, coordinate_mode, drawable, gc, points_len, points);
  delete [] points;
  return Undefined();
}

v8::Handle<v8::Value> PolyLine(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyLine(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t coordinate_mode = (uint8_t) obj->Get(v8::String::New("coordinate_mode"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t points_len = (uint32_t) obj->Get(v8::String::New("points_len"))->IntegerValue();
  xcb_point_t *points;
  v8::Local<v8::Array> points_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("points")));
  points = new xcb_point_t[points_list->Length()];
  for(unsigned int i = 0; i < points_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(points_list->Get(i)), points + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_line(connection, coordinate_mode, drawable, gc, points_len, points);
  delete [] points;
  return Undefined();
}

v8::Handle<v8::Value> PolySegment(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolySegment(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t segments_len = (uint32_t) obj->Get(v8::String::New("segments_len"))->IntegerValue();
  xcb_segment_t *segments;
  v8::Local<v8::Array> segments_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("segments")));
  segments = new xcb_segment_t[segments_list->Length()];
  for(unsigned int i = 0; i < segments_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(segments_list->Get(i)), segments + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_segment(connection, drawable, gc, segments_len, segments);
  delete [] segments;
  return Undefined();
}

v8::Handle<v8::Value> PolyRectangle(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyRectangle(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t rectangles_len = (uint32_t) obj->Get(v8::String::New("rectangles_len"))->IntegerValue();
  xcb_rectangle_t *rectangles;
  v8::Local<v8::Array> rectangles_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("rectangles")));
  rectangles = new xcb_rectangle_t[rectangles_list->Length()];
  for(unsigned int i = 0; i < rectangles_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(rectangles_list->Get(i)), rectangles + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_rectangle(connection, drawable, gc, rectangles_len, rectangles);
  delete [] rectangles;
  return Undefined();
}

v8::Handle<v8::Value> PolyArc(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyArc(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t arcs_len = (uint32_t) obj->Get(v8::String::New("arcs_len"))->IntegerValue();
  xcb_arc_t *arcs;
  v8::Local<v8::Array> arcs_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("arcs")));
  arcs = new xcb_arc_t[arcs_list->Length()];
  for(unsigned int i = 0; i < arcs_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(arcs_list->Get(i)), arcs + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_arc(connection, drawable, gc, arcs_len, arcs);
  delete [] arcs;
  return Undefined();
}

v8::Handle<v8::Value> FillPoly(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FillPoly(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint8_t shape = (uint8_t) obj->Get(v8::String::New("shape"))->IntegerValue();
  uint8_t coordinate_mode = (uint8_t) obj->Get(v8::String::New("coordinate_mode"))->IntegerValue();
  uint32_t points_len = (uint32_t) obj->Get(v8::String::New("points_len"))->IntegerValue();
  xcb_point_t *points;
  v8::Local<v8::Array> points_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("points")));
  points = new xcb_point_t[points_list->Length()];
  for(unsigned int i = 0; i < points_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(points_list->Get(i)), points + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_fill_poly(connection, drawable, gc, shape, coordinate_mode, points_len, points);
  delete [] points;
  return Undefined();
}

v8::Handle<v8::Value> PolyFillRectangle(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyFillRectangle(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t rectangles_len = (uint32_t) obj->Get(v8::String::New("rectangles_len"))->IntegerValue();
  xcb_rectangle_t *rectangles;
  v8::Local<v8::Array> rectangles_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("rectangles")));
  rectangles = new xcb_rectangle_t[rectangles_list->Length()];
  for(unsigned int i = 0; i < rectangles_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(rectangles_list->Get(i)), rectangles + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_fill_rectangle(connection, drawable, gc, rectangles_len, rectangles);
  delete [] rectangles;
  return Undefined();
}

v8::Handle<v8::Value> PolyFillArc(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyFillArc(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint32_t arcs_len = (uint32_t) obj->Get(v8::String::New("arcs_len"))->IntegerValue();
  xcb_arc_t *arcs;
  v8::Local<v8::Array> arcs_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("arcs")));
  arcs = new xcb_arc_t[arcs_list->Length()];
  for(unsigned int i = 0; i < arcs_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(arcs_list->Get(i)), arcs + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_fill_arc(connection, drawable, gc, arcs_len, arcs);
  delete [] arcs;
  return Undefined();
}

v8::Handle<v8::Value> PutImage(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PutImage(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t format = (uint8_t) obj->Get(v8::String::New("format"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  int16_t dst_x = (int16_t) obj->Get(v8::String::New("dst_x"))->IntegerValue();
  int16_t dst_y = (int16_t) obj->Get(v8::String::New("dst_y"))->IntegerValue();
  uint8_t left_pad = (uint8_t) obj->Get(v8::String::New("left_pad"))->IntegerValue();
  uint8_t depth = (uint8_t) obj->Get(v8::String::New("depth"))->IntegerValue();
  uint32_t data_len = (uint32_t) obj->Get(v8::String::New("data_len"))->IntegerValue();
  uint8_t *data;
  v8::Local<v8::Array> data_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("data")));
  data = new uint8_t[data_list->Length()];
  for(unsigned int i = 0; i < data_list->Length(); ++i) {
    data[i] = (uint8_t) data_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_put_image(connection, format, drawable, gc, width, height, dst_x, dst_y, left_pad, depth, data_len, data);
  delete [] data;
  return Undefined();
}

int GetGetImageReply(eio_req *req) {
  Reply<xcb_get_image_reply_t, xcb_get_image_cookie_t> *reply = static_cast<Reply<xcb_get_image_reply_t, xcb_get_image_cookie_t> *>(req->data);
  reply->reply = xcb_get_image_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetImageReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_image_reply_t, xcb_get_image_cookie_t> *reply = static_cast<Reply<xcb_get_image_reply_t, xcb_get_image_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("depth"), v8::Integer::New(reply->reply->depth));
  obj->Set(v8::String::New("visual"), v8::Integer::New(reply->reply->visual));
  v8::Local<v8::Array> data_list = v8::Array::New();
  obj->Set(v8::String::New("data"), data_list);
  uint8_t *data_list_ptr = xcb_get_image_data(reply->reply);
  for(int i = 0; i < xcb_get_image_data_length(reply->reply); ++i) {
    data_list->Set(i, v8::Integer::New(data_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetImage(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetImage(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t format = (uint8_t) obj->Get(v8::String::New("format"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  uint32_t plane_mask = (uint32_t) obj->Get(v8::String::New("plane_mask"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_image_cookie_t cookie = xcb_get_image(connection, format, drawable, x, y, width, height, plane_mask);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_image_reply_t, xcb_get_image_cookie_t> *reply = new Reply<xcb_get_image_reply_t, xcb_get_image_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetImageReply, EIO_PRI_DEFAULT, HandleGetImageReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> PolyText8(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyText8(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  uint32_t items_len = (uint32_t) obj->Get(v8::String::New("items_len"))->IntegerValue();
  uint8_t *items;
  v8::Local<v8::Array> items_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("items")));
  items = new uint8_t[items_list->Length()];
  for(unsigned int i = 0; i < items_list->Length(); ++i) {
    items[i] = (uint8_t) items_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_text_8(connection, drawable, gc, x, y, items_len, items);
  delete [] items;
  return Undefined();
}

v8::Handle<v8::Value> PolyText16(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyText16(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  uint32_t items_len = (uint32_t) obj->Get(v8::String::New("items_len"))->IntegerValue();
  uint8_t *items;
  v8::Local<v8::Array> items_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("items")));
  items = new uint8_t[items_list->Length()];
  for(unsigned int i = 0; i < items_list->Length(); ++i) {
    items[i] = (uint8_t) items_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_poly_text_16(connection, drawable, gc, x, y, items_len, items);
  delete [] items;
  return Undefined();
}

v8::Handle<v8::Value> ImageText8(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ImageText8(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t string_len = (uint8_t) obj->Get(v8::String::New("string_len"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  char *string;
  v8::Local<v8::String> string_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("string")));
  string = new char[string_str->Length()];
  strcpy(string, *v8::String::AsciiValue(string_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_image_text_8(connection, string_len, drawable, gc, x, y, string);
  delete [] string;
  return Undefined();
}

v8::Handle<v8::Value> ImageText16(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ImageText16(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t string_len = (uint8_t) obj->Get(v8::String::New("string_len"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  xcb_char2b_t *string;
  v8::Local<v8::Array> string_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("string")));
  string = new xcb_char2b_t[string_list->Length()];
  for(unsigned int i = 0; i < string_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(string_list->Get(i)), string + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_image_text_16(connection, string_len, drawable, gc, x, y, string);
  delete [] string;
  return Undefined();
}

v8::Handle<v8::Value> CreateColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t alloc = (uint8_t) obj->Get(v8::String::New("alloc"))->IntegerValue();
  xcb_colormap_t mid = (xcb_colormap_t) obj->Get(v8::String::New("mid"))->IntegerValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_visualid_t visual = (xcb_visualid_t) obj->Get(v8::String::New("visual"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_create_colormap(connection, alloc, mid, window, visual);
  return Undefined();
}

v8::Handle<v8::Value> FreeColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_free_colormap(connection, cmap);
  return Undefined();
}

v8::Handle<v8::Value> CopyColormapAndFree(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyColormapAndFree(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t mid = (xcb_colormap_t) obj->Get(v8::String::New("mid"))->IntegerValue();
  xcb_colormap_t src_cmap = (xcb_colormap_t) obj->Get(v8::String::New("src_cmap"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_copy_colormap_and_free(connection, mid, src_cmap);
  return Undefined();
}

v8::Handle<v8::Value> InstallColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: InstallColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_install_colormap(connection, cmap);
  return Undefined();
}

v8::Handle<v8::Value> UninstallColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UninstallColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_uninstall_colormap(connection, cmap);
  return Undefined();
}

int GetListInstalledColormapsReply(eio_req *req) {
  Reply<xcb_list_installed_colormaps_reply_t, xcb_list_installed_colormaps_cookie_t> *reply = static_cast<Reply<xcb_list_installed_colormaps_reply_t, xcb_list_installed_colormaps_cookie_t> *>(req->data);
  reply->reply = xcb_list_installed_colormaps_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleListInstalledColormapsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_list_installed_colormaps_reply_t, xcb_list_installed_colormaps_cookie_t> *reply = static_cast<Reply<xcb_list_installed_colormaps_reply_t, xcb_list_installed_colormaps_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> cmaps_list = v8::Array::New();
  obj->Set(v8::String::New("cmaps"), cmaps_list);
  xcb_colormap_t *cmaps_list_ptr = xcb_list_installed_colormaps_cmaps(reply->reply);
  for(int i = 0; i < xcb_list_installed_colormaps_cmaps_length(reply->reply); ++i) {
    cmaps_list->Set(i, v8::Integer::New(cmaps_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> ListInstalledColormaps(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListInstalledColormaps(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_list_installed_colormaps_cookie_t cookie = xcb_list_installed_colormaps(connection, window);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_list_installed_colormaps_reply_t, xcb_list_installed_colormaps_cookie_t> *reply = new Reply<xcb_list_installed_colormaps_reply_t, xcb_list_installed_colormaps_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetListInstalledColormapsReply, EIO_PRI_DEFAULT, HandleListInstalledColormapsReply, reply);
  }
  return Undefined();
}

int GetAllocColorReply(eio_req *req) {
  Reply<xcb_alloc_color_reply_t, xcb_alloc_color_cookie_t> *reply = static_cast<Reply<xcb_alloc_color_reply_t, xcb_alloc_color_cookie_t> *>(req->data);
  reply->reply = xcb_alloc_color_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleAllocColorReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_alloc_color_reply_t, xcb_alloc_color_cookie_t> *reply = static_cast<Reply<xcb_alloc_color_reply_t, xcb_alloc_color_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("red"), v8::Integer::New(reply->reply->red));
  obj->Set(v8::String::New("green"), v8::Integer::New(reply->reply->green));
  obj->Set(v8::String::New("blue"), v8::Integer::New(reply->reply->blue));
  obj->Set(v8::String::New("pixel"), v8::Integer::New(reply->reply->pixel));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> AllocColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t red = (uint16_t) obj->Get(v8::String::New("red"))->IntegerValue();
  uint16_t green = (uint16_t) obj->Get(v8::String::New("green"))->IntegerValue();
  uint16_t blue = (uint16_t) obj->Get(v8::String::New("blue"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_alloc_color_cookie_t cookie = xcb_alloc_color(connection, cmap, red, green, blue);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_alloc_color_reply_t, xcb_alloc_color_cookie_t> *reply = new Reply<xcb_alloc_color_reply_t, xcb_alloc_color_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetAllocColorReply, EIO_PRI_DEFAULT, HandleAllocColorReply, reply);
  }
  return Undefined();
}

int GetAllocNamedColorReply(eio_req *req) {
  Reply<xcb_alloc_named_color_reply_t, xcb_alloc_named_color_cookie_t> *reply = static_cast<Reply<xcb_alloc_named_color_reply_t, xcb_alloc_named_color_cookie_t> *>(req->data);
  reply->reply = xcb_alloc_named_color_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleAllocNamedColorReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_alloc_named_color_reply_t, xcb_alloc_named_color_cookie_t> *reply = static_cast<Reply<xcb_alloc_named_color_reply_t, xcb_alloc_named_color_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("pixel"), v8::Integer::New(reply->reply->pixel));
  obj->Set(v8::String::New("exact_red"), v8::Integer::New(reply->reply->exact_red));
  obj->Set(v8::String::New("exact_green"), v8::Integer::New(reply->reply->exact_green));
  obj->Set(v8::String::New("exact_blue"), v8::Integer::New(reply->reply->exact_blue));
  obj->Set(v8::String::New("visual_red"), v8::Integer::New(reply->reply->visual_red));
  obj->Set(v8::String::New("visual_green"), v8::Integer::New(reply->reply->visual_green));
  obj->Set(v8::String::New("visual_blue"), v8::Integer::New(reply->reply->visual_blue));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> AllocNamedColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocNamedColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_alloc_named_color_cookie_t cookie = xcb_alloc_named_color(connection, cmap, name_len, name);
  delete [] name;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_alloc_named_color_reply_t, xcb_alloc_named_color_cookie_t> *reply = new Reply<xcb_alloc_named_color_reply_t, xcb_alloc_named_color_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetAllocNamedColorReply, EIO_PRI_DEFAULT, HandleAllocNamedColorReply, reply);
  }
  return Undefined();
}

int GetAllocColorCellsReply(eio_req *req) {
  Reply<xcb_alloc_color_cells_reply_t, xcb_alloc_color_cells_cookie_t> *reply = static_cast<Reply<xcb_alloc_color_cells_reply_t, xcb_alloc_color_cells_cookie_t> *>(req->data);
  reply->reply = xcb_alloc_color_cells_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleAllocColorCellsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_alloc_color_cells_reply_t, xcb_alloc_color_cells_cookie_t> *reply = static_cast<Reply<xcb_alloc_color_cells_reply_t, xcb_alloc_color_cells_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> pixels_list = v8::Array::New();
  obj->Set(v8::String::New("pixels"), pixels_list);
  uint32_t *pixels_list_ptr = xcb_alloc_color_cells_pixels(reply->reply);
  for(int i = 0; i < xcb_alloc_color_cells_pixels_length(reply->reply); ++i) {
    pixels_list->Set(i, v8::Integer::New(pixels_list_ptr[i]));
  }
  v8::Local<v8::Array> masks_list = v8::Array::New();
  obj->Set(v8::String::New("masks"), masks_list);
  uint32_t *masks_list_ptr = xcb_alloc_color_cells_masks(reply->reply);
  for(int i = 0; i < xcb_alloc_color_cells_masks_length(reply->reply); ++i) {
    masks_list->Set(i, v8::Integer::New(masks_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> AllocColorCells(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocColorCells(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t contiguous = (uint8_t) obj->Get(v8::String::New("contiguous"))->BooleanValue();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t colors = (uint16_t) obj->Get(v8::String::New("colors"))->IntegerValue();
  uint16_t planes = (uint16_t) obj->Get(v8::String::New("planes"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_alloc_color_cells_cookie_t cookie = xcb_alloc_color_cells(connection, contiguous, cmap, colors, planes);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_alloc_color_cells_reply_t, xcb_alloc_color_cells_cookie_t> *reply = new Reply<xcb_alloc_color_cells_reply_t, xcb_alloc_color_cells_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetAllocColorCellsReply, EIO_PRI_DEFAULT, HandleAllocColorCellsReply, reply);
  }
  return Undefined();
}

int GetAllocColorPlanesReply(eio_req *req) {
  Reply<xcb_alloc_color_planes_reply_t, xcb_alloc_color_planes_cookie_t> *reply = static_cast<Reply<xcb_alloc_color_planes_reply_t, xcb_alloc_color_planes_cookie_t> *>(req->data);
  reply->reply = xcb_alloc_color_planes_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleAllocColorPlanesReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_alloc_color_planes_reply_t, xcb_alloc_color_planes_cookie_t> *reply = static_cast<Reply<xcb_alloc_color_planes_reply_t, xcb_alloc_color_planes_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("red_mask"), v8::Integer::New(reply->reply->red_mask));
  obj->Set(v8::String::New("green_mask"), v8::Integer::New(reply->reply->green_mask));
  obj->Set(v8::String::New("blue_mask"), v8::Integer::New(reply->reply->blue_mask));
  v8::Local<v8::Array> pixels_list = v8::Array::New();
  obj->Set(v8::String::New("pixels"), pixels_list);
  uint32_t *pixels_list_ptr = xcb_alloc_color_planes_pixels(reply->reply);
  for(int i = 0; i < xcb_alloc_color_planes_pixels_length(reply->reply); ++i) {
    pixels_list->Set(i, v8::Integer::New(pixels_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> AllocColorPlanes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocColorPlanes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t contiguous = (uint8_t) obj->Get(v8::String::New("contiguous"))->BooleanValue();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t colors = (uint16_t) obj->Get(v8::String::New("colors"))->IntegerValue();
  uint16_t reds = (uint16_t) obj->Get(v8::String::New("reds"))->IntegerValue();
  uint16_t greens = (uint16_t) obj->Get(v8::String::New("greens"))->IntegerValue();
  uint16_t blues = (uint16_t) obj->Get(v8::String::New("blues"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_alloc_color_planes_cookie_t cookie = xcb_alloc_color_planes(connection, contiguous, cmap, colors, reds, greens, blues);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_alloc_color_planes_reply_t, xcb_alloc_color_planes_cookie_t> *reply = new Reply<xcb_alloc_color_planes_reply_t, xcb_alloc_color_planes_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetAllocColorPlanesReply, EIO_PRI_DEFAULT, HandleAllocColorPlanesReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> FreeColors(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeColors(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint32_t plane_mask = (uint32_t) obj->Get(v8::String::New("plane_mask"))->IntegerValue();
  uint32_t pixels_len = (uint32_t) obj->Get(v8::String::New("pixels_len"))->IntegerValue();
  uint32_t *pixels;
  v8::Local<v8::Array> pixels_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("pixels")));
  pixels = new uint32_t[pixels_list->Length()];
  for(unsigned int i = 0; i < pixels_list->Length(); ++i) {
    pixels[i] = (uint32_t) pixels_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_free_colors(connection, cmap, plane_mask, pixels_len, pixels);
  delete [] pixels;
  return Undefined();
}

v8::Handle<v8::Value> StoreColors(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: StoreColors(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint32_t items_len = (uint32_t) obj->Get(v8::String::New("items_len"))->IntegerValue();
  xcb_coloritem_t *items;
  v8::Local<v8::Array> items_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("items")));
  items = new xcb_coloritem_t[items_list->Length()];
  for(unsigned int i = 0; i < items_list->Length(); ++i) {
    fromJS(v8::Local<v8::Object>::Cast(items_list->Get(i)), items + i);
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_store_colors(connection, cmap, items_len, items);
  delete [] items;
  return Undefined();
}

v8::Handle<v8::Value> StoreNamedColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: StoreNamedColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t flags = (uint8_t) obj->Get(v8::String::New("flags"))->IntegerValue();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint32_t pixel = (uint32_t) obj->Get(v8::String::New("pixel"))->IntegerValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_store_named_color(connection, flags, cmap, pixel, name_len, name);
  delete [] name;
  return Undefined();
}

int GetQueryColorsReply(eio_req *req) {
  Reply<xcb_query_colors_reply_t, xcb_query_colors_cookie_t> *reply = static_cast<Reply<xcb_query_colors_reply_t, xcb_query_colors_cookie_t> *>(req->data);
  reply->reply = xcb_query_colors_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryColorsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_colors_reply_t, xcb_query_colors_cookie_t> *reply = static_cast<Reply<xcb_query_colors_reply_t, xcb_query_colors_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> colors_list = v8::Array::New();
  obj->Set(v8::String::New("colors"), colors_list);
  int icolors = 0;
  for(xcb_rgb_iterator_t itr = xcb_query_colors_colors_iterator(reply->reply); itr.rem; xcb_rgb_next(&itr), ++icolors) {
    colors_list->Set(icolors, toJS(itr.data));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryColors(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryColors(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint32_t pixels_len = (uint32_t) obj->Get(v8::String::New("pixels_len"))->IntegerValue();
  uint32_t *pixels;
  v8::Local<v8::Array> pixels_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("pixels")));
  pixels = new uint32_t[pixels_list->Length()];
  for(unsigned int i = 0; i < pixels_list->Length(); ++i) {
    pixels[i] = (uint32_t) pixels_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_colors_cookie_t cookie = xcb_query_colors(connection, cmap, pixels_len, pixels);
  delete [] pixels;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_colors_reply_t, xcb_query_colors_cookie_t> *reply = new Reply<xcb_query_colors_reply_t, xcb_query_colors_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryColorsReply, EIO_PRI_DEFAULT, HandleQueryColorsReply, reply);
  }
  return Undefined();
}

int GetLookupColorReply(eio_req *req) {
  Reply<xcb_lookup_color_reply_t, xcb_lookup_color_cookie_t> *reply = static_cast<Reply<xcb_lookup_color_reply_t, xcb_lookup_color_cookie_t> *>(req->data);
  reply->reply = xcb_lookup_color_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleLookupColorReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_lookup_color_reply_t, xcb_lookup_color_cookie_t> *reply = static_cast<Reply<xcb_lookup_color_reply_t, xcb_lookup_color_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("exact_red"), v8::Integer::New(reply->reply->exact_red));
  obj->Set(v8::String::New("exact_green"), v8::Integer::New(reply->reply->exact_green));
  obj->Set(v8::String::New("exact_blue"), v8::Integer::New(reply->reply->exact_blue));
  obj->Set(v8::String::New("visual_red"), v8::Integer::New(reply->reply->visual_red));
  obj->Set(v8::String::New("visual_green"), v8::Integer::New(reply->reply->visual_green));
  obj->Set(v8::String::New("visual_blue"), v8::Integer::New(reply->reply->visual_blue));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> LookupColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: LookupColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_lookup_color_cookie_t cookie = xcb_lookup_color(connection, cmap, name_len, name);
  delete [] name;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_lookup_color_reply_t, xcb_lookup_color_cookie_t> *reply = new Reply<xcb_lookup_color_reply_t, xcb_lookup_color_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetLookupColorReply, EIO_PRI_DEFAULT, HandleLookupColorReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> CreateCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cid = (xcb_cursor_t) obj->Get(v8::String::New("cid"))->IntegerValue();
  xcb_pixmap_t source = (xcb_pixmap_t) obj->Get(v8::String::New("source"))->IntegerValue();
  xcb_pixmap_t mask = (xcb_pixmap_t) obj->Get(v8::String::New("mask"))->IntegerValue();
  uint16_t fore_red = (uint16_t) obj->Get(v8::String::New("fore_red"))->IntegerValue();
  uint16_t fore_green = (uint16_t) obj->Get(v8::String::New("fore_green"))->IntegerValue();
  uint16_t fore_blue = (uint16_t) obj->Get(v8::String::New("fore_blue"))->IntegerValue();
  uint16_t back_red = (uint16_t) obj->Get(v8::String::New("back_red"))->IntegerValue();
  uint16_t back_green = (uint16_t) obj->Get(v8::String::New("back_green"))->IntegerValue();
  uint16_t back_blue = (uint16_t) obj->Get(v8::String::New("back_blue"))->IntegerValue();
  uint16_t x = (uint16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  uint16_t y = (uint16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_create_cursor(connection, cid, source, mask, fore_red, fore_green, fore_blue, back_red, back_green, back_blue, x, y);
  return Undefined();
}

v8::Handle<v8::Value> CreateGlyphCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateGlyphCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cid = (xcb_cursor_t) obj->Get(v8::String::New("cid"))->IntegerValue();
  xcb_font_t source_font = (xcb_font_t) obj->Get(v8::String::New("source_font"))->IntegerValue();
  xcb_font_t mask_font = (xcb_font_t) obj->Get(v8::String::New("mask_font"))->IntegerValue();
  uint16_t source_char = (uint16_t) obj->Get(v8::String::New("source_char"))->IntegerValue();
  uint16_t mask_char = (uint16_t) obj->Get(v8::String::New("mask_char"))->IntegerValue();
  uint16_t fore_red = (uint16_t) obj->Get(v8::String::New("fore_red"))->IntegerValue();
  uint16_t fore_green = (uint16_t) obj->Get(v8::String::New("fore_green"))->IntegerValue();
  uint16_t fore_blue = (uint16_t) obj->Get(v8::String::New("fore_blue"))->IntegerValue();
  uint16_t back_red = (uint16_t) obj->Get(v8::String::New("back_red"))->IntegerValue();
  uint16_t back_green = (uint16_t) obj->Get(v8::String::New("back_green"))->IntegerValue();
  uint16_t back_blue = (uint16_t) obj->Get(v8::String::New("back_blue"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_create_glyph_cursor(connection, cid, source_font, mask_font, source_char, mask_char, fore_red, fore_green, fore_blue, back_red, back_green, back_blue);
  return Undefined();
}

v8::Handle<v8::Value> FreeCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_free_cursor(connection, cursor);
  return Undefined();
}

v8::Handle<v8::Value> RecolorCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: RecolorCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  uint16_t fore_red = (uint16_t) obj->Get(v8::String::New("fore_red"))->IntegerValue();
  uint16_t fore_green = (uint16_t) obj->Get(v8::String::New("fore_green"))->IntegerValue();
  uint16_t fore_blue = (uint16_t) obj->Get(v8::String::New("fore_blue"))->IntegerValue();
  uint16_t back_red = (uint16_t) obj->Get(v8::String::New("back_red"))->IntegerValue();
  uint16_t back_green = (uint16_t) obj->Get(v8::String::New("back_green"))->IntegerValue();
  uint16_t back_blue = (uint16_t) obj->Get(v8::String::New("back_blue"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_recolor_cursor(connection, cursor, fore_red, fore_green, fore_blue, back_red, back_green, back_blue);
  return Undefined();
}

int GetQueryBestSizeReply(eio_req *req) {
  Reply<xcb_query_best_size_reply_t, xcb_query_best_size_cookie_t> *reply = static_cast<Reply<xcb_query_best_size_reply_t, xcb_query_best_size_cookie_t> *>(req->data);
  reply->reply = xcb_query_best_size_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryBestSizeReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_best_size_reply_t, xcb_query_best_size_cookie_t> *reply = static_cast<Reply<xcb_query_best_size_reply_t, xcb_query_best_size_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("width"), v8::Integer::New(reply->reply->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(reply->reply->height));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryBestSize(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryBestSize(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t _class = (uint8_t) obj->Get(v8::String::New("class"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_best_size_cookie_t cookie = xcb_query_best_size(connection, _class, drawable, width, height);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_best_size_reply_t, xcb_query_best_size_cookie_t> *reply = new Reply<xcb_query_best_size_reply_t, xcb_query_best_size_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryBestSizeReply, EIO_PRI_DEFAULT, HandleQueryBestSizeReply, reply);
  }
  return Undefined();
}

int GetQueryExtensionReply(eio_req *req) {
  Reply<xcb_query_extension_reply_t, xcb_query_extension_cookie_t> *reply = static_cast<Reply<xcb_query_extension_reply_t, xcb_query_extension_cookie_t> *>(req->data);
  reply->reply = xcb_query_extension_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleQueryExtensionReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_query_extension_reply_t, xcb_query_extension_cookie_t> *reply = static_cast<Reply<xcb_query_extension_reply_t, xcb_query_extension_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("present"), v8::Boolean::New(reply->reply->present));
  obj->Set(v8::String::New("major_opcode"), v8::Integer::New(reply->reply->major_opcode));
  obj->Set(v8::String::New("first_event"), v8::Integer::New(reply->reply->first_event));
  obj->Set(v8::String::New("first_error"), v8::Integer::New(reply->reply->first_error));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> QueryExtension(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryExtension(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_query_extension_cookie_t cookie = xcb_query_extension(connection, name_len, name);
  delete [] name;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_query_extension_reply_t, xcb_query_extension_cookie_t> *reply = new Reply<xcb_query_extension_reply_t, xcb_query_extension_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetQueryExtensionReply, EIO_PRI_DEFAULT, HandleQueryExtensionReply, reply);
  }
  return Undefined();
}

int GetListExtensionsReply(eio_req *req) {
  Reply<xcb_list_extensions_reply_t, xcb_list_extensions_cookie_t> *reply = static_cast<Reply<xcb_list_extensions_reply_t, xcb_list_extensions_cookie_t> *>(req->data);
  reply->reply = xcb_list_extensions_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleListExtensionsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_list_extensions_reply_t, xcb_list_extensions_cookie_t> *reply = static_cast<Reply<xcb_list_extensions_reply_t, xcb_list_extensions_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> names_list = v8::Array::New();
  obj->Set(v8::String::New("names"), names_list);
  int inames = 0;
  for(xcb_str_iterator_t itr = xcb_list_extensions_names_iterator(reply->reply); itr.rem; xcb_str_next(&itr), ++inames) {
    names_list->Set(inames, toJS(itr.data));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> ListExtensions(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListExtensions(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_list_extensions_cookie_t cookie = xcb_list_extensions(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_list_extensions_reply_t, xcb_list_extensions_cookie_t> *reply = new Reply<xcb_list_extensions_reply_t, xcb_list_extensions_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetListExtensionsReply, EIO_PRI_DEFAULT, HandleListExtensionsReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> ChangeKeyboardMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeKeyboardMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t keycode_count = (uint8_t) obj->Get(v8::String::New("keycode_count"))->IntegerValue();
  xcb_keycode_t first_keycode = (xcb_keycode_t) obj->Get(v8::String::New("first_keycode"))->IntegerValue();
  uint8_t keysyms_per_keycode = (uint8_t) obj->Get(v8::String::New("keysyms_per_keycode"))->IntegerValue();
  xcb_keysym_t *keysyms;
  v8::Local<v8::Array> keysyms_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("keysyms")));
  keysyms = new xcb_keysym_t[keysyms_list->Length()];
  for(unsigned int i = 0; i < keysyms_list->Length(); ++i) {
    keysyms[i] = (xcb_keysym_t) keysyms_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_keyboard_mapping(connection, keycode_count, first_keycode, keysyms_per_keycode, keysyms);
  delete [] keysyms;
  return Undefined();
}

int GetGetKeyboardMappingReply(eio_req *req) {
  Reply<xcb_get_keyboard_mapping_reply_t, xcb_get_keyboard_mapping_cookie_t> *reply = static_cast<Reply<xcb_get_keyboard_mapping_reply_t, xcb_get_keyboard_mapping_cookie_t> *>(req->data);
  reply->reply = xcb_get_keyboard_mapping_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetKeyboardMappingReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_keyboard_mapping_reply_t, xcb_get_keyboard_mapping_cookie_t> *reply = static_cast<Reply<xcb_get_keyboard_mapping_reply_t, xcb_get_keyboard_mapping_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("keysyms_per_keycode"), v8::Integer::New(reply->reply->keysyms_per_keycode));
  v8::Local<v8::Array> keysyms_list = v8::Array::New();
  obj->Set(v8::String::New("keysyms"), keysyms_list);
  xcb_keysym_t *keysyms_list_ptr = xcb_get_keyboard_mapping_keysyms(reply->reply);
  for(int i = 0; i < xcb_get_keyboard_mapping_keysyms_length(reply->reply); ++i) {
    keysyms_list->Set(i, v8::Integer::New(keysyms_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetKeyboardMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetKeyboardMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_keycode_t first_keycode = (xcb_keycode_t) obj->Get(v8::String::New("first_keycode"))->IntegerValue();
  uint8_t count = (uint8_t) obj->Get(v8::String::New("count"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_keyboard_mapping_cookie_t cookie = xcb_get_keyboard_mapping(connection, first_keycode, count);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_keyboard_mapping_reply_t, xcb_get_keyboard_mapping_cookie_t> *reply = new Reply<xcb_get_keyboard_mapping_reply_t, xcb_get_keyboard_mapping_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetKeyboardMappingReply, EIO_PRI_DEFAULT, HandleGetKeyboardMappingReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> ChangeKeyboardControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeKeyboardControl(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  uint32_t *value_list;
  v8::Local<v8::Array> value_mask_valmask = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
  value_list = new uint32_t[value_mask_valmask->Length()];
  for(unsigned int i = 0; i < value_mask_valmask->Length(); ++i) {
    value_list[i] = (uint32_t) value_mask_valmask->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_keyboard_control(connection, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

int GetGetKeyboardControlReply(eio_req *req) {
  Reply<xcb_get_keyboard_control_reply_t, xcb_get_keyboard_control_cookie_t> *reply = static_cast<Reply<xcb_get_keyboard_control_reply_t, xcb_get_keyboard_control_cookie_t> *>(req->data);
  reply->reply = xcb_get_keyboard_control_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetKeyboardControlReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_keyboard_control_reply_t, xcb_get_keyboard_control_cookie_t> *reply = static_cast<Reply<xcb_get_keyboard_control_reply_t, xcb_get_keyboard_control_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("global_auto_repeat"), v8::Integer::New(reply->reply->global_auto_repeat));
  obj->Set(v8::String::New("led_mask"), v8::Integer::New(reply->reply->led_mask));
  obj->Set(v8::String::New("key_click_percent"), v8::Integer::New(reply->reply->key_click_percent));
  obj->Set(v8::String::New("bell_percent"), v8::Integer::New(reply->reply->bell_percent));
  obj->Set(v8::String::New("bell_pitch"), v8::Integer::New(reply->reply->bell_pitch));
  obj->Set(v8::String::New("bell_duration"), v8::Integer::New(reply->reply->bell_duration));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetKeyboardControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetKeyboardControl(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_keyboard_control_cookie_t cookie = xcb_get_keyboard_control(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_keyboard_control_reply_t, xcb_get_keyboard_control_cookie_t> *reply = new Reply<xcb_get_keyboard_control_reply_t, xcb_get_keyboard_control_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetKeyboardControlReply, EIO_PRI_DEFAULT, HandleGetKeyboardControlReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> Bell(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: Bell(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  int8_t percent = (int8_t) obj->Get(v8::String::New("percent"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_bell(connection, percent);
  return Undefined();
}

v8::Handle<v8::Value> ChangePointerControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangePointerControl(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  int16_t acceleration_numerator = (int16_t) obj->Get(v8::String::New("acceleration_numerator"))->IntegerValue();
  int16_t acceleration_denominator = (int16_t) obj->Get(v8::String::New("acceleration_denominator"))->IntegerValue();
  int16_t threshold = (int16_t) obj->Get(v8::String::New("threshold"))->IntegerValue();
  uint8_t do_acceleration = (uint8_t) obj->Get(v8::String::New("do_acceleration"))->BooleanValue();
  uint8_t do_threshold = (uint8_t) obj->Get(v8::String::New("do_threshold"))->BooleanValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_pointer_control(connection, acceleration_numerator, acceleration_denominator, threshold, do_acceleration, do_threshold);
  return Undefined();
}

int GetGetPointerControlReply(eio_req *req) {
  Reply<xcb_get_pointer_control_reply_t, xcb_get_pointer_control_cookie_t> *reply = static_cast<Reply<xcb_get_pointer_control_reply_t, xcb_get_pointer_control_cookie_t> *>(req->data);
  reply->reply = xcb_get_pointer_control_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetPointerControlReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_pointer_control_reply_t, xcb_get_pointer_control_cookie_t> *reply = static_cast<Reply<xcb_get_pointer_control_reply_t, xcb_get_pointer_control_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("acceleration_numerator"), v8::Integer::New(reply->reply->acceleration_numerator));
  obj->Set(v8::String::New("acceleration_denominator"), v8::Integer::New(reply->reply->acceleration_denominator));
  obj->Set(v8::String::New("threshold"), v8::Integer::New(reply->reply->threshold));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetPointerControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetPointerControl(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_pointer_control_cookie_t cookie = xcb_get_pointer_control(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_pointer_control_reply_t, xcb_get_pointer_control_cookie_t> *reply = new Reply<xcb_get_pointer_control_reply_t, xcb_get_pointer_control_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetPointerControlReply, EIO_PRI_DEFAULT, HandleGetPointerControlReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> SetScreenSaver(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetScreenSaver(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  int16_t timeout = (int16_t) obj->Get(v8::String::New("timeout"))->IntegerValue();
  int16_t interval = (int16_t) obj->Get(v8::String::New("interval"))->IntegerValue();
  uint8_t prefer_blanking = (uint8_t) obj->Get(v8::String::New("prefer_blanking"))->IntegerValue();
  uint8_t allow_exposures = (uint8_t) obj->Get(v8::String::New("allow_exposures"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_screen_saver(connection, timeout, interval, prefer_blanking, allow_exposures);
  return Undefined();
}

int GetGetScreenSaverReply(eio_req *req) {
  Reply<xcb_get_screen_saver_reply_t, xcb_get_screen_saver_cookie_t> *reply = static_cast<Reply<xcb_get_screen_saver_reply_t, xcb_get_screen_saver_cookie_t> *>(req->data);
  reply->reply = xcb_get_screen_saver_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetScreenSaverReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_screen_saver_reply_t, xcb_get_screen_saver_cookie_t> *reply = static_cast<Reply<xcb_get_screen_saver_reply_t, xcb_get_screen_saver_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("timeout"), v8::Integer::New(reply->reply->timeout));
  obj->Set(v8::String::New("interval"), v8::Integer::New(reply->reply->interval));
  obj->Set(v8::String::New("prefer_blanking"), v8::Integer::New(reply->reply->prefer_blanking));
  obj->Set(v8::String::New("allow_exposures"), v8::Integer::New(reply->reply->allow_exposures));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetScreenSaver(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetScreenSaver(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_screen_saver_cookie_t cookie = xcb_get_screen_saver(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_screen_saver_reply_t, xcb_get_screen_saver_cookie_t> *reply = new Reply<xcb_get_screen_saver_reply_t, xcb_get_screen_saver_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetScreenSaverReply, EIO_PRI_DEFAULT, HandleGetScreenSaverReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> ChangeHosts(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeHosts(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  uint8_t family = (uint8_t) obj->Get(v8::String::New("family"))->IntegerValue();
  uint16_t address_len = (uint16_t) obj->Get(v8::String::New("address_len"))->IntegerValue();
  char *address;
  v8::Local<v8::String> address_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("address")));
  address = new char[address_str->Length()];
  strcpy(address, *v8::String::AsciiValue(address_str));
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_change_hosts(connection, mode, family, address_len, address);
  delete [] address;
  return Undefined();
}

int GetListHostsReply(eio_req *req) {
  Reply<xcb_list_hosts_reply_t, xcb_list_hosts_cookie_t> *reply = static_cast<Reply<xcb_list_hosts_reply_t, xcb_list_hosts_cookie_t> *>(req->data);
  reply->reply = xcb_list_hosts_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleListHostsReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_list_hosts_reply_t, xcb_list_hosts_cookie_t> *reply = static_cast<Reply<xcb_list_hosts_reply_t, xcb_list_hosts_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("mode"), v8::Integer::New(reply->reply->mode));
  v8::Local<v8::Array> hosts_list = v8::Array::New();
  obj->Set(v8::String::New("hosts"), hosts_list);
  int ihosts = 0;
  for(xcb_host_iterator_t itr = xcb_list_hosts_hosts_iterator(reply->reply); itr.rem; xcb_host_next(&itr), ++ihosts) {
    hosts_list->Set(ihosts, toJS(itr.data));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> ListHosts(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListHosts(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_list_hosts_cookie_t cookie = xcb_list_hosts(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_list_hosts_reply_t, xcb_list_hosts_cookie_t> *reply = new Reply<xcb_list_hosts_reply_t, xcb_list_hosts_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetListHostsReply, EIO_PRI_DEFAULT, HandleListHostsReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> SetAccessControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetAccessControl(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_access_control(connection, mode);
  return Undefined();
}

v8::Handle<v8::Value> SetCloseDownMode(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetCloseDownMode(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_close_down_mode(connection, mode);
  return Undefined();
}

v8::Handle<v8::Value> KillClient(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: KillClient(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint32_t resource = (uint32_t) obj->Get(v8::String::New("resource"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_kill_client(connection, resource);
  return Undefined();
}

v8::Handle<v8::Value> RotateProperties(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: RotateProperties(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  uint16_t atoms_len = (uint16_t) obj->Get(v8::String::New("atoms_len"))->IntegerValue();
  int16_t delta = (int16_t) obj->Get(v8::String::New("delta"))->IntegerValue();
  xcb_atom_t *atoms;
  v8::Local<v8::Array> atoms_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("atoms")));
  atoms = new xcb_atom_t[atoms_list->Length()];
  for(unsigned int i = 0; i < atoms_list->Length(); ++i) {
    atoms[i] = (xcb_atom_t) atoms_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_rotate_properties(connection, window, atoms_len, delta, atoms);
  delete [] atoms;
  return Undefined();
}

v8::Handle<v8::Value> ForceScreenSaver(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ForceScreenSaver(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_force_screen_saver(connection, mode);
  return Undefined();
}

int GetSetPointerMappingReply(eio_req *req) {
  Reply<xcb_set_pointer_mapping_reply_t, xcb_set_pointer_mapping_cookie_t> *reply = static_cast<Reply<xcb_set_pointer_mapping_reply_t, xcb_set_pointer_mapping_cookie_t> *>(req->data);
  reply->reply = xcb_set_pointer_mapping_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleSetPointerMappingReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_set_pointer_mapping_reply_t, xcb_set_pointer_mapping_cookie_t> *reply = static_cast<Reply<xcb_set_pointer_mapping_reply_t, xcb_set_pointer_mapping_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("status"), v8::Integer::New(reply->reply->status));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> SetPointerMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetPointerMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t map_len = (uint8_t) obj->Get(v8::String::New("map_len"))->IntegerValue();
  uint8_t *map;
  v8::Local<v8::Array> map_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("map")));
  map = new uint8_t[map_list->Length()];
  for(unsigned int i = 0; i < map_list->Length(); ++i) {
    map[i] = (uint8_t) map_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_pointer_mapping_cookie_t cookie = xcb_set_pointer_mapping(connection, map_len, map);
  delete [] map;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_set_pointer_mapping_reply_t, xcb_set_pointer_mapping_cookie_t> *reply = new Reply<xcb_set_pointer_mapping_reply_t, xcb_set_pointer_mapping_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetSetPointerMappingReply, EIO_PRI_DEFAULT, HandleSetPointerMappingReply, reply);
  }
  return Undefined();
}

int GetGetPointerMappingReply(eio_req *req) {
  Reply<xcb_get_pointer_mapping_reply_t, xcb_get_pointer_mapping_cookie_t> *reply = static_cast<Reply<xcb_get_pointer_mapping_reply_t, xcb_get_pointer_mapping_cookie_t> *>(req->data);
  reply->reply = xcb_get_pointer_mapping_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetPointerMappingReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_pointer_mapping_reply_t, xcb_get_pointer_mapping_cookie_t> *reply = static_cast<Reply<xcb_get_pointer_mapping_reply_t, xcb_get_pointer_mapping_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  v8::Local<v8::Array> map_list = v8::Array::New();
  obj->Set(v8::String::New("map"), map_list);
  uint8_t *map_list_ptr = xcb_get_pointer_mapping_map(reply->reply);
  for(int i = 0; i < xcb_get_pointer_mapping_map_length(reply->reply); ++i) {
    map_list->Set(i, v8::Integer::New(map_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetPointerMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetPointerMapping(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_pointer_mapping_cookie_t cookie = xcb_get_pointer_mapping(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_pointer_mapping_reply_t, xcb_get_pointer_mapping_cookie_t> *reply = new Reply<xcb_get_pointer_mapping_reply_t, xcb_get_pointer_mapping_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetPointerMappingReply, EIO_PRI_DEFAULT, HandleGetPointerMappingReply, reply);
  }
  return Undefined();
}

int GetSetModifierMappingReply(eio_req *req) {
  Reply<xcb_set_modifier_mapping_reply_t, xcb_set_modifier_mapping_cookie_t> *reply = static_cast<Reply<xcb_set_modifier_mapping_reply_t, xcb_set_modifier_mapping_cookie_t> *>(req->data);
  reply->reply = xcb_set_modifier_mapping_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleSetModifierMappingReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_set_modifier_mapping_reply_t, xcb_set_modifier_mapping_cookie_t> *reply = static_cast<Reply<xcb_set_modifier_mapping_reply_t, xcb_set_modifier_mapping_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("status"), v8::Integer::New(reply->reply->status));
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> SetModifierMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetModifierMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  v8::Local<v8::Function> callback;
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
  }
  if (args.Length() >= 2) {
    callback = v8::Local<v8::Function>::Cast(args[1]);
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t keycodes_per_modifier = (uint8_t) obj->Get(v8::String::New("keycodes_per_modifier"))->IntegerValue();
  xcb_keycode_t *keycodes;
  v8::Local<v8::Array> keycodes_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("keycodes")));
  keycodes = new xcb_keycode_t[keycodes_list->Length()];
  for(unsigned int i = 0; i < keycodes_list->Length(); ++i) {
    keycodes[i] = (xcb_keycode_t) keycodes_list->Get(i)->IntegerValue();
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_set_modifier_mapping_cookie_t cookie = xcb_set_modifier_mapping(connection, keycodes_per_modifier, keycodes);
  delete [] keycodes;
  if (!callback->Equals(Undefined())) {
    Reply<xcb_set_modifier_mapping_reply_t, xcb_set_modifier_mapping_cookie_t> *reply = new Reply<xcb_set_modifier_mapping_reply_t, xcb_set_modifier_mapping_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetSetModifierMappingReply, EIO_PRI_DEFAULT, HandleSetModifierMappingReply, reply);
  }
  return Undefined();
}

int GetGetModifierMappingReply(eio_req *req) {
  Reply<xcb_get_modifier_mapping_reply_t, xcb_get_modifier_mapping_cookie_t> *reply = static_cast<Reply<xcb_get_modifier_mapping_reply_t, xcb_get_modifier_mapping_cookie_t> *>(req->data);
  reply->reply = xcb_get_modifier_mapping_reply(reply->connection, reply->cookie, NULL); 
  return 0;
}

int HandleGetModifierMappingReply(eio_req *req) {
  v8::HandleScope scope;
  Reply<xcb_get_modifier_mapping_reply_t, xcb_get_modifier_mapping_cookie_t> *reply = static_cast<Reply<xcb_get_modifier_mapping_reply_t, xcb_get_modifier_mapping_cookie_t> *>(req->data);

  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("keycodes_per_modifier"), v8::Integer::New(reply->reply->keycodes_per_modifier));
  v8::Local<v8::Array> keycodes_list = v8::Array::New();
  obj->Set(v8::String::New("keycodes"), keycodes_list);
  xcb_keycode_t *keycodes_list_ptr = xcb_get_modifier_mapping_keycodes(reply->reply);
  for(int i = 0; i < xcb_get_modifier_mapping_keycodes_length(reply->reply); ++i) {
    keycodes_list->Set(i, v8::Integer::New(keycodes_list_ptr[i]));
  }
  v8::Local<Value> args[1] = { obj };
  reply->callback->Call(v8::Context::GetCurrent()->Global(), 1, args);
  reply->callback.Dispose();
  delete reply->reply;
  delete reply;
  return 0;
}

v8::Handle<v8::Value> GetModifierMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetModifierMapping(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Local<v8::Function> callback;
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  callback = v8::Local<v8::Function>::Cast(args[0]);
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_get_modifier_mapping_cookie_t cookie = xcb_get_modifier_mapping(connection);
  if (!callback->Equals(Undefined())) {
    Reply<xcb_get_modifier_mapping_reply_t, xcb_get_modifier_mapping_cookie_t> *reply = new Reply<xcb_get_modifier_mapping_reply_t, xcb_get_modifier_mapping_cookie_t>;
    reply->callback = v8::Persistent<v8::Function>::New(callback);
    reply->cookie = cookie;
    reply->reply = 0;
    reply->connection = connection;
    eio_custom(GetGetModifierMappingReply, EIO_PRI_DEFAULT, HandleGetModifierMappingReply, reply);
  }
  return Undefined();
}

v8::Handle<v8::Value> NoOperation(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: NoOperation(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  xcb_connection_t *connection = node::ObjectWrap::Unwrap<XCBJS>(args.This())->getConnection();
  xcb_no_operation(connection);
  return Undefined();
}

// END REQUESTS } } }

static v8::Persistent<v8::Object> lookup = v8::Persistent<v8::Object>::New(v8::Object::New());

v8::Handle<v8::String> Docs(v8::Handle<v8::String> what) {
  v8::HandleScope scope;
  return scope.Close(v8::Handle<v8::String>::Cast(lookup->Get(what)));
}


void Init(v8::Handle<v8::FunctionTemplate> reqs) {
  NODE_SET_PROTOTYPE_METHOD(reqs, "CreateWindow", CreateWindow);
  lookup->Set(v8::String::New("CreateWindow"), v8::String::New("REQUEST -> CreateWindow({ depth: Integer\n, wid: Integer\n, parent: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, border_width: Integer\n, class: Integer\n, visual: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeWindowAttributes", ChangeWindowAttributes);
  lookup->Set(v8::String::New("ChangeWindowAttributes"), v8::String::New("REQUEST -> ChangeWindowAttributes({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetWindowAttributes", GetWindowAttributes);
  lookup->Set(v8::String::New("GetWindowAttributes"), v8::String::New("REQUEST -> GetWindowAttributes({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "DestroyWindow", DestroyWindow);
  lookup->Set(v8::String::New("DestroyWindow"), v8::String::New("REQUEST -> DestroyWindow({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "DestroySubwindows", DestroySubwindows);
  lookup->Set(v8::String::New("DestroySubwindows"), v8::String::New("REQUEST -> DestroySubwindows({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeSaveSet", ChangeSaveSet);
  lookup->Set(v8::String::New("ChangeSaveSet"), v8::String::New("REQUEST -> ChangeSaveSet({ mode: Integer\n, window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ReparentWindow", ReparentWindow);
  lookup->Set(v8::String::New("ReparentWindow"), v8::String::New("REQUEST -> ReparentWindow({ window: Integer\n, parent: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "MapWindow", MapWindow);
  lookup->Set(v8::String::New("MapWindow"), v8::String::New("REQUEST -> MapWindow({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "MapSubwindows", MapSubwindows);
  lookup->Set(v8::String::New("MapSubwindows"), v8::String::New("REQUEST -> MapSubwindows({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UnmapWindow", UnmapWindow);
  lookup->Set(v8::String::New("UnmapWindow"), v8::String::New("REQUEST -> UnmapWindow({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UnmapSubwindows", UnmapSubwindows);
  lookup->Set(v8::String::New("UnmapSubwindows"), v8::String::New("REQUEST -> UnmapSubwindows({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ConfigureWindow", ConfigureWindow);
  lookup->Set(v8::String::New("ConfigureWindow"), v8::String::New("REQUEST -> ConfigureWindow({ window: Integer\n, value_mask: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CirculateWindow", CirculateWindow);
  lookup->Set(v8::String::New("CirculateWindow"), v8::String::New("REQUEST -> CirculateWindow({ direction: Integer\n, window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetGeometry", GetGeometry);
  lookup->Set(v8::String::New("GetGeometry"), v8::String::New("REQUEST -> GetGeometry({ drawable: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryTree", QueryTree);
  lookup->Set(v8::String::New("QueryTree"), v8::String::New("REQUEST -> QueryTree({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "InternAtom", InternAtom);
  lookup->Set(v8::String::New("InternAtom"), v8::String::New("REQUEST -> InternAtom({ only_if_exists: Boolean\n, name_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetAtomName", GetAtomName);
  lookup->Set(v8::String::New("GetAtomName"), v8::String::New("REQUEST -> GetAtomName({ atom: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeProperty", ChangeProperty);
  lookup->Set(v8::String::New("ChangeProperty"), v8::String::New("REQUEST -> ChangeProperty({ mode: Integer\n, window: Integer\n, property: Integer\n, type: Integer\n, format: Integer\n, data_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "DeleteProperty", DeleteProperty);
  lookup->Set(v8::String::New("DeleteProperty"), v8::String::New("REQUEST -> DeleteProperty({ window: Integer\n, property: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetProperty", GetProperty);
  lookup->Set(v8::String::New("GetProperty"), v8::String::New("REQUEST -> GetProperty({ delete: Boolean\n, window: Integer\n, property: Integer\n, type: Integer\n, long_offset: Integer\n, long_length: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ListProperties", ListProperties);
  lookup->Set(v8::String::New("ListProperties"), v8::String::New("REQUEST -> ListProperties({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetSelectionOwner", SetSelectionOwner);
  lookup->Set(v8::String::New("SetSelectionOwner"), v8::String::New("REQUEST -> SetSelectionOwner({ owner: Integer\n, selection: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetSelectionOwner", GetSelectionOwner);
  lookup->Set(v8::String::New("GetSelectionOwner"), v8::String::New("REQUEST -> GetSelectionOwner({ selection: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ConvertSelection", ConvertSelection);
  lookup->Set(v8::String::New("ConvertSelection"), v8::String::New("REQUEST -> ConvertSelection({ requestor: Integer\n, selection: Integer\n, target: Integer\n, property: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SendEvent", SendEvent);
  lookup->Set(v8::String::New("SendEvent"), v8::String::New("REQUEST -> SendEvent({ propagate: Boolean\n, destination: Integer\n, event_mask: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GrabPointer", GrabPointer);
  lookup->Set(v8::String::New("GrabPointer"), v8::String::New("REQUEST -> GrabPointer({ owner_events: Boolean\n, grab_window: Integer\n, event_mask: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer\n, confine_to: Integer\n, cursor: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UngrabPointer", UngrabPointer);
  lookup->Set(v8::String::New("UngrabPointer"), v8::String::New("REQUEST -> UngrabPointer({ time: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GrabButton", GrabButton);
  lookup->Set(v8::String::New("GrabButton"), v8::String::New("REQUEST -> GrabButton({ owner_events: Boolean\n, grab_window: Integer\n, event_mask: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer\n, confine_to: Integer\n, cursor: Integer\n, button: Integer\n, modifiers: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UngrabButton", UngrabButton);
  lookup->Set(v8::String::New("UngrabButton"), v8::String::New("REQUEST -> UngrabButton({ button: Integer\n, grab_window: Integer\n, modifiers: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeActivePointerGrab", ChangeActivePointerGrab);
  lookup->Set(v8::String::New("ChangeActivePointerGrab"), v8::String::New("REQUEST -> ChangeActivePointerGrab({ cursor: Integer\n, time: Integer\n, event_mask: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GrabKeyboard", GrabKeyboard);
  lookup->Set(v8::String::New("GrabKeyboard"), v8::String::New("REQUEST -> GrabKeyboard({ owner_events: Boolean\n, grab_window: Integer\n, time: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UngrabKeyboard", UngrabKeyboard);
  lookup->Set(v8::String::New("UngrabKeyboard"), v8::String::New("REQUEST -> UngrabKeyboard({ time: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GrabKey", GrabKey);
  lookup->Set(v8::String::New("GrabKey"), v8::String::New("REQUEST -> GrabKey({ owner_events: Boolean\n, grab_window: Integer\n, modifiers: Integer\n, key: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UngrabKey", UngrabKey);
  lookup->Set(v8::String::New("UngrabKey"), v8::String::New("REQUEST -> UngrabKey({ key: Integer\n, grab_window: Integer\n, modifiers: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "AllowEvents", AllowEvents);
  lookup->Set(v8::String::New("AllowEvents"), v8::String::New("REQUEST -> AllowEvents({ mode: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GrabServer", GrabServer);
  lookup->Set(v8::String::New("GrabServer"), v8::String::New("REQUEST -> GrabServer(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UngrabServer", UngrabServer);
  lookup->Set(v8::String::New("UngrabServer"), v8::String::New("REQUEST -> UngrabServer(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryPointer", QueryPointer);
  lookup->Set(v8::String::New("QueryPointer"), v8::String::New("REQUEST -> QueryPointer({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetMotionEvents", GetMotionEvents);
  lookup->Set(v8::String::New("GetMotionEvents"), v8::String::New("REQUEST -> GetMotionEvents({ window: Integer\n, start: Integer\n, stop: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "TranslateCoordinates", TranslateCoordinates);
  lookup->Set(v8::String::New("TranslateCoordinates"), v8::String::New("REQUEST -> TranslateCoordinates({ src_window: Integer\n, dst_window: Integer\n, src_x: Integer\n, src_y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "WarpPointer", WarpPointer);
  lookup->Set(v8::String::New("WarpPointer"), v8::String::New("REQUEST -> WarpPointer({ src_window: Integer\n, dst_window: Integer\n, src_x: Integer\n, src_y: Integer\n, src_width: Integer\n, src_height: Integer\n, dst_x: Integer\n, dst_y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetInputFocus", SetInputFocus);
  lookup->Set(v8::String::New("SetInputFocus"), v8::String::New("REQUEST -> SetInputFocus({ revert_to: Integer\n, focus: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetInputFocus", GetInputFocus);
  lookup->Set(v8::String::New("GetInputFocus"), v8::String::New("REQUEST -> GetInputFocus(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryKeymap", QueryKeymap);
  lookup->Set(v8::String::New("QueryKeymap"), v8::String::New("REQUEST -> QueryKeymap(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "OpenFont", OpenFont);
  lookup->Set(v8::String::New("OpenFont"), v8::String::New("REQUEST -> OpenFont({ fid: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CloseFont", CloseFont);
  lookup->Set(v8::String::New("CloseFont"), v8::String::New("REQUEST -> CloseFont({ font: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryFont", QueryFont);
  lookup->Set(v8::String::New("QueryFont"), v8::String::New("REQUEST -> QueryFont({ font: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryTextExtents", QueryTextExtents);
  lookup->Set(v8::String::New("QueryTextExtents"), v8::String::New("REQUEST -> QueryTextExtents({ font: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ListFonts", ListFonts);
  lookup->Set(v8::String::New("ListFonts"), v8::String::New("REQUEST -> ListFonts({ max_names: Integer\n, pattern_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ListFontsWithInfo", ListFontsWithInfo);
  lookup->Set(v8::String::New("ListFontsWithInfo"), v8::String::New("REQUEST -> ListFontsWithInfo({ max_names: Integer\n, pattern_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetFontPath", SetFontPath);
  lookup->Set(v8::String::New("SetFontPath"), v8::String::New("REQUEST -> SetFontPath({ font_qty: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetFontPath", GetFontPath);
  lookup->Set(v8::String::New("GetFontPath"), v8::String::New("REQUEST -> GetFontPath(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CreatePixmap", CreatePixmap);
  lookup->Set(v8::String::New("CreatePixmap"), v8::String::New("REQUEST -> CreatePixmap({ depth: Integer\n, pid: Integer\n, drawable: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "FreePixmap", FreePixmap);
  lookup->Set(v8::String::New("FreePixmap"), v8::String::New("REQUEST -> FreePixmap({ pixmap: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CreateGC", CreateGC);
  lookup->Set(v8::String::New("CreateGC"), v8::String::New("REQUEST -> CreateGC({ cid: Integer\n, drawable: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeGC", ChangeGC);
  lookup->Set(v8::String::New("ChangeGC"), v8::String::New("REQUEST -> ChangeGC({ gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CopyGC", CopyGC);
  lookup->Set(v8::String::New("CopyGC"), v8::String::New("REQUEST -> CopyGC({ src_gc: Integer\n, dst_gc: Integer\n, value_mask: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetDashes", SetDashes);
  lookup->Set(v8::String::New("SetDashes"), v8::String::New("REQUEST -> SetDashes({ gc: Integer\n, dash_offset: Integer\n, dashes_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetClipRectangles", SetClipRectangles);
  lookup->Set(v8::String::New("SetClipRectangles"), v8::String::New("REQUEST -> SetClipRectangles({ ordering: Integer\n, gc: Integer\n, clip_x_origin: Integer\n, clip_y_origin: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "FreeGC", FreeGC);
  lookup->Set(v8::String::New("FreeGC"), v8::String::New("REQUEST -> FreeGC({ gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ClearArea", ClearArea);
  lookup->Set(v8::String::New("ClearArea"), v8::String::New("REQUEST -> ClearArea({ exposures: Boolean\n, window: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CopyArea", CopyArea);
  lookup->Set(v8::String::New("CopyArea"), v8::String::New("REQUEST -> CopyArea({ src_drawable: Integer\n, dst_drawable: Integer\n, gc: Integer\n, src_x: Integer\n, src_y: Integer\n, dst_x: Integer\n, dst_y: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CopyPlane", CopyPlane);
  lookup->Set(v8::String::New("CopyPlane"), v8::String::New("REQUEST -> CopyPlane({ src_drawable: Integer\n, dst_drawable: Integer\n, gc: Integer\n, src_x: Integer\n, src_y: Integer\n, dst_x: Integer\n, dst_y: Integer\n, width: Integer\n, height: Integer\n, bit_plane: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyPoint", PolyPoint);
  lookup->Set(v8::String::New("PolyPoint"), v8::String::New("REQUEST -> PolyPoint({ coordinate_mode: Integer\n, drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyLine", PolyLine);
  lookup->Set(v8::String::New("PolyLine"), v8::String::New("REQUEST -> PolyLine({ coordinate_mode: Integer\n, drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolySegment", PolySegment);
  lookup->Set(v8::String::New("PolySegment"), v8::String::New("REQUEST -> PolySegment({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyRectangle", PolyRectangle);
  lookup->Set(v8::String::New("PolyRectangle"), v8::String::New("REQUEST -> PolyRectangle({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyArc", PolyArc);
  lookup->Set(v8::String::New("PolyArc"), v8::String::New("REQUEST -> PolyArc({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "FillPoly", FillPoly);
  lookup->Set(v8::String::New("FillPoly"), v8::String::New("REQUEST -> FillPoly({ drawable: Integer\n, gc: Integer\n, shape: Integer\n, coordinate_mode: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyFillRectangle", PolyFillRectangle);
  lookup->Set(v8::String::New("PolyFillRectangle"), v8::String::New("REQUEST -> PolyFillRectangle({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyFillArc", PolyFillArc);
  lookup->Set(v8::String::New("PolyFillArc"), v8::String::New("REQUEST -> PolyFillArc({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PutImage", PutImage);
  lookup->Set(v8::String::New("PutImage"), v8::String::New("REQUEST -> PutImage({ format: Integer\n, drawable: Integer\n, gc: Integer\n, width: Integer\n, height: Integer\n, dst_x: Integer\n, dst_y: Integer\n, left_pad: Integer\n, depth: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetImage", GetImage);
  lookup->Set(v8::String::New("GetImage"), v8::String::New("REQUEST -> GetImage({ format: Integer\n, drawable: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, plane_mask: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyText8", PolyText8);
  lookup->Set(v8::String::New("PolyText8"), v8::String::New("REQUEST -> PolyText8({ drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "PolyText16", PolyText16);
  lookup->Set(v8::String::New("PolyText16"), v8::String::New("REQUEST -> PolyText16({ drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ImageText8", ImageText8);
  lookup->Set(v8::String::New("ImageText8"), v8::String::New("REQUEST -> ImageText8({ string_len: Integer\n, drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ImageText16", ImageText16);
  lookup->Set(v8::String::New("ImageText16"), v8::String::New("REQUEST -> ImageText16({ string_len: Integer\n, drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CreateColormap", CreateColormap);
  lookup->Set(v8::String::New("CreateColormap"), v8::String::New("REQUEST -> CreateColormap({ alloc: Integer\n, mid: Integer\n, window: Integer\n, visual: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "FreeColormap", FreeColormap);
  lookup->Set(v8::String::New("FreeColormap"), v8::String::New("REQUEST -> FreeColormap({ cmap: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CopyColormapAndFree", CopyColormapAndFree);
  lookup->Set(v8::String::New("CopyColormapAndFree"), v8::String::New("REQUEST -> CopyColormapAndFree({ mid: Integer\n, src_cmap: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "InstallColormap", InstallColormap);
  lookup->Set(v8::String::New("InstallColormap"), v8::String::New("REQUEST -> InstallColormap({ cmap: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "UninstallColormap", UninstallColormap);
  lookup->Set(v8::String::New("UninstallColormap"), v8::String::New("REQUEST -> UninstallColormap({ cmap: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ListInstalledColormaps", ListInstalledColormaps);
  lookup->Set(v8::String::New("ListInstalledColormaps"), v8::String::New("REQUEST -> ListInstalledColormaps({ window: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "AllocColor", AllocColor);
  lookup->Set(v8::String::New("AllocColor"), v8::String::New("REQUEST -> AllocColor({ cmap: Integer\n, red: Integer\n, green: Integer\n, blue: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "AllocNamedColor", AllocNamedColor);
  lookup->Set(v8::String::New("AllocNamedColor"), v8::String::New("REQUEST -> AllocNamedColor({ cmap: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "AllocColorCells", AllocColorCells);
  lookup->Set(v8::String::New("AllocColorCells"), v8::String::New("REQUEST -> AllocColorCells({ contiguous: Boolean\n, cmap: Integer\n, colors: Integer\n, planes: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "AllocColorPlanes", AllocColorPlanes);
  lookup->Set(v8::String::New("AllocColorPlanes"), v8::String::New("REQUEST -> AllocColorPlanes({ contiguous: Boolean\n, cmap: Integer\n, colors: Integer\n, reds: Integer\n, greens: Integer\n, blues: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "FreeColors", FreeColors);
  lookup->Set(v8::String::New("FreeColors"), v8::String::New("REQUEST -> FreeColors({ cmap: Integer\n, plane_mask: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "StoreColors", StoreColors);
  lookup->Set(v8::String::New("StoreColors"), v8::String::New("REQUEST -> StoreColors({ cmap: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "StoreNamedColor", StoreNamedColor);
  lookup->Set(v8::String::New("StoreNamedColor"), v8::String::New("REQUEST -> StoreNamedColor({ flags: Integer\n, cmap: Integer\n, pixel: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryColors", QueryColors);
  lookup->Set(v8::String::New("QueryColors"), v8::String::New("REQUEST -> QueryColors({ cmap: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "LookupColor", LookupColor);
  lookup->Set(v8::String::New("LookupColor"), v8::String::New("REQUEST -> LookupColor({ cmap: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CreateCursor", CreateCursor);
  lookup->Set(v8::String::New("CreateCursor"), v8::String::New("REQUEST -> CreateCursor({ cid: Integer\n, source: Integer\n, mask: Integer\n, fore_red: Integer\n, fore_green: Integer\n, fore_blue: Integer\n, back_red: Integer\n, back_green: Integer\n, back_blue: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "CreateGlyphCursor", CreateGlyphCursor);
  lookup->Set(v8::String::New("CreateGlyphCursor"), v8::String::New("REQUEST -> CreateGlyphCursor({ cid: Integer\n, source_font: Integer\n, mask_font: Integer\n, source_char: Integer\n, mask_char: Integer\n, fore_red: Integer\n, fore_green: Integer\n, fore_blue: Integer\n, back_red: Integer\n, back_green: Integer\n, back_blue: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "FreeCursor", FreeCursor);
  lookup->Set(v8::String::New("FreeCursor"), v8::String::New("REQUEST -> FreeCursor({ cursor: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "RecolorCursor", RecolorCursor);
  lookup->Set(v8::String::New("RecolorCursor"), v8::String::New("REQUEST -> RecolorCursor({ cursor: Integer\n, fore_red: Integer\n, fore_green: Integer\n, fore_blue: Integer\n, back_red: Integer\n, back_green: Integer\n, back_blue: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryBestSize", QueryBestSize);
  lookup->Set(v8::String::New("QueryBestSize"), v8::String::New("REQUEST -> QueryBestSize({ class: Integer\n, drawable: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "QueryExtension", QueryExtension);
  lookup->Set(v8::String::New("QueryExtension"), v8::String::New("REQUEST -> QueryExtension({ name_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ListExtensions", ListExtensions);
  lookup->Set(v8::String::New("ListExtensions"), v8::String::New("REQUEST -> ListExtensions(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeKeyboardMapping", ChangeKeyboardMapping);
  lookup->Set(v8::String::New("ChangeKeyboardMapping"), v8::String::New("REQUEST -> ChangeKeyboardMapping({ keycode_count: Integer\n, first_keycode: Integer\n, keysyms_per_keycode: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetKeyboardMapping", GetKeyboardMapping);
  lookup->Set(v8::String::New("GetKeyboardMapping"), v8::String::New("REQUEST -> GetKeyboardMapping({ first_keycode: Integer\n, count: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeKeyboardControl", ChangeKeyboardControl);
  lookup->Set(v8::String::New("ChangeKeyboardControl"), v8::String::New("REQUEST -> ChangeKeyboardControl({  }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetKeyboardControl", GetKeyboardControl);
  lookup->Set(v8::String::New("GetKeyboardControl"), v8::String::New("REQUEST -> GetKeyboardControl(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "Bell", Bell);
  lookup->Set(v8::String::New("Bell"), v8::String::New("REQUEST -> Bell({ percent: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangePointerControl", ChangePointerControl);
  lookup->Set(v8::String::New("ChangePointerControl"), v8::String::New("REQUEST -> ChangePointerControl({ acceleration_numerator: Integer\n, acceleration_denominator: Integer\n, threshold: Integer\n, do_acceleration: Boolean\n, do_threshold: Boolean }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetPointerControl", GetPointerControl);
  lookup->Set(v8::String::New("GetPointerControl"), v8::String::New("REQUEST -> GetPointerControl(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetScreenSaver", SetScreenSaver);
  lookup->Set(v8::String::New("SetScreenSaver"), v8::String::New("REQUEST -> SetScreenSaver({ timeout: Integer\n, interval: Integer\n, prefer_blanking: Integer\n, allow_exposures: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetScreenSaver", GetScreenSaver);
  lookup->Set(v8::String::New("GetScreenSaver"), v8::String::New("REQUEST -> GetScreenSaver(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ChangeHosts", ChangeHosts);
  lookup->Set(v8::String::New("ChangeHosts"), v8::String::New("REQUEST -> ChangeHosts({ mode: Integer\n, family: Integer\n, address_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ListHosts", ListHosts);
  lookup->Set(v8::String::New("ListHosts"), v8::String::New("REQUEST -> ListHosts(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetAccessControl", SetAccessControl);
  lookup->Set(v8::String::New("SetAccessControl"), v8::String::New("REQUEST -> SetAccessControl({ mode: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetCloseDownMode", SetCloseDownMode);
  lookup->Set(v8::String::New("SetCloseDownMode"), v8::String::New("REQUEST -> SetCloseDownMode({ mode: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "KillClient", KillClient);
  lookup->Set(v8::String::New("KillClient"), v8::String::New("REQUEST -> KillClient({ resource: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "RotateProperties", RotateProperties);
  lookup->Set(v8::String::New("RotateProperties"), v8::String::New("REQUEST -> RotateProperties({ window: Integer\n, atoms_len: Integer\n, delta: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "ForceScreenSaver", ForceScreenSaver);
  lookup->Set(v8::String::New("ForceScreenSaver"), v8::String::New("REQUEST -> ForceScreenSaver({ mode: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetPointerMapping", SetPointerMapping);
  lookup->Set(v8::String::New("SetPointerMapping"), v8::String::New("REQUEST -> SetPointerMapping({ map_len: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetPointerMapping", GetPointerMapping);
  lookup->Set(v8::String::New("GetPointerMapping"), v8::String::New("REQUEST -> GetPointerMapping(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "SetModifierMapping", SetModifierMapping);
  lookup->Set(v8::String::New("SetModifierMapping"), v8::String::New("REQUEST -> SetModifierMapping({ keycodes_per_modifier: Integer }[, cb])")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "GetModifierMapping", GetModifierMapping);
  lookup->Set(v8::String::New("GetModifierMapping"), v8::String::New("REQUEST -> GetModifierMapping(cb)")); 
  NODE_SET_PROTOTYPE_METHOD(reqs, "NoOperation", NoOperation);
  lookup->Set(v8::String::New("NoOperation"), v8::String::New("REQUEST -> NoOperation(cb)")); 
}

  }
}

#endif