#pragma once
#include "DivUI.h"

class CHero;

class CHeroDiv :
	public DivUI
{
private :

	CHero* hero;

public :

	CHeroDiv();
	~CHeroDiv() {}

	virtual void CreateAnimator() override;

	void PlayHeroIdleAnim();
	void PlayHeroWalkAnim();
	void PlayHeroCombatAnim();

	CLONE(CHeroDiv);
};

