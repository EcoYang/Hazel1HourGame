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

	void DrawRect(int x1, int y1, int x2, int y2);

private:
	void CreateCamera(uint32_t width, uint32_t height);

private:
	Hazel::Scope<Hazel::OrthographicCamera> m_Camera; 
	ImFont* m_Font;

	float m_Time = 0.0f;

	Hazel::Scope<class MappingEditorLevel> m_MappingEditorLevel;
};

