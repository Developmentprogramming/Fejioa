#pragma once

#include <Feijoa.h>

namespace Feijoa
{
	class SellowianaLayer : public Layer // Sellowiana EditorLayer
	{
	public:
		SellowianaLayer();
		virtual ~SellowianaLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnUpdate(Feijoa::Timestep ts) override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Feijoa::Event& e) override;

	private:
		OrthographicCameraController m_CameraController;

		Ref<FrameBuffer> m_FrameBuffer;
		Ref<Texture2D> m_CheckerBoardTexture;

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	};
}