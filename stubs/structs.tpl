#ifndef __AUTOGENCTOJSXCBSTRUCTS__
#define __AUTOGENCTOJSXCBSTRUCTS__
#include <v8.h>

//{ { { BEGIN STRUCTS
{{each(structName, attr) structs}}

v8::Handle<v8::Object> toJS(${XCBType(structName)} *st) {
  v8::HandleScope scope;
  v8::Local<v8::Object> obj = v8::Object::New();
{{each(i, field) attr.field}}
  {{if field.fieldType == 'field' && JSType(field.type, structName)}}
  obj->Set(v8::String::New("${field.name}"), v8::${JSType(field.type)}::New(st->${prepPropName(field.name)}));
  {{/if}}
{{/each}}
  return scope.Close(obj);
}

void fromJS(v8::Handle<v8::Object> obj, ${XCBType(structName)} *st) {
  v8::HandleScope scope;
{{each(i, field) attr.field}}
  {{if field.fieldType == 'field' && JSType(field.type, structName)}}
  st->${prepPropName(field.name)} = (${XCBType(field.type)}) obj->Get(v8::String::New("${field.name}"))->${JSType(field.type)}Value();
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
