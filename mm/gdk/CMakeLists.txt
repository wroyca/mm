file(GLOB_RECURSE sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-gdk STATIC
  ${sources}
)

target_compile_definitions(mm-gdk
PUBLIC
  GDKMM_BUILD=1
)

target_link_libraries(mm-gdk
PUBLIC
  mm-glib
  mm-gio
  mm-cairo
  mm-pango
)
