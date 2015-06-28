
#include <core/All.h>

int main(char* args, int argc)
{
	using namespace tiki;

	WindowSettings settings;
	Window* window = new Window();
	if( !window->init( settings ) )
		return 1;

	while( window->update() )
	{

	}

	window->release();

	return 0;
}

