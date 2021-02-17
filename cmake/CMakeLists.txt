cmake_minimum_required(VERSION 3.10)
include(CheckIncludeFiles)
project(simple_asio)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

check_include_files(openssl/opensslv.h HAVE_OPENSSL_HEADERS)
if(NOT HAVE_OPENSSL_HEADERS)
    message(FATAL_ERROR "OpenSSL headers are not present")
endif()

find_library(OPENSSL ssl)
if(NOT OPENSSL)
    message(FATAL_ERROR "OpenSSL is not installed")
endif()

set(_simple_asio_debug_flags -DDEBUG)
set(_simple_asio_release_flags -Wall)

add_executable(simple_asio ../tests/main.cpp)
target_include_directories(simple_asio PUBLIC ../src)
target_compile_options(simple_asio PUBLIC "$<$<CONFIG:DEBUG>:${_simple_asio_debug_flags}>")
target_compile_options(simple_asio PUBLIC "$<$<CONFIG:RELEASE>:${_simple_asio_release_flags}>")

target_link_libraries(simple_asio ssl crypto)
