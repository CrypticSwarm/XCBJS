#ifndef __XCBJS_CONFIG__
#define __XCBJS_CONFIG__

namespace XCBJS {

class Config {
public:
  static xcb_connection_t *connection;
};

xcb_connection_t *Config::connection = 0;

}

#endif
