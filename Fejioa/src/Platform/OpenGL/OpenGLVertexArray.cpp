#include "fjpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Fejioa
{

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Fejioa::ShaderDataType::Float:  return GL_FLOAT;
		case Fejioa::ShaderDataType::Float2: return GL_FLOAT;
		case Fejioa::ShaderDataType::Float3: return GL_FLOAT;
		case Fejioa::ShaderDataType::Float4: return GL_FLOAT;
		case Fejioa::ShaderDataType::Mat3:   return GL_FLOAT;
		case Fejioa::ShaderDataType::Mat4:   return GL_FLOAT;
		case Fejioa::ShaderDataType::Int:    return GL_INT;
		case Fejioa::ShaderDataType::Int2:   return GL_INT;
		case Fejioa::ShaderDataType::Int3:   return GL_INT;
		case Fejioa::ShaderDataType::Int4:   return GL_INT;
		case Fejioa::ShaderDataType::Bool:   return GL_BOOL;

		default:
			break;
		}

		FJ_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return GL_NONE;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &m_RendererID);
		glBindVertexArray(m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		FJ_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout!");

		Bind();
		vertexBuffer->Bind();

		unsigned int index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.Type), element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)element.Offset);
			index++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		Bind();
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}