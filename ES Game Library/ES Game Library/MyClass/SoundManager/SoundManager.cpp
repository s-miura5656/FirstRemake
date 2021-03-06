#include "SoundManager.h"

void SoundManager::Initialize()
{
	// ゲームで使うBGMの読み込み
	m_bgm.push_back(SoundDevice.CreateMusicFromFile(_T("Sound/title.wav")));
	m_bgm.push_back(SoundDevice.CreateMusicFromFile(_T("Sound/main.wav")));
	m_bgm.push_back(SoundDevice.CreateMusicFromFile(_T("Sound/end.wav")));

	// ゲームで使うSEの読み込み
	m_se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/start.wav")));
	m_se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/page.wav")));
	m_se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/gun2.wav")));
	m_se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/kara.wav")));
	m_se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/relord.wav")));
	m_se.push_back(SoundDevice.CreateSoundFromFile(_T("Sound/hi_score.wav")));
}

void SoundManager::BGMPlay(int bgm_number)
{
	m_bgm[bgm_number]->Play();
}

void SoundManager::SEPlay(int se_number)
{
	m_se[se_number]->Play();
}
