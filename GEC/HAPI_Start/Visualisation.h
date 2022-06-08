#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;

#include <unordered_map>

class Texture;
class Visualisation
{
private:
	int m_screenWidth{1000};
	int m_screenHeight{970};
	BYTE* m_screen{ nullptr };

	std::unordered_map<std::string, Texture*> myTextureMap;
public:
	Visualisation();
	~Visualisation();
	bool Initialise(int width, int height);
	void ClearToColour(HAPI_TColour colour);
	bool LoadTexture(const std::string& filename, const std::string& name);
	void DrawTexture(const std::string& name, int posX, int posY);

 };

