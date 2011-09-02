#ifndef __AUTOGENCTOJSXCBREQUESTS__
#define __AUTOGENCTOJSXCBREQUESTS__
#include <v8.h>

#include <config.h>

namespace XCBJS {
  namespace Request {

//{ { { BEGIN REQUESTS 

{{each(requestName, request) requests}}

v8::Handle<v8::Value> ${requestName}(const v8::Arguments& args) {
  v8::HandleScope scope;
  const char *usage = "Must have at least one argument\\nUsage: ${requestName}(obj[, cb])";
  if (args.Length() < 1) {
    return ThrowException(Exception::Error(String::New(usage)));
  }
  v8::Handle<v8::Object> obj = args[0]->ToObject();
  {{each(num, field) request.field}}
    {{if field.fieldType == 'field' && JSType(field.type)}}
  ${XCBType(field.type)} ${prepPropName(field.name)} = (${XCBType(field.type)}) obj->Get(v8::String::New("${field.name}"))->${JSType(field.type)}Value();
    {{/if}}
    {{if isListType(field)}}
      {{if includeListLen(field, request.field)}}
  ${listLenType(field)} ${listLenName(field)} = (${listLenType(field)}) obj->Get(v8::String::New("${listLenName(field)}"))->IntegerValue();
      {{/if}}
  ${listType(field)} *${listName(field)};
      {{if listType(field) === 'char'}}
  v8::Local<v8::String> ${tempListHolder(field)} = v8::Local<v8::String>::Cast(obj->Get(v8::String::New("${listName(field)}")));
  ${listName(field)} = new ${listType(field)}[${tempListHolder(field)}->Length()];
  strcpy(${listName(field)}, *v8::String::AsciiValue(${tempListHolder(field)}));
      {{else true }}
  v8::Local<v8::Array> ${tempListHolder(field)} = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New("${listName(field)}")));
  ${listName(field)} = new ${listType(field)}[${tempListHolder(field)}->Length()];
  for(unsigned int i = 0; i < ${tempListHolder(field)}->Length(); ++i) {
        {{if listJSType(field) }}
    ${listName(field)}[i] = (${listType(field)}) ${tempListHolder(field)}->Get(i)->${listJSType(field)}Value();
        {{else true}}
    fromJS(v8::Local<v8::Object>::Cast(${tempListHolder(field)}->Get(i)), ${listName(field)} + i);
        {{/if}}
  }
      {{/if}}
    {{/if}}
  {{/each}}
  ${getXCBReqName(requestName)}(XCBJS::Config::connection${getParamList(request.field)});
  {{each(num, field) request.field}}
    {{if isListType(field)}}
  delete [] ${listName(field)};
    {{/if}}
  {{/each}}
  return Undefined();
}
{{/each}}

// END REQUESTS } } }

static v8::Persistent<v8::Object> lookup = v8::Persistent<v8::Object>::New(v8::Object::New());

v8::Handle<v8::String> Docs(v8::Handle<v8::String> what) {
  v8::HandleScope scope;
  return scope.Close(v8::Handle<v8::String>::Cast(lookup->Get(what)));
}


void Init(v8::Persistent<v8::Object> reqs) {
{{each(requestName, request) requests}}
  NODE_SET_METHOD(reqs, "${requestName}", ${requestName});
  lookup->Set(v8::String::New("${requestName}"), v8::String::New("REQUEST -> ${requestName}(${getDocHelp(requestName, requests)}[, cb])")); 
{{/each}}
}

  }
}

#endif

