srcdir = "."
blddir = "build"
VERSION = "0.0.1"

def set_options(opt):
  opt.tool_options("compiler_cxx")

def configure(conf):
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")
  conf.env.append_value('LINKFLAGS', "/usr/lib/libxcb.so.1")
  conf.check_cfg(package='libxcb1-dev', args='--cflags --libs', uselib_store='XCB')

def build(bld):
  obj = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  obj.cxxflags = ["-g", "-D_LARGEFILE_SOURCE", "-Wall"]
  obj.target = 'xcb'
  obj.source = "./src/xcb.cc"
  obj.uselib = "LIBXCB"
