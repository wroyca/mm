file(GLOB_RECURSE sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-gio
  ${sources}
)

target_compile_definitions(mm-gio
PUBLIC
  GIOMM_BUILD=1
)

target_link_libraries(mm-gio
PUBLIC
  mm-glib
)
