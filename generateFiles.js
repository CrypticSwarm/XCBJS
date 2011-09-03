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
    , getXCBReqName: getXCBReqName
    , isListType: isListType
    , includeListLen: includeListLen
    , listLenName: listLenName
    , listLenType: listLenType
    , getParamList: getParamList
    , listJSType: listJSType
    , listType: listType
    , listName: listName
    , tempListHolder: tempListHolder
    , XCBReplyType: XCBReplyType
    , XCBCookieType: XCBCookieType
    , XCBReplyFunction: XCBReplyFunction
    , isLenSpecifier: isLenSpecifier
    , events: xProto.event
    , structs: xProto.struct
    , requests: xProto.request
    , enums: xProto.enum
    }
Object.keys(xProto.eventcopy).forEach(function(x) {
  data.events[x] = xProto.eventcopy[x]
})

;['events', 'structs', 'enum', 'requests'].forEach(function(name) {
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
  : short === 'delete' ? '_delete'
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
  if (!type && !data.structs[short]) return console.log("Couldn't find the appropriate V8 type for", short, "for to JS generation:")
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

function getXCBReqName(short) {
  return ('xcb' + short) .replace(/[a-z][A-Z0-9]/g, function(rep) {
    return rep[0] + '_' + rep[1]
  }).toLowerCase()
}

function isListType(field){
  return field.fieldType == 'list' || field.fieldType == 'valueparam'
}

function tempListHolder(field) {
  return field.type == 'char'       ? field.name + '_str'
  : field.fieldType == 'list'       ? field.name + '_list'
  : field.fieldType == 'valueparam' ? field['value-mask-name'] + '_valmask'
  : ''
}

function listName(field) {
  return field.fieldType == 'list' ? field.name
  : field['value-list-name']
}

function listType(field) {
  return field.fieldType == 'valueparam' ? 'uint32_t'
  : getXCBType(field.type)
}

function listJSType(field) {
  return field.fieldType == 'valueparam' ? 'Integer'
  : JSType(field.type)
}

function getParamList(fields) {
  var str = fields && fields.filter(function (field){
    return field.fieldType == 'field' || isListType(field)
  }).map(function(field) {
    return !isListType(field) ? prepPropName(field.name)
    : includeListLen(field, fields) ? listLenName(field) + ", " + listName(field)
    : listName(field)
  }).join(', ')
  return str ? ', ' + str : ''

}

function listLenType(field) {
  return field.fieldType == 'list' ? 'uint32_t'
  : getXCBType(field['value-mask-type'])
}

function listLenName(field) {
  return field.fieldType == 'list' ? field.name + '_len'
  : field['value-mask-name']

}

function includeListLen(field, fields){
  var name = listLenName(field)
  return field.name != 'keysyms'
  && field.name != 'keycodes'
  && field.name != 'event'
  && fields.every(function(f) {
    return name != f.name
  })
}

function camelToUnder(name) {
  return name.replace(/([A-Z])/g, '_$1').toLowerCase()
}

function XCBReplyType(requestName) {
  return 'xcb' + camelToUnder(requestName) + '_reply_t'
}

function XCBCookieType(requestName) {
  return 'xcb' + camelToUnder(requestName) + '_cookie_t'
}

function XCBReplyFunction(requestName) {
  return 'xcb' + camelToUnder(requestName) + '_reply'
}

function isLenSpecifier(field) {
  return /_len$/.test(field.name)
}
