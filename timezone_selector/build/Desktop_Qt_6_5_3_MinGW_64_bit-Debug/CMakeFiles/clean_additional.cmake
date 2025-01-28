# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\timezone_selector_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\timezone_selector_autogen.dir\\ParseCache.txt"
  "timezone_selector_autogen"
  )
endif()
