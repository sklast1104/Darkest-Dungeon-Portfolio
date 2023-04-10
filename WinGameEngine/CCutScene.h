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

	// ¿µ¿õ ½ºÄõµå
	CSquadDiv* heroSquad;

	// ¸ó½ºÅÍ ½ºÄõµå
	CMonSquad* monSquad;

	CHeroDiv* player;
	//CMonDiv* monster;

	vector<CMonDiv*> monsters;

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

