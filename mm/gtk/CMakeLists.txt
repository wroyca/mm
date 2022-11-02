file(GLOB_RECURSE mm-gtk CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-gtk
  ${mm-gtk}
)

target_compile_definitions(mm-gtk
PUBLIC
  GTKMM_BUILD
)

target_link_libraries(mm-gtk
PUBLIC
 mm-pango
)
