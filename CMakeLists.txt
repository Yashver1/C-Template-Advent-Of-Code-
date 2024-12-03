cmake_minimum_required(VERSION 3.20)
project(AOC CXX)
include(FetchContent)

#set where to store external dependencies
set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")

fetchcontent_declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0 
)

fetchcontent_declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)

fetchcontent_declare(
    cpr 
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG dec9422db3af470641f8b0d90e4b451c4daebf64
) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases



fetchcontent_makeavailable(cpr)
fetchcontent_makeavailable(argparse)
fetchcontent_makeavailable(Catch2)

#enable debugging information for step through
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")

set(DAY_NUMBER "1" CACHE STRING "DAY number to build")
option(COMPILE_SCRIPTS "Compile scripts directory" OFF)

if(COMPILE_SCRIPTS)
    add_subdirectory(scripts)
endif()

if (NOT COMPILE_SCRIPTS)
    add_subdirectory(day-${DAY_NUMBER}/part1)
    add_subdirectory(day-${DAY_NUMBER}/part2)
endif()
#better to manually compile scripts as it will be compiled less
# add_subdirectory(scripts)

add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_BINARY_DIR}/*
    COMMENT "Removing all files from build directory"
)



