#include "stdafx.h"
#include "AnimationDK.h"

#include "PathMgr.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Animator.h"
#include "Camera.h"
#include "Texture.h"
#include "UI.h"
#include "ViewMgr.h"

AnimationDK::AnimationDK()
	: _isHorizontalFlip{ false }
{
}

AnimationDK::~AnimationDK()
{
}

bool IsPNG(const string& strLine) {
	string ext = strLine.substr(strLine.find_last_of(".") + 1);
	return (ext == "png");
}

string extractPath(const std::wstring& filePath) {
	size_t pos = filePath.find_last_of(L"/\\");
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	std::wstring path = filePath.substr(0, pos + 1);
	return converter.to_bytes(path);
}

std::wstring stringToWstring(const std::string& narrowString) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.from_bytes(narrowString);
}

std::wstring extractFileName(const std::wstring& filePath) {
	std::size_t pos = filePath.find_last_of(L"/\\");
	if (pos != std::wstring::npos) {
		return filePath.substr(pos + 1);
	}
	return filePath;
}

int extractNumber(const std::string& str) {
	int number = 0;
	int pow = 1;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			number += (str[i] - '0') * pow;
			pow *= 10;
		}
		else if (number != 0) {
			break;
		}
	}
	return number;
}

bool CompareDKFrm(const tDarkAnimFrm& a, const tDarkAnimFrm& b) {
	return a.index < b.index;
}

void AnimationDK::Load(const wstring& _strRelativePath)
{
	wstring strFilePath = PathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;


	wstring animName = extractFileName(strFilePath);
	this->m_strName = animName;

	std::ifstream file(strFilePath);

	if (!file.is_open()) {
		cerr << "Failed to Open" << "endl";
		assert(nullptr);
	}

	string line;
	string keyName = "";
	string keyword;


	while (std::getline(file, line)) {
		istringstream lineStream(line);
		keyword = "";
		lineStream >> keyword;

		if (IsPNG(line)) {
			keyName = line;

			string path = extractPath(_strRelativePath);
			path += keyName;

			Texture* texTure = ResMgr::GetInst()->LoadTexture(stringToWstring(keyword), stringToWstring(path));

			texMap.insert(make_pair(keyName, texTure));
		}
		else

			if (keyword == "repeat:") {

				while (std::getline(file, line) && line != "") {

					tDarkAnimFrm dFrm = {};

					dFrm.texKey = keyName;
					dFrm.frameName = line;
					dFrm.index = extractNumber(line);

					std::getline(file, line); // rotate
					std::getline(file, line); // x, y
					int x, y;
					std::stringstream ss(line);
					std::string sub;
					ss >> sub >> x >> sub >> y;

					dFrm.vLT = Vec2(x, y);

					std::getline(file, line); // size 
					std::stringstream s2(line);
					s2 >> sub >> x >> sub >> y;

					dFrm.vSize = Vec2(x, y);

					std::getline(file, line); // orig 
					std::getline(file, line); // offset
					std::getline(file, line); // index;

					vecDKFrm.push_back(dFrm);
				}

			}
	}

	file.close();

	std::sort(vecDKFrm.begin(), vecDKFrm.end(), CompareDKFrm);

	float fDuration = 1.f / vecDKFrm.size();

	for (int i = 0; i < vecDKFrm.size(); i++) {
		vecDKFrm[i].fDuration = fDuration;
	}
}

void AnimationDK::Load(const wstring& _strRelativePath, const wstring& _animName)
{
	wstring strFilePath = PathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	this->m_strName = _animName;

	std::ifstream file(strFilePath);

	if (!file.is_open()) {
		cerr << "Failed to Open" << "endl";
		assert(nullptr);
	}

	string line;
	string keyName = "";
	string keyword;


	while (std::getline(file, line)) {
		istringstream lineStream(line);
		keyword = "";
		lineStream >> keyword;

		if (IsPNG(line)) {
			keyName = line;

			string path = extractPath(_strRelativePath);
			path += keyName;

			Texture* texTure = ResMgr::GetInst()->LoadTexture(stringToWstring(keyword), stringToWstring(path));

			texMap.insert(make_pair(keyName, texTure));
		}
		else

			if (keyword == "repeat:") {

				while (std::getline(file, line) && line != "") {

					tDarkAnimFrm dFrm = {};

					dFrm.texKey = keyName;
					dFrm.frameName = line;
					dFrm.index = extractNumber(line);

					std::getline(file, line); // rotate
					std::getline(file, line); // x, y
					int x, y;
					std::stringstream ss(line);
					std::string sub;
					ss >> sub >> x >> sub >> y;

					dFrm.vLT = Vec2(x, y);

					std::getline(file, line); // size 
					std::stringstream s2(line);
					s2 >> sub >> x >> sub >> y;

					dFrm.vSize = Vec2(x, y);
					// 프레임 헤이트 주는 로직 추가
					frameHeight = y;

					std::getline(file, line); // orig 
					std::getline(file, line); // offset
					std::getline(file, line); // index;

					vecDKFrm.push_back(dFrm);
				}

			}
	}

	file.close();

	std::sort(vecDKFrm.begin(), vecDKFrm.end(), CompareDKFrm);

	float fDuration = 1.f / vecDKFrm.size();

	for (int i = 0; i < vecDKFrm.size(); i++) {
		vecDKFrm[i].fDuration = fDuration;
	}
}

