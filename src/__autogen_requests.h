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

// END REQUESTS }}}

#endif
