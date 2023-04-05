#pragma once
#include "Animator.h"

class AnimatorDK :
	public Animator
{
private :
	unordered_map<string, Texture*> dkTextures;
public :
	AnimatorDK();
	~AnimatorDK();

	virtual void LoadAnimation(const wstring& _strRelativePath) override;
	virtual void LoadAnimation(const wstring& _strRelativePath, const wstring& _animName) override;
	virtual void LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip) override;
	virtual void LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip, const wstring& _animName) override;
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration) override;
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration, Vec2 fOffset) override;
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration, Vec2 fOffset, bool _isHorizontalFlip) override;
};