void AnimationDK::LoadFlippedTex(const wstring& _strRelativePath)
{
	wstring strFilePath = PathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;


	wstring animName = extractFileName(strFilePath);
	this->m_strName = animName;

	std::ifstream file(strFilePath);

	if (!file.is_open()) {
		cerr << "Failed to Open" << "endl";
		assert(nullptr);
	}

	string line;
	string keyName = "";
	string keyword;


	while (std::getline(file, line)) {
		istringstream lineStream(line);
		keyword = "";
		lineStream >> keyword;

		if (IsPNG(line)) {
			keyName = line;

			string path = extractPath(_strRelativePath);
			path += keyName;

			Texture* texTure = ResMgr::GetInst()->LoadTexture(stringToWstring(keyword), stringToWstring(path), true);

			texMap.insert(make_pair(keyName, texTure));
		}
		else

			if (keyword == "repeat:") {

				while (std::getline(file, line) && line != "") {

					tDarkAnimFrm dFrm = {};

					dFrm.texKey = keyName;
					dFrm.frameName = line;
					dFrm.index = extractNumber(line);

					std::getline(file, line); // rotate
					std::getline(file, line); // x, y
					int x, y;
					std::stringstream ss(line);
					std::string sub;
					ss >> sub >> x >> sub >> y;

					dFrm.vLT = Vec2(x, y);

					std::getline(file, line); // size 
					std::stringstream s2(line);
					s2 >> sub >> x >> sub >> y;

					dFrm.vSize = Vec2(x, y);

					std::getline(file, line); // orig 
					std::getline(file, line); // offset
					std::getline(file, line); // index;

					vecDKFrm.push_back(dFrm);
				}

			}
	}

	file.close();

	std::sort(vecDKFrm.begin(), vecDKFrm.end(), CompareDKFrm);

	float fDuration = 1.f / vecDKFrm.size();

	for (int i = 0; i < vecDKFrm.size(); i++) {
		vecDKFrm[i].fDuration = fDuration;
	}
}

void AnimationDK::update()
{
	if (m_bFinish)
		return;

	m_fAccTime += fDT;

	if (vecDKFrm[m_iCurFrm].fDuration < m_fAccTime) {

		++m_iCurFrm;

		if (vecDKFrm.size() <= m_iCurFrm) {
			m_iCurFrm = -1;
			m_bFinish = true;
			m_fAccTime = 0.f;
			return;
		}

		m_fAccTime = m_fAccTime - vecDKFrm[m_iCurFrm].fDuration;

	}
}

