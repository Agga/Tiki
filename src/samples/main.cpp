
#include <core/All.h>

#include <mutex>
#include <string>
#include <iostream>

std::mutex writeGuard;

void printMe(void* data)
{
	int base = *reinterpret_cast<int*>(data);

	for (int x = 0; x < 10; x++)
	{
		std::lock_guard<std::mutex> lock(writeGuard);
		std::cout << base * 10 + x << std::endl;
	}
}

void testThreadJoin( void* data )
{
	tiki::Thread* thread = reinterpret_cast<tiki::Thread*>( data );
	if( !thread->join() )
	{
		std::lock_guard<std::mutex> lock(writeGuard);
		std::cout << "thread is not joinable from itself " << tiki::Thread::getCurrentThreadId() << std::endl;
	}
}

void testThreadSleep( void* data )
{
	{
		std::lock_guard<std::mutex> lock(writeGuard);
		std::cout << tiki::Thread::getCurrentThreadId() << "start " << std::endl;
	}

	tiki::Thread::sleep( 1000 );

	{
		std::lock_guard<std::mutex> lock(writeGuard);
		std::cout << tiki::Thread::getCurrentThreadId() << "end " << std::endl;
	}
}

#include <Windows.h>

int main(char* args, int argc)
{
	using namespace tiki;
	/*
	Semaphore sem;
	sem.obtain();

	Thread threads[10];
	int indices[10];

	for( int x = 0; x < 10; x++ )
	{
		indices[x] = x;
		threads[x].create( testThreadSleep, nullptr );
	}

	for( int x = 0; x < 10; x++ )
	{
		threads[x].join();
	}
	*/

	return 0;
}

