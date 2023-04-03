#include "stdafx.h"
#include "SlotDown.h"

#include "DivUI.h"
#include "ImageModule.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"

SlotDown::SlotDown(DivUI* _heroPortrait, DivUI* _dragRenderer, int _slotIndex)
	: heroPortrait{_heroPortrait}, dragRenderer{_dragRenderer}, slotIndex{_slotIndex}
{
}

SlotDown::~SlotDown()
{
}

void SlotDown::Execute()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	DivUI* sideNavUI = (DivUI*)FindUIByName((UI*)pseudoUI, L"heroSideNav");

	const array<CHero*, 4> squad = GameMgr::GetInst()->GetSquad();

	// ������ �������̶� ���� ���þ��� ���ٵ� �ΰ��� �� ������ ����� Ȯ���� ����
	// ������ ���Կ� ����ΰ� �������� �����ؾ���

	if (nullptr != squad[slotIndex]) {

		if (nullptr != heroPortrait->GetIModule()) {

			wstring key = heroPortrait->GetIModule()->GetResourceKey();
			wstring path = heroPortrait->GetIModule()->GetRelativePath();

			// ������ ���������ً� ����� ��Ʈ���տ��� �̸� �ٿ������
			dragRenderer->InitImageModule(key, path);
			dragRenderer->SetName(heroPortrait->GetName());
			dragRenderer->SetId(slotIndex);
			dragRenderer->SetCanRend(true);
			heroPortrait->SetCanRendImg(false);

			//heroPortrait->SetName(L"");
			GameMgr::GetInst()->MakeEmpySlot(slotIndex);
			sideNavUI->updateValue();

		}
	}
	
}
