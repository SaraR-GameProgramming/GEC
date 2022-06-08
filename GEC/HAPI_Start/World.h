#pragma once
#include "Visualisation.h"
#include <vector>

class Visualisation;
class Entity;
class PlayerEntity;

class World
{
private:
	Visualisation *visual{nullptr};
	std::vector<Entity*> m_entities;
public:
	World();
	~World();

	bool Initialise();
	bool LoadStage();
	void Run();
};

