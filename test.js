var xcb = require ('./build/default/xcb')
  , rect = [50, 50, 100, 100]
  , dir = 1

setInterval(function() {
  rect[0] += dir
  rect[1] += dir
  rect[2] += dir
  rect[3] += dir
  if (rect[0] > 100) dir = -1
  else if (rect[0] < 50) dir = 1
  xcb.drawRect.apply(null, rect)
}, 100);


