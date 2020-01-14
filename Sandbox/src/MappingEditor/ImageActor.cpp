#include "ImageActor.h"
 
#include <imgui/imgui.h>

void ImageActor::OnRender()
{
	Actor::OnRender();

}

void ImageActor::OnImGuiRender()
{
	Actor::OnImGuiRender();
	/*
	static bool bOpen = false;
	ImGui::Begin("Image File Path", &bOpen,ImVec2(.5f,.5f));
	ImGui::End();*/
}
