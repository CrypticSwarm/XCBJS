var xcb = require ('./build/default/xcb')
  , wins = []
  , width = 800
  , height = 600

xcb.manageWindows();
xcb.onMap = function(win) {
  wins.push(win);
  var len = wins.length
    , winWidth = Math.floor(width / len)
  wins.forEach(function(window, i) {
    console.log("configuring window : ", window)
    xcb.configureWindow(window, 15, [i * winWidth, 0, winWidth, 600])
    xcb.mapWindow(window)
  })
  xcb.flush();
  console.log("Window being mapped", win);
}
