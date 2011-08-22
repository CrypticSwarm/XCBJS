var xcb = require ('./build/default/xcb')
  , wins = []
  , width = 800
  , height = 600
  , curGroup = 0
  , groups = [[]]

function nextGroup(x) {
  var t = curGroup + x
  t %= groups.length
  changeGroups(t)
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

function changeGroups(num) {
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
    , changeGroups(groups.length - 1)
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

xcb.onKeyDown = function(mask) {
  console.log(mask);
  if (mask & 8) {
    console.log("Alt Pressed");
    nextGroup(1)
  }
}
