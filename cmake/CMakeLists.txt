cmake_minimum_required(VERSION 3.10)

project(simple_asio)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(_simple_asio_debug_flags -DDEBUG)
set(_simple_asio_release_flags -Wall)

add_executable(simple_asio ../tests/main.cpp)
target_include_directories(simple_asio PUBLIC ../src)
target_compile_options(simple_asio PUBLIC "$<$<CONFIG:DEBUG>:${_simple_asio_debug_flags}>")
target_compile_options(simple_asio PUBLIC "$<$<CONFIG:RELEASE>:${_simple_asio_release_flags}>")

