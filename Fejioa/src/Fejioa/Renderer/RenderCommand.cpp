#include "fjpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Fejioa
{
	
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}