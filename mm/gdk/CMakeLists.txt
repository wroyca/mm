# CMakeList.txt : CMake project for Gdk, include source and define
# project specific logic here.
#

# Collect a list of source files from the source tree.
#
file (
GLOB_RECURSE
  mm-gdk
CONFIGURE_DEPENDS
RELATIVE
${CMAKE_CURRENT_SOURCE_DIR}
  *.cpp
  *.hpp
)

# Add source collection to Gdk's library.
#
add_library (mm-gdk
  ${mm-gdk}
)

# Specify libraries or flags to use when linking Gdk's target and/or its
# dependents.
#
target_link_libraries (mm-gdk
PUBLIC
  mm-glib
  mm-gio
  mm-cairo
  mm-pango
)

# Specifies compile definitions to use when compiling Gdk's target.
#
target_compile_definitions (mm-gdk
PUBLIC
  GDKMM_BUILD
  GDKMM_STATIC_LIB
)

# Specifies include directories to use when compiling Gdk target.
#
target_include_directories (mm-gdk
PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
PRIVATE
  ${PROJECT_SOURCE_DIR}
)

#
# Allows Gdk to be distributed in a clean form and isolates users from the details of the build process.
#

# Provides install directory variables as defined by the GNU Coding Standards.
#
include (GNUInstallDirs)

# Helpers functions for creating config files that can be included by other projects to find and use a package.
#
include (CMakePackageConfigHelpers)

# An ALIAS target which may be used interchangeably with a binary target name in read-only contexts.
#
add_library (mm::gdk ALIAS mm-gdk)

# Installs the binary files corresponding to targets built inside the project.
#
install (
TARGETS
  mm-gdk
EXPORT
  mm-gdk-targets
LIBRARY
DESTINATION
  "${CMAKE_INSTALL_LIBDIR}"
ARCHIVE
DESTINATION
  "${CMAKE_INSTALL_LIBDIR}"
)

# General-purpose file installation, which is typically used for header files, documentation, and data files required by your software.
#
install (
DIRECTORY
  "${PROJECT_SOURCE_DIR}/include/"
DESTINATION
  "${CMAKE_INSTALL_INCLUDEDIR}"
)

# Generates and installs a CMake file containing code to import targets from the installation tree into another project.
#
install (EXPORT mm-gdk-targets
FILE
  mm-gdk-targets.cmake
NAMESPACE
  mm::
DESTINATION
  "${MM_INSTALL_CONFIGDIR}"
)

# Create a version file for Gdk.
#
write_basic_package_version_file (
  "${CMAKE_CURRENT_BINARY_DIR}/mm-gdk-config-version.cmake"
VERSION
  ${PROJECT_VERSION} # TODO
COMPATIBILITY
  SameMajorVersion
)

# Create a config file for a project.
#
configure_package_config_file (
  "${PROJECT_SOURCE_DIR}/cmake/mm-config.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/mm-config.cmake"
INSTALL_DESTINATION
  "${MM_INSTALL_CONFIGDIR}"
)

# Install the config and version files.
#
install (
FILES
  "${CMAKE_CURRENT_BINARY_DIR}/mm-config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/mm-gdk-config-version.cmake"
DESTINATION
  "${MM_INSTALL_CONFIGDIR}"
)

# Export Gdk for outside projects to use it directly from the current project's build tree, without installation.
#
export (
EXPORT
 mm-gdk-targets
FILE
  "${CMAKE_CURRENT_BINARY_DIR}/mm-gdk-targets.cmake"
NAMESPACE
  mm::
)

# Store the current build directory in the CMake user package registry for package.
#
export (PACKAGE mm-gdk)
