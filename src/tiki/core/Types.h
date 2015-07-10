#pragma once

#include <cstdint>
#include <limits>

namespace tiki
{
	typedef std::int8_t i8;
	typedef std::int16_t i16;
	typedef std::int32_t i32;
	typedef std::int64_t i64;

	typedef std::uint8_t u8;
	typedef std::uint16_t u16;
	typedef std::uint32_t u32;
	typedef std::uint64_t u64;

	typedef float f32;
	typedef double f64;

	typedef std::intptr_t intptr;
	typedef std::uintptr_t uintptr;

	//TODO add constexpr
	template<typename type>
	type maxValue()
	{
		return std::numeric_limits<type>::max();
	}

	//TODO add constexpr
	template<typename type>
	type minValue()
	{
		return std::numeric_limits<type>::min();
	}
}
