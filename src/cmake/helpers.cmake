
# finds all files matching the default regex for sources
# and adds those into source_groups for vs/xcode
#
# cd  | current directory
# out | appends result to out variable
function( add_source_dir cd out )

	#get all files from the current directory
	FILE( GLOB src ${cd}/*.c ${cd}/*.cc ${cd}/*.cpp ${cd}/*.h ${cd}/*.hh ${cd}/*.hpp ${cd}/*.inl )
	SET( ${out} ${${out}} ${src} PARENT_SCOPE )

	#set filters for msvc/ xcode
	string( REPLACE ${CMAKE_CURRENT_SOURCE_DIR} "" group "/${cd}" )		
	string( REPLACE "/" "\\" group "${group}" )

	source_group( ${group} FILES ${src} )

endfunction( add_source_dir )


# recursively calls add_source_dir for all subdirectories
#
# cd  | current directory to begin with
# out | appends results to out varibale
function( add_source cd out )

	#call function recursive for all directories
	FILE( GLOB dirs RELATIVE ${cd} ${cd}/* )
	foreach( dir ${dirs} )
		if(IS_DIRECTORY ${cd}/${dir} )
			add_source( ${cd}/${dir} ${out} )
		endif()
	endforeach()

	#get all files from the current directory
	FILE( GLOB src ${cd}/*.c ${cd}/*.cc ${cd}/*.cpp ${cd}/*.h ${cd}/*.hh ${cd}/*.hpp ${cd}/*.inl )
	SET( ${out} ${${out}} ${src} PARENT_SCOPE )

	#set filters for msvc/ xcode
	string( REPLACE ${CMAKE_CURRENT_SOURCE_DIR} "" group "/${cd}" )		
	string( REPLACE "/" "\\" group "${group}" )

	source_group( ${group} FILES ${src} )
	
endfunction( add_source )

function( add_install sources )
	message("add_install begin ${sources}")
	message( "${CMAKE_CURRENT_SOURCE_DIR}" )
	message( "${CMAKE_SOURCE_DIR}" )
	foreach( file ${sources} )
		string( REPLACE ${CMAKE_CURRENT_SOURCE_DIR} "" install_dir ${file} )
		message( "install_dir ${install_dir}" )
		message( "file ${file}" )
	endforeach()
	message("add_install end")
endfunction( add_install )

