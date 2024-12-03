set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/part2.cpp
)
add_executable(part2 ${SRC})
target_link_libraries(part2 PRIVATE Catch2::Catch2WithMain)

#Set output directory for part2 executable
# set_target_properties(part2 PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/part2"
# )

#Add include directories for part2
target_include_directories(part2 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
