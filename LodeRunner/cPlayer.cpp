#include "cPlayer.h"



cPlayer::cPlayer()
{
}


cPlayer::~cPlayer()
{
}

void cPlayer::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, playerSheet->at(0)->Texture());
	glBegin(GL_QUADS);
	/*playerSheets->X0(0);playerSheets->X1(0.125);
	playerSheets->Y0(0);playerSheets->Y1(0.125);*/

	glTexCoord2f(playerSheet->at(0)->X0(), playerSheet->at(0)->Y1());	glVertex3i(x, y, 50);
	glTexCoord2f(playerSheet->at(0)->X1(), playerSheet->at(0)->Y1());	glVertex3i(x + Width(), y, 50);
	glTexCoord2f(playerSheet->at(0)->X1(), playerSheet->at(0)->Y0());	glVertex3i(x + Width(), y + Height(), 50);
	glTexCoord2f(playerSheet->at(0)->X0(), playerSheet->at(0)->Y0());	glVertex3i(x, y + Height(), 50);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cPlayer::Init()
{

}

void cPlayer::Update(float tpf /*= 0.0333*/)
{
	if (!IsGroundCollide()) {
		y -= 100 * tpf;
	}

	if (currJumpPower > 0) {
		currJumpPower -= 300 * tpf;
		y += 300 * tpf;
	}

	if (keys[GLUT_KEY_LEFT] && !IsLeftCollide()) {
		x -= 300 * tpf;
	}
	else if (keys[GLUT_KEY_RIGHT] && !IsRightCollide()) {
		x += 300 * tpf;
	}
}

void cPlayer::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	if (key == ' ' && !keys[key] && press && IsGroundCollide()) {
		Jump();
	}
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cPlayer::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
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

void cPlayer::ReadMouse(int button, int state, int x, int y)
{

}

void cPlayer::Jump()
{
	currJumpPower = jumpPower;
}

bool cPlayer::Intersect(float x0, float y0, float x1, float y1)
{
	return x < x1 && x + width > x0 &&
		y < y1 && y + height > y0;
}
