#include <node.h>
#include <string.h>
#include <xcb/xcb.h>
#include <unistd.h>
#include <iostream>


using namespace std;
using namespace node;
using namespace v8;

static xcb_connection_t *connection;
static xcb_screen_t *screen;
static xcb_gcontext_t black;
static xcb_window_t window;

class XCBJS {

public:
  static void Init(Handle<Object> target) {
    HandleScope scope;
    connection = xcb_connect(NULL, NULL);
    const xcb_setup_t      *setup  = xcb_get_setup(connection);
    xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator(setup);
    screen = iter.data;
    black = xcb_generate_id(connection);
    uint32_t        mask       = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    uint32_t        values[2]  = {screen->black_pixel, 0};
    mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    values[0] = screen->white_pixel;
    values[1] = XCB_EVENT_MASK_EXPOSURE;

    window = xcb_generate_id(connection);
    xcb_create_window(connection,                    /* Connection          */
      XCB_COPY_FROM_PARENT,          /* depth (same as root)*/
      window,                        /* window Id           */
      screen->root,                  /* parent window       */
      0, 0,                          /* x, y                */
      150, 150,                      /* width, height       */
      10,                            /* border_width        */
      XCB_WINDOW_CLASS_INPUT_OUTPUT, /* class               */
      screen->root_visual,           /* visual              */
      mask, values );                     /* masks, not used yet */

    mask      = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    values[0] = screen->black_pixel;
    values[1] = 0;
    xcb_create_gc(connection, black, window, mask, values);
    xcb_map_window(connection, window);
    xcb_flush(connection);
    eio_custom(XCBJS::ELoop, EIO_PRI_DEFAULT, XCBJS::Close, NULL);
    ev_ref(EV_DEFAULT_UC);
    NODE_SET_METHOD(target, "drawRect", XCBJS::DrawRect);
  }

  static int Close(eio_req *req) {
    return 0;
  }

  static int ELoop(eio_req *req) {
    xcb_generic_event_t *event;
    while (event = xcb_wait_for_event(connection)) {
      switch (event->response_type & ~0x80) {
        case XCB_EXPOSE:
        xcb_flush (connection);

        break;
        default:
        /* Unknown event type, ignore it */
        break;
      }
    }
    return 0;
  }

  static Handle<Value> DrawRect(const Arguments& args) {
    HandleScope scope;
    const char *usage = "usage: drawRect(x, y, width, height)";
    if (args.Length() != 4) {
      return ThrowException(Exception::Error(String::New(usage)));
    }
    xcb_rectangle_t rects[] =
    { { args[0]->Int32Value()
      , args[1]->Int32Value()
      , args[2]->Int32Value()
      , args[3]->Int32Value()
      } 
    };
    xcb_clear_area(connection, 0, window, 0, 0, 510, 510);
    xcb_poly_rectangle(connection, window, black, 1, rects);
    xcb_flush (connection);
    return Undefined();
  }

private:
};

extern "C" void
init (Handle<Object> target)
{
    HandleScope scope;
    XCBJS::Init(target);
}


