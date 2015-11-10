#pragma once
#include"Globals.h"
#include "cSprite.h"
#include "cAnimation.h"
#include "cAnimControl.h"

class cPlayer
{
private:
	cAnimControl *animControl;
	std::vector<cSprite*> *playerSheet;
	float x, y;
	int width, height;
	bool keys[255];
	bool isGroundCollide;
	bool isLeftCollide;
	bool isRightCollide;
	bool isCeilCollide;
	float jumpPower = 300;
	float currJumpPower = 0;
public:
	cPlayer(std::vector<cSprite*> *playerSheet, float x, float y, int width, int height)
		:playerSheet(playerSheet), x(x), y(y), width(width), height(height) {}
	cPlayer();
	~cPlayer();

	virtual void Render();
	virtual void Init();
	virtual void Update(float tpf = 0.0333);
	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press);
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	virtual void ReadMouse(int button, int state, int x, int y);

	void Jump();

	int Height() const { return height; }
	void Height(int val) { height = val; }
	int Width() const { return width; }
	void Width(int val) { width = val; }
	float X() const { return x; }
	void X(float val) { x = val; }
	float Y() const { return y; }
	void Y(float val) { y = val; }
	bool Intersect(float x0, float y0, float x1, float y1);
	bool IsGroundCollide() const { return isGroundCollide; }
	void IsGroundCollide(bool val) { isGroundCollide = val; }
	bool IsLeftCollide() const { return isLeftCollide; }
	void IsLeftCollide(bool val) { isLeftCollide = val; }
	bool IsRightCollide() const { return isRightCollide; }
	void IsRightCollide(bool val) { isRightCollide = val; }
	bool IsCeilCollide() const { return isCeilCollide; }
	void IsCeilCollide(bool val) { isCeilCollide = val; }
};

