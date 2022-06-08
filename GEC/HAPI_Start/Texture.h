#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;
class Texture
{
private:
	int textWidth;
	int textHeight;
	BYTE* textData{nullptr};
public:
	Texture();
	~Texture();
	bool Create(const std::string& filename);
	void FastBlit(BYTE* screen, int screenWidth,int screenHeight, int posX, int posY);
	void AlphaBlit(BYTE* screen, int screenWidth,int screenHeight, int posX, int posY);
	
};

