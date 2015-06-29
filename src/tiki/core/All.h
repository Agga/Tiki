#pragma once

#include <core/Minimal.h>
#include <core/Assert.h>

#include <core/Window/Window.h>

#if defined(TIKI_USE_SDL2)

#include <core/Window/WindowSDL.h>
typedef tiki::WindowSDL Window;

#endif

