#pragma once
#include "Globals.h"
#include "cScene.h"
#define TOTAL_TILE_Y 18
#define TOTAL_TILE_X 1000
#define TILE_SIZE 16
#define TEXTURE_TILE_SIZE 16



class cLevelScene:public cScene
{
public:
	cLevelScene();
	~cLevelScene();
	bool Load();
	char Stage[TOTAL_TILE_Y][TOTAL_TILE_X];

	virtual void Draw();

	virtual void Init();

	virtual void Update(float tpf = 0.0333);

	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press);

	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);

	virtual void ReadMouse(int button, int state, int x, int y);
	
	void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {
		glColor3f(0.0f, 0.0f, 0.0f);
		char *c;
		glRasterPos3f(x, y, z);
		for (c = string; *c != '\0'; c++) {
			glutBitmapCharacter(font, *c);
		}
		glColor3f(1.0f, 1.0f, 1.0f);
	}
};

