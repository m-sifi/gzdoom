# - Find smlib64
# Find the zmusic includes and library
#
#  LIBSM64_INCLUDE_DIR - where to find smlib64.h
#  LIBSM64_LIBRARIES   - List of libraries when using smlib64
#  LIBSM64_FOUND       - True if smlib64 found.

if(LIBSM64_INCLUDE_DIR AND LIBSM64_LIBRARIES)
    # Already in cache, be silent
    set(LIBSM64_FIND_QUIETLY TRUE)
endif()

find_path(LIBSM64_INCLUDE_DIR libsm64.h)

find_library(LIBSM64_LIBRARIES NAMES libsm64)
mark_as_advanced(LIBSM64_LIBRARIES LIBSM64_INCLUDE_DIR)

# handle the QUIETLY and REQUIRED arguments and set LIBSM64_FOUND to TRUE if 
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(libsm64 DEFAULT_MSG LIBSM64_LIBRARIES LIBSM64_INCLUDE_DIR)
