#pragma once
#include "Globals.h"
#include "cSprite.h"
class cTile
{
private:
	char tile;
	cSprite *tileSprite;
	float x, y;
	int width, height;
public:
	cTile();
	cTile(cSprite *tileSprite);
	~cTile();

	int Height() const { return height; }
	void Height(int val) { height = val; }
	int Width() const { return width; }
	void Width(int val) { width = val; }
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() const { return y; }
	void Y(float val) { y = val; }
	bool Intersect(float x0, float y0, float x1, float y1);
	cSprite * TileSprite() const { return tileSprite; }
	void TileSprite(cSprite * val) { tileSprite = val; }

	void Render();
	char Tile() const { return tile; }
	void Tile(char val) { tile = val; }
};

