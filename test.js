var xcb = require ('./build/default/xcb')
  , rects = 
    [ { rect: [ 50, 50, 100, 100 ], dir: 1, range: [0, 100]   }
    , { rect: [ 100, 200, 90, 90 ], dir: 2, range: [80, 120]  }
    , { rect: [ 20, 30, 15, 15   ], dir: 3, range: [10, 50]   }
    ]
  , windows = [xcb.generateId(), xcb.generateId(), xcb.generateId()]
  , draw = [xcb.generateId(), xcb.generateId(), xcb.generateId(), xcb.generateId()]
  , borderWidth = 5
  , width = 800
  , split = 400
  , dir = 5
  , screen = xcb.getScreen()

windows.forEach(function(window, i) {
  setTimeout(function(){
    xcb.createWindow(
      { depth: 0
      , wid: window
      , parent: screen.root
      , x: 400 * (i % 2)
      , y: 300 * Math.floor(i/2)
      , width: 400 - borderWidth
      , height: 300 - borderWidth
      , border_width: borderWidth
      , 'class': 1
      , visual: screen.root_visual
      , value_mask: 2050
      , value_list: [screen.white_pixel, 32768]
      })
    xcb.createGC(draw[i], window)
    xcb.mapWindow(window)
  }, 1000 * i + 1000)
})
xcb.flush()

setInterval(function() {
  windows.forEach(function(window, i) {
    xcb.clearArea(window, 0, 0, 400, 400)
    rects.forEach(function(rect) {
      rect.rect[0] += rect.dir
      rect.rect[1] += rect.dir
      rect.rect[2] += rect.dir
      rect.rect[3] += rect.dir
      if (rect.rect[0] >= rect.range[1] || rect.rect[0] <= rect.range[0]) rect.dir *= -1
      xcb.drawRect(window, draw[i], { x: rect.rect[0], y: rect.rect[1], width: rect.rect[2], height: rect.rect[3]})
    })
  })
  split += dir
  if (split > 500 || split < 300) dir *= -1
  xcb.flush()
}, 100);
