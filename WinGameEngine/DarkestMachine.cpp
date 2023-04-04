#include "stdafx.h"
#include "DarkestMachine.h"
#include "CIdleState.h"

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
	this->SetCurState(L"CIdleState");
}
