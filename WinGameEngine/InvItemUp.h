#pragma once
#include "CCommand.h"

class DivUI;
class Scene_Shop;
class GameMgr;

class InvItemUp :
	public CCommand
{
private :

	DivUI* myItem;
	Scene_Shop* scene;
	GameMgr* mgr;
	int index;

public :

	InvItemUp(DivUI* _myItem, int _index);
	~InvItemUp() {}

	virtual void Execute() override;
};

