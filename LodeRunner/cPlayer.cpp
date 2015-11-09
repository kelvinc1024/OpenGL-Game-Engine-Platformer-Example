#include "cPlayer.h"



cPlayer::cPlayer()
{
}


cPlayer::~cPlayer()
{
}

bool cPlayer::Intersect(float x0, float y0, float x1, float y1)
{
	return x < x1 && x + width > x0 &&
		y < y1 && y + height > y0;
}
