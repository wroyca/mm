set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4       REQUIRED gtk4)
pkg_check_modules(GOBJECT    REQUIRED gobject-2.0)
pkg_check_modules(GLIB       REQUIRED glib-2.0)
pkg_check_modules(GIO        REQUIRED gio-2.0)
pkg_check_modules(SIGC       REQUIRED sigc++-3.0)
pkg_check_modules(CAIRO      REQUIRED cairo)
pkg_check_modules(PANGO      REQUIRED pango)
pkg_check_modules(PANGOCAIRO REQUIRED pangocairo)

# With a proper interface the directories would be exported, but unfortunately
# this is not the case here, so we have to import them ourselves.

link_libraries(
  ${GTK4_LIBRARIES}
  ${GOBJECT_LIBRARIES}
  ${GLIB_LIBRARIES}
  ${GIO_LIBRARIES}
  ${SIGC_LIBRARIES}
  ${CAIRO_LIBRARIES}
  ${PANGO_INCLUDE_DIRS}
  ${PANGOCAIRO_INCLUDE_DIRS}
)

include_directories(
  ${GTK4_INCLUDE_DIRS}
  ${GOBJECT_INCLUDE_DIRS}
  ${GLIB_INCLUDE_DIRS}
  ${GIO_INCLUDE_DIRS}
  ${SIGC_INCLUDE_DIRS}
  ${CAIRO_INCLUDE_DIRS}
  ${PANGO_INCLUDE_DIRS}
  ${PANGOCAIRO_INCLUDE_DIRS}
)

# unix-print is not properly imported from pkg_check_modules(GTK4 ...)
# NOTE: We will eventually have to handle both Windows and Mac.

if (EXISTS /usr/include/gtk-4.0/unix-print)
  include_directories(/usr/include/gtk-4.0/unix-print)
endif ()

add_subdirectory(cairo)
add_subdirectory(gdk)
add_subdirectory(gio)
add_subdirectory(glib)
add_subdirectory(gtk)
add_subdirectory(pango)
add_subdirectory(examples)


