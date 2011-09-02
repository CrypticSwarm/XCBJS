#ifndef __AUTOGENCTOJSXCBREQUESTS__
#define __AUTOGENCTOJSXCBREQUESTS__
#include <v8.h>

#include <config.h>

namespace XCBJS {
  namespace Request {

//{ { { BEGIN REQUESTS 

v8::Handle<v8::Value> CreateWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_create_window(XCBJS::Config::connection, depth, wid, parent, x, y, width, height, border_width, _class, visual, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> ChangeWindowAttributes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeWindowAttributes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_change_window_attributes(XCBJS::Config::connection, window, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> GetWindowAttributes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetWindowAttributes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_get_window_attributes(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> DestroyWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: DestroyWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_destroy_window(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> DestroySubwindows(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: DestroySubwindows(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_destroy_subwindows(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> ChangeSaveSet(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeSaveSet(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_change_save_set(XCBJS::Config::connection, mode, window);
  return Undefined();
}

v8::Handle<v8::Value> ReparentWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ReparentWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_window_t parent = (xcb_window_t) obj->Get(v8::String::New("parent"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  xcb_reparent_window(XCBJS::Config::connection, window, parent, x, y);
  return Undefined();
}

v8::Handle<v8::Value> MapWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: MapWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_map_window(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> MapSubwindows(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: MapSubwindows(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_map_subwindows(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> UnmapWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UnmapWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_unmap_window(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> UnmapSubwindows(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UnmapSubwindows(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_unmap_subwindows(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> ConfigureWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ConfigureWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_configure_window(XCBJS::Config::connection, window, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> CirculateWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CirculateWindow(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t direction = (uint8_t) obj->Get(v8::String::New("direction"))->IntegerValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_circulate_window(XCBJS::Config::connection, direction, window);
  return Undefined();
}

v8::Handle<v8::Value> GetGeometry(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetGeometry(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  xcb_get_geometry(XCBJS::Config::connection, drawable);
  return Undefined();
}

v8::Handle<v8::Value> QueryTree(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryTree(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_query_tree(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> InternAtom(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: InternAtom(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t only_if_exists = (uint8_t) obj->Get(v8::String::New("only_if_exists"))->BooleanValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_intern_atom(XCBJS::Config::connection, only_if_exists, name_len, name);
  delete [] name;
  return Undefined();
}

v8::Handle<v8::Value> GetAtomName(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetAtomName(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_atom_t atom = (xcb_atom_t) obj->Get(v8::String::New("atom"))->IntegerValue();
  xcb_get_atom_name(XCBJS::Config::connection, atom);
  return Undefined();
}

v8::Handle<v8::Value> ChangeProperty(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeProperty(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_change_property(XCBJS::Config::connection, mode, window, property, type, format, data_len, data);
  delete [] data;
  return Undefined();
}

v8::Handle<v8::Value> DeleteProperty(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: DeleteProperty(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
  xcb_delete_property(XCBJS::Config::connection, window, property);
  return Undefined();
}

v8::Handle<v8::Value> GetProperty(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetProperty(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t _delete = (uint8_t) obj->Get(v8::String::New("delete"))->BooleanValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
  xcb_atom_t type = (xcb_atom_t) obj->Get(v8::String::New("type"))->IntegerValue();
  uint32_t long_offset = (uint32_t) obj->Get(v8::String::New("long_offset"))->IntegerValue();
  uint32_t long_length = (uint32_t) obj->Get(v8::String::New("long_length"))->IntegerValue();
  xcb_get_property(XCBJS::Config::connection, _delete, window, property, type, long_offset, long_length);
  return Undefined();
}

v8::Handle<v8::Value> ListProperties(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListProperties(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_list_properties(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> SetSelectionOwner(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetSelectionOwner(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t owner = (xcb_window_t) obj->Get(v8::String::New("owner"))->IntegerValue();
  xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_set_selection_owner(XCBJS::Config::connection, owner, selection, time);
  return Undefined();
}

v8::Handle<v8::Value> GetSelectionOwner(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetSelectionOwner(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
  xcb_get_selection_owner(XCBJS::Config::connection, selection);
  return Undefined();
}

v8::Handle<v8::Value> ConvertSelection(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ConvertSelection(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t requestor = (xcb_window_t) obj->Get(v8::String::New("requestor"))->IntegerValue();
  xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
  xcb_atom_t target = (xcb_atom_t) obj->Get(v8::String::New("target"))->IntegerValue();
  xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_convert_selection(XCBJS::Config::connection, requestor, selection, target, property, time);
  return Undefined();
}

v8::Handle<v8::Value> SendEvent(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SendEvent(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t propagate = (uint8_t) obj->Get(v8::String::New("propagate"))->BooleanValue();
  xcb_window_t destination = (xcb_window_t) obj->Get(v8::String::New("destination"))->IntegerValue();
  uint32_t event_mask = (uint32_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
  char *event;
  v8::Local<v8::String> event_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("event")));
  event = new char[event_str->Length()];
  strcpy(event, *v8::String::AsciiValue(event_str));
  xcb_send_event(XCBJS::Config::connection, propagate, destination, event_mask, event);
  delete [] event;
  return Undefined();
}

v8::Handle<v8::Value> GrabPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_grab_pointer(XCBJS::Config::connection, owner_events, grab_window, event_mask, pointer_mode, keyboard_mode, confine_to, cursor, time);
  return Undefined();
}

v8::Handle<v8::Value> UngrabPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_ungrab_pointer(XCBJS::Config::connection, time);
  return Undefined();
}

v8::Handle<v8::Value> GrabButton(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabButton(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_grab_button(XCBJS::Config::connection, owner_events, grab_window, event_mask, pointer_mode, keyboard_mode, confine_to, cursor, button, modifiers);
  return Undefined();
}

v8::Handle<v8::Value> UngrabButton(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabButton(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t button = (uint8_t) obj->Get(v8::String::New("button"))->IntegerValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
  xcb_ungrab_button(XCBJS::Config::connection, button, grab_window, modifiers);
  return Undefined();
}

v8::Handle<v8::Value> ChangeActivePointerGrab(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeActivePointerGrab(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  uint16_t event_mask = (uint16_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
  xcb_change_active_pointer_grab(XCBJS::Config::connection, cursor, time, event_mask);
  return Undefined();
}

v8::Handle<v8::Value> GrabKeyboard(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabKeyboard(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
  uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
  xcb_grab_keyboard(XCBJS::Config::connection, owner_events, grab_window, time, pointer_mode, keyboard_mode);
  return Undefined();
}

v8::Handle<v8::Value> UngrabKeyboard(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabKeyboard(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_ungrab_keyboard(XCBJS::Config::connection, time);
  return Undefined();
}

v8::Handle<v8::Value> GrabKey(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabKey(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
  xcb_keycode_t key = (xcb_keycode_t) obj->Get(v8::String::New("key"))->IntegerValue();
  uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
  uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
  xcb_grab_key(XCBJS::Config::connection, owner_events, grab_window, modifiers, key, pointer_mode, keyboard_mode);
  return Undefined();
}

v8::Handle<v8::Value> UngrabKey(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabKey(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_keycode_t key = (xcb_keycode_t) obj->Get(v8::String::New("key"))->IntegerValue();
  xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
  uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
  xcb_ungrab_key(XCBJS::Config::connection, key, grab_window, modifiers);
  return Undefined();
}

v8::Handle<v8::Value> AllowEvents(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllowEvents(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_allow_events(XCBJS::Config::connection, mode, time);
  return Undefined();
}

v8::Handle<v8::Value> GrabServer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GrabServer(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_grab_server(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> UngrabServer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UngrabServer(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_ungrab_server(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> QueryPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_query_pointer(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> GetMotionEvents(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetMotionEvents(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_timestamp_t start = (xcb_timestamp_t) obj->Get(v8::String::New("start"))->IntegerValue();
  xcb_timestamp_t stop = (xcb_timestamp_t) obj->Get(v8::String::New("stop"))->IntegerValue();
  xcb_get_motion_events(XCBJS::Config::connection, window, start, stop);
  return Undefined();
}

v8::Handle<v8::Value> TranslateCoordinates(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: TranslateCoordinates(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t src_window = (xcb_window_t) obj->Get(v8::String::New("src_window"))->IntegerValue();
  xcb_window_t dst_window = (xcb_window_t) obj->Get(v8::String::New("dst_window"))->IntegerValue();
  int16_t src_x = (int16_t) obj->Get(v8::String::New("src_x"))->IntegerValue();
  int16_t src_y = (int16_t) obj->Get(v8::String::New("src_y"))->IntegerValue();
  xcb_translate_coordinates(XCBJS::Config::connection, src_window, dst_window, src_x, src_y);
  return Undefined();
}

v8::Handle<v8::Value> WarpPointer(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: WarpPointer(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_warp_pointer(XCBJS::Config::connection, src_window, dst_window, src_x, src_y, src_width, src_height, dst_x, dst_y);
  return Undefined();
}

v8::Handle<v8::Value> SetInputFocus(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetInputFocus(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t revert_to = (uint8_t) obj->Get(v8::String::New("revert_to"))->IntegerValue();
  xcb_window_t focus = (xcb_window_t) obj->Get(v8::String::New("focus"))->IntegerValue();
  xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  xcb_set_input_focus(XCBJS::Config::connection, revert_to, focus, time);
  return Undefined();
}

v8::Handle<v8::Value> GetInputFocus(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetInputFocus(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_get_input_focus(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> QueryKeymap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryKeymap(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_query_keymap(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> OpenFont(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: OpenFont(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_font_t fid = (xcb_font_t) obj->Get(v8::String::New("fid"))->IntegerValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_open_font(XCBJS::Config::connection, fid, name_len, name);
  delete [] name;
  return Undefined();
}

v8::Handle<v8::Value> CloseFont(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CloseFont(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_font_t font = (xcb_font_t) obj->Get(v8::String::New("font"))->IntegerValue();
  xcb_close_font(XCBJS::Config::connection, font);
  return Undefined();
}

v8::Handle<v8::Value> QueryFont(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryFont(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_fontable_t font = (xcb_fontable_t) obj->Get(v8::String::New("font"))->IntegerValue();
  xcb_query_font(XCBJS::Config::connection, font);
  return Undefined();
}

v8::Handle<v8::Value> QueryTextExtents(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryTextExtents(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_query_text_extents(XCBJS::Config::connection, font, string_len, string);
  delete [] string;
  return Undefined();
}

v8::Handle<v8::Value> ListFonts(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListFonts(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t max_names = (uint16_t) obj->Get(v8::String::New("max_names"))->IntegerValue();
  uint16_t pattern_len = (uint16_t) obj->Get(v8::String::New("pattern_len"))->IntegerValue();
  char *pattern;
  v8::Local<v8::String> pattern_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("pattern")));
  pattern = new char[pattern_str->Length()];
  strcpy(pattern, *v8::String::AsciiValue(pattern_str));
  xcb_list_fonts(XCBJS::Config::connection, max_names, pattern_len, pattern);
  delete [] pattern;
  return Undefined();
}

v8::Handle<v8::Value> ListFontsWithInfo(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListFontsWithInfo(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t max_names = (uint16_t) obj->Get(v8::String::New("max_names"))->IntegerValue();
  uint16_t pattern_len = (uint16_t) obj->Get(v8::String::New("pattern_len"))->IntegerValue();
  char *pattern;
  v8::Local<v8::String> pattern_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("pattern")));
  pattern = new char[pattern_str->Length()];
  strcpy(pattern, *v8::String::AsciiValue(pattern_str));
  xcb_list_fonts_with_info(XCBJS::Config::connection, max_names, pattern_len, pattern);
  delete [] pattern;
  return Undefined();
}

v8::Handle<v8::Value> SetFontPath(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetFontPath(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t font_qty = (uint16_t) obj->Get(v8::String::New("font_qty"))->IntegerValue();
  uint32_t path_len = (uint32_t) obj->Get(v8::String::New("path_len"))->IntegerValue();
  char *path;
  v8::Local<v8::String> path_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("path")));
  path = new char[path_str->Length()];
  strcpy(path, *v8::String::AsciiValue(path_str));
  xcb_set_font_path(XCBJS::Config::connection, font_qty, path_len, path);
  delete [] path;
  return Undefined();
}

v8::Handle<v8::Value> GetFontPath(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetFontPath(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_get_font_path(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> CreatePixmap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreatePixmap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t depth = (uint8_t) obj->Get(v8::String::New("depth"))->IntegerValue();
  xcb_pixmap_t pid = (xcb_pixmap_t) obj->Get(v8::String::New("pid"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  xcb_create_pixmap(XCBJS::Config::connection, depth, pid, drawable, width, height);
  return Undefined();
}

v8::Handle<v8::Value> FreePixmap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreePixmap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_pixmap_t pixmap = (xcb_pixmap_t) obj->Get(v8::String::New("pixmap"))->IntegerValue();
  xcb_free_pixmap(XCBJS::Config::connection, pixmap);
  return Undefined();
}

v8::Handle<v8::Value> CreateGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_create_gc(XCBJS::Config::connection, cid, drawable, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> ChangeGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_change_gc(XCBJS::Config::connection, gc, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> CopyGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_gcontext_t src_gc = (xcb_gcontext_t) obj->Get(v8::String::New("src_gc"))->IntegerValue();
  xcb_gcontext_t dst_gc = (xcb_gcontext_t) obj->Get(v8::String::New("dst_gc"))->IntegerValue();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  xcb_copy_gc(XCBJS::Config::connection, src_gc, dst_gc, value_mask);
  return Undefined();
}

v8::Handle<v8::Value> SetDashes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetDashes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_set_dashes(XCBJS::Config::connection, gc, dash_offset, dashes_len, dashes);
  delete [] dashes;
  return Undefined();
}

v8::Handle<v8::Value> SetClipRectangles(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetClipRectangles(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_set_clip_rectangles(XCBJS::Config::connection, ordering, gc, clip_x_origin, clip_y_origin, rectangles_len, rectangles);
  delete [] rectangles;
  return Undefined();
}

v8::Handle<v8::Value> FreeGC(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeGC(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
  xcb_free_gc(XCBJS::Config::connection, gc);
  return Undefined();
}

v8::Handle<v8::Value> ClearArea(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ClearArea(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t exposures = (uint8_t) obj->Get(v8::String::New("exposures"))->BooleanValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  xcb_clear_area(XCBJS::Config::connection, exposures, window, x, y, width, height);
  return Undefined();
}

v8::Handle<v8::Value> CopyArea(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyArea(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_copy_area(XCBJS::Config::connection, src_drawable, dst_drawable, gc, src_x, src_y, dst_x, dst_y, width, height);
  return Undefined();
}

v8::Handle<v8::Value> CopyPlane(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyPlane(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_copy_plane(XCBJS::Config::connection, src_drawable, dst_drawable, gc, src_x, src_y, dst_x, dst_y, width, height, bit_plane);
  return Undefined();
}

v8::Handle<v8::Value> PolyPoint(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyPoint(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_point(XCBJS::Config::connection, coordinate_mode, drawable, gc, points_len, points);
  delete [] points;
  return Undefined();
}

v8::Handle<v8::Value> PolyLine(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyLine(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_line(XCBJS::Config::connection, coordinate_mode, drawable, gc, points_len, points);
  delete [] points;
  return Undefined();
}

v8::Handle<v8::Value> PolySegment(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolySegment(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_segment(XCBJS::Config::connection, drawable, gc, segments_len, segments);
  delete [] segments;
  return Undefined();
}

v8::Handle<v8::Value> PolyRectangle(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyRectangle(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_rectangle(XCBJS::Config::connection, drawable, gc, rectangles_len, rectangles);
  delete [] rectangles;
  return Undefined();
}

v8::Handle<v8::Value> PolyArc(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyArc(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_arc(XCBJS::Config::connection, drawable, gc, arcs_len, arcs);
  delete [] arcs;
  return Undefined();
}

v8::Handle<v8::Value> FillPoly(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FillPoly(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_fill_poly(XCBJS::Config::connection, drawable, gc, shape, coordinate_mode, points_len, points);
  delete [] points;
  return Undefined();
}

v8::Handle<v8::Value> PolyFillRectangle(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyFillRectangle(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_fill_rectangle(XCBJS::Config::connection, drawable, gc, rectangles_len, rectangles);
  delete [] rectangles;
  return Undefined();
}

v8::Handle<v8::Value> PolyFillArc(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyFillArc(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_fill_arc(XCBJS::Config::connection, drawable, gc, arcs_len, arcs);
  delete [] arcs;
  return Undefined();
}

v8::Handle<v8::Value> PutImage(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PutImage(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_put_image(XCBJS::Config::connection, format, drawable, gc, width, height, dst_x, dst_y, left_pad, depth, data_len, data);
  delete [] data;
  return Undefined();
}

v8::Handle<v8::Value> GetImage(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetImage(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t format = (uint8_t) obj->Get(v8::String::New("format"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  uint32_t plane_mask = (uint32_t) obj->Get(v8::String::New("plane_mask"))->IntegerValue();
  xcb_get_image(XCBJS::Config::connection, format, drawable, x, y, width, height, plane_mask);
  return Undefined();
}

v8::Handle<v8::Value> PolyText8(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyText8(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_text_8(XCBJS::Config::connection, drawable, gc, x, y, items_len, items);
  delete [] items;
  return Undefined();
}

v8::Handle<v8::Value> PolyText16(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: PolyText16(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_poly_text_16(XCBJS::Config::connection, drawable, gc, x, y, items_len, items);
  delete [] items;
  return Undefined();
}

v8::Handle<v8::Value> ImageText8(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ImageText8(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_image_text_8(XCBJS::Config::connection, string_len, drawable, gc, x, y, string);
  delete [] string;
  return Undefined();
}

v8::Handle<v8::Value> ImageText16(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ImageText16(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_image_text_16(XCBJS::Config::connection, string_len, drawable, gc, x, y, string);
  delete [] string;
  return Undefined();
}

v8::Handle<v8::Value> CreateColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t alloc = (uint8_t) obj->Get(v8::String::New("alloc"))->IntegerValue();
  xcb_colormap_t mid = (xcb_colormap_t) obj->Get(v8::String::New("mid"))->IntegerValue();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_visualid_t visual = (xcb_visualid_t) obj->Get(v8::String::New("visual"))->IntegerValue();
  xcb_create_colormap(XCBJS::Config::connection, alloc, mid, window, visual);
  return Undefined();
}

v8::Handle<v8::Value> FreeColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  xcb_free_colormap(XCBJS::Config::connection, cmap);
  return Undefined();
}

v8::Handle<v8::Value> CopyColormapAndFree(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CopyColormapAndFree(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t mid = (xcb_colormap_t) obj->Get(v8::String::New("mid"))->IntegerValue();
  xcb_colormap_t src_cmap = (xcb_colormap_t) obj->Get(v8::String::New("src_cmap"))->IntegerValue();
  xcb_copy_colormap_and_free(XCBJS::Config::connection, mid, src_cmap);
  return Undefined();
}

v8::Handle<v8::Value> InstallColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: InstallColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  xcb_install_colormap(XCBJS::Config::connection, cmap);
  return Undefined();
}

v8::Handle<v8::Value> UninstallColormap(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: UninstallColormap(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  xcb_uninstall_colormap(XCBJS::Config::connection, cmap);
  return Undefined();
}

v8::Handle<v8::Value> ListInstalledColormaps(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListInstalledColormaps(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
  xcb_list_installed_colormaps(XCBJS::Config::connection, window);
  return Undefined();
}

v8::Handle<v8::Value> AllocColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t red = (uint16_t) obj->Get(v8::String::New("red"))->IntegerValue();
  uint16_t green = (uint16_t) obj->Get(v8::String::New("green"))->IntegerValue();
  uint16_t blue = (uint16_t) obj->Get(v8::String::New("blue"))->IntegerValue();
  xcb_alloc_color(XCBJS::Config::connection, cmap, red, green, blue);
  return Undefined();
}

v8::Handle<v8::Value> AllocNamedColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocNamedColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_alloc_named_color(XCBJS::Config::connection, cmap, name_len, name);
  delete [] name;
  return Undefined();
}

v8::Handle<v8::Value> AllocColorCells(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocColorCells(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t contiguous = (uint8_t) obj->Get(v8::String::New("contiguous"))->BooleanValue();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t colors = (uint16_t) obj->Get(v8::String::New("colors"))->IntegerValue();
  uint16_t planes = (uint16_t) obj->Get(v8::String::New("planes"))->IntegerValue();
  xcb_alloc_color_cells(XCBJS::Config::connection, contiguous, cmap, colors, planes);
  return Undefined();
}

v8::Handle<v8::Value> AllocColorPlanes(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: AllocColorPlanes(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t contiguous = (uint8_t) obj->Get(v8::String::New("contiguous"))->BooleanValue();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t colors = (uint16_t) obj->Get(v8::String::New("colors"))->IntegerValue();
  uint16_t reds = (uint16_t) obj->Get(v8::String::New("reds"))->IntegerValue();
  uint16_t greens = (uint16_t) obj->Get(v8::String::New("greens"))->IntegerValue();
  uint16_t blues = (uint16_t) obj->Get(v8::String::New("blues"))->IntegerValue();
  xcb_alloc_color_planes(XCBJS::Config::connection, contiguous, cmap, colors, reds, greens, blues);
  return Undefined();
}

v8::Handle<v8::Value> FreeColors(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeColors(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_free_colors(XCBJS::Config::connection, cmap, plane_mask, pixels_len, pixels);
  delete [] pixels;
  return Undefined();
}

v8::Handle<v8::Value> StoreColors(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: StoreColors(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_store_colors(XCBJS::Config::connection, cmap, items_len, items);
  delete [] items;
  return Undefined();
}

v8::Handle<v8::Value> StoreNamedColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: StoreNamedColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_store_named_color(XCBJS::Config::connection, flags, cmap, pixel, name_len, name);
  delete [] name;
  return Undefined();
}

v8::Handle<v8::Value> QueryColors(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryColors(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_query_colors(XCBJS::Config::connection, cmap, pixels_len, pixels);
  delete [] pixels;
  return Undefined();
}

v8::Handle<v8::Value> LookupColor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: LookupColor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_lookup_color(XCBJS::Config::connection, cmap, name_len, name);
  delete [] name;
  return Undefined();
}

v8::Handle<v8::Value> CreateCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_create_cursor(XCBJS::Config::connection, cid, source, mask, fore_red, fore_green, fore_blue, back_red, back_green, back_blue, x, y);
  return Undefined();
}

v8::Handle<v8::Value> CreateGlyphCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: CreateGlyphCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_create_glyph_cursor(XCBJS::Config::connection, cid, source_font, mask_font, source_char, mask_char, fore_red, fore_green, fore_blue, back_red, back_green, back_blue);
  return Undefined();
}

v8::Handle<v8::Value> FreeCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: FreeCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  xcb_free_cursor(XCBJS::Config::connection, cursor);
  return Undefined();
}

v8::Handle<v8::Value> RecolorCursor(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: RecolorCursor(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
  uint16_t fore_red = (uint16_t) obj->Get(v8::String::New("fore_red"))->IntegerValue();
  uint16_t fore_green = (uint16_t) obj->Get(v8::String::New("fore_green"))->IntegerValue();
  uint16_t fore_blue = (uint16_t) obj->Get(v8::String::New("fore_blue"))->IntegerValue();
  uint16_t back_red = (uint16_t) obj->Get(v8::String::New("back_red"))->IntegerValue();
  uint16_t back_green = (uint16_t) obj->Get(v8::String::New("back_green"))->IntegerValue();
  uint16_t back_blue = (uint16_t) obj->Get(v8::String::New("back_blue"))->IntegerValue();
  xcb_recolor_cursor(XCBJS::Config::connection, cursor, fore_red, fore_green, fore_blue, back_red, back_green, back_blue);
  return Undefined();
}

v8::Handle<v8::Value> QueryBestSize(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryBestSize(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t _class = (uint8_t) obj->Get(v8::String::New("class"))->IntegerValue();
  xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
  uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  xcb_query_best_size(XCBJS::Config::connection, _class, drawable, width, height);
  return Undefined();
}

v8::Handle<v8::Value> QueryExtension(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: QueryExtension(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint16_t name_len = (uint16_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
  char *name;
  v8::Local<v8::String> name_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("name")));
  name = new char[name_str->Length()];
  strcpy(name, *v8::String::AsciiValue(name_str));
  xcb_query_extension(XCBJS::Config::connection, name_len, name);
  delete [] name;
  return Undefined();
}

v8::Handle<v8::Value> ListExtensions(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListExtensions(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_list_extensions(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> ChangeKeyboardMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeKeyboardMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_change_keyboard_mapping(XCBJS::Config::connection, keycode_count, first_keycode, keysyms_per_keycode, keysyms);
  delete [] keysyms;
  return Undefined();
}

v8::Handle<v8::Value> GetKeyboardMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetKeyboardMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_keycode_t first_keycode = (xcb_keycode_t) obj->Get(v8::String::New("first_keycode"))->IntegerValue();
  uint8_t count = (uint8_t) obj->Get(v8::String::New("count"))->IntegerValue();
  xcb_get_keyboard_mapping(XCBJS::Config::connection, first_keycode, count);
  return Undefined();
}

v8::Handle<v8::Value> ChangeKeyboardControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeKeyboardControl(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
  uint32_t *value_list;
  v8::Local<v8::Array> value_mask_valmask = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
  value_list = new uint32_t[value_mask_valmask->Length()];
  for(unsigned int i = 0; i < value_mask_valmask->Length(); ++i) {
    value_list[i] = (uint32_t) value_mask_valmask->Get(i)->IntegerValue();
  }
  xcb_change_keyboard_control(XCBJS::Config::connection, value_mask, value_list);
  delete [] value_list;
  return Undefined();
}

v8::Handle<v8::Value> GetKeyboardControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetKeyboardControl(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_get_keyboard_control(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> Bell(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: Bell(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  int8_t percent = (int8_t) obj->Get(v8::String::New("percent"))->IntegerValue();
  xcb_bell(XCBJS::Config::connection, percent);
  return Undefined();
}

v8::Handle<v8::Value> ChangePointerControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangePointerControl(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  int16_t acceleration_numerator = (int16_t) obj->Get(v8::String::New("acceleration_numerator"))->IntegerValue();
  int16_t acceleration_denominator = (int16_t) obj->Get(v8::String::New("acceleration_denominator"))->IntegerValue();
  int16_t threshold = (int16_t) obj->Get(v8::String::New("threshold"))->IntegerValue();
  uint8_t do_acceleration = (uint8_t) obj->Get(v8::String::New("do_acceleration"))->BooleanValue();
  uint8_t do_threshold = (uint8_t) obj->Get(v8::String::New("do_threshold"))->BooleanValue();
  xcb_change_pointer_control(XCBJS::Config::connection, acceleration_numerator, acceleration_denominator, threshold, do_acceleration, do_threshold);
  return Undefined();
}

v8::Handle<v8::Value> GetPointerControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetPointerControl(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_get_pointer_control(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> SetScreenSaver(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetScreenSaver(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  int16_t timeout = (int16_t) obj->Get(v8::String::New("timeout"))->IntegerValue();
  int16_t interval = (int16_t) obj->Get(v8::String::New("interval"))->IntegerValue();
  uint8_t prefer_blanking = (uint8_t) obj->Get(v8::String::New("prefer_blanking"))->IntegerValue();
  uint8_t allow_exposures = (uint8_t) obj->Get(v8::String::New("allow_exposures"))->IntegerValue();
  xcb_set_screen_saver(XCBJS::Config::connection, timeout, interval, prefer_blanking, allow_exposures);
  return Undefined();
}

v8::Handle<v8::Value> GetScreenSaver(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetScreenSaver(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_get_screen_saver(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> ChangeHosts(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ChangeHosts(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  uint8_t family = (uint8_t) obj->Get(v8::String::New("family"))->IntegerValue();
  uint16_t address_len = (uint16_t) obj->Get(v8::String::New("address_len"))->IntegerValue();
  char *address;
  v8::Local<v8::String> address_str = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("address")));
  address = new char[address_str->Length()];
  strcpy(address, *v8::String::AsciiValue(address_str));
  xcb_change_hosts(XCBJS::Config::connection, mode, family, address_len, address);
  delete [] address;
  return Undefined();
}

v8::Handle<v8::Value> ListHosts(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ListHosts(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_list_hosts(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> SetAccessControl(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetAccessControl(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_set_access_control(XCBJS::Config::connection, mode);
  return Undefined();
}

v8::Handle<v8::Value> SetCloseDownMode(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetCloseDownMode(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_set_close_down_mode(XCBJS::Config::connection, mode);
  return Undefined();
}

v8::Handle<v8::Value> KillClient(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: KillClient(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint32_t resource = (uint32_t) obj->Get(v8::String::New("resource"))->IntegerValue();
  xcb_kill_client(XCBJS::Config::connection, resource);
  return Undefined();
}

v8::Handle<v8::Value> RotateProperties(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: RotateProperties(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
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
  xcb_rotate_properties(XCBJS::Config::connection, window, atoms_len, delta, atoms);
  delete [] atoms;
  return Undefined();
}

v8::Handle<v8::Value> ForceScreenSaver(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ForceScreenSaver(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
  xcb_force_screen_saver(XCBJS::Config::connection, mode);
  return Undefined();
}

v8::Handle<v8::Value> SetPointerMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetPointerMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t map_len = (uint8_t) obj->Get(v8::String::New("map_len"))->IntegerValue();
  uint8_t *map;
  v8::Local<v8::Array> map_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("map")));
  map = new uint8_t[map_list->Length()];
  for(unsigned int i = 0; i < map_list->Length(); ++i) {
    map[i] = (uint8_t) map_list->Get(i)->IntegerValue();
  }
  xcb_set_pointer_mapping(XCBJS::Config::connection, map_len, map);
  delete [] map;
  return Undefined();
}

v8::Handle<v8::Value> GetPointerMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetPointerMapping(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_get_pointer_mapping(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> SetModifierMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: SetModifierMapping(obj[, cb])";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  uint8_t keycodes_per_modifier = (uint8_t) obj->Get(v8::String::New("keycodes_per_modifier"))->IntegerValue();
  xcb_keycode_t *keycodes;
  v8::Local<v8::Array> keycodes_list = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("keycodes")));
  keycodes = new xcb_keycode_t[keycodes_list->Length()];
  for(unsigned int i = 0; i < keycodes_list->Length(); ++i) {
    keycodes[i] = (xcb_keycode_t) keycodes_list->Get(i)->IntegerValue();
  }
  xcb_set_modifier_mapping(XCBJS::Config::connection, keycodes_per_modifier, keycodes);
  delete [] keycodes;
  return Undefined();
}

v8::Handle<v8::Value> GetModifierMapping(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: GetModifierMapping(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_get_modifier_mapping(XCBJS::Config::connection);
  return Undefined();
}

v8::Handle<v8::Value> NoOperation(const v8::Arguments& args) {
  v8::HandleScope scope;
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: NoOperation(cb)";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  xcb_no_operation(XCBJS::Config::connection);
  return Undefined();
}

// END REQUESTS } } }

static v8::Persistent<v8::Object> lookup = v8::Persistent<v8::Object>::New(v8::Object::New());

v8::Handle<v8::String> Docs(v8::Handle<v8::String> what) {
  v8::HandleScope scope;
  return scope.Close(v8::Handle<v8::String>::Cast(lookup->Get(what)));
}


void Init(v8::Persistent<v8::Object> reqs) {
  NODE_SET_METHOD(reqs, "CreateWindow", CreateWindow);
  lookup->Set(v8::String::New("CreateWindow"), v8::String::New("REQUEST -> CreateWindow({ depth: Integer\n, wid: Integer\n, parent: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, border_width: Integer\n, class: Integer\n, visual: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ChangeWindowAttributes", ChangeWindowAttributes);
  lookup->Set(v8::String::New("ChangeWindowAttributes"), v8::String::New("REQUEST -> ChangeWindowAttributes({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetWindowAttributes", GetWindowAttributes);
  lookup->Set(v8::String::New("GetWindowAttributes"), v8::String::New("REQUEST -> GetWindowAttributes({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "DestroyWindow", DestroyWindow);
  lookup->Set(v8::String::New("DestroyWindow"), v8::String::New("REQUEST -> DestroyWindow({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "DestroySubwindows", DestroySubwindows);
  lookup->Set(v8::String::New("DestroySubwindows"), v8::String::New("REQUEST -> DestroySubwindows({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ChangeSaveSet", ChangeSaveSet);
  lookup->Set(v8::String::New("ChangeSaveSet"), v8::String::New("REQUEST -> ChangeSaveSet({ mode: Integer\n, window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ReparentWindow", ReparentWindow);
  lookup->Set(v8::String::New("ReparentWindow"), v8::String::New("REQUEST -> ReparentWindow({ window: Integer\n, parent: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "MapWindow", MapWindow);
  lookup->Set(v8::String::New("MapWindow"), v8::String::New("REQUEST -> MapWindow({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "MapSubwindows", MapSubwindows);
  lookup->Set(v8::String::New("MapSubwindows"), v8::String::New("REQUEST -> MapSubwindows({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "UnmapWindow", UnmapWindow);
  lookup->Set(v8::String::New("UnmapWindow"), v8::String::New("REQUEST -> UnmapWindow({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "UnmapSubwindows", UnmapSubwindows);
  lookup->Set(v8::String::New("UnmapSubwindows"), v8::String::New("REQUEST -> UnmapSubwindows({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ConfigureWindow", ConfigureWindow);
  lookup->Set(v8::String::New("ConfigureWindow"), v8::String::New("REQUEST -> ConfigureWindow({ window: Integer\n, value_mask: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CirculateWindow", CirculateWindow);
  lookup->Set(v8::String::New("CirculateWindow"), v8::String::New("REQUEST -> CirculateWindow({ direction: Integer\n, window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetGeometry", GetGeometry);
  lookup->Set(v8::String::New("GetGeometry"), v8::String::New("REQUEST -> GetGeometry({ drawable: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "QueryTree", QueryTree);
  lookup->Set(v8::String::New("QueryTree"), v8::String::New("REQUEST -> QueryTree({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "InternAtom", InternAtom);
  lookup->Set(v8::String::New("InternAtom"), v8::String::New("REQUEST -> InternAtom({ only_if_exists: Boolean\n, name_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetAtomName", GetAtomName);
  lookup->Set(v8::String::New("GetAtomName"), v8::String::New("REQUEST -> GetAtomName({ atom: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ChangeProperty", ChangeProperty);
  lookup->Set(v8::String::New("ChangeProperty"), v8::String::New("REQUEST -> ChangeProperty({ mode: Integer\n, window: Integer\n, property: Integer\n, type: Integer\n, format: Integer\n, data_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "DeleteProperty", DeleteProperty);
  lookup->Set(v8::String::New("DeleteProperty"), v8::String::New("REQUEST -> DeleteProperty({ window: Integer\n, property: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetProperty", GetProperty);
  lookup->Set(v8::String::New("GetProperty"), v8::String::New("REQUEST -> GetProperty({ delete: Boolean\n, window: Integer\n, property: Integer\n, type: Integer\n, long_offset: Integer\n, long_length: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ListProperties", ListProperties);
  lookup->Set(v8::String::New("ListProperties"), v8::String::New("REQUEST -> ListProperties({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SetSelectionOwner", SetSelectionOwner);
  lookup->Set(v8::String::New("SetSelectionOwner"), v8::String::New("REQUEST -> SetSelectionOwner({ owner: Integer\n, selection: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetSelectionOwner", GetSelectionOwner);
  lookup->Set(v8::String::New("GetSelectionOwner"), v8::String::New("REQUEST -> GetSelectionOwner({ selection: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ConvertSelection", ConvertSelection);
  lookup->Set(v8::String::New("ConvertSelection"), v8::String::New("REQUEST -> ConvertSelection({ requestor: Integer\n, selection: Integer\n, target: Integer\n, property: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SendEvent", SendEvent);
  lookup->Set(v8::String::New("SendEvent"), v8::String::New("REQUEST -> SendEvent({ propagate: Boolean\n, destination: Integer\n, event_mask: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GrabPointer", GrabPointer);
  lookup->Set(v8::String::New("GrabPointer"), v8::String::New("REQUEST -> GrabPointer({ owner_events: Boolean\n, grab_window: Integer\n, event_mask: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer\n, confine_to: Integer\n, cursor: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "UngrabPointer", UngrabPointer);
  lookup->Set(v8::String::New("UngrabPointer"), v8::String::New("REQUEST -> UngrabPointer({ time: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GrabButton", GrabButton);
  lookup->Set(v8::String::New("GrabButton"), v8::String::New("REQUEST -> GrabButton({ owner_events: Boolean\n, grab_window: Integer\n, event_mask: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer\n, confine_to: Integer\n, cursor: Integer\n, button: Integer\n, modifiers: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "UngrabButton", UngrabButton);
  lookup->Set(v8::String::New("UngrabButton"), v8::String::New("REQUEST -> UngrabButton({ button: Integer\n, grab_window: Integer\n, modifiers: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ChangeActivePointerGrab", ChangeActivePointerGrab);
  lookup->Set(v8::String::New("ChangeActivePointerGrab"), v8::String::New("REQUEST -> ChangeActivePointerGrab({ cursor: Integer\n, time: Integer\n, event_mask: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GrabKeyboard", GrabKeyboard);
  lookup->Set(v8::String::New("GrabKeyboard"), v8::String::New("REQUEST -> GrabKeyboard({ owner_events: Boolean\n, grab_window: Integer\n, time: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "UngrabKeyboard", UngrabKeyboard);
  lookup->Set(v8::String::New("UngrabKeyboard"), v8::String::New("REQUEST -> UngrabKeyboard({ time: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GrabKey", GrabKey);
  lookup->Set(v8::String::New("GrabKey"), v8::String::New("REQUEST -> GrabKey({ owner_events: Boolean\n, grab_window: Integer\n, modifiers: Integer\n, key: Integer\n, pointer_mode: Integer\n, keyboard_mode: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "UngrabKey", UngrabKey);
  lookup->Set(v8::String::New("UngrabKey"), v8::String::New("REQUEST -> UngrabKey({ key: Integer\n, grab_window: Integer\n, modifiers: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "AllowEvents", AllowEvents);
  lookup->Set(v8::String::New("AllowEvents"), v8::String::New("REQUEST -> AllowEvents({ mode: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GrabServer", GrabServer);
  lookup->Set(v8::String::New("GrabServer"), v8::String::New("REQUEST -> GrabServer(cb)")); 
  NODE_SET_METHOD(reqs, "UngrabServer", UngrabServer);
  lookup->Set(v8::String::New("UngrabServer"), v8::String::New("REQUEST -> UngrabServer(cb)")); 
  NODE_SET_METHOD(reqs, "QueryPointer", QueryPointer);
  lookup->Set(v8::String::New("QueryPointer"), v8::String::New("REQUEST -> QueryPointer({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetMotionEvents", GetMotionEvents);
  lookup->Set(v8::String::New("GetMotionEvents"), v8::String::New("REQUEST -> GetMotionEvents({ window: Integer\n, start: Integer\n, stop: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "TranslateCoordinates", TranslateCoordinates);
  lookup->Set(v8::String::New("TranslateCoordinates"), v8::String::New("REQUEST -> TranslateCoordinates({ src_window: Integer\n, dst_window: Integer\n, src_x: Integer\n, src_y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "WarpPointer", WarpPointer);
  lookup->Set(v8::String::New("WarpPointer"), v8::String::New("REQUEST -> WarpPointer({ src_window: Integer\n, dst_window: Integer\n, src_x: Integer\n, src_y: Integer\n, src_width: Integer\n, src_height: Integer\n, dst_x: Integer\n, dst_y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SetInputFocus", SetInputFocus);
  lookup->Set(v8::String::New("SetInputFocus"), v8::String::New("REQUEST -> SetInputFocus({ revert_to: Integer\n, focus: Integer\n, time: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetInputFocus", GetInputFocus);
  lookup->Set(v8::String::New("GetInputFocus"), v8::String::New("REQUEST -> GetInputFocus(cb)")); 
  NODE_SET_METHOD(reqs, "QueryKeymap", QueryKeymap);
  lookup->Set(v8::String::New("QueryKeymap"), v8::String::New("REQUEST -> QueryKeymap(cb)")); 
  NODE_SET_METHOD(reqs, "OpenFont", OpenFont);
  lookup->Set(v8::String::New("OpenFont"), v8::String::New("REQUEST -> OpenFont({ fid: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CloseFont", CloseFont);
  lookup->Set(v8::String::New("CloseFont"), v8::String::New("REQUEST -> CloseFont({ font: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "QueryFont", QueryFont);
  lookup->Set(v8::String::New("QueryFont"), v8::String::New("REQUEST -> QueryFont({ font: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "QueryTextExtents", QueryTextExtents);
  lookup->Set(v8::String::New("QueryTextExtents"), v8::String::New("REQUEST -> QueryTextExtents({ font: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ListFonts", ListFonts);
  lookup->Set(v8::String::New("ListFonts"), v8::String::New("REQUEST -> ListFonts({ max_names: Integer\n, pattern_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ListFontsWithInfo", ListFontsWithInfo);
  lookup->Set(v8::String::New("ListFontsWithInfo"), v8::String::New("REQUEST -> ListFontsWithInfo({ max_names: Integer\n, pattern_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SetFontPath", SetFontPath);
  lookup->Set(v8::String::New("SetFontPath"), v8::String::New("REQUEST -> SetFontPath({ font_qty: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetFontPath", GetFontPath);
  lookup->Set(v8::String::New("GetFontPath"), v8::String::New("REQUEST -> GetFontPath(cb)")); 
  NODE_SET_METHOD(reqs, "CreatePixmap", CreatePixmap);
  lookup->Set(v8::String::New("CreatePixmap"), v8::String::New("REQUEST -> CreatePixmap({ depth: Integer\n, pid: Integer\n, drawable: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "FreePixmap", FreePixmap);
  lookup->Set(v8::String::New("FreePixmap"), v8::String::New("REQUEST -> FreePixmap({ pixmap: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CreateGC", CreateGC);
  lookup->Set(v8::String::New("CreateGC"), v8::String::New("REQUEST -> CreateGC({ cid: Integer\n, drawable: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ChangeGC", ChangeGC);
  lookup->Set(v8::String::New("ChangeGC"), v8::String::New("REQUEST -> ChangeGC({ gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CopyGC", CopyGC);
  lookup->Set(v8::String::New("CopyGC"), v8::String::New("REQUEST -> CopyGC({ src_gc: Integer\n, dst_gc: Integer\n, value_mask: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SetDashes", SetDashes);
  lookup->Set(v8::String::New("SetDashes"), v8::String::New("REQUEST -> SetDashes({ gc: Integer\n, dash_offset: Integer\n, dashes_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SetClipRectangles", SetClipRectangles);
  lookup->Set(v8::String::New("SetClipRectangles"), v8::String::New("REQUEST -> SetClipRectangles({ ordering: Integer\n, gc: Integer\n, clip_x_origin: Integer\n, clip_y_origin: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "FreeGC", FreeGC);
  lookup->Set(v8::String::New("FreeGC"), v8::String::New("REQUEST -> FreeGC({ gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ClearArea", ClearArea);
  lookup->Set(v8::String::New("ClearArea"), v8::String::New("REQUEST -> ClearArea({ exposures: Boolean\n, window: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CopyArea", CopyArea);
  lookup->Set(v8::String::New("CopyArea"), v8::String::New("REQUEST -> CopyArea({ src_drawable: Integer\n, dst_drawable: Integer\n, gc: Integer\n, src_x: Integer\n, src_y: Integer\n, dst_x: Integer\n, dst_y: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CopyPlane", CopyPlane);
  lookup->Set(v8::String::New("CopyPlane"), v8::String::New("REQUEST -> CopyPlane({ src_drawable: Integer\n, dst_drawable: Integer\n, gc: Integer\n, src_x: Integer\n, src_y: Integer\n, dst_x: Integer\n, dst_y: Integer\n, width: Integer\n, height: Integer\n, bit_plane: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyPoint", PolyPoint);
  lookup->Set(v8::String::New("PolyPoint"), v8::String::New("REQUEST -> PolyPoint({ coordinate_mode: Integer\n, drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyLine", PolyLine);
  lookup->Set(v8::String::New("PolyLine"), v8::String::New("REQUEST -> PolyLine({ coordinate_mode: Integer\n, drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolySegment", PolySegment);
  lookup->Set(v8::String::New("PolySegment"), v8::String::New("REQUEST -> PolySegment({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyRectangle", PolyRectangle);
  lookup->Set(v8::String::New("PolyRectangle"), v8::String::New("REQUEST -> PolyRectangle({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyArc", PolyArc);
  lookup->Set(v8::String::New("PolyArc"), v8::String::New("REQUEST -> PolyArc({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "FillPoly", FillPoly);
  lookup->Set(v8::String::New("FillPoly"), v8::String::New("REQUEST -> FillPoly({ drawable: Integer\n, gc: Integer\n, shape: Integer\n, coordinate_mode: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyFillRectangle", PolyFillRectangle);
  lookup->Set(v8::String::New("PolyFillRectangle"), v8::String::New("REQUEST -> PolyFillRectangle({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyFillArc", PolyFillArc);
  lookup->Set(v8::String::New("PolyFillArc"), v8::String::New("REQUEST -> PolyFillArc({ drawable: Integer\n, gc: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PutImage", PutImage);
  lookup->Set(v8::String::New("PutImage"), v8::String::New("REQUEST -> PutImage({ format: Integer\n, drawable: Integer\n, gc: Integer\n, width: Integer\n, height: Integer\n, dst_x: Integer\n, dst_y: Integer\n, left_pad: Integer\n, depth: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetImage", GetImage);
  lookup->Set(v8::String::New("GetImage"), v8::String::New("REQUEST -> GetImage({ format: Integer\n, drawable: Integer\n, x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, plane_mask: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyText8", PolyText8);
  lookup->Set(v8::String::New("PolyText8"), v8::String::New("REQUEST -> PolyText8({ drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "PolyText16", PolyText16);
  lookup->Set(v8::String::New("PolyText16"), v8::String::New("REQUEST -> PolyText16({ drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ImageText8", ImageText8);
  lookup->Set(v8::String::New("ImageText8"), v8::String::New("REQUEST -> ImageText8({ string_len: Integer\n, drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ImageText16", ImageText16);
  lookup->Set(v8::String::New("ImageText16"), v8::String::New("REQUEST -> ImageText16({ string_len: Integer\n, drawable: Integer\n, gc: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CreateColormap", CreateColormap);
  lookup->Set(v8::String::New("CreateColormap"), v8::String::New("REQUEST -> CreateColormap({ alloc: Integer\n, mid: Integer\n, window: Integer\n, visual: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "FreeColormap", FreeColormap);
  lookup->Set(v8::String::New("FreeColormap"), v8::String::New("REQUEST -> FreeColormap({ cmap: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CopyColormapAndFree", CopyColormapAndFree);
  lookup->Set(v8::String::New("CopyColormapAndFree"), v8::String::New("REQUEST -> CopyColormapAndFree({ mid: Integer\n, src_cmap: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "InstallColormap", InstallColormap);
  lookup->Set(v8::String::New("InstallColormap"), v8::String::New("REQUEST -> InstallColormap({ cmap: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "UninstallColormap", UninstallColormap);
  lookup->Set(v8::String::New("UninstallColormap"), v8::String::New("REQUEST -> UninstallColormap({ cmap: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ListInstalledColormaps", ListInstalledColormaps);
  lookup->Set(v8::String::New("ListInstalledColormaps"), v8::String::New("REQUEST -> ListInstalledColormaps({ window: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "AllocColor", AllocColor);
  lookup->Set(v8::String::New("AllocColor"), v8::String::New("REQUEST -> AllocColor({ cmap: Integer\n, red: Integer\n, green: Integer\n, blue: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "AllocNamedColor", AllocNamedColor);
  lookup->Set(v8::String::New("AllocNamedColor"), v8::String::New("REQUEST -> AllocNamedColor({ cmap: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "AllocColorCells", AllocColorCells);
  lookup->Set(v8::String::New("AllocColorCells"), v8::String::New("REQUEST -> AllocColorCells({ contiguous: Boolean\n, cmap: Integer\n, colors: Integer\n, planes: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "AllocColorPlanes", AllocColorPlanes);
  lookup->Set(v8::String::New("AllocColorPlanes"), v8::String::New("REQUEST -> AllocColorPlanes({ contiguous: Boolean\n, cmap: Integer\n, colors: Integer\n, reds: Integer\n, greens: Integer\n, blues: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "FreeColors", FreeColors);
  lookup->Set(v8::String::New("FreeColors"), v8::String::New("REQUEST -> FreeColors({ cmap: Integer\n, plane_mask: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "StoreColors", StoreColors);
  lookup->Set(v8::String::New("StoreColors"), v8::String::New("REQUEST -> StoreColors({ cmap: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "StoreNamedColor", StoreNamedColor);
  lookup->Set(v8::String::New("StoreNamedColor"), v8::String::New("REQUEST -> StoreNamedColor({ flags: Integer\n, cmap: Integer\n, pixel: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "QueryColors", QueryColors);
  lookup->Set(v8::String::New("QueryColors"), v8::String::New("REQUEST -> QueryColors({ cmap: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "LookupColor", LookupColor);
  lookup->Set(v8::String::New("LookupColor"), v8::String::New("REQUEST -> LookupColor({ cmap: Integer\n, name_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CreateCursor", CreateCursor);
  lookup->Set(v8::String::New("CreateCursor"), v8::String::New("REQUEST -> CreateCursor({ cid: Integer\n, source: Integer\n, mask: Integer\n, fore_red: Integer\n, fore_green: Integer\n, fore_blue: Integer\n, back_red: Integer\n, back_green: Integer\n, back_blue: Integer\n, x: Integer\n, y: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "CreateGlyphCursor", CreateGlyphCursor);
  lookup->Set(v8::String::New("CreateGlyphCursor"), v8::String::New("REQUEST -> CreateGlyphCursor({ cid: Integer\n, source_font: Integer\n, mask_font: Integer\n, source_char: Integer\n, mask_char: Integer\n, fore_red: Integer\n, fore_green: Integer\n, fore_blue: Integer\n, back_red: Integer\n, back_green: Integer\n, back_blue: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "FreeCursor", FreeCursor);
  lookup->Set(v8::String::New("FreeCursor"), v8::String::New("REQUEST -> FreeCursor({ cursor: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "RecolorCursor", RecolorCursor);
  lookup->Set(v8::String::New("RecolorCursor"), v8::String::New("REQUEST -> RecolorCursor({ cursor: Integer\n, fore_red: Integer\n, fore_green: Integer\n, fore_blue: Integer\n, back_red: Integer\n, back_green: Integer\n, back_blue: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "QueryBestSize", QueryBestSize);
  lookup->Set(v8::String::New("QueryBestSize"), v8::String::New("REQUEST -> QueryBestSize({ class: Integer\n, drawable: Integer\n, width: Integer\n, height: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "QueryExtension", QueryExtension);
  lookup->Set(v8::String::New("QueryExtension"), v8::String::New("REQUEST -> QueryExtension({ name_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ListExtensions", ListExtensions);
  lookup->Set(v8::String::New("ListExtensions"), v8::String::New("REQUEST -> ListExtensions(cb)")); 
  NODE_SET_METHOD(reqs, "ChangeKeyboardMapping", ChangeKeyboardMapping);
  lookup->Set(v8::String::New("ChangeKeyboardMapping"), v8::String::New("REQUEST -> ChangeKeyboardMapping({ keycode_count: Integer\n, first_keycode: Integer\n, keysyms_per_keycode: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetKeyboardMapping", GetKeyboardMapping);
  lookup->Set(v8::String::New("GetKeyboardMapping"), v8::String::New("REQUEST -> GetKeyboardMapping({ first_keycode: Integer\n, count: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ChangeKeyboardControl", ChangeKeyboardControl);
  lookup->Set(v8::String::New("ChangeKeyboardControl"), v8::String::New("REQUEST -> ChangeKeyboardControl({  }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetKeyboardControl", GetKeyboardControl);
  lookup->Set(v8::String::New("GetKeyboardControl"), v8::String::New("REQUEST -> GetKeyboardControl(cb)")); 
  NODE_SET_METHOD(reqs, "Bell", Bell);
  lookup->Set(v8::String::New("Bell"), v8::String::New("REQUEST -> Bell({ percent: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ChangePointerControl", ChangePointerControl);
  lookup->Set(v8::String::New("ChangePointerControl"), v8::String::New("REQUEST -> ChangePointerControl({ acceleration_numerator: Integer\n, acceleration_denominator: Integer\n, threshold: Integer\n, do_acceleration: Boolean\n, do_threshold: Boolean }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetPointerControl", GetPointerControl);
  lookup->Set(v8::String::New("GetPointerControl"), v8::String::New("REQUEST -> GetPointerControl(cb)")); 
  NODE_SET_METHOD(reqs, "SetScreenSaver", SetScreenSaver);
  lookup->Set(v8::String::New("SetScreenSaver"), v8::String::New("REQUEST -> SetScreenSaver({ timeout: Integer\n, interval: Integer\n, prefer_blanking: Integer\n, allow_exposures: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetScreenSaver", GetScreenSaver);
  lookup->Set(v8::String::New("GetScreenSaver"), v8::String::New("REQUEST -> GetScreenSaver(cb)")); 
  NODE_SET_METHOD(reqs, "ChangeHosts", ChangeHosts);
  lookup->Set(v8::String::New("ChangeHosts"), v8::String::New("REQUEST -> ChangeHosts({ mode: Integer\n, family: Integer\n, address_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ListHosts", ListHosts);
  lookup->Set(v8::String::New("ListHosts"), v8::String::New("REQUEST -> ListHosts(cb)")); 
  NODE_SET_METHOD(reqs, "SetAccessControl", SetAccessControl);
  lookup->Set(v8::String::New("SetAccessControl"), v8::String::New("REQUEST -> SetAccessControl({ mode: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SetCloseDownMode", SetCloseDownMode);
  lookup->Set(v8::String::New("SetCloseDownMode"), v8::String::New("REQUEST -> SetCloseDownMode({ mode: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "KillClient", KillClient);
  lookup->Set(v8::String::New("KillClient"), v8::String::New("REQUEST -> KillClient({ resource: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "RotateProperties", RotateProperties);
  lookup->Set(v8::String::New("RotateProperties"), v8::String::New("REQUEST -> RotateProperties({ window: Integer\n, atoms_len: Integer\n, delta: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "ForceScreenSaver", ForceScreenSaver);
  lookup->Set(v8::String::New("ForceScreenSaver"), v8::String::New("REQUEST -> ForceScreenSaver({ mode: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "SetPointerMapping", SetPointerMapping);
  lookup->Set(v8::String::New("SetPointerMapping"), v8::String::New("REQUEST -> SetPointerMapping({ map_len: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetPointerMapping", GetPointerMapping);
  lookup->Set(v8::String::New("GetPointerMapping"), v8::String::New("REQUEST -> GetPointerMapping(cb)")); 
  NODE_SET_METHOD(reqs, "SetModifierMapping", SetModifierMapping);
  lookup->Set(v8::String::New("SetModifierMapping"), v8::String::New("REQUEST -> SetModifierMapping({ keycodes_per_modifier: Integer }[, cb])")); 
  NODE_SET_METHOD(reqs, "GetModifierMapping", GetModifierMapping);
  lookup->Set(v8::String::New("GetModifierMapping"), v8::String::New("REQUEST -> GetModifierMapping(cb)")); 
  NODE_SET_METHOD(reqs, "NoOperation", NoOperation);
  lookup->Set(v8::String::New("NoOperation"), v8::String::New("REQUEST -> NoOperation(cb)")); 
}

  }
}

#endif