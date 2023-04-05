#include "stdafx.h"
#include "MainLeftUpdateCom.h"

#include "DivUI.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CHero.h"
#include "CSkill.h"

MainLeftUpdateCom::MainLeftUpdateCom(DivUI* _mainLeftPanel)
	: mainLeftPanel{_mainLeftPanel}
{
}

void MainLeftUpdateCom::Execute()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	GameMgr* mgr = GameMgr::GetInst();
	CHero* curHero = mgr->GetFocusedHero();

	DivUI* heroPortrait = (DivUI*)FindUIByName(pseudoUI, L"heroPortrait");
	heroPortrait->InitImageModule(curHero->GetKey(), curHero->GetPath());

	DivUI* heroName = (DivUI*)FindUIByName(pseudoUI, L"heroName");
	heroName->InitTextModule(curHero->GetName(), 25);

	DivUI* heroJob = (DivUI*)FindUIByName(pseudoUI, L"heroJob");
	heroJob->InitTextModule(curHero->GetJobName(), 20);

	DivUI* skillContainer = (DivUI*)FindUIByName(pseudoUI, L"skillContainer");

	for (int i = 0; i < 4; i++) {
		DivUI* skillUI = (DivUI*)(skillContainer->GetChildUI()[i]);
		CSkill* heroSkill = curHero->GetCurSkills()[i];

		if (heroSkill->IsAlive()) {
			skillUI->InitImageModule(heroSkill->GetSkillName(), heroSkill->GetSkillPath());
		}
		else {
			skillUI->InitImageModule(heroSkill->GetSkillName() + L"_gray", heroSkill->GetGraySkillPath());
		}
	}

	int curHpVal = curHero->GetCurHp();

	DivUI* curHp = (DivUI*)FindUIByName(pseudoUI, L"curHp");
	curHp->InitTextModule(curHpVal, 20);

	int maxHpVal = curHero->GetHp();

	DivUI* maxHp = (DivUI*)FindUIByName(pseudoUI, L"maxHp");
	maxHp->InitTextModule(L" / " + to_wstring(curHero->GetHp()), 20);

	DivUI* curStress = (DivUI*)FindUIByName(pseudoUI, L"curStress");
	curStress->InitTextModule(curHero->GetCurStress(), 20);

	DivUI* hitRateVal = (DivUI*)FindUIByName(pseudoUI, L"hitRateVal");
	hitRateVal->InitTextModule(curHero->GetHitRate(), 20.f);

	DivUI* critRateVal = (DivUI*)FindUIByName(pseudoUI, L"critRateVal");
	critRateVal->InitTextModule(to_wstring(curHero->GetCriticalHitRate()) + L".0%", 20.f);

	wstring minDam = to_wstring(curHero->GetDamageLower());
	wstring maxDam = to_wstring(curHero->GetDamageUppder());
	wstring damageStr = minDam + L"-" + maxDam;

	DivUI* damageVal = (DivUI*)FindUIByName(pseudoUI, L"damageVal");
	damageVal->InitTextModule(damageStr, 20);

	DivUI* avoidVal = (DivUI*)FindUIByName(pseudoUI, L"avoidVal");
	avoidVal->InitTextModule(curHero->GetAvoidanceRate(), 20);

	DivUI* shieldVal = (DivUI*)FindUIByName(pseudoUI, L"shieldVal");
	shieldVal->InitTextModule(to_wstring(curHero->GetDefenseRate()) + L"%", 20);

	DivUI* speedVal = (DivUI*)FindUIByName(pseudoUI, L"speedVal");
	speedVal->InitTextModule(curHero->GetSpeed(), 20);

	DivUI* weaponPortrait = (DivUI*)FindUIByName(pseudoUI, L"weaponPortrait");
	weaponPortrait->InitImageModule(curHero->GetEquipKey(), curHero->GetEquipPath());

	DivUI* shieldPortrait = (DivUI*)FindUIByName(pseudoUI, L"shieldPortrait");
	shieldPortrait->InitImageModule(curHero->GetArmourKey(), curHero->GetArmourPath());
}
