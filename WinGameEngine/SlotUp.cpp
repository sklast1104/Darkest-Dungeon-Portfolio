#include "stdafx.h"
#include "SlotUp.h"
#include "DivUI.h"
#include "ImageModule.h"
#include "GameMgr.h"
#include "CHero.h"

SlotUp::SlotUp(DivUI* _mySlot ,DivUI* _dragUI, int _slotIndex, DivUI* _slotContainer)
	: dragUI{_dragUI}, mySlot{_mySlot}, slotIndex{_slotIndex}, slotContainer{_slotContainer}
{
}

void SlotUp::Execute()
{
	wstring key = L"";
	wstring path = L"";
	wstring hName = L"";
	GameMgr* mgr = GameMgr::GetInst();

	if (nullptr != dragUI->GetIModule()) {
		key = dragUI->GetIModule()->GetResourceKey();
		path = dragUI->GetIModule()->GetRelativePath();
		hName = dragUI->GetName();
	}

	if (key != L"" && path != L"") {

		if (mgr->isSlotEmpty(slotIndex)) {
			mgr->AddSquad(slotIndex, hName);
			mySlot->InitImageModule(key, path);
			mySlot->SetName(hName);
			mySlot->SetCanRendImg(true);
		}
		else {
			
			int prevIndex = dragUI->GetId();
			//CHero* draggingHero = mgr->FindHeroByName(hName);
			mgr->AddSquad(prevIndex, hName);

			if (prevIndex == slotIndex) return;

			mgr->SwapSquad(prevIndex, slotIndex);

			// ���� �����̳ʸ� ��ȸ�ؼ� �ڽ��� �����̳� �̸����� hero�� ã�Ƽ� �ش� ����η� 
			// �̸� �� �̹��� �ʱ�ȭ �׸��� �̹��� ������ ������

			// ������� �Դٸ� ���ӸŴ������� �����ϴ� ������ ���� �ε����� ������ ���� ����
			for (int i = 0; i < slotContainer->GetChildUI().size(); i++) {

				DivUI* slotPortrait = (DivUI*)(slotContainer->GetChildUI()[i]->GetChildUI()[0]);
				
				if (prevIndex == i) {
					
					CHero* prevHero = mgr->GetHeroBySquad(prevIndex);
					slotPortrait->InitImageModule(prevHero->GetKey(), prevHero->GetPath());
					slotPortrait->SetName(prevHero->GetName());
					slotPortrait->SetCanRend(true);
					slotPortrait->SetCanRendImg(true);
				}
				else if (slotIndex == i) {
					CHero* curHero = mgr->GetHeroBySquad(slotIndex);
					slotPortrait->InitImageModule(curHero->GetKey(), curHero->GetPath());
					slotPortrait->SetName(curHero->GetName());
					slotPortrait->SetCanRend(true);
					slotPortrait->SetCanRendImg(true);
				}
			}
		}
	}
}
