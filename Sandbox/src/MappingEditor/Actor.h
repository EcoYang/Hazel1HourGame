#pragma once
#include "Hazel.h"

class Actor
{
public:
	Actor(const glm::vec2 & Position);
	Actor(float PosX, float PosY); 
	virtual ~Actor() = default;

	void SetTexture(const std::string & TexturePath);
	void LoadAssets();

	virtual void Update(Hazel::Timestep ts); 
	void OnImGuiRender();

	virtual std::string ToString() const;

	const glm::vec2& GetPosition() const { return m_Position; }

private:
	glm::vec2 m_Position;
	unsigned int m_Index;
	std::string m_Name;

	Hazel::Ref<Hazel::Texture2D> m_Texture; 
};

inline std::ostream& operator<<(std::ostream& os, const Actor* ActPtr)
{
	return os << ActPtr->ToString();
}