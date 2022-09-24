file(GLOB_RECURSE sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

add_library(mm-cairo
  ${sources}
)

target_compile_definitions(mm-cairo
PUBLIC
  CAIROMM_BUILD=1
)
