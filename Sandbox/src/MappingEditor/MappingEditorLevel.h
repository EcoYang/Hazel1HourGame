#pragma once

#include "Hazel.h"

class MappingEditorLevel
{
public:
	void Init();

	void OnUpdate(Hazel::Timestep ts);
	void OnRender();

	void OnImGuiRender(); 
	void Reset();

private:
	std::vector<class Actor*> m_ActorVector;

};