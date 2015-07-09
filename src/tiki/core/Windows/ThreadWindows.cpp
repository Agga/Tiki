#include <core/Threading/Thread.h>
#include <core/Types.h>

#include <Windows.h>

namespace tiki
{
	struct ThreadHandle
	{
		ThreadHandle() : m_Handle(nullptr), m_ThreadId(0),
			m_Callback(nullptr), m_Parameter(nullptr){ }

		HANDLE m_Handle;
		DWORD m_ThreadId;

		ThreadCallback m_Callback;
		void* m_Parameter;
	};

	// helper function to manage calling convention
	DWORD WINAPI threadEntry( void* data )
	{
		ThreadHandle* thread = reinterpret_cast<ThreadHandle*>(data);
		thread->m_Callback(thread->m_Parameter);
		return 0;
	}

	namespace Thread
	{
		ThreadHandle* create( ThreadCallback callback, void* data )
		{
			ThreadHandle* thread = new ThreadHandle();
			
			HANDLE handle = CreateThread(nullptr, 0, threadEntry,
				thread, 0, &thread->m_ThreadId);

			if (handle == nullptr)
			{
				delete thread;
				return nullptr;
			}

			// add threadstate
			thread->m_Handle = handle;
			thread->m_Callback = callback;
			thread->m_Parameter = data;

			return thread;
		}

		void join(ThreadHandle* thread)
		{
			WaitForSingleObject(thread->m_Handle, INFINITE);
		}

		void pause(ThreadHandle* thread)
		{
			SuspendThread(thread->m_Handle);
		}

		void resume(ThreadHandle* thread)
		{
			ResumeThread(thread->m_Handle);
		}
	}
}