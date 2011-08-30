#ifndef __AUTOGENCTOJSXCBEVENTS__
#define __AUTOGENCTOJSXCBEVENTS__
#include <v8.h>

static v8::Persistent<v8::Object> t;

void InitXCB2JSEvents(v8::Persistent<v8::Object> tar) {
  t = tar;
}

//{ { { BEGIN SYMBOL CREATION 
{{each(eventName, event) events}}
static v8::Persistent<v8::String> ${getSymName(eventName)} = v8::Persistent<v8::String>::New(v8::String::NewSymbol("on${shortEventName(eventName)}"));
{{/each}}

// END SYMBOL CREATION } } }

//{ { { BEGIN EVENT PREP 

{{each(eventName, event) events}}
{{if event.field}}

template <typename T>
v8::Handle<v8::Object> ${getPrepName(eventName)}(const T& ev) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
  {{each(propName, type) event.field}}
    {{if JSType(type)}}
  obj->Set(v8::String::New("${propName}"), v8::${JSType(type)}::New(ev->${prepPropName(propName)}));
    {{/if}}
  {{/each}}
  return scope.Close(obj);
}
{{/if}}
{{/each}}

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
{{each(eventName, event) events}}
{{if event.field || event.ref}}
    case ${xcbEnumName(eventName)}: return handle_event((${xcbEventType(eventName)} *) ev, ${getSymName(eventName)}, ${getPrepName(eventName)});
{{/if}}
{{/each}}
    default: delete ev;
  }
  return 0;
}

#endif
