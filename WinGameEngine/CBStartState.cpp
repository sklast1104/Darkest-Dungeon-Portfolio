#include "stdafx.h"
#include "CBStartState.h"
#include "TimeMgr.h"

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
}


