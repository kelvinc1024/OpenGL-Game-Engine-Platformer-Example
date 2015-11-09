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

void cLevelScene::Draw()
{
	int tex_id = cAssetManager::getInstance().GetID(IMG_STAGE);
	int tex_w, tex_h;
	cAssetManager::getInstance().GetSize(tex_id, &tex_w, &tex_h);

	float x0, y0, x1, y1;
	float tex_offset_x, tex_offset_y;

	tex_offset_x = 1.0f / float(tex_w / TEXTURE_TILE_SIZE);
	tex_offset_y = 1.0f / float(tex_h / TEXTURE_TILE_SIZE);

	x0 = tex_offset_x * 0;
	y0 = tex_offset_y * 0;
	x1 = tex_offset_x * 1;
	y1 = tex_offset_y * 1;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_id);
	for (int i = 0;i < TOTAL_TILE_Y;i++) {
		for (int j = 0;j < strlen(Stage[i]);j++) {
			if (Stage[i][j] != ' ') {
				glBegin(GL_QUADS);
				glTexCoord2f(x0, y0);	glVertex3i(j*TILE_SIZE, (TOTAL_TILE_Y - i)*TILE_SIZE, 10);
				glTexCoord2f(x1, y0);	glVertex3i((j + 1)* TILE_SIZE, (TOTAL_TILE_Y - i)*TILE_SIZE, 10);
				glTexCoord2f(x1, y1);	glVertex3i((j + 1)* TILE_SIZE, ((TOTAL_TILE_Y - i) + 1)*TILE_SIZE, 10);
				glTexCoord2f(x0, y1);	glVertex3i(j*TILE_SIZE, ((TOTAL_TILE_Y - i) + 1)*TILE_SIZE, 10);
				glEnd();
			}
		}
	}
	glDisable(GL_TEXTURE_2D);
}

void cLevelScene::Init()
{
}

void cLevelScene::Update(float tpf /*= 0.0333*/)
{
}

void cLevelScene::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cLevelScene::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cLevelScene::ReadMouse(int button, int state, int x, int y)
{
}
