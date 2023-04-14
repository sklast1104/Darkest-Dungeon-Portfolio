#include "stdafx.h"
#include "HeroDivClick.h"
#include "GameMgr.h"

#include "DivUI.h"
#include "CSquadDiv.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Sound.h"

HeroDivClick::HeroDivClick(CSquadDiv* _squadDiv, int _realIndex)
	: squadDiv{_squadDiv}, realIndex{_realIndex}
{
}

void HeroDivClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"btnClickSound", L"resource\\sound\\UI\\ui_shared\\ui_town_button_click.wav");
	Sound* clickSound = ResMgr::GetInst()->FindSound(L"btnClickSound");

	clickSound->SetVolume(60.f);
	clickSound->Play(false);

	GameMgr* mgr = GameMgr::GetInst();
	mgr->SetFocusIndex(realIndex);

	// 그냥 여기도 게임매니저 기반으로 바로 포커싱된 인덱스로 알아서 오버레이 키도록
	// 구현해도 상관은 없을거 같긴 함
	squadDiv->EnableOverlay(realIndex);

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	DivUI* mainLeftPanel = (DivUI*)FindUIByName(pseudoUI, L"mainLeftPanel");

	mainLeftPanel->updateValue();
}
