#pragma once

#include "Feijoa/Renderer/PerspectiveCamera.h"
#include "Feijoa/Renderer/Texture.h"

namespace Feijoa
{
	class Renderer3D
	{
	public:
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;

			uint32_t GetTotalVertexCount() { return QuadCount * 8; }
			uint32_t GetTotalIndexCount() { return QuadCount * 36; }
		};

	public:
		static void Init();
		static void Shutdown();

		static void ResetStats();
		static Statistics GetStats();

		static void BeginScene(PerspectiveCamera& camera);
		static void EndScene();
		static void Flush();

		static void DrawQuad(const glm::vec3& position, const glm::vec3& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec3& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));

		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec3& size, float rotation, const glm::vec3& rotation_vec, const glm::vec4& color);

	private:
		static void FlushAndReset();
	};
}