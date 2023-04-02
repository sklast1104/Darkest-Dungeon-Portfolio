#include "stdafx.h"
#include "InvItemDown.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "GameMgr.h"
#include "Scene_Shop.h"
#include "DivUI.h"
#include "ImageModule.h"

InvItemDown::InvItemDown(DivUI* _myItem, int _index)
	: scene{ (Scene_Shop*)SceneMgr::GetInst()->GetCurScene() }
	, myItem{ _myItem }, mgr{ GameMgr::GetInst() }, index{ _index }
{
}

void InvItemDown::Execute()
{
	if (SceneMgr::GetInst()->GetCurScene()->GetName() == L"Scene_Shop") {
		
		DivUI* itemDragger = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"itemDragger");

		// 인벤토리를 조사해서 인벤토리 기반으로 가져오자

		array<CItem*, 16>& inventory = mgr->GetInventory();

		CItem* curClicked = inventory[index];

		if (nullptr == curClicked) return;

		// 빈 슬롯이 아닐때만 
		if (nullptr != myItem->GetIModule()) {
			itemDragger->InitImageModule(myItem->GetIModule()->GetResourceKey(), myItem->GetIModule()->GetRelativePath());
			itemDragger->SetCanRend(true);
			itemDragger->SetId(index);
		}

	}
}
