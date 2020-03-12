cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER "/usr/bin/g++" CACHE STRING "g++ compiler" FORCE)
set(CMAKE_C_COMPILER "/usr/bin/gcc" CACHE STRING "gcc compiler" FORCE)
set(CMAKE_C_FLAG "${CMAKE_C_FLAGS} -g -O0")
set(CMAKE_CXX_FLAG "${CMAKE_C_FLAGS} -g -O0 -lboost_system")


project(ESP_TEST
        LANGUAGES C CXX)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)
find_package(Boost 1.65.1 REQUIRED
             COMPONENTS date_time system)
find_package(Boost COMPONENTS system filesystem REQUIRED)

message("## Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")  # デバッグ用：解決したパスを表示
message("## Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")  # デバッグ用：解決したパスを表示

file(GLOB MAIN_SOURCES main.cpp src/*.cpp)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(test ${MAIN_SOURCES})

target_link_libraries(test
    ${Boost_LIBRARY_DIRS}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    )

