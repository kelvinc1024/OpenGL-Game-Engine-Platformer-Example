#pragma once
#include "Globals.h"
#define TOTAL_TILE_Y 18
#define TOTAL_TILE_X 1000
#define TILE_SIZE 16
#define TEXTURE_TILE_SIZE 16

class cScene
{
public:
	cScene();
	~cScene();
	bool Load();
	char Stage[TOTAL_TILE_Y][TOTAL_TILE_X];

	void Draw(int tex_id, int tex_w, int tex_h);
};

