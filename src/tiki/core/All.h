#pragma once

#include <core/Config.h>
#include <core/Types.h>

#include <core/Platform.h>
#include <core/Assert.h>

#include <core/Window/Window.h>

#if defined(TIKI_USE_SDL2)

#include <core/Window/WindowSDL.h>
typedef tiki::WindowSDL Window;

#endif

#include <core/Threading/Thread.h>
#include <core/Threading/Semaphore.h>

