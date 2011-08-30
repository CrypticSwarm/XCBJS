#ifndef __AUTOGENCTOJSXCBSTRUCTS__
#define __AUTOGENCTOJSXCBSTRUCTS__
#include <v8.h>

//{ { { BEGIN STRUCTS
{{each(structName, attr) structs}}

v8::Handle<v8::Object> toJS(${XCBType(structName)} *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
{{each(propName, type) attr.field}}
  {{if JSType(type, structName)}}
  obj->Set(v8::String::New("${propName}"), v8::${JSType(type)}::New(st->${prepPropName(propName)}));
  {{/if}}
{{/each}}
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, ${XCBType(structName)} *st) {
  v8::HandleScope scope;
{{each(propName, type) attr.field}}
  {{if JSType(type, structName)}}
  st->${prepPropName(propName)} = (${XCBType(type)}) obj->Get(v8::String::New("${propName}"))->${JSType(type)}Value();
  {{/if}}
{{/each}}
}
{{/each}}
// END STRUCTS } } }


//{ { { BEGIN DOCS 

static v8::Persistent<v8::Object> lookup;

void InitXCB2JSStructs(v8::Persistent<v8::Object> tar) {
  t = tar;
  lookup = v8::Persistent<v8::Object>::New(v8::Object::New());
{{each(structName, struct) structs}}
  lookup->Set(v8::String::New("${DocName(structName)}"), v8::String::New("${structName}: ${getDocHelp(structName, structs)}")); 
{{/each}}
}

v8::Handle<v8::String> structDocs(v8::Handle<v8::String> what) {
  v8::HandleScope scope;
  return scope.Close(v8::Handle<v8::String>::Cast(lookup->Get(what)));
}

// END DOCS } } }


#endif
