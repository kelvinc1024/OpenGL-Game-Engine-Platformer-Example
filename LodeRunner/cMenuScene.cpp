#include "cMenuScene.h"

cMenuScene::cMenuScene()
{

}

cMenuScene::~cMenuScene()
{

}

void cMenuScene::Init()
{
}

void cMenuScene::Update(float tpf /*= 0.0333*/)
{
}

void cMenuScene::Draw()
{
	renderBitmapString(5, 580, 9, GLUT_BITMAP_HELVETICA_18, "Menu", 1, 0, 0);

}

void cMenuScene::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	printf("Normal key: %d\n", key);
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}

	if (key == 13) {
		
	}
}

void cMenuScene::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	printf("Special key: %d", key);
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}

	
}

void cMenuScene::ReadMouse(int button, int state, int x, int y)
{
}
