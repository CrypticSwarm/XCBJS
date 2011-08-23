var fs = require('fs')
  , description = JSON.parse(fs.readFileSync('events.json'))
  , typeLookup = description.types
  , events = description.events
  , str = ""

function getSymName(short) {
  return 'on' + short + "Sym"
}

function getPrepName(short) {
  return "prepare" + short + "Event"
}

str += "#ifndef __AUTOGENCTOJSXCBEVENTS__\n"
str += "#define __AUTOGENCTOJSXCBEVENTS__\n"
str += "#include <v8.h>\n\n"

str += "static v8::Persistent<v8::Object> t;\n\n"

str += "void InitXCB2JSEvents(v8::Persistent<v8::Object> tar) {\n"
str += "\tt = tar;\n"
str += "}\n\n"

str += "//{{{ BEGIN SYMBOL CREATION \n\n"
Object.keys(events).forEach(function(eventName) { 
  str+= "static v8::Persistent<v8::String> " + getSymName(eventName) 
     +  " = v8::Persistent<v8::String>::New(v8::String::NewSymbol(\"on" + (events[eventName].alias || eventName) + "\"));\n"
})
str += "\n"
str += "// END SYMBOL CREATION }}}\n\n"

str += "//{{{ BEGIN EVENT PREP \n\n"

Object.keys(events).forEach(function(eventName) { 
  var event = events[eventName].attributes
  str += "template <typename T>\n"
  str += "void " + getPrepName(eventName) + "(const T& ev, v8::Handle<v8::Function> cb) {\n"
  str += "\tv8::HandleScope scope;\n"
  str += "\tv8::Local<v8::Object> obj = v8::Object::New();\n"
  Object.keys(event).forEach(function(propName) {
    var type = typeLookup[event[propName]]
    str += "\tobj->Set(v8::String::New(\"" + propName + "\"), v8::" + type + "::New(ev->" + propName.replace('-', '_') + "));\n"
  })
  str += "\tv8::Local<v8::Value> args[1] = { obj };\n"
  str += "\tcb->Call(obj, 1, args);\n"
  str += "}\n\n"
})

str += "// END EVENT PREP FUNCS}}}\n\n"

str += "template <typename T>\n"
str += "int handle_event(T ev, v8::Handle<v8::String> sym, void (*cb)(const T&, v8::Handle<v8::Function>)) {\n"
str += "\tv8::HandleScope scope;\n"
str += "\tv8::Local<v8::Value> val = t->Get(sym);\n"
str += "\tif (val->IsFunction()) {\n"
str += "\t\tv8::Local<v8::Function> jscb = v8::Local<v8::Function>::Cast(val);\n"
str += "\t\tcb(ev, jscb);\n"
str += "\t\tdelete ev;\n"
str += "\t}\n"
str += "\treturn 0;\n"
str += "}\n\n"

str += "inline int distributeEvent(xcb_generic_event_t *ev) {\n"
str += "\tswitch(ev->response_type & ~0x80) {\n"
Object.keys(events).forEach(function(eventName) { 
  var xcbName = ("xcb" + eventName).replace(/([A-Z])/g, function(letter) {
    return '_' + letter
  })
  str += "\t\tcase " + xcbName.toUpperCase() + ": "
      +  "return handle_event((" + xcbName.toLowerCase() + "_event_t *) ev, " + getSymName(eventName)
      +  ", " + getPrepName(eventName) + ");\n"
})
str += "\t\tdefault: delete ev;\n"
str += "\t}\n"
str += "\treturn 0;"

str += "}\n\n"

str += "#endif\n"

fs.writeFileSync('src/__autogen_events.h', str)
