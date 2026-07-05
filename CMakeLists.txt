cmake_minimum_required(VERSION 3.16)

project(RestApiLearning)

set(CMAKE_CXX_STANDARD 17)

add_executable(
    rest_api
    src/main.cpp
    src/json_utils.cpp
)
target_include_directories(rest_api PRIVATE
    include
    /home/soham/Crow/include
)