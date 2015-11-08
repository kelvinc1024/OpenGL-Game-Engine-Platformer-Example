#pragma warning(disable:4996)
#include "cData.h"
#include <string.h>

cData::cData(void) {}
cData::~cData(void) {}

int cData::GetID(int img)
{
	return textures[img].GetID();
}

void cData::GetSize(int img, int *w, int *h)
{
	textures[img].GetSize(w, h);
}

bool cData::LoadImage(int img, char *filename, int type)
{
	int res;

	res = textures[img].Load(filename, type);
	if (!res) return false;

	return true;
}
bool cData::Load()
{
	int res;

	res = LoadImage(IMG_CHARACTER,	"Textures/NES - Lode Runner - Characters.png", GL_RGBA);
	if (!res) return false;
	res = LoadImage(IMG_STAGE,		"Textures/NES - Lode Runner - Tileset.png", GL_RGBA);
	if (!res) return false;

	
	return true;
}

