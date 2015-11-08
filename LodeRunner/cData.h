#pragma once

#include "cTexture.h"

#define TOTAL_TILE_Y 18
#define TOTAL_TILE_X 1000

//Image array size
#define NUM_TEX		 3

//Image identifiers
#define IMG_CHARACTER	0
#define IMG_STAGE		1

class cData
{
public:
	cData(void);
	~cData(void);

	int  GetID(int img);
	void GetSize(int img, int *w, int *h);
	bool Load();

	char Stage[TOTAL_TILE_Y][TOTAL_TILE_X];

private:
	cTexture textures[NUM_TEX];
	bool LoadImage(int img, char *filename, int type = GL_RGBA);
};
