#include "cLevelScene.h"
#include <string.h>
#include <GL\glew.h>
#include "cAssetManager.h"
#pragma warning(disable:4996)

cLevelScene::cLevelScene()
{
	
}

cLevelScene::~cLevelScene()
{
}

bool cLevelScene::Load()
{
	FILE *f = fopen("Levels/level01.txt", "r");
	if (f) {
		int i = 0;
		while (!feof(f)) {
			fscanf(f, "%[^\n]\n", Stage[i++]);
		}
	}
	else {
		return false;
	}
}

void cLevelScene::Render()
{
	int tex_id = cAssetManager::getInstance().GetID(IMG_STAGE);
	int tex_w, tex_h;
	cAssetManager::getInstance().GetSize(tex_id, &tex_w, &tex_h);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, cAssetManager::getInstance().GetID(BG_COLORED_GRASS));
	for (int j = 0;j < 10;j++) {
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);	glVertex3i(j * 600, 0, 100);
		glTexCoord2f(1, 1);	glVertex3i((j + 1) * 600, 0, 100);
		glTexCoord2f(1, 0);	glVertex3i((j + 1) * 600, 600, 100);
		glTexCoord2f(0, 0);	glVertex3i(j * 600, 600, 100);
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);

	renderBitmapString(5, 580, 9, GLUT_BITMAP_HELVETICA_18, "Lighthouse3D", 1, 0, 0);
}

void cLevelScene::Init()
{
	Load();
}

void cLevelScene::Update(float tpf /*= 0.0333*/)
{
}

void cLevelScene::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cLevelScene::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cLevelScene::ReadMouse(int button, int state, int x, int y)
{
}
