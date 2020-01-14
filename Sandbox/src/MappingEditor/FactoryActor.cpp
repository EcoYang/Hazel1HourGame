#include "FactoryActor.h"
 
FactoryActor::FactoryActor()
{
}

FactoryActor::~FactoryActor()
{
}

FactoryActor* FactoryActor::Get()
{
	static FactoryActor s_Instance;
	return &s_Instance;
} 
