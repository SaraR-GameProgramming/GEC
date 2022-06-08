#pragma once

#include <string>
class Visualisation;

class Entity
{
protected:
	int pos_X{ 0 };
	int pos_Y{ 0 };
	int health{ 0 };
	int speed{ 5 };
	std::string m_textureName;
public:
	Entity();
	~Entity();

	bool Initialise(const std::string &,int posX,int posY);
	void Render(Visualisation& vis);


	virtual void Update() = 0;

};

