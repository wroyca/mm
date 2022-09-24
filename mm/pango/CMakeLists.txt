file(GLOB_RECURSE sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-pango
  ${sources}
)

target_compile_definitions(mm-pango
PUBLIC
  PANGOMM_BUILD=1
)

target_link_libraries(mm-pango
PUBLIC
  mm-glib
  mm-gio
  mm-cairo
)
