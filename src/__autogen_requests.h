#ifndef __AUTOGENCTOJSXCBREQUESTS__
#define __AUTOGENCTOJSXCBREQUESTS__
#include <v8.h>

#include <config.h>

//{{{ BEGIN REQUESTS 

void xcbReqCreateWindow(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
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
	v8::Local<v8::Array> maskarr = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
	value_list = new uint32_t[maskarr->Length()];
	for(unsigned int i = 0; i < maskarr->Length(); ++i) {
		value_list[i] = (uint32_t) maskarr->Get(i)->IntegerValue();
	}
	xcb_create_window(XCBJS::Config::connection, depth, wid, parent, x, y, width, height, border_width, _class, visual, value_mask, value_list);
	delete [] value_list;
}

void xcbReqChangeWindowAttributes(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
	uint32_t *value_list;
	v8::Local<v8::Array> maskarr = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
	value_list = new uint32_t[maskarr->Length()];
	for(unsigned int i = 0; i < maskarr->Length(); ++i) {
		value_list[i] = (uint32_t) maskarr->Get(i)->IntegerValue();
	}
	xcb_change_window_attributes(XCBJS::Config::connection, window, value_mask, value_list);
	delete [] value_list;
}

void xcbReqGetWindowAttributes(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_get_window_attributes(XCBJS::Config::connection, window);
}

void xcbReqDestroyWindow(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_destroy_window(XCBJS::Config::connection, window);
}

void xcbReqDestroySubwindows(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_destroy_subwindows(XCBJS::Config::connection, window);
}

void xcbReqChangeSaveSet(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_change_save_set(XCBJS::Config::connection, mode, window);
}

void xcbReqReparentWindow(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_window_t parent = (xcb_window_t) obj->Get(v8::String::New("parent"))->IntegerValue();
	int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
	int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
	xcb_reparent_window(XCBJS::Config::connection, window, parent, x, y);
}

void xcbReqMapWindow(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_map_window(XCBJS::Config::connection, window);
}

void xcbReqMapSubwindows(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_map_subwindows(XCBJS::Config::connection, window);
}

void xcbReqUnmapWindow(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_unmap_window(XCBJS::Config::connection, window);
}

void xcbReqUnmapSubwindows(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_unmap_subwindows(XCBJS::Config::connection, window);
}

