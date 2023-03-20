#pragma once

#include "UI.h"

class ImageModule;

class DivUI :
	public UI
{
private :
	
	ImageModule* iModule;

public :

	DivUI();
	~DivUI();

	void InitImageModule(const wstring& _resourceKey, const wstring& _relativePath);

	virtual void render(HDC _dc) override;

	void LoadAnimation(const wstring& _animName, const wstring& _atlasPath);

	CLONE(DivUI);
};

