file(GLOB_RECURSE mm-cairo CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-cairo
  ${mm-cairo}
)

target_compile_definitions(mm-cairo
PUBLIC
  CAIROMM_BUILD
 _USE_MATH_DEFINES
)

target_link_libraries(mm-cairo
PUBLIC
  mm-glib
  mm-gio
)
