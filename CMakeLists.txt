cmake_minimum_required(VERSION 2.8)


set (CMAKE_C_COMPILER clang)
set (CMAKE_CXX_COMPILER clang++)

#set (CMAKE_CXX_FLAGS -std=c++11)
#set (CMAKE_CXX_FLAGS /EHsc /NODEFAULTLIB:libcmt /NODEFAULTLIB:msvcrt )


project( tanaka )

include_directories( "ext/glm" )
include_directories( "ext/glfw-3.0.3.bin.WIN32/include" )
include_directories( "ext/glew-1.10.0/include" )
include_directories( "src" )

link_directories( "${CMAKE_SOURCE_DIR}/ext/glew-1.10.0/lib/Release/Win32" )
link_directories( "${CMAKE_SOURCE_DIR}/ext/glfw-3.0.3.bin.WIN32/lib-msvc110")

add_subdirectory( src )
