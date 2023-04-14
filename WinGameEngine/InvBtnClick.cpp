#include "stdafx.h"
#include "InvBtnClick.h"

#include "DivUI.h"
#include "ResMgr.h"
#include "Sound.h"

InvBtnClick::InvBtnClick(DivUI* _inventoryPanel, DivUI* _mapPanel)
	: mapPanel{ _mapPanel }, inventoryPanel{ _inventoryPanel }
{
}

void InvBtnClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"btnClickSound", L"resource\\sound\\UI\\ui_shared\\ui_town_button_click.wav");
	Sound* clickSound = ResMgr::GetInst()->FindSound(L"btnClickSound");

	clickSound->SetVolume(60.f);
	clickSound->Play(false);

	inventoryPanel->AllCanTarget(true);
	inventoryPanel->SetCanRend(true);

	mapPanel->AllCanTarget(false);
	mapPanel->SetCanRend(false);
}
