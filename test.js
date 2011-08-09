var xcb = require ('./build/default/xcb')
  , rects = 
    [ { rect: [ 50, 50, 100, 100 ], dir: 1, range: [0, 100]   }
    , { rect: [ 100, 200, 90, 90 ], dir: 2, range: [80, 120] }
    , { rect: [ 20, 30, 15, 15   ], dir: 3, range: [10, 50]   }
    ]
  , windows = [xcb.generateId(), xcb.generateId(), xcb.generateId(), xcb.generateId()]
  , draw = [xcb.generateId(), xcb.generateId(), xcb.generateId(), xcb.generateId()]

windows.forEach(function(window, i) {
  xcb.createWindow(window, 400 * (i % 2), 300 * Math.floor(i/2), 398, 298)
  xcb.createGC(draw[i], window)
  xcb.mapWindow(window)
})
xcb.flush()


setInterval(function() {
  windows.forEach(function(window, i) {
    xcb.clearArea(window, 0, 0, 300, 300)
    rects.forEach(function(rect) {
      rect.rect[0] += rect.dir
      rect.rect[1] += rect.dir
      rect.rect[2] += rect.dir
      rect.rect[3] += rect.dir
      if (rect.rect[0] >= rect.range[1] || rect.rect[0] <= rect.range[0]) rect.dir *= -1
      xcb.drawRect(window, draw[i], rect.rect[0], rect.rect[1], rect.rect[2], rect.rect[3])
    })
  })
  xcb.flush()
}, 100);


