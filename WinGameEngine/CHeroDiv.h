#pragma once
#include "DivUI.h"

class CHero;
class CSelectedOverlay;

class CHeroDiv :
	public DivUI
{
private :

	CHero* hero;
	CSelectedOverlay* overlay;

	wstring idleAnimName;
	wstring walkAnimName;
	wstring combatAnimName;

public :

	CHeroDiv(CHero* _hero);
	~CHeroDiv() {}

	virtual void CreateAnimator() override;

	void PlayHeroIdleAnim();
	void PlayHeroWalkAnim();
	void PlayHeroCombatAnim();

	void EnableOverlay(bool _isEnable);
	void SetOverlay(CSelectedOverlay* _overlay) { overlay = _overlay; }

	CLONE(CHeroDiv);
};

