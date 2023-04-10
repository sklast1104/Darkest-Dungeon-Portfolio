#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;

class CEnemyTurn :
	public CState
{
private :

	// ���� ������
	CSquadDiv* heroSquad;

	// ���� ������
	CMonSquad* monSquad;

	// ���� ��Ŀ������ ���� �ε���
	int curMIdx;
	int curHIdx;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;
	bool canCg;

public :

	CEnemyTurn();
	~CEnemyTurn();

};

