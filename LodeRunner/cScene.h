#pragma once
#include "Globals.h"
class cScene
{
protected:

public:
	cScene();
	~cScene();
	virtual void Init() = 0;
	virtual void Update(float tpf = 0.0333) = 0;
	virtual void Draw() = 0;
	//Input
	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) = 0;
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) = 0;
	virtual void ReadMouse(int button, int state, int x, int y) = 0;

	void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string,
		float r,
		float g,
		float b) {
		glColor3f(r, g, b);
		char *c;
		glRasterPos3f(x, y, z);
		for (c = string; *c != '\0'; c++) {
			glutBitmapCharacter(font, *c);
		}
		glColor3f(1.0f, 1.0f, 1.0f);
	}
};

