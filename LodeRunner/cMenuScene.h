#pragma once
#include "cScene.h"
class cMenuScene:public cScene
{
public:
	cMenuScene();
	~cMenuScene();

	virtual void Init() override;

	virtual void Update(float tpf = 0.0333) override;

	virtual void Draw() override;

	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) override;

	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) override;

	virtual void ReadMouse(int button, int state, int x, int y) override;

private:
	bool keys[255];
};

