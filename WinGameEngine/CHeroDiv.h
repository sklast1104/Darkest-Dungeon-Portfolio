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
	DivUI* attackedOverlay;
	DivUI* curHpBar;

	wstring idleAnimName;
	wstring walkAnimName;
	wstring combatAnimName;
	wstring attackedAnimName;

public :

	CHeroDiv(CHero* _hero);
	~CHeroDiv() {}

	virtual void CreateAnimator() override;

	void PlayHeroIdleAnim();
	void PlayHeroWalkAnim();
	void PlayHeroCombatAnim();
	void PlayCurSkillByIdx(int _idx);
	void PlayAttackedAnim();

	void EnableOverlay(bool _isEnable);
	void EnableAttackedOverlay(bool _isEnable);
	void SetOverlay(CSelectedOverlay* _overlay) { overlay = _overlay; }
	void SetAttackedOverlay(DivUI* _overlay) { attackedOverlay = _overlay; }
	void SetCurHpBar(DivUI* _hpBar) { curHpBar = _hpBar; }

	void UpdateHpBar();

	void EnableAllChildUI(bool _enable);

	void EnableSkill();
	

	CLONE(CHeroDiv);
};

