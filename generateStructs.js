var fs = require('fs')
  , jqtpl = require("jqtpl")
  , structs = JSON.parse(fs.readFileSync('xStructs.json'))
  , typeLookup = JSON.parse(fs.readFileSync('xTypes.json'))
  , jsTypes = typeLookup.xtojs
  , cTypes = typeLookup.xtoc
  , data =
    { prepPropName: prepPropName
    , XCBType: getXCBType
    , JSType: getJSType  
    , getJSTypeExample: getJSTypeExample
    , getDocHelp: getDocHelp
    , DocName: DocName
    , structs: structs
    }
  , tplFile = fs.readFileSync('stubs/structs.tpl').toString().replace(/\n\s*{{/g, '{{').replace(/}}\s*$/g, '}}')

fs.writeFileSync('src/__autogen_structs.h', jqtpl.tmpl(tplFile, data))
function prepPropName(short) {
  return short == 'class' ? '_class' : short
}

function getXCBType(short) {
  return cTypes[short] ? cTypes[short] : ('xcb' + short + '_t') .replace(/[a-z][A-Z]/g, function(rep) {
    return rep[0] + '_' + rep[1]
  }).toLowerCase()
}

function getJSType(short, structName) {
  var type = short == 'TIMESTAMP' ? 'Integer': jsTypes[short] 
  if (!type) return console.log("Couldn't find the appropriate V8 type for", short, "for to JS generation:", structName)
  return type
}

function DocName(short) {
  return getXCBType(short).replace(/xcb_|_t/g, '').replace(/_[a-z]/g, function(m) { return m[1].toUpperCase() })
}

function getDocHelp(short) {
  return '{ ' + Object.keys(structs[short].field).map(function(field) {
    return field + ": " + getJSTypeExample(getJSType(structs[short].field[field]))
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

