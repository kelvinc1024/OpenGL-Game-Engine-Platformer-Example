#pragma once

#include "cSound.h"
#include "cAssetManager.h"
#include "cRect.h"
#include "cLevelScene.h"
#include "cScene.h"
#include "cLevelScene.h"

#define GAME_WIDTH	800
#define GAME_HEIGHT 600

class cGame
{
public:
	cGame(void);
	virtual ~cGame(void);

	bool Init(int level);
	bool Loop();
	void Finalize();

	//Input
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state, int x, int y);
	//Process
	bool Process();
	void Reshape(int w, int h);
	//Output
	void Render();

private:
	unsigned char keys[256];

	bool bSceneValid = true;

	cScene *active_scene;
	cRect visible_area;
	cSound Sound;

	float time;

	void UpdateCamera(int h1, int h2);
	bool LoadDynamicLayer(int lvl);
};
