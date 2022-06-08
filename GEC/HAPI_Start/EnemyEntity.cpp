#include "EnemyEntity.h"

EnemyEntity::EnemyEntity()
{
}

EnemyEntity::~EnemyEntity()
{
}

void EnemyEntity::Update()
{
	if (pos_X > 0)
	{
		pos_X -= 3;
		if (pos_X == 0)
		{
			pos_X = pos_X += 3;
		}
	}
	
	
	/*if (pos_X < 900)
	{
		pos_X += 3;
	}*/
	
	/*if (rand() % 1 == 0)
	{
		pos_X += rand() % 4 - 2;
		pos_Y += rand() % 4 - 2;
	}*/
}
