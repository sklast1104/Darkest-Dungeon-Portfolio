#pragma once
#include "DivUI.h"

class CDarkMonster;

class CMonDiv :
	public DivUI
{

private :

	CDarkMonster* monster;

	wstring combatAnimName;

public :

	CMonDiv(CDarkMonster* _monster);
	~CMonDiv() {}

	virtual void CreateAnimator() override;
	void PlayCombatAnim();

	CLONE(CMonDiv);
};

