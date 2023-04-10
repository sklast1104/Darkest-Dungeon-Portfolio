#include "stdafx.h"
#include "CMonDead.h"
#include "DivUI.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "GameMgr.h"
#include "CMonDiv.h"
#include "TimeMgr.h"

CMonDead::CMonDead()
	: CState(L"CMonDead")
	, elapsedTime{0.f}
	, lerpTime{1.f}
{
}

CMonDead::~CMonDead()
{
}

void CMonDead::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");

	GameMgr* mgr = GameMgr::GetInst();

	int heroIdx = mgr->GetFocusIndex();
	int skillIdx = mgr->GetSIndex();
	int monIdx = mgr->GetMonFocusIdx();

	for (int i = 0; i < monSquad->GetMonDivs().size(); i++) {

		if (monSquad->GetMonDivs()[i]->GetId() > monIdx) {
			//int newId = monSquad->GetMonDivs()[i]->GetId() - monIdx;
			//monSquad->GetMonDivs()[i]->SetId(newId);
			moveDiv.push_back(monSquad->GetMonDivs()[i]);
			startPos.push_back(monSquad->GetMonDivs()[i]->GetPos());
			toPos.push_back(monSquad->GetMonDivs()[i]->GetPos() + Vec2(-150.f, 0.f));
		}
	}

	canCg = true;
}

void CMonDead::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= lerpTime) {
		elapsedTime = lerpTime;
	}

	float t = elapsedTime / lerpTime;

	for (int i = 0; i < moveDiv.size(); i++) {

		moveDiv[i]->SetPos(Mathf::Lerp(startPos[i], toPos[i], t));

	}

	if (elapsedTime == lerpTime && canCg) {
		canCg = false;

		ChangeState(GetStateMachine(), L"CWaitState");
	}

	// 남은 몬스터들 이동 로직

}

void CMonDead::Exit()
{
	elapsedTime = 0.f;
}
