#include "Actor.h"

using namespace Hazel;

static int s_CurrentIndex = 0;

Actor::Actor(const glm::vec2 & Position)
	: m_Position(Position),
	m_Index(++s_CurrentIndex),
	m_Name("Actor " + std::to_string(m_Index))
{

}

Actor::Actor(float PosX, float PosY)
	:m_Position(glm::vec2(PosX, PosY)),
	m_Index(++s_CurrentIndex),
	m_Name("Actor " + std::to_string(m_Index))
{

}

void Actor::SetTexture(const std::string& TexturePath)
{
	m_Texture = Texture2D::Create(TexturePath);
}

void Actor::LoadAssets()
{
}

void Actor::Update(Hazel::Timestep ts)
{
	HZ_PROFILE_FUNCTION();

	Hazel::Renderer2D::DrawQuad({ m_Position.x, m_Position.y }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });
}

void Actor::OnImGuiRender()
{
}

std::string Actor::ToString() const
{
	std::stringstream ss;
	ss << "Name : " << m_Name << " Position : " << " x :"<< m_Position.x << " y : " << m_Position.y;

	return ss.str();
}

 