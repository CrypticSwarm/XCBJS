#ifndef __AUTOGENCTOJSXCBSTRUCTS__
#define __AUTOGENCTOJSXCBSTRUCTS__
#include <v8.h>

//{ { { BEGIN STRUCTS

v8::Handle<v8::Object> toJS(xcb_char2b_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("byte1"), v8::Integer::New(st->byte1));
  obj->Set(v8::String::New("byte2"), v8::Integer::New(st->byte2));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_char2b_t *st) {
  v8::HandleScope scope;
  st->byte1 = (uint8_t) obj->Get(v8::String::New("byte1"))->IntegerValue();
  st->byte2 = (uint8_t) obj->Get(v8::String::New("byte2"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_point_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("x"), v8::Integer::New(st->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(st->y));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_point_t *st) {
  v8::HandleScope scope;
  st->x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  st->y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_rectangle_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("x"), v8::Integer::New(st->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(st->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(st->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(st->height));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_rectangle_t *st) {
  v8::HandleScope scope;
  st->x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  st->y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  st->width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  st->height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_arc_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("x"), v8::Integer::New(st->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(st->y));
  obj->Set(v8::String::New("width"), v8::Integer::New(st->width));
  obj->Set(v8::String::New("height"), v8::Integer::New(st->height));
  obj->Set(v8::String::New("angle1"), v8::Integer::New(st->angle1));
  obj->Set(v8::String::New("angle2"), v8::Integer::New(st->angle2));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_arc_t *st) {
  v8::HandleScope scope;
  st->x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  st->y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
  st->width = (uint16_t) obj->Get(v8::String::New("width"))->IntegerValue();
  st->height = (uint16_t) obj->Get(v8::String::New("height"))->IntegerValue();
  st->angle1 = (int16_t) obj->Get(v8::String::New("angle1"))->IntegerValue();
  st->angle2 = (int16_t) obj->Get(v8::String::New("angle2"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_format_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("depth"), v8::Integer::New(st->depth));
  obj->Set(v8::String::New("bits_per_pixel"), v8::Integer::New(st->bits_per_pixel));
  obj->Set(v8::String::New("scanline_pad"), v8::Integer::New(st->scanline_pad));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_format_t *st) {
  v8::HandleScope scope;
  st->depth = (uint8_t) obj->Get(v8::String::New("depth"))->IntegerValue();
  st->bits_per_pixel = (uint8_t) obj->Get(v8::String::New("bits_per_pixel"))->IntegerValue();
  st->scanline_pad = (uint8_t) obj->Get(v8::String::New("scanline_pad"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_visualtype_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("visual_id"), v8::Integer::New(st->visual_id));
  obj->Set(v8::String::New("class"), v8::Integer::New(st->_class));
  obj->Set(v8::String::New("bits_per_rgb_value"), v8::Integer::New(st->bits_per_rgb_value));
  obj->Set(v8::String::New("colormap_entries"), v8::Integer::New(st->colormap_entries));
  obj->Set(v8::String::New("red_mask"), v8::Integer::New(st->red_mask));
  obj->Set(v8::String::New("green_mask"), v8::Integer::New(st->green_mask));
  obj->Set(v8::String::New("blue_mask"), v8::Integer::New(st->blue_mask));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_visualtype_t *st) {
  v8::HandleScope scope;
  st->visual_id = (xcb_visualid_t) obj->Get(v8::String::New("visual_id"))->IntegerValue();
  st->_class = (uint8_t) obj->Get(v8::String::New("class"))->IntegerValue();
  st->bits_per_rgb_value = (uint8_t) obj->Get(v8::String::New("bits_per_rgb_value"))->IntegerValue();
  st->colormap_entries = (uint16_t) obj->Get(v8::String::New("colormap_entries"))->IntegerValue();
  st->red_mask = (uint32_t) obj->Get(v8::String::New("red_mask"))->IntegerValue();
  st->green_mask = (uint32_t) obj->Get(v8::String::New("green_mask"))->IntegerValue();
  st->blue_mask = (uint32_t) obj->Get(v8::String::New("blue_mask"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_depth_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("depth"), v8::Integer::New(st->depth));
  v8::Local<v8::Array> visuals_list = v8::Array::New();
  obj->Set(v8::String::New("visuals"), visuals_list);
  int ivisuals = 0;
  for(xcb_visualtype_iterator_t itr = xcb_depth_visuals_iterator(st); itr.rem; xcb_visualtype_next(&itr), ++ivisuals) {
    visuals_list->Set(ivisuals, toJS(itr.data));
  }
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_depth_t *st) {
  v8::HandleScope scope;
  st->depth = (uint8_t) obj->Get(v8::String::New("depth"))->IntegerValue();
  st->visuals_len = (uint16_t) obj->Get(v8::String::New("visuals_len"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_screen_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("root"), v8::Integer::New(st->root));
  obj->Set(v8::String::New("default_colormap"), v8::Integer::New(st->default_colormap));
  obj->Set(v8::String::New("white_pixel"), v8::Integer::New(st->white_pixel));
  obj->Set(v8::String::New("black_pixel"), v8::Integer::New(st->black_pixel));
  obj->Set(v8::String::New("current_input_masks"), v8::Integer::New(st->current_input_masks));
  obj->Set(v8::String::New("width_in_pixels"), v8::Integer::New(st->width_in_pixels));
  obj->Set(v8::String::New("height_in_pixels"), v8::Integer::New(st->height_in_pixels));
  obj->Set(v8::String::New("width_in_millimeters"), v8::Integer::New(st->width_in_millimeters));
  obj->Set(v8::String::New("height_in_millimeters"), v8::Integer::New(st->height_in_millimeters));
  obj->Set(v8::String::New("min_installed_maps"), v8::Integer::New(st->min_installed_maps));
  obj->Set(v8::String::New("max_installed_maps"), v8::Integer::New(st->max_installed_maps));
  obj->Set(v8::String::New("root_visual"), v8::Integer::New(st->root_visual));
  obj->Set(v8::String::New("backing_stores"), v8::Integer::New(st->backing_stores));
  obj->Set(v8::String::New("save_unders"), v8::Boolean::New(st->save_unders));
  obj->Set(v8::String::New("root_depth"), v8::Integer::New(st->root_depth));
  v8::Local<v8::Array> allowed_depths_list = v8::Array::New();
  obj->Set(v8::String::New("allowed_depths"), allowed_depths_list);
  int iallowed_depths = 0;
  for(xcb_depth_iterator_t itr = xcb_screen_allowed_depths_iterator(st); itr.rem; xcb_depth_next(&itr), ++iallowed_depths) {
    allowed_depths_list->Set(iallowed_depths, toJS(itr.data));
  }
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_screen_t *st) {
  v8::HandleScope scope;
  st->root = (xcb_window_t) obj->Get(v8::String::New("root"))->IntegerValue();
  st->default_colormap = (xcb_colormap_t) obj->Get(v8::String::New("default_colormap"))->IntegerValue();
  st->white_pixel = (uint32_t) obj->Get(v8::String::New("white_pixel"))->IntegerValue();
  st->black_pixel = (uint32_t) obj->Get(v8::String::New("black_pixel"))->IntegerValue();
  st->current_input_masks = (uint32_t) obj->Get(v8::String::New("current_input_masks"))->IntegerValue();
  st->width_in_pixels = (uint16_t) obj->Get(v8::String::New("width_in_pixels"))->IntegerValue();
  st->height_in_pixels = (uint16_t) obj->Get(v8::String::New("height_in_pixels"))->IntegerValue();
  st->width_in_millimeters = (uint16_t) obj->Get(v8::String::New("width_in_millimeters"))->IntegerValue();
  st->height_in_millimeters = (uint16_t) obj->Get(v8::String::New("height_in_millimeters"))->IntegerValue();
  st->min_installed_maps = (uint16_t) obj->Get(v8::String::New("min_installed_maps"))->IntegerValue();
  st->max_installed_maps = (uint16_t) obj->Get(v8::String::New("max_installed_maps"))->IntegerValue();
  st->root_visual = (xcb_visualid_t) obj->Get(v8::String::New("root_visual"))->IntegerValue();
  st->backing_stores = (uint8_t) obj->Get(v8::String::New("backing_stores"))->IntegerValue();
  st->save_unders = (uint8_t) obj->Get(v8::String::New("save_unders"))->BooleanValue();
  st->root_depth = (uint8_t) obj->Get(v8::String::New("root_depth"))->IntegerValue();
  st->allowed_depths_len = (uint8_t) obj->Get(v8::String::New("allowed_depths_len"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_setup_request_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("byte_order"), v8::Integer::New(st->byte_order));
  obj->Set(v8::String::New("protocol_major_version"), v8::Integer::New(st->protocol_major_version));
  obj->Set(v8::String::New("protocol_minor_version"), v8::Integer::New(st->protocol_minor_version));
  obj->Set(v8::String::New("authorization_protocol_name"), v8::String::New((char*)xcb_setup_request_authorization_protocol_name(st)));
  obj->Set(v8::String::New("authorization_protocol_data"), v8::String::New((char*)xcb_setup_request_authorization_protocol_data(st)));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_setup_request_t *st) {
  v8::HandleScope scope;
  st->byte_order = (uint8_t) obj->Get(v8::String::New("byte_order"))->IntegerValue();
  st->protocol_major_version = (uint16_t) obj->Get(v8::String::New("protocol_major_version"))->IntegerValue();
  st->protocol_minor_version = (uint16_t) obj->Get(v8::String::New("protocol_minor_version"))->IntegerValue();
  st->authorization_protocol_name_len = (uint16_t) obj->Get(v8::String::New("authorization_protocol_name_len"))->IntegerValue();
  st->authorization_protocol_data_len = (uint16_t) obj->Get(v8::String::New("authorization_protocol_data_len"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_setup_failed_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("status"), v8::Integer::New(st->status));
  obj->Set(v8::String::New("protocol_major_version"), v8::Integer::New(st->protocol_major_version));
  obj->Set(v8::String::New("protocol_minor_version"), v8::Integer::New(st->protocol_minor_version));
  obj->Set(v8::String::New("length"), v8::Integer::New(st->length));
  obj->Set(v8::String::New("reason"), v8::String::New((char*)xcb_setup_failed_reason(st)));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_setup_failed_t *st) {
  v8::HandleScope scope;
  st->status = (uint8_t) obj->Get(v8::String::New("status"))->IntegerValue();
  st->reason_len = (uint8_t) obj->Get(v8::String::New("reason_len"))->IntegerValue();
  st->protocol_major_version = (uint16_t) obj->Get(v8::String::New("protocol_major_version"))->IntegerValue();
  st->protocol_minor_version = (uint16_t) obj->Get(v8::String::New("protocol_minor_version"))->IntegerValue();
  st->length = (uint16_t) obj->Get(v8::String::New("length"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_setup_authenticate_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("status"), v8::Integer::New(st->status));
  obj->Set(v8::String::New("length"), v8::Integer::New(st->length));
  obj->Set(v8::String::New("reason"), v8::String::New((char*)xcb_setup_authenticate_reason(st)));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_setup_authenticate_t *st) {
  v8::HandleScope scope;
  st->status = (uint8_t) obj->Get(v8::String::New("status"))->IntegerValue();
  st->length = (uint16_t) obj->Get(v8::String::New("length"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_setup_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("status"), v8::Integer::New(st->status));
  obj->Set(v8::String::New("protocol_major_version"), v8::Integer::New(st->protocol_major_version));
  obj->Set(v8::String::New("protocol_minor_version"), v8::Integer::New(st->protocol_minor_version));
  obj->Set(v8::String::New("length"), v8::Integer::New(st->length));
  obj->Set(v8::String::New("release_number"), v8::Integer::New(st->release_number));
  obj->Set(v8::String::New("resource_id_base"), v8::Integer::New(st->resource_id_base));
  obj->Set(v8::String::New("resource_id_mask"), v8::Integer::New(st->resource_id_mask));
  obj->Set(v8::String::New("motion_buffer_size"), v8::Integer::New(st->motion_buffer_size));
  obj->Set(v8::String::New("maximum_request_length"), v8::Integer::New(st->maximum_request_length));
  obj->Set(v8::String::New("image_byte_order"), v8::Integer::New(st->image_byte_order));
  obj->Set(v8::String::New("bitmap_format_bit_order"), v8::Integer::New(st->bitmap_format_bit_order));
  obj->Set(v8::String::New("bitmap_format_scanline_unit"), v8::Integer::New(st->bitmap_format_scanline_unit));
  obj->Set(v8::String::New("bitmap_format_scanline_pad"), v8::Integer::New(st->bitmap_format_scanline_pad));
  obj->Set(v8::String::New("min_keycode"), v8::Integer::New(st->min_keycode));
  obj->Set(v8::String::New("max_keycode"), v8::Integer::New(st->max_keycode));
  obj->Set(v8::String::New("vendor"), v8::String::New((char*)xcb_setup_vendor(st)));
  v8::Local<v8::Array> pixmap_formats_list = v8::Array::New();
  obj->Set(v8::String::New("pixmap_formats"), pixmap_formats_list);
  int ipixmap_formats = 0;
  for(xcb_format_iterator_t itr = xcb_setup_pixmap_formats_iterator(st); itr.rem; xcb_format_next(&itr), ++ipixmap_formats) {
    pixmap_formats_list->Set(ipixmap_formats, toJS(itr.data));
  }
  v8::Local<v8::Array> roots_list = v8::Array::New();
  obj->Set(v8::String::New("roots"), roots_list);
  int iroots = 0;
  for(xcb_screen_iterator_t itr = xcb_setup_roots_iterator(st); itr.rem; xcb_screen_next(&itr), ++iroots) {
    roots_list->Set(iroots, toJS(itr.data));
  }
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_setup_t *st) {
  v8::HandleScope scope;
  st->status = (uint8_t) obj->Get(v8::String::New("status"))->IntegerValue();
  st->protocol_major_version = (uint16_t) obj->Get(v8::String::New("protocol_major_version"))->IntegerValue();
  st->protocol_minor_version = (uint16_t) obj->Get(v8::String::New("protocol_minor_version"))->IntegerValue();
  st->length = (uint16_t) obj->Get(v8::String::New("length"))->IntegerValue();
  st->release_number = (uint32_t) obj->Get(v8::String::New("release_number"))->IntegerValue();
  st->resource_id_base = (uint32_t) obj->Get(v8::String::New("resource_id_base"))->IntegerValue();
  st->resource_id_mask = (uint32_t) obj->Get(v8::String::New("resource_id_mask"))->IntegerValue();
  st->motion_buffer_size = (uint32_t) obj->Get(v8::String::New("motion_buffer_size"))->IntegerValue();
  st->vendor_len = (uint16_t) obj->Get(v8::String::New("vendor_len"))->IntegerValue();
  st->maximum_request_length = (uint16_t) obj->Get(v8::String::New("maximum_request_length"))->IntegerValue();
  st->roots_len = (uint8_t) obj->Get(v8::String::New("roots_len"))->IntegerValue();
  st->pixmap_formats_len = (uint8_t) obj->Get(v8::String::New("pixmap_formats_len"))->IntegerValue();
  st->image_byte_order = (uint8_t) obj->Get(v8::String::New("image_byte_order"))->IntegerValue();
  st->bitmap_format_bit_order = (uint8_t) obj->Get(v8::String::New("bitmap_format_bit_order"))->IntegerValue();
  st->bitmap_format_scanline_unit = (uint8_t) obj->Get(v8::String::New("bitmap_format_scanline_unit"))->IntegerValue();
  st->bitmap_format_scanline_pad = (uint8_t) obj->Get(v8::String::New("bitmap_format_scanline_pad"))->IntegerValue();
  st->min_keycode = (xcb_keycode_t) obj->Get(v8::String::New("min_keycode"))->IntegerValue();
  st->max_keycode = (xcb_keycode_t) obj->Get(v8::String::New("max_keycode"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_timecoord_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("time"), v8::Integer::New(st->time));
  obj->Set(v8::String::New("x"), v8::Integer::New(st->x));
  obj->Set(v8::String::New("y"), v8::Integer::New(st->y));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_timecoord_t *st) {
  v8::HandleScope scope;
  st->time = (xcb_timestamp_t) obj->Get(v8::String::New("time"))->IntegerValue();
  st->x = (int16_t) obj->Get(v8::String::New("x"))->IntegerValue();
  st->y = (int16_t) obj->Get(v8::String::New("y"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_fontprop_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("name"), v8::Integer::New(st->name));
  obj->Set(v8::String::New("value"), v8::Integer::New(st->value));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_fontprop_t *st) {
  v8::HandleScope scope;
  st->name = (xcb_atom_t) obj->Get(v8::String::New("name"))->IntegerValue();
  st->value = (uint32_t) obj->Get(v8::String::New("value"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_charinfo_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("left_side_bearing"), v8::Integer::New(st->left_side_bearing));
  obj->Set(v8::String::New("right_side_bearing"), v8::Integer::New(st->right_side_bearing));
  obj->Set(v8::String::New("character_width"), v8::Integer::New(st->character_width));
  obj->Set(v8::String::New("ascent"), v8::Integer::New(st->ascent));
  obj->Set(v8::String::New("descent"), v8::Integer::New(st->descent));
  obj->Set(v8::String::New("attributes"), v8::Integer::New(st->attributes));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_charinfo_t *st) {
  v8::HandleScope scope;
  st->left_side_bearing = (int16_t) obj->Get(v8::String::New("left_side_bearing"))->IntegerValue();
  st->right_side_bearing = (int16_t) obj->Get(v8::String::New("right_side_bearing"))->IntegerValue();
  st->character_width = (int16_t) obj->Get(v8::String::New("character_width"))->IntegerValue();
  st->ascent = (int16_t) obj->Get(v8::String::New("ascent"))->IntegerValue();
  st->descent = (int16_t) obj->Get(v8::String::New("descent"))->IntegerValue();
  st->attributes = (uint16_t) obj->Get(v8::String::New("attributes"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_str_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("name"), v8::String::New((char*)xcb_str_name(st)));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_str_t *st) {
  v8::HandleScope scope;
  st->name_len = (uint8_t) obj->Get(v8::String::New("name_len"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_segment_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("x1"), v8::Integer::New(st->x1));
  obj->Set(v8::String::New("y1"), v8::Integer::New(st->y1));
  obj->Set(v8::String::New("x2"), v8::Integer::New(st->x2));
  obj->Set(v8::String::New("y2"), v8::Integer::New(st->y2));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_segment_t *st) {
  v8::HandleScope scope;
  st->x1 = (int16_t) obj->Get(v8::String::New("x1"))->IntegerValue();
  st->y1 = (int16_t) obj->Get(v8::String::New("y1"))->IntegerValue();
  st->x2 = (int16_t) obj->Get(v8::String::New("x2"))->IntegerValue();
  st->y2 = (int16_t) obj->Get(v8::String::New("y2"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_coloritem_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("pixel"), v8::Integer::New(st->pixel));
  obj->Set(v8::String::New("red"), v8::Integer::New(st->red));
  obj->Set(v8::String::New("green"), v8::Integer::New(st->green));
  obj->Set(v8::String::New("blue"), v8::Integer::New(st->blue));
  obj->Set(v8::String::New("flags"), v8::Integer::New(st->flags));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_coloritem_t *st) {
  v8::HandleScope scope;
  st->pixel = (uint32_t) obj->Get(v8::String::New("pixel"))->IntegerValue();
  st->red = (uint16_t) obj->Get(v8::String::New("red"))->IntegerValue();
  st->green = (uint16_t) obj->Get(v8::String::New("green"))->IntegerValue();
  st->blue = (uint16_t) obj->Get(v8::String::New("blue"))->IntegerValue();
  st->flags = (uint8_t) obj->Get(v8::String::New("flags"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_rgb_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("red"), v8::Integer::New(st->red));
  obj->Set(v8::String::New("green"), v8::Integer::New(st->green));
  obj->Set(v8::String::New("blue"), v8::Integer::New(st->blue));
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_rgb_t *st) {
  v8::HandleScope scope;
  st->red = (uint16_t) obj->Get(v8::String::New("red"))->IntegerValue();
  st->green = (uint16_t) obj->Get(v8::String::New("green"))->IntegerValue();
  st->blue = (uint16_t) obj->Get(v8::String::New("blue"))->IntegerValue();
}

v8::Handle<v8::Object> toJS(xcb_host_t *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  obj->Set(v8::String::New("family"), v8::Integer::New(st->family));
  v8::Local<v8::Array> address_list = v8::Array::New();
  obj->Set(v8::String::New("address"), address_list);
  uint8_t *address_list_ptr = xcb_host_address(st);
  for(int i = 0; i < xcb_host_address_length(st); ++i) {
    address_list->Set(i, v8::Integer::New(address_list_ptr[i]));
  }
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, xcb_host_t *st) {
  v8::HandleScope scope;
  st->family = (uint8_t) obj->Get(v8::String::New("family"))->IntegerValue();
  st->address_len = (uint16_t) obj->Get(v8::String::New("address_len"))->IntegerValue();
}
// END STRUCTS } } }


//{ { { BEGIN DOCS 

static v8::Persistent<v8::Object> lookup;

void InitXCB2JSStructs() {
  lookup = v8::Persistent<v8::Object>::New(v8::Object::New());
  lookup->Set(v8::String::New("char2b"), v8::String::New("CHAR2B: { byte1: Integer\n, byte2: Integer }")); 
  lookup->Set(v8::String::New("point"), v8::String::New("POINT: { x: Integer\n, y: Integer }")); 
  lookup->Set(v8::String::New("rectangle"), v8::String::New("RECTANGLE: { x: Integer\n, y: Integer\n, width: Integer\n, height: Integer }")); 
  lookup->Set(v8::String::New("arc"), v8::String::New("ARC: { x: Integer\n, y: Integer\n, width: Integer\n, height: Integer\n, angle1: Integer\n, angle2: Integer }")); 
  lookup->Set(v8::String::New("format"), v8::String::New("FORMAT: { depth: Integer\n, bits_per_pixel: Integer\n, scanline_pad: Integer }")); 
  lookup->Set(v8::String::New("visualtype"), v8::String::New("VISUALTYPE: { visual_id: Integer\n, class: Integer\n, bits_per_rgb_value: Integer\n, colormap_entries: Integer\n, red_mask: Integer\n, green_mask: Integer\n, blue_mask: Integer }")); 
  lookup->Set(v8::String::New("depth"), v8::String::New("DEPTH: { depth: Integer\n, visuals_len: Integer }")); 
  lookup->Set(v8::String::New("screen"), v8::String::New("SCREEN: { root: Integer\n, default_colormap: Integer\n, white_pixel: Integer\n, black_pixel: Integer\n, current_input_masks: Integer\n, width_in_pixels: Integer\n, height_in_pixels: Integer\n, width_in_millimeters: Integer\n, height_in_millimeters: Integer\n, min_installed_maps: Integer\n, max_installed_maps: Integer\n, root_visual: Integer\n, backing_stores: Integer\n, save_unders: Boolean\n, root_depth: Integer\n, allowed_depths_len: Integer }")); 
  lookup->Set(v8::String::New("setupRequest"), v8::String::New("SetupRequest: { byte_order: Integer\n, protocol_major_version: Integer\n, protocol_minor_version: Integer\n, authorization_protocol_name_len: Integer\n, authorization_protocol_data_len: Integer }")); 
  lookup->Set(v8::String::New("setupFailed"), v8::String::New("SetupFailed: { status: Integer\n, reason_len: Integer\n, protocol_major_version: Integer\n, protocol_minor_version: Integer\n, length: Integer }")); 
  lookup->Set(v8::String::New("setupAuthenticate"), v8::String::New("SetupAuthenticate: { status: Integer\n, length: Integer }")); 
  lookup->Set(v8::String::New("setup"), v8::String::New("Setup: { status: Integer\n, protocol_major_version: Integer\n, protocol_minor_version: Integer\n, length: Integer\n, release_number: Integer\n, resource_id_base: Integer\n, resource_id_mask: Integer\n, motion_buffer_size: Integer\n, vendor_len: Integer\n, maximum_request_length: Integer\n, roots_len: Integer\n, pixmap_formats_len: Integer\n, image_byte_order: Integer\n, bitmap_format_bit_order: Integer\n, bitmap_format_scanline_unit: Integer\n, bitmap_format_scanline_pad: Integer\n, min_keycode: Integer\n, max_keycode: Integer }")); 
  lookup->Set(v8::String::New("timecoord"), v8::String::New("TIMECOORD: { time: Integer\n, x: Integer\n, y: Integer }")); 
  lookup->Set(v8::String::New("fontprop"), v8::String::New("FONTPROP: { name: Integer\n, value: Integer }")); 
  lookup->Set(v8::String::New("charinfo"), v8::String::New("CHARINFO: { left_side_bearing: Integer\n, right_side_bearing: Integer\n, character_width: Integer\n, ascent: Integer\n, descent: Integer\n, attributes: Integer }")); 
  lookup->Set(v8::String::New("str"), v8::String::New("STR: { name_len: Integer }")); 
  lookup->Set(v8::String::New("segment"), v8::String::New("SEGMENT: { x1: Integer\n, y1: Integer\n, x2: Integer\n, y2: Integer }")); 
  lookup->Set(v8::String::New("coloritem"), v8::String::New("COLORITEM: { pixel: Integer\n, red: Integer\n, green: Integer\n, blue: Integer\n, flags: Integer }")); 
  lookup->Set(v8::String::New("rgb"), v8::String::New("RGB: { red: Integer\n, green: Integer\n, blue: Integer }")); 
  lookup->Set(v8::String::New("host"), v8::String::New("HOST: { family: Integer\n, address_len: Integer }")); 
}

v8::Handle<v8::String> structDocs(v8::Handle<v8::String> what) {
  v8::HandleScope scope;
  return scope.Close(v8::Handle<v8::String>::Cast(lookup->Get(what)));
}

// END DOCS } } }


#endif