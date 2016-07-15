// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#pragma once
#include "Globals.h"
#include "cSprite.h"
#include "cGameObject.h"
class cTile: public cGameObject
{
private:
	char tile;
	cSprite *tileSprite;
	float x, y;
	int width, height;
	int posX, posY;
public:
	cTile();
	cTile(cSprite *tileSprite, float x, float y, int width, int height, int posX, int posY) 
		:tileSprite(tileSprite),x(x),y(y),width(width),height(height),posX(posX),posY(posY){}
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

	char Tile() const { return tile; }
	void Tile(char val) { tile = val; }
	int PosY() const { return posY; }
	void PosY(int val) { posY = val; }
	int PosX() const { return posX; }
	void PosX(int val) { posX = val; }

	virtual void Render() override;

	virtual void Init() override;

	virtual void Update(float tpf = 0.0333) override;

	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) override;

	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) override;

	virtual void ReadMouse(int button, int state, int x, int y) override;

};

