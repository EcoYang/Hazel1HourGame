#pragma once

#include "Hazel.h"
#include "Actor.h"

class ImageActor : public Actor
{
public: 
	using Actor::Actor;
	virtual void OnRender() override;

	virtual void OnImGuiRender() override;
};

