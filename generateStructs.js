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
  return cTypes[short] ? cTypes[short] : ('xcb' + short + '_t') .replace(/[a-z][A-Z]/, function(rep) {
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
        + type + "Value();\n"
  })
  str += "}\n\n"
})
str += "// END STRUCTS }}}\n\n"


str += "#endif\n"

fs.writeFileSync('src/__autogen_structs.h', str)
