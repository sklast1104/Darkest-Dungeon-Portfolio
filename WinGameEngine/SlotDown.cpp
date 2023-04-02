#include "stdafx.h"
#include "SlotDown.h"

#include "DivUI.h"
#include "ImageModule.h"
#include "GameMgr.h"

SlotDown::SlotDown(DivUI* _heroPortrait, DivUI* _dragRenderer, int _slotIndex)
	: heroPortrait{_heroPortrait}, dragRenderer{_dragRenderer}, slotIndex{_slotIndex}
{
}

SlotDown::~SlotDown()
{
}

void SlotDown::Execute()
{
	// ½½·ÔÀ» »óÁ¡¾ÀÀÌ¶û ´øÀü ¼±ÅÃ¾À¸¸ ¾µÅÙµ¥ µÎ°³´Ù ÀÌ ·ÎÁ÷À» »ç¿ëÇÒ È®·üÀÌ ³ôÀ½

	if (nullptr != heroPortrait->GetIModule()) {
		wstring key = heroPortrait->GetIModule()->GetResourceKey();
		wstring path = heroPortrait->GetIModule()->GetRelativePath();

		dragRenderer->InitImageModule(key, path);
		dragRenderer->SetName(heroPortrait->GetName());
		dragRenderer->SetId(slotIndex);
		dragRenderer->SetCanRend(true);
		heroPortrait->SetCanRendImg(false);

		heroPortrait->SetName(L"");
		GameMgr::GetInst()->MakeEmpySlot(slotIndex);
	}
}
