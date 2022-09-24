file(GLOB_RECURSE sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_executable(mm-examples
  ${sources}
)

target_link_libraries(mm-examples
PUBLIC
  mm-gtk
  mm-glib
  mm-gio
  mm-cairo
  mm-pango
  mm-gdk
)
