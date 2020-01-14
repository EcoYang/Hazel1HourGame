#pragma once
#include "Hazel.h"

class MappingEditorLevel;

class Actor
{
public:
	Actor(const glm::vec2 & Position);
	Actor(float PosX, float PosY); 
	virtual ~Actor();

	void Init();
	void SetTexture(const std::string & TexturePath);

	virtual void Update(Hazel::Timestep ts); 
	void OnRender();

	void OnImGuiRender();

	void Reset();

	virtual std::string ToString() const;
	 
	const glm::vec2& GetPosition() const { return m_Position; }
	const glm::vec2& GetScale() const { return m_Scale; }

	void Destroy();
	void SetLevel(MappingEditorLevel * Level);

private:
	glm::vec2 m_Position;
	glm::vec2 m_Scale;

	unsigned int m_Index;
	std::string m_Name;

	Hazel::Ref<Hazel::Texture2D> m_Texture; 

	static MappingEditorLevel * s_Level;
};

inline std::ostream& operator<<(std::ostream& os, const Actor* ActPtr)
{
	return os << ActPtr->ToString();
}