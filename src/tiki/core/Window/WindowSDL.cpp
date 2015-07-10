#include <core/Config.h>

#if defined(TIKI_USE_SDL2)

#include <core/Window/WindowSDL.h>
#include <core/Window/Window.h>

#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace tiki
{
	WindowSDL::WindowSDL() :
		m_Window( nullptr )
	{

	}

	WindowSDL::~WindowSDL()
	{
		release();
	}

	bool WindowSDL::init(const WindowSettings& settings)
	{
		if( m_Window )
			return true;

		if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
			return false;

		u32 windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

		m_Window = SDL_CreateWindow( 
			"Tiki Hunt",
			settings.m_PosX == -1 ? SDL_WINDOWPOS_CENTERED : settings.m_PosX,
			settings.m_PosY == -1 ? SDL_WINDOWPOS_CENTERED : settings.m_PosY,
			settings.m_Width,
			settings.m_Height,
			windowFlags );

		return m_Window != nullptr;
	}

	bool WindowSDL::release()
	{
		if( m_Window )
		{
			SDL_DestroyWindow( m_Window );
			m_Window = nullptr;
			SDL_Quit();

			return true;
		}

		return false;
	}

	bool WindowSDL::update()
	{
		SDL_Event event;
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
			{
				return false;
			}
		}

		return true;
	}

	void WindowSDL::setSettings(const WindowSettings& settings)
	{

	}
}

#endif //TIKI_USE_SDL2