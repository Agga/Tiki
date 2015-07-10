#include <core/Threading/Semaphore.h>

namespace tiki
{
	Semaphore::Semaphore()
	{

	}

	Semaphore::~Semaphore()
	{

	}

	bool Semaphore::create()
	{
		return true;
	}

	void Semaphore::release()
	{

	}

	bool Semaphore::obtain( u64 milliseconds /*= maxValue<u64>()*/ )
	{
		return milliseconds > 100;
	}
}