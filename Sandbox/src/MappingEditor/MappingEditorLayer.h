#pragma once

#include "Hazel.h"

#include <imgui/imgui.h>

class MappingEditorLayer : public Hazel::Layer 
{
public:
	MappingEditorLayer();
	virtual ~MappingEditorLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Hazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hazel::Event& e) override;
	bool OnMouseButtonPressed(Hazel::MouseButtonPressedEvent& e);
	bool OnWindowResize(Hazel::WindowResizeEvent& e);
private:
	void CreateCamera(uint32_t width, uint32_t height);

private:
	Hazel::Scope<Hazel::OrthographicCamera> m_Camera; 
	ImFont* m_Font;

	std::vector<class Actor*> m_ActorVector;

	float m_Time = 0.0f;
};

