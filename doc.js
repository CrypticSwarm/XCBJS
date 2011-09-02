var repl = require('repl')
  , x = require('./build/default/xcb')
  , xcbhelp = repl.start('XCB > ')

xcbhelp.context.x = x

//In the REPL just type in any X Request, Struct, or Event name to get more information.
//Example:
//x.help('CreateGC')
