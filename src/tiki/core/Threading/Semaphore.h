#pragma once

#include <core/Types.h>

namespace tiki
{
	class Semaphore
	{
	public:
		struct SemaphoreImpl;

		Semaphore();
		~Semaphore();

		bool create();
		void release();
		bool obtain( u64 milliseconds = maxValue<u64>() );

	private:
		SemaphoreImpl* m_Impl;
	};
}
