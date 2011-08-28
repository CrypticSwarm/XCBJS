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
  return ('xcb' + short) .replace(/[a-z][A-Z]/g, function(rep) {
    return rep[0] + '_' + rep[1]
  }).toLowerCase()
}

function prepPropName(propName) {
  return propName in { "class": true, "new": true } ? '_' + propName : propName
}

function getJSType(short,requestName) {
  var type = jsTypes[short]
  if (!type) return console.log("Couldn't find the appropriate V8 type for", short, "for to JS generation:", requestName)
  return type
}

str += "#ifndef __AUTOGENCTOJSXCBREQUESTS__\n"
str += "#define __AUTOGENCTOJSXCBREQUESTS__\n"
str += "#include <v8.h>\n\n"
str += "#include <config.h>\n\n"


str += "//{{{ BEGIN REQUESTS \n\n"
var f = 0;
Object.keys(requests).forEach(function(requestName, f) {
if (f) return
  var request = requests[requestName].field
    , valparam = requests[requestName].valueparam
    , params = [];
  str += "void xcbReq" + requestName + "(v8::Handle<v8::Object> obj) {\n"
  str += "\tv8::HandleScope scope;\n"
  if (request) Object.keys(request).forEach(function(propName) {
    var type = getJSType(request[propName], requestName)
    if (!type) return
    params.push(prepPropName(propName))
    str += "\t" + getXCBType(request[propName]) + " " + prepPropName(propName) + " = (" + getXCBType(request[propName])
        +  ") obj->Get(v8::String::New(\"" + propName + "\"))->"
        + type + "Value();\n"
  })
  if (valparam ) {
    var masktype = valparam['value-mask-type']
      , maskname = valparam['value-mask-name']
      , listname = valparam['value-list-name']
      , type = getJSType(masktype, requestName)
    if (!type) return
    params.push(maskname)
    params.push(listname)
    str += "\t" + getXCBType(masktype) + " " + maskname + " = (" + getXCBType(masktype)
        +  ") obj->Get(v8::String::New(\"" + maskname + "\"))->"
        + type + "Value();\n"
    str += "\t" + getXCBType(masktype) + " *" + listname + ";\n"
    str += "\tv8::Local<v8::Array> maskarr = v8::Local<v8::Array>::Cast(obj->Get(v8::String::New(\"" + listname + "\")));\n"
    str += "\t" + listname + " = new " + getXCBType(masktype) + "[maskarr->Length()];\n"
    str += "\tfor(unsigned int i = 0; i < maskarr->Length(); ++i) {\n"
    str += "\t\t" + listname + "[i] = (" + getXCBType(masktype) + ") maskarr->Get(i)->" + type + "Value();\n"
    str += "\t}\n"
  }
  str += "\t" + getXCBReqName(requestName) + "(XCBJS::Config::connection, " + params.join(', ') + ");\n"
  if (valparam) {
    str += "\tdelete [] " + listname + ";\n"
  }
  str += "}\n\n"
})

str += "// END REQUESTS }}}\n\n"

str += "#endif\n"

fs.writeFileSync('src/__autogen_requests.h', str)
