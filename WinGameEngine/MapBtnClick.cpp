#include "stdafx.h"
#include "MapBtnClick.h"
#include "ResMgr.h"
#include "Sound.h"

#include "DivUI.h"

MapBtnClick::MapBtnClick(DivUI* _mapPanel, DivUI* _inventoryPanel)
	: mapPanel{_mapPanel}, inventoryPanel{_inventoryPanel}
{
}

void MapBtnClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"btnClickSound", L"resource\\sound\\UI\\ui_shared\\ui_town_button_click.wav");
	Sound* clickSound = ResMgr::GetInst()->FindSound(L"btnClickSound");

	clickSound->SetVolume(60.f);
	clickSound->Play(false);

	mapPanel->AllCanTarget(true);
	mapPanel->SetCanRend(true);

	inventoryPanel->AllCanTarget(false);
	inventoryPanel->SetCanRend(false);
}
