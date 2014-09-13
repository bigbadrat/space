cmake_minimum_required(VERSION 2.8)


set (CMAKE_C_COMPILER clang)
set (CMAKE_CXX_COMPILER clang++)

#set (CMAKE_CXX_FLAGS -std=c++11)
#set (CMAKE_CXX_FLAGS /EHsc /NODEFAULTLIB:libcmt /NODEFAULTLIB:msvcrt )


project( tanaka )

include_directories( "ext/glm" )
include_directories( "ext/glfw/include" )
include_directories( "ext/glew/include" )
include_directories( "src" )

link_directories( "${CMAKE_SOURCE_DIR}/ext/glew/lib" )
link_directories( "${CMAKE_SOURCE_DIR}/ext/glfw/lib")

add_subdirectory( src )
