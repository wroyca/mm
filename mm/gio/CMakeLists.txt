file(GLOB_RECURSE mm-gio CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-gio STATIC
  ${mm-gio}
)

target_compile_definitions(mm-gio
PUBLIC
  GIOMM_BUILD
)

target_link_libraries(mm-gio
PUBLIC
  mm-glib
)
