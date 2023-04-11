#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;
class CTurnPlayer;
class CHeroDiv;
class CMonDiv;
class DamageDiv;

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

	DamageDiv* heroDmgUI;
	vector<DamageDiv*> monDmgUIs;

	bool isPlayerAttack;
	bool moveBack;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CCutScene();
	~CCutScene();

	void SetHeroDmgUI(DamageDiv* ui) { heroDmgUI = ui; }
	void AddMonDmgUIs(DamageDiv* ui) { monDmgUIs.push_back(ui);}

	void IsPlayerAttack(bool _isPlayerAttack) { isPlayerAttack = _isPlayerAttack; }
	vector<DamageDiv*>& GetDamageDivs() {
		return monDmgUIs
			;
	}
};

