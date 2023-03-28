#pragma once

#include "UI.h"

class ImageModule;
class TextModule;
class CCommand;

class DivUI :
	public UI
{
private :
	
	ImageModule* iModule;
	TextModule* tModule;

	bool canRendImg;
	bool canRendTxt;
	bool canRend;

protected :

	CCommand* onMouseOver;
	CCommand* onMouseClick;

public :

	DivUI();
	~DivUI();

	void SetCanRendImg(bool _canRendImg) { canRendImg = _canRendImg; }
	void SetCanRendTxt(bool _canRendTxt) { canRendTxt = _canRendTxt; }
	void SetCanRend(bool _canRend) { canRend = _canRend; }

	void SetSrcAlpha(int _alpha);
	void SetTextColor(UINT r, UINT g, UINT b);
	void SetSecondFont();
	void SetFormat(UINT _format);

	void InitImageModule(const wstring& _resourceKey, const wstring& _relativePath);
	void InitTextModule(const wstring& _text, const UINT _textSize);

	void InitOnMouseOver(CCommand* _onMouseOver) { onMouseOver = _onMouseOver; }
	void InitOnMouseClick(CCommand* _onMouseClick) { onMouseClick = _onMouseClick; }

	virtual void render(HDC _dc) override;

	void LoadAnimation(const wstring& _animName, const wstring& _atlasPath);

	CLONE(DivUI);
};

