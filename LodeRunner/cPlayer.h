#pragma once
#include"Globals.h"
#include "cSprite.h"

class cPlayer
{
private:
	std::vector<cSprite*> *playerSheet;
	float x, y;
	int width, height;

public:
	cPlayer(std::vector<cSprite*> *playerSheet, float x, float y, int width, int height)
		:playerSheet(playerSheet), x(x), y(y), width(width), height(height) {}
	cPlayer();
	~cPlayer();

	void Render();
	int Height() const { return height; }
	void Height(int val) { height = val; }
	int Width() const { return width; }
	void Width(int val) { width = val; }
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() const { return y; }
	void Y(float val) { y = val; }
	bool Intersect(float x0, float y0, float x1, float y1);
};

