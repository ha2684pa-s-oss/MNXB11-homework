cmake_minimum_required(VERSION 3.10)
project(PI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Werror -march=native")

# Use root-config to get proper flags
find_program(ROOTCONFIG_EXEC root-config REQUIRED)

execute_process(COMMAND ${ROOTCONFIG_EXEC} --cflags
  OUTPUT_VARIABLE ROOT_CFLAGS_RAW
  OUTPUT_STRIP_TRAILING_WHITESPACE)

execute_process(COMMAND ${ROOTCONFIG_EXEC} --libs
  OUTPUT_VARIABLE ROOT_LIBS_RAW
  OUTPUT_STRIP_TRAILING_WHITESPACE)

# Split into lists (IMPORTANT)
separate_arguments(ROOT_CFLAGS_LIST UNIX_COMMAND "${ROOT_CFLAGS_RAW}")
separate_arguments(ROOT_LIBS_LIST UNIX_COMMAND "${ROOT_LIBS_RAW}")

# Make lists available to subdirectories
set(ROOT_CFLAGS_LIST ${ROOT_CFLAGS_LIST} CACHE INTERNAL "")
set(ROOT_LIBS_LIST ${ROOT_LIBS_LIST} CACHE INTERNAL "")

add_subdirectory(src)

