#include "cSprite.h"



cSprite::cSprite()
{
}


cSprite::cSprite(unsigned int texture, float x0, float y0, float x1, float x2)
{
	this->texture = texture;
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
}

cSprite::~cSprite()
{
}
