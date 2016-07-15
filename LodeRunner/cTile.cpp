// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cTile.h"
#include "cAssetManager.h"


cTile::cTile()
{

}

cTile::~cTile()
{
}

bool cTile::Intersect(float x0, float y0, float x1, float y1)
{
	return x < x1 && x + width > x0 &&
		y < y1 && y + height > y0;
}

void cTile::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tileSprite->Texture());
	glBegin(GL_QUADS);
	/*tileSprite->X0(0);tileSprite->X1(0.125);
	tileSprite->Y0(0);tileSprite->Y1(0.125);*/

	glTexCoord2f(tileSprite->X0(), tileSprite->Y1());	glVertex3i(x, y, 50);
	glTexCoord2f(tileSprite->X1(), tileSprite->Y1());	glVertex3i(x + Width(), y, 50);
	glTexCoord2f(tileSprite->X1(), tileSprite->Y0());	glVertex3i(x + Width(), y + Height(), 50);
	glTexCoord2f(tileSprite->X0(), tileSprite->Y0());	glVertex3i(x, y + Height(), 50);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cTile::Init()
{
}

void cTile::Update(float tpf /*= 0.0333*/)
{
}

void cTile::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cTile::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cTile::ReadMouse(int button, int state, int x, int y)
{
}
