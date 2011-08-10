var xcb = require ('./build/default/xcb')
  , wins = []
  , width = 800
  , height = 600
  , curGroup = 0
  , groups = [[]]

function sizeWindows() {
  var len = wins.length
    , winWidth = Math.floor(width / len)
  wins.forEach(function(window, i) {
    console.log("configuring window : ", window)
    xcb.configureWindow(window, 15, [i * winWidth, 0, winWidth, 600])
    xcb.mapWindow(window)
  })
  xcb.flush();
}

function changeGroups(num) {
  if (num === curGroup) return
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
xcb.onMap = function(win) {
  wins.push(win);
  if (groups[curGroup].length == 2) groups.push([])
    , changeGroups(groups.length - 1)
  groups[curGroup].push(win)
  sizeWindows()
  console.log("Window being mapped", win);
}

xcb.onUnMap = function(win) {
  console.log('window being umapped. Do i need to call unmapwindow?')
  var index = wins.indexOf(win)
  if (index != -1) wins.splice(index, 1)
  else console.log('we werent watching the window', win)
  sizeWindows()
}

