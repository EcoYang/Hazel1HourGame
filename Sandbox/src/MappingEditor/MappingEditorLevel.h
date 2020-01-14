#pragma once

#include "Hazel.h"

class MappingEditorLevel
{
public:
	MappingEditorLevel();
	virtual ~MappingEditorLevel();

	void Init();

	void OnUpdate(Hazel::Timestep ts);
	void OnRender();

	void OnImGuiRender(); 
	void Reset();

public:
	void SpawnActor(const glm::vec2 & SpawnPosition, const glm::vec2 & SpawnScale);

private:
	std::vector<class Actor*> m_ActorVector;

};