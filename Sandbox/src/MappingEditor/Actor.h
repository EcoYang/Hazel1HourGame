#pragma once
#include "Hazel.h"

class MappingEditorLevel;

class Actor
{
public:
	Actor(const glm::vec2 & Position);
	Actor(float PosX, float PosY); 
	virtual ~Actor();


	virtual void SetTexture(const std::string & TexturePath);

	virtual void Update(Hazel::Timestep ts); 
	virtual void OnRender();

	virtual void OnImGuiRender();

	virtual void Reset();

	virtual std::string ToString() const;
	
	virtual void Destroy();
	
public:
	const glm::vec2& GetPosition() const { return m_Position; }
	const glm::vec2& GetScale() const { return m_Scale; }

protected:
	virtual void Init();

private:
	glm::vec2 m_Position;
	glm::vec2 m_Scale;

	unsigned int m_Index;
	std::string m_Name;

	Hazel::Ref<Hazel::Texture2D> m_Texture; 
};

inline std::ostream& operator<<(std::ostream& os, const Actor* ActPtr)
{
	return os << ActPtr->ToString();
}