#pragma once

class DivUI;
class CDungeon;
class Scene_DSelect;

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
	static DivUI* CreateSlotContainer(Vec2 _vPos, DivUI* _dragRenderer);

	static DivUI* DungeonPgPanel(Vec2 _vPos, CDungeon* _dungeon, Scene_DSelect* _dScene);
	static DivUI* CreateShopItem(Vec2 _vPos, wstring _key, wstring _path, int _count, int _cost, DivUI* shopInvPanel);
	static DivUI* CreateInvItem(Vec2 _vPos, wstring _key, wstring _path, int _count);

};

