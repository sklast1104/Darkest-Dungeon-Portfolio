#include "stdafx.h"
#include "InvBtnClick.h"

#include "DivUI.h"

InvBtnClick::InvBtnClick(DivUI* _inventoryPanel, DivUI* _mapPanel)
	: mapPanel{ _mapPanel }, inventoryPanel{ _inventoryPanel }
{
}

void InvBtnClick::Execute()
{
	inventoryPanel->AllCanTarget(true);
	inventoryPanel->SetCanRend(true);

	mapPanel->AllCanTarget(false);
	mapPanel->SetCanRend(false);
}
