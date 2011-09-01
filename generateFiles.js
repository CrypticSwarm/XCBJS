var fs = require('fs')
  , jqtpl = require("jqtpl")
  , typeLookup = JSON.parse(fs.readFileSync('protocols/xTypes.json'))
  , xProto = JSON.parse(fs.readFileSync('protocols/xProtocol.json'))
  , jsTypes = typeLookup.xtojs
  , cTypes = typeLookup.xtoc
  , data =
    { prepPropName: prepPropName
    , xcbEventType: xcbEventType
    , xcbEnumName: xcbEnumName
    , JSType: JSType  
    , shortEventName: shortEventName
    , getPrepName: getPrepName
    , getSymName: getSymName
    , XCBType: getXCBType
    , getJSTypeExample: getJSTypeExample
    , getDocHelp: getDocHelp
    , DocName: DocName
    , enumValue: enumValue
    , events: xProto.event
    , structs: xProto.struct
    , requests: xProto.request
    , enums: xProto.enum
    }

Object.keys(xProto.eventcopy).forEach(function(x) {
  data.events[x] = xProto.eventcopy[x]
})

;['events', 'structs', 'enum'].forEach(function(name) {
  var tplFile = fs.readFileSync('stubs/' + name + '.tpl').toString().replace(/\n\s*{{/g, '{{').replace(/}}\s*$/g, '}}')
  fs.writeFileSync('src/__autogen_' + name + '.h', jqtpl.tmpl(tplFile, data))
})

function getSymName(short) {
  return 'on' + short + "Sym"
}

function getPrepName(short) {
  if (!data.events[short].field && data.events[short].ref) short = data.events[short].ref
  return "prepare" + short + "Event"
}

function prepPropName(short) {
  return short === 'new' ? '_new' 
  : short === 'class' ? '_class'
  : short
}

function shortEventName(name) {
  return name.replace('Notify', '')
}

function xcbEventType(eventName) {
  return xcbEnumName(eventName).toLowerCase() + "_event_t"
}

function xcbEnumName(eventName) {
  return ("xcb" + eventName).replace(/([A-Z])/g, function(letter) {
    return '_' + letter
  }).toUpperCase()
}

function JSType(short) {
  var type = short == 'TIMESTAMP' ? 'Integer': jsTypes[short] 
  if (!type) return console.log("Couldn't find the appropriate V8 type for", short, "for to JS generation:")
  return type
}

function getXCBType(short) {
  return cTypes[short] ? cTypes[short] : ('xcb' + short + '_t') .replace(/[a-z][A-Z]/g, function(rep) {
    return rep[0] + '_' + rep[1]
  }).toLowerCase()
}


function DocName(short) {
  return getXCBType(short).replace(/xcb_|_t/g, '').replace(/_[a-z]/g, function(m) { return m[1].toUpperCase() })
}

function getDocHelp(short, section) {
  if (!section[short].field && section[short].ref) short = section[short].ref
  if (!section[short].field) return '{ }'
  return '{ ' + section[short].field.filter(function(field) {
    return field.fieldType == 'field'
  }).map(function(field) {
    return field.name + ": " + getJSTypeExample(JSType(field.type))
  }).join('\\n, ') + ' }'
}

function getJSTypeExample(type) {
  return type
}

function enumValue(enumItem){
  return enumItem.value ? enumItem.value : 1 << parseInt(enumItem.bit)
}
