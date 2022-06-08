#include "World.h"
#include "PlayerEntity.h"
#include "BackgroundEntity.h"
#include "Texture.h"
#include "EnemyEntity.h"
World::World()
{
}

World::~World()
{
	for (auto p : m_entities)
		delete p;
	delete visual;
}

bool World::Initialise()
{
	 visual = new Visualisation();
	if (!visual->Initialise(1000, 970))
	{
		delete visual;
		return false;
	}
		return true;
	
}

bool World::LoadStage()
{


	/*if (!visual->LoadTexture("Data\\Background.tga", "Background"))
		return false;

	BackgroundEntity* BG = new BackgroundEntity();
	BG->Initialise("Background", 445, 800);
	m_entities.push_back(BG);*/


	if (!visual->LoadTexture("Data\\playerShip2_red.png", "playerShip2_red"))
		return false;

	PlayerEntity *player = new PlayerEntity();
	player->Initialise("playerShip2_red", 420, 880);
	m_entities.push_back(player);

	// top row of the invaders (needs to be able to shoot!)
	if (!visual->LoadTexture("Data\\enemyGreen3.png", "enemyGreen3"))
		return false;
	EnemyEntity* topRowEnemy = new EnemyEntity();
	topRowEnemy->Initialise("enemyGreen3", 140,10); 
	m_entities.push_back(topRowEnemy);

	EnemyEntity* topRowEnemy1 = new EnemyEntity();
	topRowEnemy1->Initialise("enemyGreen3", 360,10);
	m_entities.push_back(topRowEnemy1);

	EnemyEntity* topRowEnemy2 = new EnemyEntity();
	topRowEnemy2->Initialise("enemyGreen3", 580, 10);
	m_entities.push_back(topRowEnemy2);

	if (!visual->LoadTexture("Data\\enemyBlue3.png", "enemyBlue3"))
		return false;

	EnemyEntity* topRowEnemy3 = new EnemyEntity();
	topRowEnemy3->Initialise("enemyBlue3", 250,10); 
	m_entities.push_back(topRowEnemy3);

	EnemyEntity* topRowEnemy4 = new EnemyEntity();
	topRowEnemy4->Initialise("enemyBlue3", 470, 10);
	m_entities.push_back(topRowEnemy4);

	EnemyEntity* topRowEnemy5 = new EnemyEntity();
	topRowEnemy5->Initialise("enemyBlue3", 690, 10);
	m_entities.push_back(topRowEnemy5);

	//Top mid row of invaders 
	if (!visual->LoadTexture("Data\\enemyBlack1.png", "enemyBlack1"))
		return false;

	EnemyEntity* topMidRowEnemy = new EnemyEntity();
	topMidRowEnemy->Initialise("enemyBlack1", 140, 100);
	m_entities.push_back(topMidRowEnemy);

	EnemyEntity* topMidRowEnemy2 = new EnemyEntity();
	topMidRowEnemy2->Initialise("enemyBlack1", 360, 100);
	m_entities.push_back(topMidRowEnemy2);

	EnemyEntity* topMidRowEnemy4 = new EnemyEntity();
	topMidRowEnemy4->Initialise("enemyBlack1", 580, 100);
	m_entities.push_back(topMidRowEnemy4);

	if (!visual->LoadTexture("Data\\enemyRed1.png", "enemyRed1"))
		return false;

	EnemyEntity* topMidRowEnemy1 = new EnemyEntity();
	topMidRowEnemy1->Initialise("enemyRed1", 250, 100);
	m_entities.push_back(topMidRowEnemy1);

	EnemyEntity* topMidRowEnemy3 = new EnemyEntity();
	topMidRowEnemy3->Initialise("enemyRed1", 470, 100);
	m_entities.push_back(topMidRowEnemy3);

	EnemyEntity* topMidRowEnemy5 = new EnemyEntity();
	topMidRowEnemy5->Initialise("enemyRed1", 690, 100);
	m_entities.push_back(topMidRowEnemy5);

	// Bottom mid row of invaders (needs to be able to shoot!)

	if (!visual->LoadTexture("Data\\enemyBlue2.png", "enemyBlue2"))
		return false;

	EnemyEntity* bottomMidRowEnemy = new EnemyEntity();
	bottomMidRowEnemy->Initialise("enemyBlue2", 140, 190);
	m_entities.push_back(bottomMidRowEnemy);

	EnemyEntity* bottomMidRowEnemy2 = new EnemyEntity();
	bottomMidRowEnemy2->Initialise("enemyBlue2", 360, 190);
	m_entities.push_back(bottomMidRowEnemy2);

	EnemyEntity* bottomMidRowEnemy4 = new EnemyEntity();
	bottomMidRowEnemy4->Initialise("enemyBlue2", 580, 190);
	m_entities.push_back(bottomMidRowEnemy4);


	if (!visual->LoadTexture("Data\\enemyBlack2.png", "enemyBlack2"))
		return false;

	EnemyEntity* bottomMidRowEnemy1 = new EnemyEntity();
	bottomMidRowEnemy1->Initialise("enemyBlack2", 250, 190);
	m_entities.push_back(bottomMidRowEnemy1);

	EnemyEntity* bottomMidRowEnemy3 = new EnemyEntity();
	bottomMidRowEnemy3->Initialise("enemyBlack2", 470, 190);
	m_entities.push_back(bottomMidRowEnemy3);

	EnemyEntity* bottomMidRowEnemy5 = new EnemyEntity();
	bottomMidRowEnemy5->Initialise("enemyBlack2", 690, 190);
	m_entities.push_back(bottomMidRowEnemy5);

	// Bottom row of invaders
	if (!visual->LoadTexture("Data\\enemyRed5.png", "enemyRed5"))
		return false;

	EnemyEntity* bottomRowEnemy = new EnemyEntity();
	bottomRowEnemy->Initialise("enemyRed5", 140, 280);
	m_entities.push_back(bottomRowEnemy);

	EnemyEntity* bottomRowEnemy2 = new EnemyEntity();
	bottomRowEnemy2->Initialise("enemyRed5", 360, 280);
	m_entities.push_back(bottomRowEnemy2);

	EnemyEntity* bottomRowEnemy4 = new EnemyEntity();
	bottomRowEnemy4->Initialise("enemyRed5", 580, 280);
	m_entities.push_back(bottomRowEnemy4);


	if (!visual->LoadTexture("Data\\enemyGreen5.png", "enemyGreen5"))
		return false;

	EnemyEntity* bottomRowEnemy1 = new EnemyEntity();
	bottomRowEnemy1->Initialise("enemyGreen5", 250, 280);
	m_entities.push_back(bottomRowEnemy1);

	EnemyEntity* bottomRowEnemy3 = new EnemyEntity();
	bottomRowEnemy3->Initialise("enemyGreen5", 470, 280);
	m_entities.push_back(bottomRowEnemy3);

	EnemyEntity* bottomRowEnemy5 = new EnemyEntity();
	bottomRowEnemy5->Initialise("enemyGreen5", 690, 280);
	m_entities.push_back(bottomRowEnemy5);

}
constexpr DWORD GTR{ 75 }; // GTR Stands for Game Tick Rate
void World::Run()
{
	DWORD TimeSinceLastUpdate{ 0 };

	// The Game Loop

	while (HAPI.Update())
	{
		HAPI.SetShowFPS(true);
		visual->ClearToColour(HAPI_TColour::BLACK);
		HAPI_TColour colour(255, 255, 0);
		

		if (HAPI.GetTime() - TimeSinceLastUpdate >= GTR)
		{
			for (auto p : m_entities)
				p->Update();

			TimeSinceLastUpdate = HAPI.GetTime();
		}
		
		for (auto p : m_entities)
			p->Render(*visual);
	}

}
