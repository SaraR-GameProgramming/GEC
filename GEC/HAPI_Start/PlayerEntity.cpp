#include "PlayerEntity.h"
#include "HAPI_lib.h"

using namespace HAPISPACE;
PlayerEntity::PlayerEntity()
{
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::Update()
{
	const HAPI_TKeyboardData &keyData = HAPI.GetKeyboardData();

	//if (keyData.scanCode['W']) // Up
		//pos_Y-= speed;
	//if (keyData.scanCode['S']) // Down
		//pos_Y+= speed;

	//left to right movement
	if (keyData.scanCode['A']) // Left
		pos_X-= speed;
	if (keyData.scanCode['D']) // Right
		pos_X+=speed;
}
 