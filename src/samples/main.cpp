
#include <core/All.h>

#include <string>
#include <iostream>

#include <core/Threading/Thread.h>

void printMe(void* data)
{
	tiki::u64 base = *reinterpret_cast<tiki::u64*>(data);

	for (int x = 0; x < 10; x++)
	{
		std::cout << base * 10 + x << std::endl;
	}
}

int main(char* args, int argc)
{
	using namespace tiki;

	ThreadHandle* threads[10];
	u64 indices[10];

	for (u64 index = 0; index < 10; index++)
	{
		indices[index] = index;
		threads[index] = Thread::create(printMe, &indices[index]);
	}

	for (int x = 0; x < 10; x++)
	{
		Thread::join(threads[x]);
	}


	/*WindowSettings settings;
	Window* window = new Window();
	if( !window->init( settings ) )
		return 1;

	while( window->update() )
	{

	}

	window->release();*/

	return 0;
}

