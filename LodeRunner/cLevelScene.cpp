#include "cLevelScene.h"
#include "cAssetManager.h"
#include "cGame.h"
#pragma warning(disable:4996)

cLevelScene::cLevelScene()
{

}

cLevelScene::~cLevelScene()
{
}

void cLevelScene::Init()
{
	Load();
	//for (int i = 0;i < TOTAL_TILE_Y;i++) {
	//	printf("%s\n", Stage[i]);
	//}

	player = new cPlayer(cAssetManager::getInstance().player, 100, 200, 2 * TILE_SIZE, 4 * TILE_SIZE);
}

bool cLevelScene::Load()
{
	FILE *f = fopen("Levels/level01.txt", "r");
	if (f) {
		int i = 0;
		while (!feof(f)) {
			char temp[1000];
			fscanf(f, "%[^\n]\n", &temp);
			for (int j = 0;j < strlen(temp);j++) {
				if (temp[j] != ' ') {
					cTile *t = new cTile(cAssetManager::getInstance().tiles->at(3), j*TILE_SIZE, (TOTAL_TILE_Y - i)*TILE_SIZE, TILE_SIZE, TILE_SIZE, j, i);
					Stage.push_back(t);
				}
			}
			++i;

		}
	}
	else {
		return false;
	}
}

void cLevelScene::Render()
{
	GLuint tex_id = cAssetManager::getInstance().GetID(BG_COLORED_GRASS);
	int tex_w, tex_h;
	cAssetManager::getInstance().GetSize(tex_id, &tex_w, &tex_h);

	//background render
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_id);
	for (int j = -15;j < 15;j++) {
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);	glVertex3i(j * 600, 0, 100);
		glTexCoord2f(1, 1);	glVertex3i((j + 1) * 600, 0, 100);
		glTexCoord2f(1, 0);	glVertex3i((j + 1) * 600, 600, 100);
		glTexCoord2f(0, 0);	glVertex3i(j * 600, 600, 100);
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);

	//tile render
	for (int j = 0;j < Stage.size();j++) {
		Stage[j]->Render();
	}

	player->Render();

	renderBitmapString(5, 580, 9, GLUT_BITMAP_HELVETICA_18, "Lighthouse3D", 1, 0, 0);
}



void cLevelScene::Update(float tpf /*= 0.0333*/)
{
	player->Update();

	CheckPlayerGroundCollision();
	CheckPlayerSideCollision();

	UpdateCamera();
}

void cLevelScene::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	player->ReadKeyboard(key, x, y, press);
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
	player->ReadSpecialKeyboard(key, x, y, press);
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
	player->ReadMouse(button, state, x, y);
}

void cLevelScene::CheckPlayerGroundCollision()
{
	bool groundFlag = false;
	for (int i = 0;i < Stage.size();i++)
	{
		if (Stage.at(i)->Intersect(
			player->X() + 30,
			player->Y(),
			player->X() + player->Width() - 30,
			player->Y() + 50
			)) {
			if (player->Y() - player->Height() < Stage.at(i)->Y()) {
				groundFlag = true;
			}
		}
	}
	if (groundFlag)
		player->IsGroundCollide(true);
	else
		player->IsGroundCollide(false);
}

void cLevelScene::CheckPlayerSideCollision()
{
	bool rightCollision = false;
	bool leftCollision = false;
	for (int i = 0;i < Stage.size();i++)
	{
		if (Stage.at(i)->Intersect(
			player->X(),
			player->Y() + 30,
			player->X() + 50,
			player->Y() + player->Height() - 30
			)) {
			if (player->Y() - player->Height() < Stage.at(i)->Y()) {
				leftCollision = true;
			}
		}
		if (Stage.at(i)->Intersect(
			player->X() + player->Width() - 50,
			player->Y() + 30,
			player->X() + player->Width(),
			player->Y() + player->Height() - 30
			)) {
			if (player->X() < Stage.at(i)->X() + Stage.at(i)->Width()) {
				rightCollision = true;
			}
		}
	}
	if (rightCollision)
		player->IsRightCollide(true);
	else
		player->IsRightCollide(false);
	if (leftCollision)
		player->IsLeftCollide(true);
	else
		player->IsLeftCollide(false);
}

void cLevelScene::UpdateCamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	visible_area.top = GAME_HEIGHT;
	visible_area.bottom = 0;
	visible_area.left = player->X() - GAME_WIDTH / 2 + 200;
	visible_area.right = player->X() + GAME_WIDTH / 2 + 200;
	glOrtho(visible_area.left, visible_area.right, visible_area.bottom, visible_area.top, 3, -101);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
