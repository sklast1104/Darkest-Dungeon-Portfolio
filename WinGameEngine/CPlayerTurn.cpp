#include "stdafx.h"
#include "CPlayerTurn.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "ResMgr.h"
#include "Sound.h"

CPlayerTurn::CPlayerTurn()
	: CState(L"CPlayerTurn")
{
}

CPlayerTurn::~CPlayerTurn()
{
}

void CPlayerTurn::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	curHeroIndex = GameMgr::GetInst()->GetFocusIndex();

	// wait���� ���Ǿ� �;ߵǴµ� ������ ���� ��� ���ϹǷ� 3���� �س��� �׽�Ʈ
	curHeroIndex = 3;
	GameMgr::GetInst()->SetFocusIndex(3);

	heroSquad->PlayHeroCombatAnim();
	monSquad->SetCanRend(true);
	heroSquad->EnableFocus(curHeroIndex);

	ResMgr::GetInst()->LoadSound(L"BattleBgm", L"resource\\sound\\Music\\Combat_Level1_Loop1 {1ba3a4b1-3a73-424c-abaa-3f7520bfb535}.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"BattleBgm");

	pTitleSound->SetVolume(20.f);
	pTitleSound->PlayToBGM(true);
}

void CPlayerTurn::Update()
{
}

void CPlayerTurn::Exit()
{
}


