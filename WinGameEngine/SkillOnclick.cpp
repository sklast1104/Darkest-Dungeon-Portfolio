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

	// ������ ���� �� �������� ����ִ°ŵ� �ؾ���

	GameMgr* mgr = GameMgr::GetInst();

	CHero* curFocusedHero = mgr->GetFocusedHero();

	CSkill* curSkill = curFocusedHero->GetCurSkills()[skillSeq];

	curSkill->GetSkillRange();

	vector<UI*> focusedMonOverlays = FindUIsByName(pseudoUI, L"focusedOverlay_monster");

	vector<UI*> nfocusedMonOverlays;

	// monDivs ������ �ʿ��� ���� ����
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

	// ���� �Ŵ����� ���� �������� ��ų �ε��� �˸� 
	mgr->SetSIndex(skillSeq);
	
	// ��ų ������ ���� �������� Ŭ�� �̺�Ʈ ����� �ؾ���
	// �ϴ� �̺�Ʈ �׳� ����غ��� �����غ��� �ƴϸ� �׳� ĵŸ���� false���൵ �ɰŰ��⵵�ϰ�..
}
