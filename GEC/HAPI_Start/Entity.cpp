#include "Entity.h"
#include "Visualisation.h"
Entity::Entity()
{
}

Entity::~Entity()
{
}

bool Entity::Initialise(const std::string& textureName, int posX, int posY)
{
	m_textureName = textureName;
	pos_X = posX;
	pos_Y = posY;
	return true;
}

void Entity::Render(Visualisation& vis)
{
	vis.DrawTexture(m_textureName, pos_X, pos_Y);
}
