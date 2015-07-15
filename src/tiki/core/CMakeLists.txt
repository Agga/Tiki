

if( TIKI_WINDOWS )
	add_source_dir( ${CMAKE_CURRENT_SOURCE_DIR}/Windows sources )
endif()

add_source_dir( ${CMAKE_CURRENT_SOURCE_DIR}/Threading sources )
add_source_dir( ${CMAKE_CURRENT_SOURCE_DIR}/Window sources )
add_source_dir( ${CMAKE_CURRENT_SOURCE_DIR}/Util sources )
add_source_dir( ${CMAKE_CURRENT_SOURCE_DIR} sources )

add_library( core STATIC ${sources} )
target_link_libraries( core sdl2 )
