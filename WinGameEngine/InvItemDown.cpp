#include "stdafx.h"
#include "InvItemDown.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "GameMgr.h"
#include "Scene_Shop.h"
#include "DivUI.h"
#include "ImageModule.h"

InvItemDown::InvItemDown(DivUI* _myItem, int _index)
	: scene{ SceneMgr::GetInst()->GetCurScene() }
	, myItem{ _myItem }, mgr{ GameMgr::GetInst() }, index{ _index }
{
}

void InvItemDown::Execute()
{
	DivUI* itemDragger = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"itemDragger");

	// �κ��丮�� �����ؼ� �κ��丮 ������� ��������

	array<CItem*, 16>& inventory = mgr->GetInventory();

	CItem* curClicked = inventory[index];

	if (nullptr == curClicked) return;

	// �� ������ �ƴҶ��� 
	if (nullptr != myItem->GetIModule()) {
		itemDragger->InitImageModule(myItem->GetIModule()->GetResourceKey(), myItem->GetIModule()->GetRelativePath());
		itemDragger->SetCanRend(true);
		itemDragger->SetId(index);
	}

}
