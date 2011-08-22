var xcb = require ('./build/default/xcb')
  , wins = []
  , width = 800
  , height = 600
  , curGroup = 0
  , groups = [[]]

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
    xcb.configureWindow(window, 15, [i * winWidth, 0, winWidth, 600])
  })
  xcb.flush();
}

function changeGroup(num) {
  if (num === curGroup) return
  console.log('switching groups to', num)
  groups[curGroup].forEach(function(window) {
    xcb.unmapWindow(window)
  })
  curGroup = num
  groups[curGroup].forEach(function(window) {
    xcb.mapWindow(window)
  })
  sizeWindows()
}

xcb.manageWindows();
xcb.onCreate = function(win) {
  console.log("Window being created, indexing", win);
  wins.push(win);
  if (groups[curGroup].length == 2) groups.push([])
    , changeGroup(groups.length - 1)
  groups[curGroup].push(win)
  sizeWindows()
}

xcb.onDestroy = function(win) {
  var index = wins.indexOf(win)
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

xcb.onMap = function(window) {
  console.log('\tmapping win', window)
  xcb.mapWindow(window)
  xcb.flush();
}

xcb.onUnMap = function(window) {
  console.log('\t*unmapping win', window)
}

xcb.onKeyDown = function(mask, code) {
  console.log('Keypress')
  console.log('\tmask =>', mask);
  console.log('\tdetail =>', code)

  if (mask & 8) {
    switch (code) {
      case 113: return nextGroup(-1)
      case 114: return nextGroup(1)
      case 10:  return changeGroup(0)
      case 11:  return changeGroup(1)
      case 12:  return changeGroup(2)
    }
  }
}
