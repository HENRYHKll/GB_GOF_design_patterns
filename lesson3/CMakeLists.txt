cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SBomber1)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(SBomber1 ${SOURCES})


include(CTest)
add_test(NAME chec_SBomber1
    COMMAND SBomber1)

