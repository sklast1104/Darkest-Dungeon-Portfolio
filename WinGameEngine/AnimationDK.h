#pragma once
#include "Animation.h"

struct tDarkAnimFrm {
	// ������ �̸�
	string frameName;
	// �»�� ��ǥ
	Vec2 vLT;
	// �̹��� ũ��
	Vec2 vSize;
	// ������
	Vec2 vOffset;
	// �� �����Ӵ� ���ӽð�
	float fDuration;
	// �ؽ��� Ű
	string texKey;
	// �ִϸ��̼� �ε���
	UINT index;
};

class AnimationDK :
	public Animation
{
private :

	// ��Ű��Ʈ �ִϸ��̼� .atlas ���� 
	unordered_map<string, Texture*> texMap;
	vector<tDarkAnimFrm> vecDKFrm;

	// �¿� ������ �ؽ��ĸ� �ҷ�������
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

	// ������ �ؽ��İ� �̹� �ִٰ� ������
	void InvertedRender(HDC _dc);

	void SetAllFrameDuration(float fDuration) override;
	void SetAllFrameOffset(Vec2 offset) override;

	friend class AnimatorDK;

};