void xcbReqConfigureWindow(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	uint16_t value_mask = (uint16_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
	uint32_t *value_list;
	v8::Local<v8::Array> maskarr = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
	value_list = new uint32_t[maskarr->Length()];
	for(unsigned int i = 0; i < maskarr->Length(); ++i) {
		value_list[i] = (uint32_t) maskarr->Get(i)->IntegerValue();
	}
	xcb_configure_window(XCBJS::Config::connection, window, value_mask, value_list);
	delete [] value_list;
}

void xcbReqCirculateWindow(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t direction = (uint8_t) obj->Get(v8::String::New("direction"))->IntegerValue();
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_circulate_window(XCBJS::Config::connection, direction, window);
}

void xcbReqGetGeometry(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
	xcb_get_geometry(XCBJS::Config::connection, drawable);
}

void xcbReqQueryTree(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_query_tree(XCBJS::Config::connection, window);
}

void xcbReqGetAtomName(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_atom_t atom = (xcb_atom_t) obj->Get(v8::String::New("atom"))->IntegerValue();
	xcb_get_atom_name(XCBJS::Config::connection, atom);
}

void xcbReqDeleteProperty(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
	xcb_delete_property(XCBJS::Config::connection, window, property);
}

void xcbReqGetProperty(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t _delete = (uint8_t) obj->Get(v8::String::New("delete"))->BooleanValue();
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
	xcb_atom_t type = (xcb_atom_t) obj->Get(v8::String::New("type"))->IntegerValue();
	uint32_t long_offset = (uint32_t) obj->Get(v8::String::New("long_offset"))->IntegerValue();
	uint32_t long_length = (uint32_t) obj->Get(v8::String::New("long_length"))->IntegerValue();
	xcb_get_property(XCBJS::Config::connection, _delete, window, property, type, long_offset, long_length);
}

void xcbReqListProperties(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_list_properties(XCBJS::Config::connection, window);
}

void xcbReqSetSelectionOwner(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t owner = (xcb_window_t) obj->Get(v8::String::New("owner"))->IntegerValue();
	xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	xcb_set_selection_owner(XCBJS::Config::connection, owner, selection, time);
}

void xcbReqGetSelectionOwner(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
	xcb_get_selection_owner(XCBJS::Config::connection, selection);
}

void xcbReqConvertSelection(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t requestor = (xcb_window_t) obj->Get(v8::String::New("requestor"))->IntegerValue();
	xcb_atom_t selection = (xcb_atom_t) obj->Get(v8::String::New("selection"))->IntegerValue();
	xcb_atom_t target = (xcb_atom_t) obj->Get(v8::String::New("target"))->IntegerValue();
	xcb_atom_t property = (xcb_atom_t) obj->Get(v8::String::New("property"))->IntegerValue();
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	xcb_convert_selection(XCBJS::Config::connection, requestor, selection, target, property, time);
}

void xcbReqGrabPointer(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
	xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
	uint16_t event_mask = (uint16_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
	uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
	uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
	xcb_window_t confine_to = (xcb_window_t) obj->Get(v8::String::New("confine_to"))->IntegerValue();
	xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	xcb_grab_pointer(XCBJS::Config::connection, owner_events, grab_window, event_mask, pointer_mode, keyboard_mode, confine_to, cursor, time);
}

void xcbReqUngrabPointer(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	xcb_ungrab_pointer(XCBJS::Config::connection, time);
}

void xcbReqGrabButton(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
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
}

void xcbReqUngrabButton(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t button = (uint8_t) obj->Get(v8::String::New("button"))->IntegerValue();
	xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
	uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
	xcb_ungrab_button(XCBJS::Config::connection, button, grab_window, modifiers);
}

void xcbReqChangeActivePointerGrab(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	uint16_t event_mask = (uint16_t) obj->Get(v8::String::New("event_mask"))->IntegerValue();
	xcb_change_active_pointer_grab(XCBJS::Config::connection, cursor, time, event_mask);
}

void xcbReqGrabKeyboard(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
	xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
	uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
	xcb_grab_keyboard(XCBJS::Config::connection, owner_events, grab_window, time, pointer_mode, keyboard_mode);
}

void xcbReqUngrabKeyboard(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	xcb_ungrab_keyboard(XCBJS::Config::connection, time);
}

void xcbReqGrabKey(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t owner_events = (uint8_t) obj->Get(v8::String::New("owner_events"))->BooleanValue();
	xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
	uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
	xcb_keycode_t key = (xcb_keycode_t) obj->Get(v8::String::New("key"))->IntegerValue();
	uint8_t pointer_mode = (uint8_t) obj->Get(v8::String::New("pointer_mode"))->IntegerValue();
	uint8_t keyboard_mode = (uint8_t) obj->Get(v8::String::New("keyboard_mode"))->IntegerValue();
	xcb_grab_key(XCBJS::Config::connection, owner_events, grab_window, modifiers, key, pointer_mode, keyboard_mode);
}

void xcbReqUngrabKey(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_keycode_t key = (xcb_keycode_t) obj->Get(v8::String::New("key"))->IntegerValue();
	xcb_window_t grab_window = (xcb_window_t) obj->Get(v8::String::New("grab_window"))->IntegerValue();
	uint16_t modifiers = (uint16_t) obj->Get(v8::String::New("modifiers"))->IntegerValue();
	xcb_ungrab_key(XCBJS::Config::connection, key, grab_window, modifiers);
}

void xcbReqAllowEvents(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	xcb_allow_events(XCBJS::Config::connection, mode, time);
}

void xcbReqGrabServer(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_grab_server(XCBJS::Config::connection);
}

void xcbReqUngrabServer(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_ungrab_server(XCBJS::Config::connection);
}

void xcbReqQueryPointer(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_query_pointer(XCBJS::Config::connection, window);
}

void xcbReqGetMotionEvents(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_timestamp_t start = (xcb_timestamp_t) obj->Get(v8::String::New("start"))->IntegerValue();
	xcb_timestamp_t stop = (xcb_timestamp_t) obj->Get(v8::String::New("stop"))->IntegerValue();
	xcb_get_motion_events(XCBJS::Config::connection, window, start, stop);
}

void xcbReqTranslateCoordinates(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t src_window = (xcb_window_t) obj->Get(v8::String::New("src_window"))->IntegerValue();
	xcb_window_t dst_window = (xcb_window_t) obj->Get(v8::String::New("dst_window"))->IntegerValue();
	int16_t src_x = (int16_t) obj->Get(v8::String::New("src_x"))->IntegerValue();
	int16_t src_y = (int16_t) obj->Get(v8::String::New("src_y"))->IntegerValue();
	xcb_translate_coordinates(XCBJS::Config::connection, src_window, dst_window, src_x, src_y);
}

void xcbReqWarpPointer(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t src_window = (xcb_window_t) obj->Get(v8::String::New("src_window"))->IntegerValue();
	xcb_window_t dst_window = (xcb_window_t) obj->Get(v8::String::New("dst_window"))->IntegerValue();
	int16_t src_x = (int16_t) obj->Get(v8::String::New("src_x"))->IntegerValue();
	int16_t src_y = (int16_t) obj->Get(v8::String::New("src_y"))->IntegerValue();
	uint16_t src_width = (uint16_t) obj->Get(v8::String::New("src_width"))->IntegerValue();
	uint16_t src_height = (uint16_t) obj->Get(v8::String::New("src_height"))->IntegerValue();
	int16_t dst_x = (int16_t) obj->Get(v8::String::New("dst_x"))->IntegerValue();
	int16_t dst_y = (int16_t) obj->Get(v8::String::New("dst_y"))->IntegerValue();
	xcb_warp_pointer(XCBJS::Config::connection, src_window, dst_window, src_x, src_y, src_width, src_height, dst_x, dst_y);
}

void xcbReqSetInputFocus(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t revert_to = (uint8_t) obj->Get(v8::String::New("revert_to"))->IntegerValue();
	xcb_window_t focus = (xcb_window_t) obj->Get(v8::String::New("focus"))->IntegerValue();
	xcb_timestamp_t time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
	xcb_set_input_focus(XCBJS::Config::connection, revert_to, focus, time);
}

void xcbReqGetInputFocus(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_get_input_focus(XCBJS::Config::connection);
}

void xcbReqQueryKeymap(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_query_keymap(XCBJS::Config::connection);
}

void xcbReqCloseFont(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_font_t font = (xcb_font_t) obj->Get(v8::String::New("font"))->IntegerValue();
	xcb_close_font(XCBJS::Config::connection, font);
}

void xcbReqQueryFont(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_fontable_t font = (xcb_fontable_t) obj->Get(v8::String::New("font"))->IntegerValue();
	xcb_query_font(XCBJS::Config::connection, font);
}

void xcbReqGetFontPath(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_get_font_path(XCBJS::Config::connection);
}

void xcbReqCreatePixmap(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t depth = (uint8_t) obj->Get(v8::String::New("depth"))->IntegerValue();
	xcb_pixmap_t pid = (xcb_pixmap_t) obj->Get(v8::String::New("pid"))->IntegerValue();
	xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
	uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
	uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
	xcb_create_pixmap(XCBJS::Config::connection, depth, pid, drawable, width, height);
}

void xcbReqFreePixmap(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_pixmap_t pixmap = (xcb_pixmap_t) obj->Get(v8::String::New("pixmap"))->IntegerValue();
	xcb_free_pixmap(XCBJS::Config::connection, pixmap);
}

void xcbReqCreateGC(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_gcontext_t cid = (xcb_gcontext_t) obj->Get(v8::String::New("cid"))->IntegerValue();
	xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
	uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
	uint32_t *value_list;
	v8::Local<v8::Array> maskarr = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
	value_list = new uint32_t[maskarr->Length()];
	for(unsigned int i = 0; i < maskarr->Length(); ++i) {
		value_list[i] = (uint32_t) maskarr->Get(i)->IntegerValue();
	}
	xcb_create_gc(XCBJS::Config::connection, cid, drawable, value_mask, value_list);
	delete [] value_list;
}

void xcbReqChangeGC(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
	uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
	uint32_t *value_list;
	v8::Local<v8::Array> maskarr = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
	value_list = new uint32_t[maskarr->Length()];
	for(unsigned int i = 0; i < maskarr->Length(); ++i) {
		value_list[i] = (uint32_t) maskarr->Get(i)->IntegerValue();
	}
	xcb_change_gc(XCBJS::Config::connection, gc, value_mask, value_list);
	delete [] value_list;
}

void xcbReqCopyGC(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_gcontext_t src_gc = (xcb_gcontext_t) obj->Get(v8::String::New("src_gc"))->IntegerValue();
	xcb_gcontext_t dst_gc = (xcb_gcontext_t) obj->Get(v8::String::New("dst_gc"))->IntegerValue();
	uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
	xcb_copy_gc(XCBJS::Config::connection, src_gc, dst_gc, value_mask);
}

void xcbReqFreeGC(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_gcontext_t gc = (xcb_gcontext_t) obj->Get(v8::String::New("gc"))->IntegerValue();
	xcb_free_gc(XCBJS::Config::connection, gc);
}

void xcbReqClearArea(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t exposures = (uint8_t) obj->Get(v8::String::New("exposures"))->BooleanValue();
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
	int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
	uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
	uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
	xcb_clear_area(XCBJS::Config::connection, exposures, window, x, y, width, height);
}

void xcbReqCopyArea(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
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
}

void xcbReqCopyPlane(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
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
}

void xcbReqGetImage(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t format = (uint8_t) obj->Get(v8::String::New("format"))->IntegerValue();
	xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
	int16_t x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
	int16_t y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
	uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
	uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
	uint32_t plane_mask = (uint32_t) obj->Get(v8::String::New("plane_mask"))->IntegerValue();
	xcb_get_image(XCBJS::Config::connection, format, drawable, x, y, width, height, plane_mask);
}

void xcbReqCreateColormap(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t alloc = (uint8_t) obj->Get(v8::String::New("alloc"))->IntegerValue();
	xcb_colormap_t mid = (xcb_colormap_t) obj->Get(v8::String::New("mid"))->IntegerValue();
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_visualid_t visual = (xcb_visualid_t) obj->Get(v8::String::New("visual"))->IntegerValue();
	xcb_create_colormap(XCBJS::Config::connection, alloc, mid, window, visual);
}

void xcbReqFreeColormap(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
	xcb_free_colormap(XCBJS::Config::connection, cmap);
}

void xcbReqCopyColormapAndFree(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_colormap_t mid = (xcb_colormap_t) obj->Get(v8::String::New("mid"))->IntegerValue();
	xcb_colormap_t src_cmap = (xcb_colormap_t) obj->Get(v8::String::New("src_cmap"))->IntegerValue();
	xcb_copy_colormap_and_free(XCBJS::Config::connection, mid, src_cmap);
}

void xcbReqInstallColormap(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
	xcb_install_colormap(XCBJS::Config::connection, cmap);
}

void xcbReqUninstallColormap(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
	xcb_uninstall_colormap(XCBJS::Config::connection, cmap);
}

void xcbReqListInstalledColormaps(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_window_t window = (xcb_window_t) obj->Get(v8::String::New("window"))->IntegerValue();
	xcb_list_installed_colormaps(XCBJS::Config::connection, window);
}

void xcbReqAllocColor(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
	uint16_t red = (uint16_t) obj->Get(v8::String::New("red"))->IntegerValue();
	uint16_t green = (uint16_t) obj->Get(v8::String::New("green"))->IntegerValue();
	uint16_t blue = (uint16_t) obj->Get(v8::String::New("blue"))->IntegerValue();
	xcb_alloc_color(XCBJS::Config::connection, cmap, red, green, blue);
}

void xcbReqAllocColorCells(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t contiguous = (uint8_t) obj->Get(v8::String::New("contiguous"))->BooleanValue();
	xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
	uint16_t colors = (uint16_t) obj->Get(v8::String::New("colors"))->IntegerValue();
	uint16_t planes = (uint16_t) obj->Get(v8::String::New("planes"))->IntegerValue();
	xcb_alloc_color_cells(XCBJS::Config::connection, contiguous, cmap, colors, planes);
}

void xcbReqAllocColorPlanes(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t contiguous = (uint8_t) obj->Get(v8::String::New("contiguous"))->BooleanValue();
	xcb_colormap_t cmap = (xcb_colormap_t) obj->Get(v8::String::New("cmap"))->IntegerValue();
	uint16_t colors = (uint16_t) obj->Get(v8::String::New("colors"))->IntegerValue();
	uint16_t reds = (uint16_t) obj->Get(v8::String::New("reds"))->IntegerValue();
	uint16_t greens = (uint16_t) obj->Get(v8::String::New("greens"))->IntegerValue();
	uint16_t blues = (uint16_t) obj->Get(v8::String::New("blues"))->IntegerValue();
	xcb_alloc_color_planes(XCBJS::Config::connection, contiguous, cmap, colors, reds, greens, blues);
}

void xcbReqCreateCursor(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
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
}

void xcbReqCreateGlyphCursor(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
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
}

void xcbReqFreeCursor(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
	xcb_free_cursor(XCBJS::Config::connection, cursor);
}

void xcbReqRecolorCursor(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_cursor_t cursor = (xcb_cursor_t) obj->Get(v8::String::New("cursor"))->IntegerValue();
	uint16_t fore_red = (uint16_t) obj->Get(v8::String::New("fore_red"))->IntegerValue();
	uint16_t fore_green = (uint16_t) obj->Get(v8::String::New("fore_green"))->IntegerValue();
	uint16_t fore_blue = (uint16_t) obj->Get(v8::String::New("fore_blue"))->IntegerValue();
	uint16_t back_red = (uint16_t) obj->Get(v8::String::New("back_red"))->IntegerValue();
	uint16_t back_green = (uint16_t) obj->Get(v8::String::New("back_green"))->IntegerValue();
	uint16_t back_blue = (uint16_t) obj->Get(v8::String::New("back_blue"))->IntegerValue();
	xcb_recolor_cursor(XCBJS::Config::connection, cursor, fore_red, fore_green, fore_blue, back_red, back_green, back_blue);
}

void xcbReqQueryBestSize(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t _class = (uint8_t) obj->Get(v8::String::New("class"))->IntegerValue();
	xcb_drawable_t drawable = (xcb_drawable_t) obj->Get(v8::String::New("drawable"))->IntegerValue();
	uint16_t width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
	uint16_t height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
	xcb_query_best_size(XCBJS::Config::connection, _class, drawable, width, height);
}

void xcbReqListExtensions(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_list_extensions(XCBJS::Config::connection);
}

void xcbReqGetKeyboardMapping(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_keycode_t first_keycode = (xcb_keycode_t) obj->Get(v8::String::New("first_keycode"))->IntegerValue();
	uint8_t count = (uint8_t) obj->Get(v8::String::New("count"))->IntegerValue();
	xcb_get_keyboard_mapping(XCBJS::Config::connection, first_keycode, count);
}

void xcbReqChangeKeyboardControl(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint32_t value_mask = (uint32_t) obj->Get(v8::String::New("value_mask"))->IntegerValue();
	uint32_t *value_list;
	v8::Local<v8::Array> maskarr = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("value_list")));
	value_list = new uint32_t[maskarr->Length()];
	for(unsigned int i = 0; i < maskarr->Length(); ++i) {
		value_list[i] = (uint32_t) maskarr->Get(i)->IntegerValue();
	}
	xcb_change_keyboard_control(XCBJS::Config::connection, value_mask, value_list);
	delete [] value_list;
}

