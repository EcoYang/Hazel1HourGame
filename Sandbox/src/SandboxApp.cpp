#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include "GameLayer.h"
#include "MappingEditor/MappingEditorLayer.h"

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new MappingEditorLayer());
	}

	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}