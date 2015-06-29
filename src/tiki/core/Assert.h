#pragma once

#include <core/Config.h>		// global defines
#include <core/Platform.h>		// platform specific defines

namespace tiki
{
#if defined(TIKI_ASSERTION)

#define TIKI_ASSERT( condition ) \
	do \
	{ \
		if(!(condition)) \
		{ \
			TIKI_DEBUG_BREAK(); \
		} \
	} while( false )

// returns true if condition is valid
#define TIKI_ASSERT_IF( condition ) \
	( (condition) ? true : false )

#else

#define TIKI_ASSERT( condition )
#define TIKI_ASSERT_IF( condition ) true

#endif
}