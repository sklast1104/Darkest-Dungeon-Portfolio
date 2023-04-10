#pragma once
#include "DivUI.h"

class CDarkMonster;
class CSelectedOverlay;
class DivUI;

class CMonDiv :
	public DivUI
{

private :

	CDarkMonster* monster;
	CSelectedOverlay* overlay;
	DivUI* curHpBar;

	wstring combatAnimName;

public :

	CMonDiv(CDarkMonster* _monster);
	~CMonDiv() {}

	virtual void CreateAnimator() override;
	void PlayCombatAnim();
	void PlayAttackedAnim();
	void PlayCurSkilByIdx(int _idx);

	void EnableAllChildUI(bool _enable);

	void SetOverlay(CSelectedOverlay* _overlay) { overlay = _overlay; }
	void EnableOverlay(bool _isEnable);
	void SetCuHpBar(DivUI* _hpBar) { curHpBar = _hpBar; }
	void UpdateHpBar();

	CLONE(CMonDiv);
};

