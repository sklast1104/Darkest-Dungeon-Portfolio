#include "stdafx.h"
#include "CIdleState.h"

#include "CSquadDiv.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "KeyMgr.h"
#include "TimeMgr.h"

CIdleState::CIdleState()
	: CState(L"CIdleState")
	, hero{nullptr}
{
}

CIdleState::~CIdleState()
{
}

void CIdleState::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	CSquadDiv* squad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");

	hero = squad;
	// curScene���� pseudoUI ���ͼ� �÷��̾� ����
}

void CIdleState::Update()
{
	// �̺κ� ���߿� �ٽ� ����
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	CSquadDiv* squad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");

	hero = squad;

	Vec2 pos = hero->GetFinalPos();

	if (KEY_HOLD(KEY::D)) {
		hero->SetPos(Vec2(pos.x + (hero->GetSpeed() * fDT), pos.y));
		hero->PlayHeroWalkAnim();
	}
	else if (KEY_HOLD(KEY::A)) {
		hero->SetPos(Vec2(pos.x + (-hero->GetSpeed() * fDT), pos.y));
		hero->PlayHeroWalkAnim();
	}
	else {
		hero->PlayHeroIdleAnim();
	}
}

void CIdleState::Exit()
{
}


