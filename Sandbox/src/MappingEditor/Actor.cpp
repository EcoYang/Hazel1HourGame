#include "Actor.h"

#include "MappingEditorLevel.h"

using namespace Hazel;

static int s_CurrentIndex = 0;

Actor::Actor(const glm::vec2 & Position)
	: m_Position(Position),
	m_Index(++s_CurrentIndex),
	m_Name("Actor " + std::to_string(m_Index)),
	m_Scale(1.f, 1.f)
{
	Init();
}

Actor::Actor(float PosX, float PosY)
	:m_Position(glm::vec2(PosX, PosY)),
	m_Index(++s_CurrentIndex),
	m_Name("Actor " + std::to_string(m_Index)),
	m_Scale(1.f, 1.f)
{
	Init();
}

Actor::~Actor()
{
	Destroy();
}

void Actor::Init()
{
	m_Index = ++s_CurrentIndex;
	SetTexture("assets/textures/ChernoLogo.png");
}

void Actor::SetTexture(const std::string& TexturePath)
{
	m_Texture = Texture2D::Create(TexturePath);
}
 
void Actor::Update(Hazel::Timestep ts)
{
	HZ_PROFILE_FUNCTION();

	Hazel::Renderer2D::DrawQuad({ m_Position.x, m_Position.y }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
}

void Actor::OnRender()
{
	if (m_Texture == nullptr) 
	{
		return;
	}

	Renderer2D::DrawQuad({ m_Position.x, m_Position.y, 0.5f }, m_Scale, m_Texture);
}

void Actor::OnImGuiRender()
{
}

void Actor::Reset()
{

}

std::string Actor::ToString() const
{
	std::stringstream ss;
	ss << "Name : " << m_Name << " Position : " << " x :"<< m_Position.x << " y : " << m_Position.y;

	return ss.str();
}

void Actor::Destroy()
{
}
