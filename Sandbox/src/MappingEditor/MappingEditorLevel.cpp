#include "MappingEditorLevel.h"

#include "Actor.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace Hazel;

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
}

MappingEditorLevel::~MappingEditorLevel()
{
}

void MappingEditorLevel::Init()
{
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
