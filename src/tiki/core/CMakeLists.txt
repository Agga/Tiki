

add_source( ${CMAKE_CURRENT_SOURCE_DIR} sources )
add_library( core STATIC ${sources} )
target_link_libraries( core sdl2 )