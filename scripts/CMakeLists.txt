set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.cpp)

set(CMAKE_CXX_STANDARD 20)


add_executable(AOC_parser ${SRC})
target_link_libraries(AOC_parser PRIVATE cpr::cpr)
target_link_libraries(AOC_parser PRIVATE argparse)
target_include_directories(AOC_parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#dont need header file as implementation is independent and does not need to be exported
# target_include_directories(parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)