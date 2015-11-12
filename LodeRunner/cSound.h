// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
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
	static cSound& getInstance()
	{
		static cSound instance;
		return instance;
	}

	bool Load();
	void Play(int sound_id);
	void StopAll();
	void Update();

	FMOD::System*     system; //handle to FMOD engine
	FMOD::Sound*      sounds[NUM_SOUNDS]; //sound that will be loaded and played
	FMOD::Channel*    ambient1Channel;
	FMOD::Channel*    ambient2Channel;
	FMOD::DSP*        dspSmoothStop;
private:
	~cSound(void);
	cSound(void);
	cSound(cSound const&) = delete;
	void operator=(cSound const&) = delete;
};