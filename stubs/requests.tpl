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
  if (args.Length() < 1) {
    const char *usage = "Must have at least one argument\\nUsage: ${requestName}({{if request.field}}obj[, cb]{{else}}cb{{/if}})";
    return v8::ThrowException(v8::Exception::Error(v8::String::New(usage)));
  }
  {{if !request.field}}
  if (!args[0]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Callback.")));
  }
  {{/if}}
  {{if request.field}}
  if (!args[0]->IsObject()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("First argument must be an Object.")));
  }
  if (args.Length() >= 2 && !args[1]->IsFunction()) {
    return v8::ThrowException(v8::Exception::TypeError(v8::String::New("The Second argument should be a callback")));
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
  {{/if}}
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
  lookup->Set(v8::String::New("${requestName}"), v8::String::New("REQUEST -> ${requestName}({{if request.field}}${getDocHelp(requestName, requests)}[, cb]{{else}}cb{{/if}})")); 
{{/each}}
}

  }
}

#endif

