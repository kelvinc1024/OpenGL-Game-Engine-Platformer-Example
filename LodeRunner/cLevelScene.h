#pragma once
#include "Globals.h"
#include "cScene.h"
#include "cTile.h"
#include "cPlayer.h"
#define TOTAL_TILE_Y 18
#define TOTAL_TILE_X 1000
#define TILE_SIZE 64
#define TEXTURE_TILE_SIZE 128


class cLevelScene:public cScene
{
public:
	cLevelScene();
	~cLevelScene();
	bool Load();
	std::vector<cTile*> Stage;
	cPlayer *player;

	virtual void Render();

	virtual void Init();

	virtual void Update(float tpf = 0.0333);

	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press);

	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);

	virtual void ReadMouse(int button, int state, int x, int y);
	
private:
	bool keys[255];
};

