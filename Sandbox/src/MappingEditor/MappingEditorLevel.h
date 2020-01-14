#pragma once

#include "Hazel.h"

class Actor;

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
	void DestroyActor(Actor * ActorPtr);

private:
	std::vector<Actor*> m_ActorVector;

	static MappingEditorLevel * s_Instance;
};