#pragma warning(disable:4996)
#include "cAssetManager.h"
#include "Globals.h"

cAssetManager::cAssetManager(void) {}
cAssetManager::~cAssetManager(void) {}

int cAssetManager::GetID(int img)
{
	return textures[img].GetID();
}

void cAssetManager::GetSize(int img, int *w, int *h)
{
	textures[img].GetSize(w, h);
}

bool cAssetManager::LoadImage(int img, char *filename, int type)
{
	int res;

	res = textures[img].Load(filename, type);
	if (!res) return false;

	return true;
}
bool cAssetManager::Load()
{
	int res;

	res = LoadImage(SPRITESHEET_TILES, "Textures/Spritesheets/spritesheet_tiles.png", GL_RGBA);
	if (!res) return false;
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 8; i++) {
			float x0, y0, x1, y1;
			int tex_w, tex_h;
			GetSize(GetID(SPRITESHEET_TILES), &tex_w, &tex_h);
			float sprite_width = 128.0f / tex_w;
			float sprite_height = 128.0f / tex_h;
			x0 = sprite_width*j;
			x1 = sprite_width*(j + 1);
			y0 = sprite_height*i;
			y1 = sprite_height*(i + 1);
			tiles->push_back(new cSprite(GetID(SPRITESHEET_TILES), x0, y0, x1, y1));
		}
	}

	res = LoadImage(SPRITESHEET_PLAYERS, "Textures/Spritesheets/spritesheet_players.png", GL_RGBA);
	if (!res) return false;
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 8; i++) {
			float x0, y0, x1, y1;
			int tex_w, tex_h;
			GetSize(GetID(SPRITESHEET_PLAYERS), &tex_w, &tex_h);
			float sprite_width = 128.0f / tex_w;
			float sprite_height = 256.0f / tex_h;
			x0 = sprite_width*j;
			x1 = sprite_width*(j + 1);
			y0 = sprite_height*i;
			y1 = sprite_height*(i + 1);
			player->push_back(new cSprite(GetID(SPRITESHEET_PLAYERS), x0, y0, x1, y1));
			
		}
	}

	res = LoadImage(BG_COLORED_GRASS, "Textures/PNG/Backgrounds/colored_grass.png");
	if (!res) return false;

	return true;
}

