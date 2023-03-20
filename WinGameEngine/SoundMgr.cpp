#include "stdafx.h"
#include "SoundMgr.h"

#include "Core.h"
#include "Sound.h"

SoundMgr::SoundMgr()
	: m_pSound(nullptr)
	, m_pBGM(nullptr)
{
}

SoundMgr::~SoundMgr()
{
}

int SoundMgr::init(void)
{
	if (FAILED(DirectSoundCreate8(NULL, &m_pSound, NULL)))
	{
		MessageBox(NULL, L"Sound Create Fail", L"SYSTEM ERROR", MB_OK);
		return false;
	}

	HWND hWnd = Core::GetInst()->GetMainHwnd();
	if (FAILED(m_pSound->SetCooperativeLevel(hWnd, DISCL_EXCLUSIVE)))
	{
		MessageBox(NULL, L"Sound Fail", L"SYSTEM ERROR", MB_OK);
		return false;
	}

	return true;
}

void SoundMgr::RegisterToBGM(Sound* _pSound)
{
	if (m_pBGM != nullptr)
		m_pBGM->Stop(true);

	m_pBGM = _pSound;
}
