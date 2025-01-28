# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\digital_clock_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\digital_clock_autogen.dir\\ParseCache.txt"
  "digital_clock_autogen"
  )
endif()
