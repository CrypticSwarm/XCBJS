var fs = require('fs')
  , requests = JSON.parse(fs.readFileSync('xRequests.json'))
  , structs = JSON.parse(fs.readFileSync('xStructs.json'))
  , typeLookup = JSON.parse(fs.readFileSync('xTypes.json'))
  , jsTypes = typeLookup.xtojs
  , cTypes = typeLookup.xtoc
  , str = ""

function getXCBType(short) {
  return cTypes[short] ? cTypes[short] : ('xcb' + short + '_t') .replace(/[a-z][A-Z]/g, function(rep) {
    return rep[0] + '_' + rep[1]
  }).toLowerCase()
}

function getXCBReqName(short) {
  return ('xcb' + short) .replace(/[a-z][A-Z0-9]/g, function(rep) {
    return rep[0] + '_' + rep[1]
  }).toLowerCase()
}

function prepPropName(propName) {
  return propName in { "class": true, "new": true, "delete": true } ? '_' + propName : propName
}

function getJSType(short) {
  return jsTypes[short]
}

function partialAddList(type, name, params) {
  var jstype = getJSType(type)
    , specialType = structs[type]
    , buf = ""
  if (!jstype && !specialType) return console.log("Couldn't find the appropriate V8 type for", type, "for to JS generation:", name), ""
  params.push(name)
  buf += "\t" + getXCBType(type) + " *" + name + ";\n"
  if (type === 'char') {
    var jsname = "strval_" + name
    buf += "\tv8::Local<v8::String> " + jsname + " = v8::Local<v8::String>::Cast(obj->Get(v8::String::New(\"" + name + "\")));\n"
    buf += "\t" + name + " = new " + type + "[" + jsname + "->Length()];\n"
    buf += "\tstrcpy(" + name + ", *v8::String::AsciiValue(" + jsname + "));\n"
  }
  else if (jstype) {
    var jsname = "maskarr_" + name
    buf += "\tv8::Local<v8::Array> " + jsname + " = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New(\"" + name + "\")));\n"
    buf += "\t" + name + " = new " + getXCBType(type) + "[" + jsname + "->Length()];\n"
    buf += "\tfor(unsigned int i = 0; i < " + jsname + "->Length(); ++i) {\n"
    buf += "\t\t" + name + "[i] = (" + getXCBType(type) + ") " + jsname + "->Get(i)->" + jstype + "Value();\n"
    buf += "\t}\n"
  }
  else if(specialType) {
    var jsname  = "maskarr_" + name
    buf += "\tv8::Local<v8::Array> " + jsname + " = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New(\"" + name + "\")));\n"
    buf += "\t" + name + " = new " + getXCBType(type) + "[" + jsname + "->Length()];\n"
    buf += "\tfor(unsigned int i = 0; i < " + jsname + "->Length(); ++i) {\n"
    buf += "\t\tfromJS(v8::Local<v8::Object>::Cast(" + jsname + "->Get(i)), " + name + " + i);\n"
    buf += "\t}\n"
  }
  return buf
}

str += "#ifndef __AUTOGENCTOJSXCBREQUESTS__\n"
str += "#define __AUTOGENCTOJSXCBREQUESTS__\n"
str += "#include <v8.h>\n\n"
str += "#include <config.h>\n\n"


str += "//{{{ BEGIN REQUESTS \n\n"
var f = 0;
Object.keys(requests).forEach(function(requestName, f) {
  var request = requests[requestName].field
    , valparam = requests[requestName].valueparam
    , lists = requests[requestName].list
    , params = []
  str += "void xcbReq" + requestName + "(v8::Handle<v8::Object> obj) {\n"
  str += "\tv8::HandleScope scope;\n"
  if (request) Object.keys(request).forEach(function(propName) {
    var type = getJSType(request[propName])
    if (!type) return console.log("Couldn't find the appropriate V8 type for", request[propName], "for to JS generation:", requestName)
    params.push(prepPropName(propName))
    str += "\t" + getXCBType(request[propName]) + " " + prepPropName(propName) + " = (" + getXCBType(request[propName])
        +  ") obj->Get(v8::String::New(\"" + propName + "\"))->"
        + (type == 'Date' ? 'Integer' : type) + "Value();\n"
  })
  if (valparam) {
    var masktype = valparam['value-mask-type']
      , maskname = valparam['value-mask-name']
      , listname = valparam['value-list-name']
      , type = getJSType(masktype)
    if (!type) return console.log("Couldn't find the appropriate V8 type for", masktype, "for to JS generation:", requestName)
    if (params.indexOf(maskname) == -1) {
      params.push(maskname)
      str += "\t" + getXCBType(masktype) + " " + maskname + " = (" + getXCBType(masktype)
          +  ") obj->Get(v8::String::New(\"" + maskname + "\"))->"
          + type + "Value();\n"
    }
    str += partialAddList('CARD32', listname, params)
  }
  if (lists) Object.keys(lists).forEach(function(name) {
    var lenVar = name + '_len'
    if (name != 'keysyms' && name != 'keycodes' && params.indexOf(lenVar) == -1 && params.indexOf(name + '_mask') == -1) {
      params.push(lenVar)
      str += "\tuint32_t " + lenVar + " = (uint32_t)"
          +  " obj->Get(v8::String::New(\"" + lenVar + "\"))->IntegerValue();\n"
    }
    str += partialAddList(lists[name], name, params)
  })
  str += "\t" + getXCBReqName(requestName) + "(XCBJS::Config::connection" + (params.length ? ", " : "") + params.join(', ') + ");\n"
  if (valparam) {
    str += "\tdelete [] " + listname + ";\n"
  }
  if (lists) Object.keys(lists).forEach(function(listname) {
    str += "\tdelete [] " + listname + ";\n"
  })
  str += "}\n\n"
})

str += "// END REQUESTS }}}\n\n"

str += "#endif\n"

fs.writeFileSync('src/__autogen_requests.h', str)
