#u need to include both lib code and source code to link them even though u only include header in main
set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/part1.cpp
)

add_executable(part1 ${SRC})
target_link_libraries(part1 PRIVATE Catch2::Catch2WithMain)

#Set output directory for part1 executable
# set_target_properties(part1 PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/part1"
# )

#Add include directories for part1
target_include_directories(part1 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
