#pragma once
#include "CCommand.h"

class DivUI;

class InvBtnClick :
	public CCommand
{
private :

	DivUI* inventoryPanel;
	DivUI* mapPanel;

public :

	InvBtnClick(DivUI* _inventoryPanel, DivUI* _mapPanel);
	~InvBtnClick() {}

	virtual void Execute() override;
};

