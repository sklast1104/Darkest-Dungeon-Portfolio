#include "stdafx.h"
#include "AnimatorDK.h"

#include "AnimationDK.h"

AnimatorDK::AnimatorDK()
{
}

AnimatorDK::~AnimatorDK()
{
}

void AnimatorDK::LoadAnimation(const wstring& _strRelativePath)
{
	AnimationDK* dkAnim = new AnimationDK;
	dkAnim->Load(_strRelativePath);

	dkAnim->m_pAnimator = this;
	m_mapAnim.insert(make_pair(dkAnim->GetName(), dkAnim));
}

void AnimatorDK::LoadAnimation(const wstring& _strRelativePath, const wstring& _animName)
{
	AnimationDK* dkAnim = new AnimationDK;
	dkAnim->Load(_strRelativePath, _animName);

	dkAnim->m_pAnimator = this;
	m_mapAnim.insert(make_pair(_animName, dkAnim));
}

void AnimatorDK::LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip)
{
	if (!_isHorizontalFlip) {
		LoadAnimation(_strRelativePath);
	}
	else {
		// ���� �ؽ��İ� ������ٰ� �����ϴ°��� �ƴ϶� ������ �ؽ��Ŀ���
		// �¿� ������ �ؽ��ĸ� ��������
		AnimationDK* dkAnim = new AnimationDK;
		dkAnim->SetHorizontalFlip();
		dkAnim->LoadFlippedTex(_strRelativePath);

		dkAnim->m_pAnimator = this;
		m_mapAnim.insert(make_pair(dkAnim->GetName(), dkAnim));
	}
}

void AnimatorDK::LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip, const wstring& _animName)
{
	if (!_isHorizontalFlip) {
		LoadAnimation(_strRelativePath);
	}
	else {
		// ���� �ؽ��İ� ������ٰ� �����ϴ°��� �ƴ϶� ������ �ؽ��Ŀ���
		// �¿� ������ �ؽ��ĸ� ��������
		AnimationDK* dkAnim = new AnimationDK;
		dkAnim->SetHorizontalFlip();
		dkAnim->LoadFlippedTex(_strRelativePath);

		dkAnim->m_pAnimator = this;
		m_mapAnim.insert(make_pair(_animName, dkAnim));
	}
}

void AnimatorDK::LoadAnimation(const wstring& _strRelativePath, float fDuration)
{
	AnimationDK* dkAnim = new AnimationDK;
	dkAnim->Load(_strRelativePath);
	dkAnim->SetAllFrameDuration(fDuration);

	dkAnim->m_pAnimator = this;
	m_mapAnim.insert(make_pair(dkAnim->GetName(), dkAnim));
}

void AnimatorDK::LoadAnimation(const wstring& _strRelativePath, float fDuration, Vec2 fOffset)
{
	AnimationDK* dkAnim = new AnimationDK;
	dkAnim->Load(_strRelativePath);
	dkAnim->SetAllFrameDuration(fDuration);
	dkAnim->SetAllFrameOffset(fOffset);

	dkAnim->m_pAnimator = this;
	m_mapAnim.insert(make_pair(dkAnim->GetName(), dkAnim));
}

void AnimatorDK::LoadAnimation(const wstring& _strRelativePath, float fDuration, Vec2 fOffset, bool _isHorizontalFlip)
{
}
