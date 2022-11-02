file(GLOB_RECURSE mm-pango CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-pango
  ${mm-pango}
)

target_compile_definitions(mm-pango
PUBLIC
  PANGOMM_BUILD
)

target_link_libraries(mm-pango
PUBLIC
  mm-glib
  mm-gio
  mm-cairo
)
