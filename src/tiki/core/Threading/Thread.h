#pragma once


namespace tiki
{
	struct ThreadHandle;
	typedef void(*ThreadCallback)(void*);

	namespace Thread
	{
		ThreadHandle* create( ThreadCallback callback, void* data );
		void destroy( ThreadHandle* thread );

		void join(ThreadHandle* thread);
		void pause(ThreadHandle* thread);
		void resume(ThreadHandle* thread);

		void setName(ThreadHandle* thread, const char* name);
	}
}