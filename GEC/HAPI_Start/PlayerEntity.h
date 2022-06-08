#pragma once
#include "Entity.h"

class PlayerEntity : public Entity
{
private:
	int numOfLives{ 3 };
public:
	PlayerEntity();
	~PlayerEntity();
	void Update() override;
};

