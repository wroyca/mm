file (
GLOB_RECURSE
  mm-examples
CONFIGURE_DEPENDS
RELATIVE
${CMAKE_CURRENT_SOURCE_DIR}
  *.cpp
  *.hpp
)

add_executable (mm-examples
  ${mm-examples}
)

target_link_libraries (mm-examples
PUBLIC
  mm::adw
  mm::gtk
  mm::glib
  mm::gio
  mm::cairo
  mm::pango
  mm::gdk
)
