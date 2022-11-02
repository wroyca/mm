# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.24 FATAL_ERROR)
project ("MM")

# Forces CXX standard version on all subprojects.
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Checks for all the given modules, setting a variety of result variables in
# the calling scope.
#
find_package      (PkgConfig  REQUIRED)
pkg_check_modules (GTK        REQUIRED gtk4)
pkg_check_modules (LIBADWAITA REQUIRED libadwaita-1)
pkg_check_modules (CAIRO      REQUIRED cairo)
pkg_check_modules (GIO        REQUIRED gio-2.0)
pkg_check_modules (GLIB       REQUIRED glib-2.0)
pkg_check_modules (GOBJECT    REQUIRED gobject-2.0)
pkg_check_modules (PANGO      REQUIRED pango)
pkg_check_modules (PANGOCAIRO REQUIRED pangocairo)
pkg_check_modules (SIGC       REQUIRED sigc++-3.0)

link_libraries (
  ${GTK4_LIBRARIES}
  ${LIBADWAITA_LIBRARIES}
  ${GOBJECT_LIBRARIES}
  ${GLIB_LIBRARIES}
  ${GIO_LIBRARIES}
  ${SIGC_LIBRARIES}
  ${CAIRO_LIBRARIES}
  ${PANGO_INCLUDE_DIRS}
  ${PANGOCAIRO_INCLUDE_DIRS}
)

include_directories (
  ${GTK4_INCLUDE_DIRS}
  ${LIBADWAITA_INCLUDE_DIRS}
  ${GOBJECT_INCLUDE_DIRS}
  ${GLIB_INCLUDE_DIRS}
  ${GIO_INCLUDE_DIRS}
  ${SIGC_INCLUDE_DIRS}
  ${CAIRO_INCLUDE_DIRS}
  ${PANGO_INCLUDE_DIRS}
  ${PANGOCAIRO_INCLUDE_DIRS}
)

link_directories (
  ${GTK4_LIBRARY_DIRS}
  ${LIBADWAITA_LIBRARY_DIRS}
)

add_compile_options(/MP)

# Treat mm/ as a workspace.
#
include_directories (${CMAKE_SOURCE_DIR})

# Include sub-projects.
#
add_subdirectory ("mm")
