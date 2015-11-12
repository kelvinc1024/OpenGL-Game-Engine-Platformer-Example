// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cLevel1Scene.h"
#include "cAssetManager.h"
#include "cGame.h"
#include "cMenuScene.h"
#pragma warning(disable:4996)

cLevel1Scene::cLevel1Scene()
{

}

cLevel1Scene::~cLevel1Scene()
{
}

void cLevel1Scene::Init()
{
	Load();
	//for (int i = 0;i < TOTAL_TILE_Y;i++) {
	//	printf("%s\n", Stage[i]);
	//}

	player = new cPlayer(cAssetManager::getInstance().player, 100, 200, 2 * TILE_SIZE, 4 * TILE_SIZE);
	player->Init();
}

bool cLevel1Scene::Load()
{
	FILE *f = fopen("Levels/level01.txt", "r");
	if (f) {
		int i = 0;
		while (!feof(f)) {
			char temp[1000];
			fscanf(f, "%[^\n]\n", &temp);
			for (int j = 0;j < strlen(temp);j++) {
				if (temp[j] == 'e') {
					exit = new cTile(cAssetManager::getInstance().tiles->at(71), j*TILE_SIZE, (TOTAL_TILE_Y - i)*TILE_SIZE, TILE_SIZE, TILE_SIZE, j, i);
				}
				else if (temp[j] == 'g') {
					exit_door_bottom = new cTile(cAssetManager::getInstance().tiles->at(59), j*TILE_SIZE, (TOTAL_TILE_Y - i)*TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2, j, i);
				}
				else if (temp[j] == 'h') {
					exit_door_top = new cTile(cAssetManager::getInstance().tiles->at(58), j*TILE_SIZE, (TOTAL_TILE_Y - i+1)*TILE_SIZE, TILE_SIZE * 2, TILE_SIZE * 2, j, i);
				}
				else if (temp[j] == 'p') {

				}
				else if (temp[j] != ' ') {
					cTile *t = new cTile(cAssetManager::getInstance().tiles->at(66), j*TILE_SIZE, (TOTAL_TILE_Y - i)*TILE_SIZE, TILE_SIZE, TILE_SIZE, j, i);
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

void cLevel1Scene::Render()
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

	exit->Render();
	exit_door_bottom->Render();
	exit_door_top->Render();

	player->Render();

	renderBitmapString(5, 580, 9, GLUT_BITMAP_HELVETICA_18, "Lighthouse3D", 1, 0, 0);
}



void cLevel1Scene::Update(float tpf /*= 0.0333*/)
{
	player->Update();

	CheckPlayerGroundCollision();
	CheckPlayerSideCollision();

	UpdateCamera();
}

void cLevel1Scene::ReadKeyboard(unsigned char key, int x, int y, bool press)
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

void cLevel1Scene::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
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

void cLevel1Scene::ReadMouse(int button, int state, int x, int y)
{
	player->ReadMouse(button, state, x, y);
}

void cLevel1Scene::CheckPlayerGroundCollision()
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

	if (exit_door_bottom->Intersect(
		player->X(), 
		player->Y(), 
		player->X() + player->Width(), 
		player->Y() + player->Height())
		) {
		cGame::getInstance().UpdateScene(new cMenuScene());
	}
}

void cLevel1Scene::CheckPlayerSideCollision()
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

void cLevel1Scene::UpdateCamera()
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
