var xcb = require ('./build/default/xcb')
  , rects = 
    [ { rect: [ 50, 50, 100, 100 ], dir: 1, range: [0, 100]   }
    , { rect: [ 200, 400, 90, 90 ], dir: 2, range: [180, 220] }
    , { rect: [ 20, 30, 15, 15   ], dir: 3, range: [10, 50]   }
    ]

setInterval(function() {
  xcb.clearArea(0, 0, 600, 600)
  rects.forEach(function(rect) {
    rect.rect[0] += rect.dir
    rect.rect[1] += rect.dir
    rect.rect[2] += rect.dir
    rect.rect[3] += rect.dir
    if (rect.rect[0] >= rect.range[1] || rect.rect[0] <= rect.range[0]) rect.dir *= -1
    xcb.drawRect.apply(null, rect.rect)
  })
  xcb.flush()
}, 100);


