#pragma once

#include <core/Config.h>
#include <core/Types.h>

#ifdef TIKI_WINDOWS
#include <core/Windows/AtomicWindows.h>
#else
#error "no atomic implementation"
#endif

namespace tiki
{

}
