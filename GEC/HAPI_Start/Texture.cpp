#include "Texture.h"
#include "Rectangle.h"

bool Texture::Create(const std::string& filename)
{
	if (!HAPI.LoadTexture(filename, &textData, textWidth, textHeight))
	{
		return false;
	}
	return true;
}

void Texture::FastBlit(BYTE* screen, int screenWidth, int screenHeight, int posX, int posY)
{
	
		for (int newY = 0; newY < textHeight; newY++)
		{
			int offset = (screenWidth * (posY + newY) + posX) * 4;
			int textureOffset = textHeight * newY * 4;
			memcpy(screen + offset, textData + textureOffset, (screenWidth * 4));

		}
	
}

void Texture::AlphaBlit(BYTE* screen, int screenWidth, int screenHeight, int posX, int posY)
{

	Rectangle screenRect(0, screenWidth, 0, screenHeight);
	Rectangle textureRect(0, textWidth, 0, textHeight);

	textureRect.translate(posX, posY);
	textureRect.ClipTo(screenRect);
	textureRect.translate(-posX, -posY);

	if (posX < 0)
		posX = 0;
	if (posY < 0)
		posY = 0;

	// says where the on the screen is the top left of the texture
	BYTE* screenStart = screen + (posX + posY * screenWidth) * 4;
	BYTE* textureStart=textData +(textureRect.left + textureRect.top * textWidth) * 4;

	

	int endOfScreenLine( screenWidth * 4 - textureRect.Width() * 4 );
	int endOfTextureLine((textWidth - textureRect.Width()) * 4);
       	for (int posY = 0; posY < textureRect.Height(); posY++)  
	{
		for (int posX = 0; posX < textureRect.Width(); posX++)
		{


			BYTE a = textureStart[3];
			if (a > 0)
			{
				if (a == 255)
				{
					memcpy(screenStart, textureStart, 4);
				}
				else {
					float alpha = a / 255.0f;

					(screenStart[0] = alpha * (textureStart[0] + screenStart[0] * (1.0f - alpha)));
					(screenStart[1] = alpha * (textureStart[1] + screenStart[1] * (1.0f - alpha)));
					(screenStart[2] = alpha * (textureStart[2] + screenStart[2] * (1.0f - alpha)));
					
				}
			}
			screenStart += 4;
			textureStart += +4;
		}
		screenStart += endOfScreenLine;
		textureStart += endOfTextureLine;
	}
}

Texture::Texture()
{
}

Texture::~Texture()
{
	delete[]textData;
}
