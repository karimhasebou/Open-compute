
# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
set(HEADER_LIST "${OpenCompute_SOURCE_DIR}/open_compute/vector_math.h")
# Make an automatic library - will be static or dynamic based on user setting
add_library(open_compute SHARED vector_math.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
# target_include_directories(open_compute PUBLIC ../include)

# This depends on (header only) boost

# All users of this library will need at least C++11
target_compile_features(open_compute PUBLIC cxx_std_11)


# IDEs should put the headers in a nice place
#source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
