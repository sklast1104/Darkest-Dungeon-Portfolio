#pragma once
#include "DivUI.h"

class CMonDiv;

class CMonSquad :
	public DivUI
{
private :

	vector<CMonDiv*> monDivs;

public :

	CMonSquad();
	~CMonSquad();

	virtual void update() override;

	void AddMonster(CMonDiv* _monDiv) { monDivs.push_back(_monDiv); }

	void PlayIdleCombatAnim();

	CLONE(CMonSquad);
};

