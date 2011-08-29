var f = require('fs')
  , x = require('libxml-to-js')

function extend(obj, ext) {
  Object.keys(ext).forEach(function(key) {
    if (key in obj) console.log("warning overriding ", key, "in", obj)
    obj[key] = ext[key]
  })
  return obj
}

function mergeAttr(obj) {
  Object.keys(obj).forEach(function(key) {
    if (key !== '@' && typeof obj[key] === 'object') {
      mergeAttr(obj[key])
    }
    if (Array.isArray(obj[key]) && 'name' in obj[key][0]) obj[key] = prepName(obj[key])
    if (key === 'field' || key === 'list') obj[key] = prepField(obj[key])
    if (key === 'item') obj.values = prepItem(obj[key]), delete obj[key]
  })
  if (obj['@']) extend(obj, obj['@'])
  delete obj['@']
}

function stripTags(tags) {
  return function stripper(key, val) {
    return tags.some(function(tag) {
      return key === tag
    }) ? undefined : val
  }
}

function prepName(arr) {
  var ret = {}
  arr.forEach(function(val) {
    ret[val.name] = val
    delete val.name
  })
  return ret
}

function prepItem(item) {
  var ret = {}
  if ('name' in item) {
    ret[item.name] = item
    delete item.name
    return ret
  }
  Object.keys(item).forEach(function(key) {
    ret[key] = parseInt(item[key].bit ? 1 << item[key].bit
               : item[key].value) || item[key]
  })
  return ret
}

function prepField(field, t) {
  var ret = {}
  if ('name' in field && typeof field.name != 'object') {
    ret[field.name] = field.type
    delete field.name
    return ret
  }
  Object.keys(field).forEach(function(key) {
    ret[key] = field[key].type
  })
  return ret
}



x(f.readFileSync('xproto.xml').toString(), function(err, result) {
  if (err) return console.log("err?", err)
  delete result['@']
  mergeAttr(result)
  f.writeFileSync("xEvents.json", JSON.stringify(extend(result.event, result.eventcopy),  stripTags(['comment', 'pad', 'op', 'opcode']), 2))
  f.writeFileSync("xStructs.json", JSON.stringify(result.struct,  stripTags(['comment', 'pad', 'op', 'opcode']), 2))
  f.writeFileSync("xRequests.json", JSON.stringify(result.request,  stripTags(['comment', 'pad', 'op', 'opcode']), 2))
})
