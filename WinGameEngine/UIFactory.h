#pragma once

class DivUI;
class CDungeon;
class Scene_DSelect;
class CInvItem;
class CSquadDiv;
class CMonSquad;
class CNode;
class DMapUI;

class UIFactory
{
private :

	UIFactory() {}
	~UIFactory() {}

	static void MakeBFSMap(DMapUI* _mapPanel);
	static void MakeRoomUI(Vec2 pos, DMapUI* mapPanel, CNode* node);

public :

	static DivUI* CreateTitle();
	static DivUI* CreateTownDiscUI(Vec2 _vPos, const wstring& _titleName, const wstring& _disc);
	static DivUI* CreateBottomNavUI();
	static DivUI* CreateSideNavUI();
	static DivUI* CreateSlotContainer(Vec2 _vPos, DivUI* _dragRenderer);

	static DivUI* DungeonPgPanel(Vec2 _vPos, CDungeon* _dungeon, Scene_DSelect* _dScene);
	static DivUI* CreateShopItem(Vec2 _vPos, wstring _key, wstring _path, int _count, int _cost, DivUI* shopInvPanel);
	static DivUI* CreateInvItem(Vec2 _vPos, wstring _key, wstring _path, int _count);

	static DivUI* CreateToolTip(Vec2 _vPos, CInvItem* _invItem);
	static CSquadDiv* CreateSquadDiv();
	static CMonSquad* CreateMonSquadDiv();
	static DivUI* CreateDungeonPanel();
	static DivUI* CreateSkilTitle();
	static DivUI* CreateBStartDiv();
	static DivUI* CreateLeftBlood();
	static DivUI* CreateRightBlood();
	
	static DivUI* CreateVignBg();

};

