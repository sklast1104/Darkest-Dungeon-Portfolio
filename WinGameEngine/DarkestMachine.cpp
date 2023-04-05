#include "stdafx.h"
#include "DarkestMachine.h"
#include "CIdleState.h"
#include "CWaitState.h"
#include "CPlayerTurn.h"
#include "CEnemyTurn.h"
#include "CBStartState.h"

DarkestMachine::DarkestMachine()
	: player{ nullptr }
{
	Init();
}

DarkestMachine::~DarkestMachine()
{

}

// 한번만 호출해야됨 (State 초기화 하는 역할)
void DarkestMachine::Init()
{
	this->AddState(new CIdleState);
	this->AddState(new CWaitState);
	this->AddState(new CBStartState);
	this->AddState(new CPlayerTurn);

	this->SetCurState(L"CIdleState");
}
