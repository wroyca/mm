file(GLOB_RECURSE sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-glib
  ${sources}
)

target_compile_definitions(mm-glib
PUBLIC
  GLIBMM_BUILD=1
)
