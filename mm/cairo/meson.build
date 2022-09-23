mm_cairo_sources = [
  'mm-cairo.h',
  'context.cc',
  'context.h',
  'context_private.h',
  'context_surface_quartz.cc',
  'context_surface_win32.cc',
  'context_surface_xlib.cc',
  'device.cc',
  'device.h',
  'enums.h',
  'exception.cc',
  'exception.h',
  'fontface.cc',
  'fontface.h',
  'fontoptions.cc',
  'fontoptions.h',
  'matrix.cc',
  'matrix.h',
  'mm-cairoconfig.h',
  'path.cc',
  'path.h',
  'pattern.cc',
  'pattern.h',
  'private.cc',
  'private.h',
  'quartz_font.cc',
  'quartz_font.h',
  'quartz_surface.cc',
  'quartz_surface.h',
  'refptr.h',
  'region.cc',
  'region.h',
  'scaledfont.cc',
  'scaledfont.h',
  'script.cc',
  'script.h',
  'script_surface.cc',
  'script_surface.h',
  'surface.cc',
  'surface.h',
  'types.h',
  'win32_font.cc',
  'win32_font.h',
  'win32_surface.cc',
  'win32_surface.h',
  'xlib_surface.cc',
  'xlib_surface.h'
]

mm_cairo_cpp_args = ['-DCAIROMM_BUILD=1']

mm_cairo_include_directories = [
  '..' / '..',
  '..' / '..' / 'subprojects' / 'libsigcplusplus'
]

mm_cairo_dependencies = [
  dependency('sigc++-3.0', fallback:['sigc++-3.0']),
  dependency('gobject-2.0'),
  dependency('glib-2.0'),
  dependency('gio-2.0'),
  dependency('gio-unix-2.0'),
  dependency('cairo')
]

mm_cairo_library = library('mm-cairo',
  mm_cairo_sources,
  dependencies: mm_cairo_dependencies,
  implicit_include_directories: false,
  include_directories: mm_cairo_include_directories,
  cpp_args: mm_cairo_cpp_args,
  install: true
)
