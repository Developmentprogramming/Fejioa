#pragma once

#include "Fejioa/Core/Core.h"

struct GLFWwindow;

namespace Fejioa
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static Scope<GraphicsContext> Create(GLFWwindow* window);
	};
}