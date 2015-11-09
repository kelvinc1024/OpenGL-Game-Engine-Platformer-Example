#pragma once

#include "cTexture.h"
#include "Globals.h"
#include "cSprite.h"

//Image array size
#define NUM_TEX		 3

//Image identifiers
#define SPRITESHEET_PLAYERS	2
#define IMG_STAGE			1
#define BG_COLORED_GRASS	3

class cAssetManager
{
public:
	static cAssetManager& getInstance()
	{
		static cAssetManager instance;
		return instance;
	}

	int  GetID(int img);
	void GetSize(int img, int *w, int *h);
	bool Load();

	std::vector<cSprite> player;

private:
	~cAssetManager(void);
	cAssetManager(void);
	cAssetManager(cAssetManager const&) = delete;
	void operator=(cAssetManager const&) = delete;


	cTexture textures[NUM_TEX];
	bool LoadImage(int img, char *filename, int type = GL_RGBA);
};
