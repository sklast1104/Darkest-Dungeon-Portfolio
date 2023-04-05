#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;

class CWaitState :
	public CState
{
private :

	// ���� ������
	CSquadDiv* heroSquad;

	// ���� ������
	CMonSquad* monSquad;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CWaitState();
	~CWaitState();

};

