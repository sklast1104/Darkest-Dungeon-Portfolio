#include "stdafx.h"
#include "CIdleState.h"

#include "CSquadDiv.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Sound.h"
#include "Camera.h"
#include "CMonSquad.h"

CIdleState::CIdleState()
	: CState(L"CIdleState")
	, hSquad{nullptr}
	, mSquad{nullptr}
{
}

CIdleState::~CIdleState()
{
}

void CIdleState::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	CSquadDiv* squad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	squad->EnableAllCanTarget();
	hSquad = squad;

	// 몬스터 스쿼드 타겟은 꺼주고 BStart에서 스쿼드 타겟 켜줘야 한다
	mSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	mSquad->makeTargetMons(false);


	// curScene에서 pseudoUI 얻어와서 플레이어 세팅
	ResMgr::GetInst()->LoadSound(L"RuinsLevel1Bgm", L"resource\\sound\\Music\\Explore_Vaults_Level_1_Loop {a2068a43-0914-44b6-b2ec-e3cc8160dab9}.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"RuinsLevel1Bgm");

	pTitleSound->SetVolume(20.f);
	pTitleSound->PlayToBGM(true);

	// 씬 상태에 따라 달리 처리할 필요 있을수 있음
	//Camera::GetInst()->SetCurLookAt(Vec2(960.f, 540.f) + Vec2(300.f, 0.f));

	sName = SceneMgr::GetInst()->GetCurScene()->GetName();
}

void CIdleState::Update()
{
	// 이부분 나중에 다시 수정
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	CSquadDiv* squad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");

	hSquad = squad;

	mSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");

	Vec2 pos = hSquad->GetFinalPos();

	if (KEY_HOLD(KEY::D)) {
		hSquad->SetPos(Vec2(pos.x + (hSquad->GetSpeed() * fDT), pos.y));
		hSquad->PlayHeroWalkAnim();
	}
	else if (KEY_HOLD(KEY::A)) {
		hSquad->SetPos(Vec2(pos.x + (-hSquad->GetSpeed() * fDT), pos.y));
		hSquad->PlayHeroWalkAnim();
	}
	else {
		hSquad->PlayHeroIdleAnim();
	}

	float player_x = pos.x;
	
	// 몬스터 스쿼드도 일정 
	Vec2 monPos = mSquad->GetFinalPos();
	mSquad->SetPos(hSquad->GetFinalPos() + Vec2(590.f, 0.f));

	// 이 범위는 현 캐릭터 로스터에 따라 달라질 수는 있음
	if (player_x >= 860.f && player_x <= 4100.f) {

		if (SceneMgr::GetInst()->GetCurScene()->GetName() == L"Scene_Path") {
			Camera::GetInst()->SetCurLookAt(pos + Vec2(410.f, 370.f));
		}
	}
}

void CIdleState::Exit()
{
}


