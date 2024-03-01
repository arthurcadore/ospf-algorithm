cmake_minimum_required(VERSION 3.13)
project(route_finder)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)

add_executable(route_finder src/main.cpp src/dijkstra.cpp src/parse_csv.cpp src/router_remover.h src/router_remover.cpp)

add_custom_target(run
    COMMAND route_finder
    DEPENDS route_finder
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
