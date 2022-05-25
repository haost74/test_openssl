cmake_minimum_required(VERSION 3.8)
project(app)



#set(OPENSSL_USE_STATIC_LIBS ON)
#set(OPENSSL_USE_STATIC_LIBS OFF)

include(FetchContent)
FetchContent_Declare(
  ssl_content
  URL      https://github.com/janbar/openssl-cmake/archive/refs/tags/1.1.1k-20210430.tar.gz
  URL_HASH MD5=f4294e5de7ebb20f9a695155660f1afd
)
FetchContent_MakeAvailable(ssl_content)
add_library(OpenSSL::SSL ALIAS ssl)
add_library(OpenSSL::Crypto ALIAS crypto)


add_executable(app main.cpp src/generate.cpp)
target_link_libraries(app
    PRIVATE
    OpenSSL::Crypto
    OpenSSL::SSL
)