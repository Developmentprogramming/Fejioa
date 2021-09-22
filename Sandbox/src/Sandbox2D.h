#pragma once

#include <Fejioa.h>

class Sandbox2D : public Fejioa::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Fejioa::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Fejioa::Event& e) override;

private:
	Fejioa::OrthographicCameraController m_CameraController;

	Fejioa::Ref<Fejioa::FrameBuffer> m_FrameBuffer;
	Fejioa::Ref<Fejioa::Texture2D> m_CheckerBoardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};