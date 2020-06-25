#include "SoundManager.h"

void SoundManager::Initialize()
{
	// ゲームで使うBGMの読み込み
	bgm.push_back(SoundDevice.CreateMusicFromFile(_T("Sound/title.wav")));
	bgm.push_back(SoundDevice.CreateMusicFromFile(_T("Sound/main.wav")));
	bgm.push_back(SoundDevice.CreateMusicFromFile(_T("Sound/end.wav")));

	// ゲームで使うSEの読み込み
	se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/start.wav")));
	se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/page.wav")));
	se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/gun2.wav")));
	se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/kara.wav")));
	se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/relord.wav")));
	se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/hi_score.wav")));
}

void SoundManager::BGMPlay(int bgm_number)
{
	bgm[bgm_number]->Play();
}

void SoundManager::SEPlay(int se_number)
{
	se[se_number]->Play();
}
