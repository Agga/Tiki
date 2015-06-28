#pragma once

#include <core/Config.h>
#include <core/Types.h>

namespace tiki
{
	struct WindowSettings
	{
		WindowSettings() :
			m_Width( 800 ), m_Height( 600 ),
			m_PosX( -1 ), m_PosY( -1 )
		{

		}

		i32 m_Width;
		i32 m_Height;

		// -1 indicates centered position
		i32 m_PosX;
		i32 m_PosY;
	};
}