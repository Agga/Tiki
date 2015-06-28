cmake_minimum_required( VERSION 3.0 )

set (CMAKE_CONFIGURATION_TYPES "Debug;Release;Master" CACHE STRING "" FORCE )

project( tiki )

#include helper functions
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake )
include( helpers )

#compiler specific settings
if( WIN32 )
	include( windows )
elseif( APPLE )
	include( osx )
else()
	include( linux )
endif()

#default directories
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE} )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE} )

#add include directory for generated/ copyied files
include_directories( ${CMAKE_BINARY_DIR}/generated )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/tiki )

add_subdirectory( tiki )
add_subdirectory( samples )
