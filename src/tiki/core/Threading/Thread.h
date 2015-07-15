#pragma once

#include <core/Types.h>

namespace tiki
{
	typedef void(*ThreadProc)(void*);

	class Thread
	{
	public:
		struct ThreadImpl;

		Thread();
		~Thread();

		/*
		creates a thread in a running state
			proc -> function that will be executed by the thread
			data -> data passed to ThreadProc; data is not owned by thread
			returns true on success
		 */
		bool create( ThreadProc proc, void* data );

		/*
		stalls threadA until the joined threadB finishes
			- returns true immediately if joined thread already finished
			- returns false if threadA and threadB are equal
			- returns false if thread is not valid	
		 */
		bool join();

		/*
		thread will be executed unto completion
		after a call to detach a thread is no longer joinable
		 */
		bool detach();
		
		
		static void sleep( u64 milliseconds );
		static u64  getCurrentThreadId();
		
	private:
		ThreadImpl* m_Impl;
	};
}
