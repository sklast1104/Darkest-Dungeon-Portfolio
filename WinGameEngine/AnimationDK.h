#pragma once
#include "Animation.h"

struct tDarkAnimFrm {
	// 프레임 이름
	string frameName;
	// 좌상단 좌표
	Vec2 vLT;
	// 이미지 크기
	Vec2 vSize;
	// 오프셋
	Vec2 vOffset;
	// 한 프레임당 지속시간
	float fDuration;
	// 텍스쳐 키
	string texKey;
	// 애니메이션 인덱스
	UINT index;
};

class AnimationDK :
	public Animation
{
private :

	// 다키스트 애니메이션 .atlas 관련 
	unordered_map<string, Texture*> texMap;
	vector<tDarkAnimFrm> vecDKFrm;

	// 좌우 반전된 텍스쳐를 불러오는지
	bool _isHorizontalFlip;

public :

	AnimationDK();
	~AnimationDK();

	void Load(const wstring& _strRelativePath) override;
	void Load(const wstring& _strRelativePath, const wstring& _animName) override;
	void LoadFlippedTex(const wstring& _strRelativePath);
	virtual void update() override;
	virtual void render(HDC _dc) override;

	void SetHorizontalFlip() { _isHorizontalFlip = true; }

	// 반전된 텍스쳐가 이미 있다고 가정함
	void InvertedRender(HDC _dc);

	void SetAllFrameDuration(float fDuration) override;
	void SetAllFrameOffset(Vec2 offset) override;

	friend class AnimatorDK;

};

