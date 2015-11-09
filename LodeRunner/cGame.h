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
	static cGame& getInstance()
	{
		static cGame instance;
		return instance;
	}

	bool Init();
	bool Loop();

	//Input
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state, int x, int y);
	//Process
	bool Update(float tpf=0.0333);
	void Reshape(int w, int h);
	//Output
	void Render();

	void UpdateScene(cScene *scene);
private:
	~cGame(void);
	cGame(void);
	cGame(cGame const&) = delete;
	void operator=(cGame const&) = delete;

	unsigned char keys[256];
	bool bSceneValid = true;
	bool bIsFirst = true;

	cScene *active_scene;
	cScene *next_scene;
	cRect visible_area;

	float time;

	void RealUpdateScene();
};
