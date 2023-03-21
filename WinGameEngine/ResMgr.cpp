#include "stdafx.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Sound.h"

#include "PathMgr.h"

ResMgr::ResMgr() {

}

ResMgr::~ResMgr() {

	Safe_Delete_Map(m_mapTex);
	Safe_Delete_Map(m_mapSound);
}

Texture* ResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	Texture* pTex = FindTexture(_strKey);
	if (nullptr != pTex) {
		return pTex;
	}

	wstring strFilePath = PathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new Texture;
	pTex->Load(strFilePath);
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

Texture* ResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath, bool _horizontalFlipped)
{
	Texture* pTex = FindTexture(_strKey);
	if (nullptr != pTex) {
		return pTex;
	}

	wstring strFilePath = PathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new Texture;

	if (!_horizontalFlipped) {
		pTex->Load(strFilePath);
	}
	else {
		pTex->LoadHorizonTalFlipped(strFilePath);
	}

	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

Texture* ResMgr::CreateTexutre(const wstring& _strKey, UINT _iWidth, UINT _iHeight)
{
	Texture* pTex = FindTexture(_strKey);
	if (nullptr != pTex) {
		return pTex;
	}

	pTex = new Texture;
	pTex->Create(_iWidth, _iHeight);
	pTex->SetKey(_strKey);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

Texture* ResMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, Res*>::iterator iter = m_mapTex.find(_strKey);

	if (iter == m_mapTex.end()) {
		return nullptr;
	}

	return (Texture*)iter->second;
}

Sound* ResMgr::LoadSound(const wstring& _strKey, const wstring& _strRelativePath)
{
	Sound* pSound = FindSound(_strKey);
	if (nullptr != pSound) {
		return pSound;
	}

	wstring strFilePath = PathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pSound = new Sound;
	pSound->Load(strFilePath);
	pSound->SetKey(_strKey);
	pSound->SetRelativePath(_strRelativePath);

	m_mapSound.insert(make_pair(_strKey, pSound));

	return pSound;
}

Sound* ResMgr::FindSound(const wstring& _strKey)
{
	map<wstring, Res*>::iterator iter = m_mapSound.find(_strKey);

	if (iter == m_mapSound.end()) {
		return nullptr;
	}

	return (Sound*)iter->second;
}
