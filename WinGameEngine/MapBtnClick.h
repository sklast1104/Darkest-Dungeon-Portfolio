#pragma once
#include "CCommand.h"

class DivUI;

class MapBtnClick :
	public CCommand
{

private :

	DivUI* mapPanel;
	DivUI* inventoryPanel;

public :

	MapBtnClick(DivUI* _mapPanel, DivUI* _inventoryPanel);
	~MapBtnClick() {}

	virtual void Execute() override;
};

