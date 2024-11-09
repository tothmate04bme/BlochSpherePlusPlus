# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/hellocube_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/hellocube_autogen.dir/ParseCache.txt"
  "hellocube_autogen"
  )
endif()
