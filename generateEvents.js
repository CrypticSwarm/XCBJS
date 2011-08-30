var fs = require('fs')
  , jqtpl = require("jqtpl")
  , typeLookup = JSON.parse(fs.readFileSync('xTypes.json')).xtojs
  , events = JSON.parse(fs.readFileSync('xEvents.json'))
  , data =
    { prepPropName: prepPropName
    , xcbEventType: xcbEventType
    , xcbEnumName: xcbEnumName
    , JSType: JSType  
    , shortEventName: shortEventName
    , getPrepName: getPrepName
    , getSymName: getSymName
    , events: events
    }
  , tplFile = fs.readFileSync('stubs/events.tpl').toString().replace(/\n\s*{{/g, '{{').replace(/}}\s*$/g, '}}')
fs.writeFileSync('src/__autogen_events.h', jqtpl.tmpl(tplFile, data))

function getSymName(short) {
  return 'on' + short + "Sym"
}

function getPrepName(short) {
  if (events[short].ref) short = events[short].ref
  return "prepare" + short + "Event"
}

function prepPropName(short) {
  return short === 'new' ? '_new' : short
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

function JSType(type) {
  return typeLookup[type]
}
