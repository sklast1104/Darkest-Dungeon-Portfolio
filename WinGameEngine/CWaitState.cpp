#include "stdafx.h"
#include "CWaitState.h"

#include "TimeMgr.h"
#include "DivUI.h"
#include "SceneMgr.h"
#include "Scene.h"

#include "CSquadDiv.h"
#include "CMonSquad.h"

CWaitState::CWaitState()
	: CState(L"CWaitState")
	, elapsedTime{ 0.f }
{
}

CWaitState::~CWaitState()
{
}

void CWaitState::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
}

void CWaitState::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 2.f) {

		elapsedTime = 0.f;

		ChangeState(GetStateMachine(), L"CPlayerTurn");
	}
}

void CWaitState::Exit()
{
}


