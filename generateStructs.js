var fs = require('fs')
  , structs = JSON.parse(fs.readFileSync('xStructs.json'))
  , typeLookup = JSON.parse(fs.readFileSync('xTypes.json'))
  , jsTypes = typeLookup.xtojs
  , cTypes = typeLookup.xtoc
  , str = ""

function prepPropName(short) {
  return short == 'class' ? '_class' : short
}

function getXCBType(short) {
  return cTypes[short] ? cTypes[short] : ('xcb' + short + '_t') .replace(/[a-z][A-Z]/g, function(rep) {
    return rep[0] + '_' + rep[1]
  }).toLowerCase()
}

function getJSType(short, structName) {
  var type = jsTypes[short]
  if (!type) return console.log("Couldn't find the appropriate V8 type for", short, "for to JS generation:", structName)
  return type
}

str += "#ifndef __AUTOGENCTOJSXCBSTRUCTS__\n"
str += "#define __AUTOGENCTOJSXCBSTRUCTS__\n"
str += "#include <v8.h>\n\n"

str += "//{{{ BEGIN STRUCTS \n\n"
Object.keys(structs).forEach(function(structName) {
  var struct = structs[structName].field
  str += "v8::Handle<v8::Object> toJS(" + getXCBType(structName) + " *st) {\n"
  str += "\tv8::HandleScope scope;\n"
  str += "\tv8::Local<v8::Object> obj = v8::Object::New();\n"
  Object.keys(struct).forEach(function(propName) {
    var type = getJSType(struct[propName], structName)
    if (!type) return
    str += "\tobj->Set(v8::String::New(\"" + propName + "\"), v8::" + type + "::New(st->" + prepPropName(propName) + "));\n"
  })
  str += "\treturn scope.Close(obj);\n"
  str += "}\n\n"
  
  str += "void fromJS(v8::Handle<v8::Object> obj, " + getXCBType(structName) + " *st) {\n"
  str += "\tv8::HandleScope scope;\n"
  Object.keys(struct).forEach(function(propName) {
    var type = getJSType(struct[propName], structName)
    if (!type) return
    str += "\tst->" + prepPropName(propName) + " = (" + getXCBType(struct[propName]) 
        +  ") obj->Get(v8::String::New(\"" + propName + "\"))->"
        + (type == 'Date' ? 'Integer' : type) + "Value();\n"
  })
  str += "}\n\n"
})
str += "// END STRUCTS }}}\n\n"


function getJSTypeExample(type) {
  switch(type) {
    case "Integer": return 7
    case "String": return "I am a string"
    case "Bool": return true
    case "Date": return "2011-01-22"
  }
}

str += "//{{{ BEGIN DOCS \n\n"
str += "v8::Handle<v8::String> structDocs(v8::Handle<v8::String> what) {\n"
str += "\tv8::HandleScope scope;\n"
str += "\tv8::String::AsciiValue str(what);\n"
Object.keys(structs).forEach(function(structName) {
  var struct = structs[structName].field
    , exp = {}
  Object.keys(struct).forEach(function(propName) {
    exp[propName] = getJSTypeExample(getJSType(struct[propName]))
  })
  str += "\tif(strcmp(*str, \"" + getXCBType(structName).replace(/xcb_|_t/g, '').replace(/_[a-z]/g, function(m) { return m[1].toUpperCase() })
      + "\") == 0) return scope.Close(v8::String::New(\"" + structName + ": " + JSON.stringify(exp).replace(/"/g, "\\\"") + "\"));\n"
})
str += "\treturn scope.Close(v8::String::New(\"\"));\n"
str += "}\n"


str += "// END DOCS }}}\n\n"

str += "#endif\n"

fs.writeFileSync('src/__autogen_structs.h', str)
