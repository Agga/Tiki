
#include <core/Threading/Thread.h>
#include <Windows.h>

namespace tiki
{
	struct Thread::ThreadImpl
	{
		HANDLE m_Handle;
		u64 m_ThreadId;

		ThreadProc m_Proc;
		void* m_Data;
	};

	namespace detail
	{
		// windows thread API requires a special calling convention
		// this function calls the real ThreadProc
		DWORD WINAPI threadEntry( void* data )
		{
			Thread::ThreadImpl* thread = reinterpret_cast<Thread::ThreadImpl*>( data );
			thread->m_Proc( thread->m_Data );
			return 0;
		}
	}

	Thread::Thread() :
		m_Impl( nullptr )
	{

	}

	Thread::~Thread()
	{
		release();
	}

	bool Thread::create(ThreadProc proc, void* data)
	{
		release();

		ThreadImpl* thread = new ThreadImpl();
		thread->m_Proc = proc;
		thread->m_Data = data;

		thread->m_Handle = CreateThread( nullptr, 0, detail::threadEntry,
			thread, 0, (LPDWORD)&thread->m_ThreadId );

		if( thread->m_Handle == nullptr )
		{
			delete thread;
			return false;
		}

		m_Impl = thread;
		return true;
	}

	void Thread::release()
	{
		if( m_Impl )
		{
			join();
			delete m_Impl;
			m_Impl = nullptr;
		}
	}

	bool Thread::join() const
	{
		if( m_Impl && m_Impl->m_ThreadId != getCurrentThreadId() )
		{
			DWORD result;
			if( GetExitCodeThread( m_Impl->m_Handle, &result ) )
			{
				if( result == STILL_ACTIVE )
				{
					WaitForSingleObject( m_Impl->m_Handle, INFINITE );
				}

				return true;
			}
		}
		return false;
	}

	u64 Thread::getCurrentThreadId()
	{
		//TODO add static assert for size test
		return static_cast<u64>( GetCurrentThreadId() );
	}

	void Thread::sleep( u64 milliseconds )
	{
		Sleep( DWORD(milliseconds) );
	}
}
