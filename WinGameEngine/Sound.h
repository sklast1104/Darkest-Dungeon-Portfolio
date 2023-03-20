#pragma once
#include "Res.h"

class Sound :
	public Res
{
private:
	LPDIRECTSOUNDBUFFER		m_pSoundBuffer;
	DSBUFFERDESC			m_tBuffInfo;
	int						m_iVolume;

	bool LoadWaveSound(const wstring& _strPath);
	int GetDecibel(float _fVolume);
public:

	Sound();
	virtual ~Sound();

	int Load(const wstring& _strPath);
	// �Ϲ� ���
	void Play(bool _bLoop = false);
	// BGM���� ���
	void PlayToBGM(bool _bLoop = false);
	void Stop(bool _bReset = false);
	// ���� ���� (0~100)
	void SetVolume(float _fVolume);
	// �������� ��ġ ����
	void SetPosition(float _fPosition);



};
