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

// �ѹ��� ȣ���ؾߵ� (State �ʱ�ȭ �ϴ� ����)
void DarkestMachine::Init()
{
	this->AddState(new CIdleState);
	this->AddState(new CWaitState);
	this->AddState(new CBStartState);
	this->AddState(new CPlayerTurn);

	this->SetCurState(L"CIdleState");
}
