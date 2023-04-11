#pragma once

class Sound;

class SoundMgr
{
private :

	LPDIRECTSOUND8	m_pSound;
	Sound* m_pBGM;

public :
	int init(void);
	LPDIRECTSOUND8 GetSoundDevice() { return m_pSound; }
	void RegisterToBGM(Sound* _pSound);

	Sound* GetCurBgm() { return m_pBGM; }

public :

	SINGLE(SoundMgr);
};

