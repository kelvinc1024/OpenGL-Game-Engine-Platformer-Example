// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cMenuScene.h"
#include "cLevel1Scene.h"
#include "cGame.h"

cMenuScene::cMenuScene()
{

}

cMenuScene::~cMenuScene()

{

}

void cMenuScene::Init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	visible_area.top = GAME_HEIGHT;
	visible_area.bottom = 0;
	visible_area.left = 0;
	visible_area.right = GAME_WIDTH;
	glOrtho(visible_area.left, visible_area.right, visible_area.bottom, visible_area.top, 3, -101);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void cMenuScene::Update(float tpf /*= 0.0333*/)
{
}

void cMenuScene::Render()
{
	renderBitmapString(300, 300, 9, GLUT_BITMAP_HELVETICA_18, "Press Any Key To Continue", 1, 0, 0);

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
		cGame::getInstance().UpdateScene(new cLevel1Scene());
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
