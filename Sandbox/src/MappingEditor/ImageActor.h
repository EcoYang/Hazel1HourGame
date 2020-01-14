#pragma once

#include "Hazel.h"
#include "Actor.h"

class ImageActor : public Actor
{
public: 
	using Actor::Actor;
	virtual void OnRender() override;

	virtual void OnImGuiRender() override;

protected:
	std::string OpenFileName(wchar_t* Filter = L"Image files (*.jpg, *.png) | *.jpg; *.png", HWND Owner = NULL);
	
private:
	std::string m_FilePath;
};

