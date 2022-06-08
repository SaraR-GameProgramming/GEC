#include "Visualisation.h"
#include "Texture.h"

Visualisation::Visualisation()
{
}

Visualisation::~Visualisation()
{
	for (auto p : myTextureMap)
		delete p.second;
}

bool Visualisation::Initialise(int width, int height)
{
	if (!HAPI.Initialise(width, height, "Space inv"))
		return false;
	m_screen = HAPI.GetScreenPointer();
	return true;
}

void Visualisation::ClearToColour(HAPI_TColour colour)
{
	for (size_t i = 0; i < m_screenWidth * m_screenHeight; i++)
		memcpy(m_screen + i * 4, &colour, 4);
}

bool Visualisation::LoadTexture(const std::string& filename, const std::string& name)
{
	Texture* newTexture = new Texture;
	if (!newTexture->Create(filename))
	{
		delete newTexture;
		return false;
	}

	myTextureMap[name] = newTexture;
	return true;
}

void Visualisation::DrawTexture(const std::string& name, int posX, int posY)
{
	myTextureMap[name]->AlphaBlit(m_screen, m_screenWidth, m_screenHeight, posX, posY);
}
