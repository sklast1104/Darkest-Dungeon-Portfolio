#include "stdafx.h"
#include "SkillOnclick.h"

#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "GameMgr.h"
#include "CHero.h"
#include "CSkill.h"
#include "CDarkMonster.h"
#include "CMonSquad.h"

SkillOnclick::SkillOnclick(DivUI* _skillUI)
	: skillUI{ _skillUI }
{
}

void SkillOnclick::Execute()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	vector<UI*> skillSelectedUIs = FindUIsByName(pseudoUI, L"skillSelected");

	int skillSeq = skillUI->GetId();

	for (int i = 0; i < 4; i++) {

		if (i == skillSeq) {
			((DivUI*)skillSelectedUIs[i])->SetCanRend(true);
		}
		else {
			((DivUI*)skillSelectedUIs[i])->SetCanRend(false);
		}

	}

	// 범위에 따라 적 오버레이 띄워주는거도 해야함

	GameMgr* mgr = GameMgr::GetInst();

	CHero* curFocusedHero = mgr->GetFocusedHero();

	CSkill* curSkill = curFocusedHero->GetCurSkills()[skillSeq];

	curSkill->GetSkillRange();

	vector<UI*> focusedMonOverlays = FindUIsByName(pseudoUI, L"focusedOverlay_monster");

	vector<UI*> nfocusedMonOverlays;

	// monDivs 정렬이 필요할 수도 있음
	const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

	for (int i = 0; i < 4; i++) {

		if (nullptr != monSquad[i] && !monSquad[i]->IsDead()) {
			nfocusedMonOverlays.push_back(focusedMonOverlays[i]);
		}
	}
	
	for (int i = 0; i < 4; i++) {
		((DivUI*)focusedMonOverlays[i])->SetCanRend(false);
	}

	for (int i = 0; i < curSkill->GetSkillRange().size(); i++) {

		if (curSkill->GetSkillRange()[i]) {
			if (i < nfocusedMonOverlays.size()) {
				((DivUI*)nfocusedMonOverlays[i])->SetCanRend(true);
			}	
		}
	}

	// 게임 매니저에 현재 세팅중인 스킬 인덱스 알림 
	mgr->SetSIndex(skillSeq);
	
	// 스킬 범위에 따라 몬스터한테 클릭 이벤트 등록을 해야함
	// 일단 이벤트 그냥 등록해보고 진행해보자 아니면 그냥 캔타겟을 false해줘도 될거같기도하고..
}
