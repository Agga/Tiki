#pragma once

#include <Windows.h>
#include <core/Platform.h>

namespace tiki
{
	// returns initial value of destination
	template<typename T>
	TIKI_FORCE_INLINE T atomicCompareAndSwap( T& destination, T newValue, T expected )
	{
		static_assert( sizeof(T) <= sizeof(LONG), "size missmatch" );

		return (T)InterlockedCompareExchange( 
			(volatile LONG*)&destination,
			(LONG)newValue,
			(LONG)expected );
	}

	template<typename T>
	TIKI_FORCE_INLINE T atomicIncrement( T& destination )
	{
		static_assert( sizeof(T) <= sizeof(LONG), "size missmatch" );
		return (T)InterlockedIncrement( (volatile LONG*)&destination );

	}

	template<typename T>
	TIKI_FORCE_INLINE T atomicDecrement( T& destination )
	{
		static_assert( sizeof(T) <= sizeof(LONG), "size missmatch" );
		return (T)InterlockedDecrement( (volatile LONG*)&destination );
	}
}