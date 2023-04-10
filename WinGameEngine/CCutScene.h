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

	// 영웅 스쿼드
	CSquadDiv* heroSquad;

	// 몬스터 스쿼드
	CMonSquad* monSquad;

	// 공격자
	CTurnPlayer* attacker;

	// 피격자
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

