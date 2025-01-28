# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "digital_clock\\CMakeFiles\\digital_clock_autogen.dir\\AutogenUsed.txt"
  "digital_clock\\CMakeFiles\\digital_clock_autogen.dir\\ParseCache.txt"
  "digital_clock\\digital_clock_autogen"
  "timezone_selector\\CMakeFiles\\timezone_selector_autogen.dir\\AutogenUsed.txt"
  "timezone_selector\\CMakeFiles\\timezone_selector_autogen.dir\\ParseCache.txt"
  "timezone_selector\\timezone_selector_autogen"
  )
endif()
