#include "stdafx.h"
#include "MapBtnClick.h"

#include "DivUI.h"

MapBtnClick::MapBtnClick(DivUI* _mapPanel, DivUI* _inventoryPanel)
	: mapPanel{_mapPanel}, inventoryPanel{_inventoryPanel}
{
}

void MapBtnClick::Execute()
{
	mapPanel->AllCanTarget(true);
	mapPanel->SetCanRend(true);

	inventoryPanel->AllCanTarget(false);
	inventoryPanel->SetCanRend(false);
}
