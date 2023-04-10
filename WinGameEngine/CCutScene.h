#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;
class CTurnPlayer;
class CHeroDiv;
class CMonDiv;

class CCutScene :
	public CState
{

private :

	// ���� ������
	CSquadDiv* heroSquad;

	// ���� ������
	CMonSquad* monSquad;

	// ������
	CTurnPlayer* attacker;

	// �ǰ���
	CTurnPlayer* victim;

	CHeroDiv* player;
	CMonDiv* monster;

	bool isPlayerAttack;
	bool moveBack;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CCutScene();
	~CCutScene();

	void IsPlayerAttack(bool _isPlayerAttack) { isPlayerAttack = _isPlayerAttack; }
};

