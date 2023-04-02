#pragma once
#include "CCommand.h"

class DivUI;
class Scene_Shop;
class GameMgr;

class InvItemDown :
	public CCommand
{
private :

	DivUI* myItem;
	Scene_Shop* scene;
	GameMgr* mgr;
	int index;

public :

	InvItemDown(DivUI* _myItem, int _index);
	~InvItemDown() {}

	virtual void Execute() override;

};

