#pragma once

#include "ImageActor.h"

class FactoryActor
{
public:
	FactoryActor();
	virtual ~FactoryActor();

	static FactoryActor* Get();
	 
	template<typename T>
	inline T* BuildActor(const char* ActorType, const glm::vec2& SpawnPosition, const glm::vec2& SpawnScale)
	{
		T* NewActor = nullptr;
		if (ActorType == "Default")
		{
			NewActor = new Actor(SpawnPosition, SpawnScale);
		}
		else if (ActorType == "ImageActor")
		{
			NewActor = new ImageActor(SpawnPosition, SpawnScale);
		}

		return NewActor;
	}

	/*template<typename T>
	inline T* BuildActor(const char* ActorType, const glm::vec2& SpawnPosition) 
	{
		BuildActor(ActorType, SpawnPosition, {1.f, 1.f});
	}

	template<typename T>
	inline T* BuildActor(const char* ActorType)
	{
		BuildActor(ActorType, {0.f, 0.f}, { 1.f, 1.f });
	}*/

private: 
};

