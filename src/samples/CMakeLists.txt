


add_source( ${CMAKE_CURRENT_SOURCE_DIR} source )
add_executable( samples ${source} )
target_link_libraries( samples core )
