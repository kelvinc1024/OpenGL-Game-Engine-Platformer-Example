#pragma once

#include "cTexture.h"

//Image array size
#define NUM_TEX		 3

//Image identifiers
#define IMG_CHARACTER	0
#define IMG_STAGE		1
#define IMG_TILESET		2

class cData
{
public:
	cData(void);
	~cData(void);

	int  GetID(int img);
	void GetSize(int img, int *w, int *h);
	bool Load();

private:
	cTexture textures[NUM_TEX];
	bool LoadImage(int img, char *filename, int type = GL_RGBA);
};
