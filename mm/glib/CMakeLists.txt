file(GLOB_RECURSE mm-glib CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-glib STATIC
  ${mm-glib}
)

target_compile_definitions(mm-glib
PUBLIC
  GLIBMM_BUILD
)
