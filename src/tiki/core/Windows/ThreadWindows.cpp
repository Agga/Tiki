
#include <core/Threading/Thread.h>
#include <core/Threading/Atomic.h>
#include <core/Assert.h>

#include <Windows.h>

namespace tiki
{
	struct Thread::ThreadImpl
	{
		HANDLE m_Handle;
		u64 m_ThreadId;
		u8 m_RefCount;

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

			if( atomicDecrement( thread->m_RefCount ) == 0 )
			{
				delete thread;
			}

			return 0;
		}
	}

	Thread::Thread() :
		m_Impl( nullptr )
	{

	}

	Thread::~Thread()
	{
		// a thread has to be either joined or detached 
		TIKI_ASSERT( m_Impl == nullptr );
	}

	bool Thread::create(ThreadProc proc, void* data)
	{
		TIKI_ASSERT( m_Impl == nullptr );
		TIKI_ASSERT( proc != nullptr );

		ThreadImpl* thread = new ThreadImpl();
		thread->m_Proc = proc;
		thread->m_Data = data;
		thread->m_RefCount = 2;

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

	bool Thread::join()
	{
		if( m_Impl && m_Impl->m_ThreadId != getCurrentThreadId() )
		{
			DWORD result;
			if( GetExitCodeThread( m_Impl->m_Handle, &result ) )
			{
				if( result == STILL_ACTIVE )
				{
					WaitForSingleObject( m_Impl->m_Handle, INFINITE );
					CloseHandle( m_Impl->m_Handle );

					atomicDecrement( m_Impl->m_RefCount );
					TIKI_ASSERT( m_Impl->m_RefCount == 0 );
					
					delete m_Impl;
					m_Impl = nullptr;
				}

				return true;
			}
		}
		return false;
	}

	bool Thread::detach()
	{
		if( m_Impl && m_Impl->m_ThreadId != getCurrentThreadId() )
		{
			CloseHandle( m_Impl->m_Handle );

			if( atomicDecrement( m_Impl->m_RefCount ) == 0 )
			{
				delete m_Impl;
			}

			m_Impl = nullptr;
		}
		return false;
	}

	u64 Thread::getCurrentThreadId()
	{
		static_assert( sizeof(DWORD) <= sizeof(u64), "size missmatch" );
		return static_cast<u64>( GetCurrentThreadId() );
	}

	void Thread::sleep( u64 milliseconds )
	{
		Sleep( DWORD(milliseconds) );
	}
}