void AnimationDK::render(HDC _dc)
{
	if (m_bFinish)
		return;

	if (!_isHorizontalFlip) {
		Object* pObj = m_pAnimator->GetObj();
		UI* pUI = (UI*)pObj;

		Vec2 vPos = pUI->GetFinalPos();
		Vec2 vScale = pUI->GetScale();
		Vec2 vOffset = Vec2(vecDKFrm[m_iCurFrm].vOffset.x, vecDKFrm[m_iCurFrm].vOffset.y);
		Vec2 vFrameScale = Vec2(vecDKFrm[m_iCurFrm].vSize);

		if (pUI->IsCamEffected()) {
			vPos = Camera::GetInst()->GetRenderPos(vPos);
		}

		if (pUI->isViewEffected()) {
			// 프레임 오프셋 크기도 늘려줘야 할 수도 있음

			vPos = ViewMgr::GetInst()->GetViewPortPos(vPos);
			vScale = ViewMgr::GetInst()->GetViewPortScale(vScale);
			vOffset = ViewMgr::GetInst()->GetViewPortPos(vOffset);

			vFrameScale = ViewMgr::GetInst()->GetViewPortPos(vFrameScale);
		}

		BLENDFUNCTION bf = {};

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.AlphaFormat = AC_SRC_ALPHA;
		bf.SourceConstantAlpha = 255;

		// DK Animation은 모두 UI좌표로 다룰 예정이라서 vPos를 Left Top 취급함
		AlphaBlend(_dc
			, (int)(vPos.x  + vOffset.x)
			, (int)(vPos.y + vOffset.y)
			, (int)(vFrameScale.x * mulScale)
			, (int)(vFrameScale.y * mulScale)
			, texMap[vecDKFrm[m_iCurFrm].texKey]->GetDC()
			, (int)(vecDKFrm[m_iCurFrm].vLT.x)
			, (int)(vecDKFrm[m_iCurFrm].vLT.y)
			, (int)(vecDKFrm[m_iCurFrm].vSize.x)
			, (int)(vecDKFrm[m_iCurFrm].vSize.y)
			, bf);

		//AlphaBlend(_dc
		//	, (int)(vPos.x - vScale.x / 2.f + vecDKFrm[m_iCurFrm].vOffset.x)
		//	, (int)(vPos.y - vScale.y / 2.f + vecDKFrm[m_iCurFrm].vOffset.y)
		//	, (int)(vecDKFrm[m_iCurFrm].vSize.x)
		//	, (int)(vecDKFrm[m_iCurFrm].vSize.y)
		//	, texMap[vecDKFrm[m_iCurFrm].texKey]->GetDC()
		//	, (int)(vecDKFrm[m_iCurFrm].vLT.x)
		//	, (int)(vecDKFrm[m_iCurFrm].vLT.y)
		//	, (int)(vecDKFrm[m_iCurFrm].vSize.x)
		//	, (int)(vecDKFrm[m_iCurFrm].vSize.y)
		//	, bf);
	}
	else {
		InvertedRender(_dc);
	}
}

void AnimationDK::InvertedRender(HDC _dc)
{
	Object* pObj = m_pAnimator->GetObj();
	UI* pUI = (UI*)pObj;

	Vec2 vPos = pUI->GetFinalPos();
	Vec2 frameScale = vecDKFrm[m_iCurFrm].vSize;
	Vec2 vOffset = Vec2(vecDKFrm[m_iCurFrm].vOffset.x, vecDKFrm[m_iCurFrm].vOffset.y);

	if (pUI->IsCamEffected()) {
		vPos = Camera::GetInst()->GetRenderPos(vPos);
	}

	if (pUI->isViewEffected()) {
		// 프레임 오프셋 크기도 늘려줘야 할 수도 있음

		vPos = ViewMgr::GetInst()->GetViewPortPos(vPos);
		frameScale = ViewMgr::GetInst()->GetViewPortScale(frameScale);
		vOffset = ViewMgr::GetInst()->GetViewPortPos(vOffset);
	}

	BLENDFUNCTION bf = {};

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = AC_SRC_ALPHA;
	bf.SourceConstantAlpha = 255;

	Texture* tex = texMap[vecDKFrm[m_iCurFrm].texKey];
	size_t width = tex->Width();
	size_t height = tex->Height();

	int newX = width - (vecDKFrm[m_iCurFrm].vLT.x) - (vecDKFrm[m_iCurFrm].vSize.x);
	int newY = height - (vecDKFrm[m_iCurFrm].vLT.y) - (vecDKFrm[m_iCurFrm].vSize.y);

	AlphaBlend(_dc
		, (int)(vPos.x + vOffset.x)
		, (int)(vPos.y + vOffset.y)
		, (int)(frameScale.x * mulScale)
		, (int)(frameScale.y * mulScale)
		, texMap[vecDKFrm[m_iCurFrm].texKey]->GetDC()
		, (int)(newX)
		, (int)(vecDKFrm[m_iCurFrm].vLT.y)
		, (int)(vecDKFrm[m_iCurFrm].vSize.x)
		, (int)(vecDKFrm[m_iCurFrm].vSize.y)
		, bf);
}

void AnimationDK::SetAllFrameDuration(float fDuration)
{
	for (int i = 0; i < vecDKFrm.size(); i++) {
		vecDKFrm[i].fDuration = fDuration;
	}
}

void AnimationDK::SetAllFrameOffset(Vec2 offset)
{
	for (int i = 0; i < vecDKFrm.size(); i++) {
		vecDKFrm[i].vOffset = offset;
	}
}
