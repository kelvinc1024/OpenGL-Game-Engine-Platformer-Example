#pragma once

#include "cSound.h"
#include "cAssetManager.h"
#include "cRect.h"
#include "cScene.h"

#define GAME_WIDTH	800
#define GAME_HEIGHT 600

class cGame
{
public:
	cGame(void);
	virtual ~cGame(void);

	bool Init();
	bool Loop();
	void Finalize();

	//Input
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state, int x, int y);
	//Process
	bool Update(float tpf=0.0333);
	void Reshape(int w, int h);
	//Output
	void Render();

private:
	unsigned char keys[256];

	bool bSceneValid = true;

	cScene *active_scene;
	cRect visible_area;

	float time;
};
