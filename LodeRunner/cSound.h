#pragma once

#pragma comment(lib, "fmodex_vc.lib" ) // fmod library

#include <fmod.hpp> //fmod c++ header

//Sound array size
#define NUM_SOUNDS 15

//Sound identifiers
#define	SOUND_AMBIENT1      0
#define	SOUND_AMBIENT2      1


class cSound
{
public:
	cSound(void);
	virtual ~cSound(void);

	bool Load();
	void Play(int sound_id);
	void Stop(int sound_id);
	void SmoothStop(int sound_id);
	void StopAll();
	void Update();

	FMOD::System*     system; //handle to FMOD engine
	FMOD::Sound*      sounds[NUM_SOUNDS]; //sound that will be loaded and played
	FMOD::Channel*    ambient1Channel;
	FMOD::Channel*    ambient2Channel;
	FMOD::DSP*        dspSmoothStop;
};