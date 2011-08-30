var fs = require('fs')
  , jqtpl = require("jqtpl")
  , typeLookup = JSON.parse(fs.readFileSync('xTypes.json'))
  , jsTypes = typeLookup.xtojs
  , cTypes = typeLookup.xtoc
  , events = JSON.parse(fs.readFileSync('xEvents.json'))
  , structs = JSON.parse(fs.readFileSync('xStructs.json'))
  , data =
    { prepPropName: prepPropName
    , xcbEventType: xcbEventType
    , xcbEnumName: xcbEnumName
    , JSType: JSType  
    , shortEventName: shortEventName
    , getPrepName: getPrepName
    , getSymName: getSymName
    , events: events
    , XCBType: getXCBType
    , getJSTypeExample: getJSTypeExample
    , getDocHelp: getDocHelp
    , DocName: DocName
    , structs: structs
    }

;['events', 'structs'].forEach(function(name) {
  var tplFile = fs.readFileSync('stubs/' + name + '.tpl').toString().replace(/\n\s*{{/g, '{{').replace(/}}\s*$/g, '}}')
  fs.writeFileSync('src/__autogen_' + name + '.h', jqtpl.tmpl(tplFile, data))
})

function getSymName(short) {
  return 'on' + short + "Sym"
}

function getPrepName(short) {
  if (events[short].ref) short = events[short].ref
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

function getDocHelp(short) {
  return '{ ' + Object.keys(structs[short].field).map(function(field) {
    return field + ": " + getJSTypeExample(JSType(structs[short].field[field]))
  }).join('\\n, ') + ' }'
}

function getJSTypeExample(type) {
  switch(type) {
    case "Integer": return 7
    case "String": return "\\\"I am a string\\\""
    case "Bool": return true
    case "Date": return "\\\"2011-01-22\\\""
  }
}

