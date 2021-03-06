#include "MappingEditorLevel.h"

#include "ImageActor.h"
#include "FactoryActor.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace Hazel;

MappingEditorLevel * MappingEditorLevel::s_Instance = nullptr;

static glm::vec4 HSVtoRGB(const glm::vec3& hsv) {
	int H = (int)(hsv.x * 360.0f);
	double S = hsv.y;
	double V = hsv.z;

	double C = S * V;
	double X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
	double m = V - C;
	double Rs, Gs, Bs;

	if (H >= 0 && H < 60) {
		Rs = C;
		Gs = X;
		Bs = 0;
	}
	else if (H >= 60 && H < 120) {
		Rs = X;
		Gs = C;
		Bs = 0;
	}
	else if (H >= 120 && H < 180) {
		Rs = 0;
		Gs = C;
		Bs = X;
	}
	else if (H >= 180 && H < 240) {
		Rs = 0;
		Gs = X;
		Bs = C;
	}
	else if (H >= 240 && H < 300) {
		Rs = X;
		Gs = 0;
		Bs = C;
	}
	else {
		Rs = C;
		Gs = 0;
		Bs = X;
	}

	return { (Rs + m), (Gs + m), (Bs + m), 1.0f };
}

MappingEditorLevel::MappingEditorLevel()
{
	if(s_Instance)
	{
		HZ_ERROR("Instance Existed on Mapping Editor Level");
	}

	s_Instance = this;
}

MappingEditorLevel::~MappingEditorLevel()
{
	s_Instance = nullptr;
}

void MappingEditorLevel::Init()
{ 
	SpawnActor("ImageActor");
}

void MappingEditorLevel::OnUpdate(Hazel::Timestep ts)
{
	for (Actor * ActorPtr : m_ActorVector) 
	{
		ActorPtr->Update(ts);
	}
}

void MappingEditorLevel::OnRender()
{
	for (Actor* ActorPtr : m_ActorVector)
	{
		ActorPtr->OnRender();
	}

	Renderer2D::DrawQuad({ 1.0f, 1.0f }, { 0.8f, 0.8f }, { 1.f , 0.f , 0.f , 1.0f });
	Renderer2D::DrawQuad({ -1.0f, -1.0f }, { 0.8f, 0.8f }, { 0.0f, 1.0f, 0.0f, 1.0f });
	Renderer2D::DrawQuad({ -1.0f, 1.0f }, { 0.8f, 0.8f }, { 0.0f, 0.f, 1.0f, 1.0f });
	Renderer2D::DrawQuad({ 1.0f, -1.0f }, { 0.8f, 0.8f }, { 0.0f, 1.0f, 1.0f, 1.0f });

}

void MappingEditorLevel::OnImGuiRender()
{
	for (Actor* ActorPtr : m_ActorVector)
	{
		ActorPtr->OnImGuiRender();
	}
}

void MappingEditorLevel::Reset()
{
	for (Actor* ActorPtr : m_ActorVector)
	{
		ActorPtr->Reset();
	}
}

Actor* MappingEditorLevel::SpawnActor(const char* ActorType, const glm::vec2& SpawnPosition, const glm::vec2& SpawnScale)
{
	FactoryActor* FactoryActorPtr = FactoryActor::Get();
	Actor* NewActor= FactoryActorPtr->BuildActor<Actor>(ActorType, SpawnPosition, SpawnScale);
	m_ActorVector.push_back(NewActor);
	return NewActor;
}

Actor* MappingEditorLevel::SpawnActor(const char* ActorType, const glm::vec2& SpawnPosition)
{
	return SpawnActor(ActorType, SpawnPosition, {1.f, 1.f});
}

Actor* MappingEditorLevel::SpawnActor(const char* ActorType)
{
	return SpawnActor(ActorType, {0.f,0.f});
}
 
void MappingEditorLevel::DestroyActor(Actor* ActorPtr)
{
	for (auto it = m_ActorVector.begin(); it != m_ActorVector.end(); ++it) 
	{
		Actor* Act = *it;
		if (Act != ActorPtr) continue;

		m_ActorVector.erase(it);
		delete Act;
		break;
	}
}
