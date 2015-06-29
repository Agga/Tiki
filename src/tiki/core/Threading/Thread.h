#pragma once

#include <core/Config.h>

#if defined(TIKI_WINDOWS)
#include <core/Threading/ThreadWindows.h>

namespace tiki
{
	typedef ThreadWindows Thread;
}

#endif

