#include "stdafx.h"
#include "SkillContainerUpdate.h"
#include "GameMgr.h"
#include "CHero.h"
#include "CSkill.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"

SkillContainerUpdate::SkillContainerUpdate(DivUI* _skillContainer)
	: skillContainer{_skillContainer}
{
}

SkillContainerUpdate::~SkillContainerUpdate()
{
}

// �׳� ���⼭ ��Ŀ�̵� ����ζ� ��ġ�� ���� ��ų ��� ���� ��� ���� �ع�����
void SkillContainerUpdate::Execute()
{
	GameMgr* mgr = GameMgr::GetInst();

	CHero* hero = mgr->GetFocusedHero();
	int curFocusIdx = mgr->GetFocusIndex();

	const array<CSkill*, 4> skillArr = hero->GetCurSkills();

	//DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	//DivUI* skillContainer = (DivUI*)FindUIByName(pseudoUI, L"skillContainer");

	vector<UI*> skillUIs = skillContainer->GetChildUI();

	for (int i = 0; i < 4; i++) {
		skillArr[i]->SetSkillAlive(false);
	}

	for (int i = 0; i < 4; i++) {

		CSkill* heroSkill = skillArr[i];

		// ��ų ���� �ȿ� ���� ĳ���� ��ġ�� ������
		if (heroSkill->GetSkillPos()[curFocusIdx]) {
			heroSkill->SetSkillAlive(true);
		}

		if (heroSkill->IsAlive()) {
			DivUI* skillUI = (DivUI*)skillUIs[i];
			skillUI->InitImageModule(heroSkill->GetSkillName(), heroSkill->GetSkillPath());
		}
		else {
			DivUI* skillUI = (DivUI*)skillUIs[i];
			skillUI->InitImageModule(heroSkill->GetSkillName() + L"_gray", heroSkill->GetGraySkillPath());
		}
	}
}
