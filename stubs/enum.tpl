#ifndef __AUTOGENCTOJSXCBENUMS__
#define __AUTOGENCTOJSXCBENUMS__
#include <v8.h>

namespace XCBJS {
  namespace Enum {

void Init(v8::Persistent<v8::Object> enums) {
{{each(enumName, enum) enums}}
  v8::Local<v8::Object> ${enumName}Obj = v8::Object::New();
  enums->Set(v8::String::New("${enumName}"), ${enumName}Obj);
  {{each(i, enumItem) enum.field}}
  ${enumName}Obj->Set(v8::String::New("${enumItem.name}"), v8::Integer::New(${enumValue(enumItem)}));
  {{/each}}
{{/each}}
}
  }
}

#endif
