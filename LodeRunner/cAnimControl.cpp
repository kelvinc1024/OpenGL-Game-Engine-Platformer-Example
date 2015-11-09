#include "cAnimControl.h"

cAnimControl::cAnimControl()
{
	counter = 0;
}


cAnimControl::~cAnimControl()
{
}

void cAnimControl::AddAnim(std::string animType, std::string name, int start, int end, float duration)
{
	animStatus[name] = cAnimation(animType, name, start, end, duration);
	SetActiveAnim(name);
}

void cAnimControl::RemoveAnim(std::string name)
{
	animStatus[name] = cAnimation();
}

void cAnimControl::SetAnim(std::string animType, std::string name, int start, int end, float duration)
{
	animStatus[name] = cAnimation(animType, name, start, end, duration);
}

void cAnimControl::SetActiveAnim(std::string name)
{
	activeAnimation = animStatus[name];
	activeName = name;
	index = animStatus[name].Start();
}

void cAnimControl::UpdateAnim(float tpf)
{
	counter += tpf;
	if (counter >= activeAnimation.AnimDuration()) {
		counter -= activeAnimation.AnimDuration();
		if (activeAnimation.AnimType() == "StraightLoop") {
			index++;
			if (index > activeAnimation.End()) index = activeAnimation.Start();
		}
		else if (activeAnimation.AnimType() == "RoundLoop") {

		}
		else if (activeAnimation.AnimType() == "NoLoop") {
			if (index < activeAnimation.End()) index++;
		}
	}
}

