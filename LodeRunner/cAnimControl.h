#pragma once
#include "Globals.h"
#include "cAnimation.h"
class cAnimControl
{
public:
	cAnimControl();
	~cAnimControl();
	void AddAnim(std::string animType, std::string name, int start, int end, float duration);
	void RemoveAnim(std::string name);
	void SetAnim(std::string animType, std::string name, int start, int end, float duration);
	void SetActiveAnim(std::string name);
	void UpdateAnim(float tpf=0.0333);
	int Index() const { return index; }
	std::string ActiveName() const { return activeName; }
private:
	std::map<std::string, cAnimation> animStatus;
	std::string activeName;
	cAnimation activeAnimation;
	int index = 0;
	float counter = 0;
};

