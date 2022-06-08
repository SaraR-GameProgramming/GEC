#pragma once
#include "Entity.h"
class BackgroundEntity : public Entity
{
public:
	BackgroundEntity();
	~BackgroundEntity();
	void Update() override;
};