void xcbReqGetKeyboardControl(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_get_keyboard_control(XCBJS::Config::connection);
}

void xcbReqBell(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	int8_t percent = (int8_t) obj->Get(v8::String::New("percent"))->IntegerValue();
	xcb_bell(XCBJS::Config::connection, percent);
}

void xcbReqChangePointerControl(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	int16_t acceleration_numerator = (int16_t) obj->Get(v8::String::New("acceleration_numerator"))->IntegerValue();
	int16_t acceleration_denominator = (int16_t) obj->Get(v8::String::New("acceleration_denominator"))->IntegerValue();
	int16_t threshold = (int16_t) obj->Get(v8::String::New("threshold"))->IntegerValue();
	uint8_t do_acceleration = (uint8_t) obj->Get(v8::String::New("do_acceleration"))->BooleanValue();
	uint8_t do_threshold = (uint8_t) obj->Get(v8::String::New("do_threshold"))->BooleanValue();
	xcb_change_pointer_control(XCBJS::Config::connection, acceleration_numerator, acceleration_denominator, threshold, do_acceleration, do_threshold);
}

void xcbReqGetPointerControl(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_get_pointer_control(XCBJS::Config::connection);
}

void xcbReqSetScreenSaver(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	int16_t timeout = (int16_t) obj->Get(v8::String::New("timeout"))->IntegerValue();
	int16_t interval = (int16_t) obj->Get(v8::String::New("interval"))->IntegerValue();
	uint8_t prefer_blanking = (uint8_t) obj->Get(v8::String::New("prefer_blanking"))->IntegerValue();
	uint8_t allow_exposures = (uint8_t) obj->Get(v8::String::New("allow_exposures"))->IntegerValue();
	xcb_set_screen_saver(XCBJS::Config::connection, timeout, interval, prefer_blanking, allow_exposures);
}

void xcbReqGetScreenSaver(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_get_screen_saver(XCBJS::Config::connection);
}

void xcbReqListHosts(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_list_hosts(XCBJS::Config::connection);
}

void xcbReqSetAccessControl(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
	xcb_set_access_control(XCBJS::Config::connection, mode);
}

void xcbReqSetCloseDownMode(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
	xcb_set_close_down_mode(XCBJS::Config::connection, mode);
}

void xcbReqKillClient(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint32_t resource = (uint32_t) obj->Get(v8::String::New("resource"))->IntegerValue();
	xcb_kill_client(XCBJS::Config::connection, resource);
}

void xcbReqForceScreenSaver(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	uint8_t mode = (uint8_t) obj->Get(v8::String::New("mode"))->IntegerValue();
	xcb_force_screen_saver(XCBJS::Config::connection, mode);
}

void xcbReqGetPointerMapping(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_get_pointer_mapping(XCBJS::Config::connection);
}

void xcbReqGetModifierMapping(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_get_modifier_mapping(XCBJS::Config::connection);
}

void xcbReqNoOperation(v8::Handle<v8::Object> obj) {
	v8::HandleScope scope;
	xcb_no_operation(XCBJS::Config::connection);
}

// END REQUESTS }}}

#endif
