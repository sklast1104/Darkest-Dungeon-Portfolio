#include "stdafx.h"
#include "CBStartState.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Sound.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "ResMgr.h"
#include "Sound.h"

CBStartState::CBStartState()
	: CState(L"CBStartState")
	, elapsedTime{0.f}
{
}

CBStartState::~CBStartState()
{
}

void CBStartState::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	CSquadDiv* heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	CMonSquad* monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	int curHeroIndex = GameMgr::GetInst()->GetFocusIndex();

	heroSquad->DisableAllOverlay();
	heroSquad->PlayHeroCombatAnim();

	GameMgr::GetInst()->MakeSquadAlive();
	GameMgr::GetInst()->MakeTurnAlive();
	
	monSquad->SetCanRend(true);
	monSquad->makeTargetMons(true);
	monSquad->makeVisibleMons(true);
	monSquad->restorePos();
	monSquad->updateHpBar();

	ResMgr::GetInst()->LoadSound(L"BattleBgm", L"resource\\sound\\Music\\Combat_Level1_Loop1 {1ba3a4b1-3a73-424c-abaa-3f7520bfb535}.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"BattleBgm");

	pTitleSound->SetVolume(20.f);
	pTitleSound->PlayToBGM(true);
}

void CBStartState::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 2.f) {

		elapsedTime = 0.f;

		ChangeState(GetStateMachine(), L"CWaitState");
	}
}

void CBStartState::Exit()
{
	elapsedTime = 0.f;
}


