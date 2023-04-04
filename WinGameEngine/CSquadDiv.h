#pragma once
#include "DivUI.h"

class CHeroDiv;

class CSquadDiv :
	public DivUI
{
private :

	vector<CHeroDiv*> heros;
	float speed;

public :

	CSquadDiv();
	~CSquadDiv();

	virtual void update() override;

	float GetSpeed() { return speed; }

	void AddHero(CHeroDiv* _hero) { heros.push_back(_hero); }

	void PlayHeroIdleAnim();
	void PlayHeroWalkAnim();
	void PlayHeroCombatAnim();

	CLONE(CSquadDiv);
};

