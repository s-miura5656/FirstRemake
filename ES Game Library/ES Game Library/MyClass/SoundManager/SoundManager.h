#pragma once

#include "../../ESGLib.h"

enum SE_Num
{
	Start,
	Page,
	Gun,
	Empty,
	Reload,
	HiScore
};

enum BGM_Num
{
	Title,
	Main,
	Result
};

class SoundManager
{
public:
	~SoundManager() {};

	static SoundManager& Instance() {
		static SoundManager instance;
		return instance;
	}

	void Initialize();
	void BGMPlay(int bgm_number);
	void SEPlay(int se_number);

private:
	SoundManager() {};
	SoundManager(const SoundManager&) = delete;
	void operator=(const SoundManager&) = delete;

	std::vector<MUSIC> bgm;
	std::vector<SOUND> se;
};