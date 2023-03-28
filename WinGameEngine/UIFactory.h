#pragma once

class DivUI;

class UIFactory
{
private :

	UIFactory() {}
	~UIFactory() {}

public :

	static DivUI* CreateTownDiscUI(Vec2 _vPos, const wstring& _titleName, const wstring& _disc);

};

