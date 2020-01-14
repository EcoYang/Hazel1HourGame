#include "MappingEditorLayer.h"

#include "MappingEditorLevel.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
 
using namespace Hazel;

MappingEditorLayer::MappingEditorLayer()
	:Layer("MappingEditorLayer")
{
	auto& window = Application::Get().GetWindow();
	CreateCamera(window.GetWidth(), window.GetHeight());
}

MappingEditorLayer::~MappingEditorLayer()
{
}

void MappingEditorLayer::OnAttach()
{
	ImGuiIO io = ImGui::GetIO();
	m_Font = io.Fonts->AddFontFromFileTTF("assets/OpenSans-Regular.ttf", 24.f);

	m_MappingEditorLevel = CreateScope<MappingEditorLevel>();
	m_MappingEditorLevel->Init();
}

void MappingEditorLayer::OnDetach()
{
}

void MappingEditorLayer::OnUpdate(Hazel::Timestep ts)
{
	m_Time += ts;
	m_MappingEditorLevel->OnUpdate(ts);

	// Render
	Hazel::RenderCommand::SetClearColor({ 0.0f, 0.0f, 0.0f, 1 });
	Hazel::RenderCommand::Clear();

	Hazel::Renderer2D::BeginScene(*m_Camera); 
	m_MappingEditorLevel->OnRender();
	Hazel::Renderer2D::EndScene();
}

void MappingEditorLayer::OnImGuiRender()
{
	m_MappingEditorLevel->OnImGuiRender();
}

void MappingEditorLayer::OnEvent(Hazel::Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(MappingEditorLayer::OnWindowResize));
	dispatcher.Dispatch<MouseButtonPressedEvent>(HZ_BIND_EVENT_FN(MappingEditorLayer::OnMouseButtonPressed));
}

bool MappingEditorLayer::OnMouseButtonPressed(Hazel::MouseButtonPressedEvent& e)
{
	return false;
}

bool MappingEditorLayer::OnWindowResize(Hazel::WindowResizeEvent& e)
{
	CreateCamera(e.GetWidth(), e.GetHeight());
	return false;
}



void MappingEditorLayer::CreateCamera(uint32_t width, uint32_t height)
{
	float aspectRatio = (float)width / (float)height;

	float camWidth = 8.0f;
	float bottom   = -camWidth;
	float top      = camWidth;
	float left     = bottom * aspectRatio;
	float right    = top * aspectRatio;
	m_Camera = CreateScope<OrthographicCamera>(left, right, bottom, top);
}
