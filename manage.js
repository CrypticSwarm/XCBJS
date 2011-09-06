var xcb = require ('./build/default/xcb')
  , wins = []
  , width = 800
  , height = 600
  , curGroup = 0
  , groups = [[]]
  , root = xcb.getScreen()
console.log('root: ', root)

function mod(x, by) {
  return (x > 0) ? x % by
         : (by - (Math.abs(x) % by)) % by
}

function nextGroup(x) {
  var t = curGroup + x
  t = mod(t, groups.length)
  changeGroup(t)
}

function sizeWindows() {
  var group = groups[curGroup]
    , len = group.length
    , winWidth = Math.floor(width / len)
  group.forEach(function(window, i) {
    console.log("\t*resizing window : ", window)
    xcb.ConfigureWindow({ window: window, value_mask: 15, value_list: [i * winWidth, 0, winWidth, 600] })
  })
  xcb.flush();
}

xcb.QueryTree({ window: root.root }, function(qtree) {
  console.log("Query Tree Response")
  console.log(qtree)
  qtree.children.forEach(function(child) {
    xcb.GetWindowAttributes({ window: child }, function(attrs) {
      console.log('wid', child, attrs)
      if (!(attrs.override_redirect || attrs.map_state == xcb.MapState.Unmapped)) {
        console.log('managing', child)
        manage(child)
      }
    })
  })
})

console.log(xcb.getSetup());

function changeGroup(num) {
  if (num === curGroup) return
  console.log('switching groups to', num)
  groups[curGroup].forEach(function(window) {
    xcb.UnmapWindow({ window: window })
  })
  curGroup = num
  groups[curGroup].forEach(function(window) {
    xcb.MapWindow({ window: window })
  })
  sizeWindows()
}

xcb.manageWindows();
xcb.onCreate = function(ev) {
  console.log("Window being created, indexing", ev.window)
  console.log('\tParent -> ', ev.parent)
  xcb.GetWindowAttributes({ window: ev.window }, function(reply) {
    console.log('Response from window ', ev.window, ' configuration!', reply)
  })
  manage(ev.window)
}

function manage(wid) {
  wins.push(wid);
  if (groups[curGroup].length == 2) groups.push([])
    , changeGroup(groups.length - 1)
  groups[curGroup].push(wid)
  sizeWindows()
}

xcb.onDestroy = function(ev) {
  var win = ev.window
    , index = wins.indexOf(win)
  if (index != -1) {
    console.log('window destroyed, removing from index', win)
    wins.splice(index, 1)
    groups.forEach(function(group, i) {
      var index = group.indexOf(win)
      if (index != -1) {
        group.splice(index, 1)
        if (i === curGroup) sizeWindows()
      }
    })
  }
  else console.log('we werent watching the window', win)
}

xcb.onMapRequest = function(ev) {
  console.log('\tmapping win', ev.window)
  xcb.MapWindow({ window: ev.window })
  xcb.flush();
}

xcb.onUnmap = function(ev) {
  console.log('\t*unmapping win', ev.window)
}

xcb.onKeyPress = function(event) {
  console.log('Keypress')
  console.log(event)
  if (event.state & 8) {
    switch (event.detail) {
      case 113: return nextGroup(-1)
      case 114: return nextGroup(1)
      case 10:  return changeGroup(0)
      case 11:  return changeGroup(1)
      case 12:  return changeGroup(2)
    }
  }
}
