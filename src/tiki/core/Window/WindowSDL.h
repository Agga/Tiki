#pragma once

struct SDL_Window;

namespace tiki
{
	struct WindowSettings;

	class WindowSDL
	{
	public:
		WindowSDL();
		~WindowSDL();

		bool init( const WindowSettings& settings );
		bool release();

		bool update();

		void setSettings( const WindowSettings& settings );

	private:
		SDL_Window* m_Window;
	};
}