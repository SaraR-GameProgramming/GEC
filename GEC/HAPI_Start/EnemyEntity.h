#pragma once
#include "Entity.h"
class EnemyEntity : public Entity
{
public:
	EnemyEntity();
	~EnemyEntity();
	void Update() override;
};

