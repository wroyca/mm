# CMakeList.txt : CMake project for Pango, include source and define
# project specific logic here.
#

# Collect a list of source files from the source tree.
#
file (
GLOB_RECURSE
  mm-pango
CONFIGURE_DEPENDS
RELATIVE
${CMAKE_CURRENT_SOURCE_DIR}
  *.cpp
  *.hpp
)

# Add source collection to Pango's library.
#
add_library (mm-pango STATIC
  ${mm-pango}
)

# Specify libraries or flags to use when linking Pango's target and/or its
# dependents.
#
target_link_libraries (mm-pango
PUBLIC
  mm-glib
  mm-gio
  mm-cairo
)

# Specifies compile definitions to use when compiling Pango's target.
#
target_compile_definitions (mm-pango
PUBLIC
  PANGOMM_BUILD
  PANGOMM_STATIC_LIB
)

# Specifies include directories to use when compiling Pango target.
#
target_include_directories (mm-pango
PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
PRIVATE
  ${PROJECT_SOURCE_DIR}
)

#
# Allows Pango to be distributed in a clean form and isolates users from the details of the build process.
#

# Provides install directory variables as defined by the GNU Coding Standards.
#
include (GNUInstallDirs)

# Helpers functions for creating config files that can be included by other projects to find and use a package.
#
include (CMakePackageConfigHelpers)

# An ALIAS target which may be used interchangeably with a binary target name in read-only contexts.
#
add_library (mm::pango ALIAS mm-pango)

# Installs the binary files corresponding to targets built inside the project.
#
install (
TARGETS
  mm-pango
EXPORT
  mm-pango-targets
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
install (EXPORT mm-pango-targets
FILE
  mm-pango-targets.cmake
NAMESPACE
  mm::
DESTINATION
  "${MM_INSTALL_CONFIGDIR}"
)

# Create a version file for Pango.
#
write_basic_package_version_file (
  "${CMAKE_CURRENT_BINARY_DIR}/mm-pango-config-version.cmake"
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
  "${CMAKE_CURRENT_BINARY_DIR}/mm-pango-config-version.cmake"
DESTINATION
  "${MM_INSTALL_CONFIGDIR}"
)

# Export Pango for outside projects to use it directly from the current project's build tree, without installation.
#
export (
EXPORT
 mm-pango-targets
FILE
  "${CMAKE_CURRENT_BINARY_DIR}/mm-pango-targets.cmake"
NAMESPACE
  mm::
)

# Store the current build directory in the CMake user package registry for package.
#
export (PACKAGE mm-pango)
