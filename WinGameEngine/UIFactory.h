#pragma once

class DivUI;

class UIFactory
{
private :

	UIFactory() {}
	~UIFactory() {}

public :

	static DivUI* CreateTitle();

	static DivUI* CreateTownDiscUI(Vec2 _vPos, const wstring& _titleName, const wstring& _disc);
	static DivUI* CreateBottomNavUI();

	static DivUI* CreateSideNavUI();

};

