# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Software_laser_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Software_laser_autogen.dir\\ParseCache.txt"
  "Software_laser_autogen"
  )
endif()
