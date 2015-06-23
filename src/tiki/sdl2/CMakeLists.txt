


if( TIKI_WINDOWS )
	add_library( sdl2 STATIC IMPORTED GLOBAL )
	set_target_properties( sdl2 PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include )

	set_target_properties( sdl2 PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/windows/x64/SDL2.lib )	

	#set_target_properties( sdl2 PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/windows/x64/SDL2.dll )
	#set_target_properties( sdl2 PROPERTIES IMPORTED_IMPLIB ${CMAKE_CURRENT_SOURCE_DIR}/windows/x64/SDL2.lib )

	message( STATUS "FIX ME | copy of dlls seems incorrect" )
	
	foreach( config ${CMAKE_CONFIGURATION_TYPES} )
		file( COPY ${CMAKE_CURRENT_SOURCE_DIR}/windows/x64/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${config} )
	endforeach()
endif()