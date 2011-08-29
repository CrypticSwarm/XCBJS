var xcb = require ('./build/default/xcb')
  , rects = 
    [ { rect: { x: 50, y: 50, width: 100, height: 100 }, dir: 1, range: [0, 100]   }
    , { rect: { x: 100, y: 200, width: 90, height: 90 }, dir: 2, range: [80, 120]  }
    , { rect: { x: 20, y: 30, width: 15, height: 15   }, dir: 3, range: [10, 50]   }
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
    xcb.mapWindow({ window: window })
  }, 1000 * i + 1000)
})
xcb.flush()

setInterval(function() {
  windows.forEach(function(window, i) {
    xcb.clearArea(window, 0, 0, 400, 400)
    rects.forEach(function(rect) {
      rect.rect.x += rect.dir
      rect.rect.y += rect.dir
      rect.rect.width += rect.dir
      rect.rect.height += rect.dir
      if (rect.rect.x >= rect.range[1] || rect.rect.x <= rect.range[0]) rect.dir *= -1
    })
    var rectList = rects.map(function(r) { return r.rect })
    xcb.drawRect({ drawable: window, gc: draw[i], rectangles_len: rectList.length, rectangles: rectList })
  })
  split += dir
  if (split > 500 || split < 300) dir *= -1
  xcb.flush()
}, 100);
