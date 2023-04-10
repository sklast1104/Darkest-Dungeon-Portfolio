#include "stdafx.h"
#include "CEnemyTurn.h"

#include "DivUI.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "GameMgr.h"

#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "CDarkMonster.h"
#include "CSkill.h"

#include "TimeMgr.h"
#include "CCutScene.h"
#include "DarkestMachine.h"

CEnemyTurn::CEnemyTurn()
	: CState(L"CEnemyTurn")
	, elapsedTime{0.f}, canCg{true}
{
}

CEnemyTurn::~CEnemyTurn()
{
}

bool isAvailSkil(CSkill* skil, int _idx) {

	array<bool, 4>& pos = skil->GetSkillPos();

	if (pos[_idx]) {
		return true;
	}

	return false;
}

bool CanAttack(CSkill* skil, int _idx) {

	return skil->GetSkillRange()[_idx];
}

void CEnemyTurn::Enter()
{
	GameMgr* mgr = GameMgr::GetInst();

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	curMIdx = GameMgr::GetInst()->GetMonFocusIdx();
	curHIdx = GameMgr::GetInst()->GetFocusIndex();

	// ���� ���� ���ʹ� �������� ���ְ� 
	monSquad->EnableOverlay(curMIdx);

	// ���� ����� ĳ���ʹ� �ǰ� �������� ����ߵ�
	CDarkMonster* dMon = mgr->GetFocusedMonster();
	const array<CSkill*, 4> mSkils = dMon->GetCurSkills();

	CSkill* curSkil = nullptr;
	int heroIdx;
	int sIdx;

	for (int i = 0; i < 4; i++) {

		CSkill* skil = mSkils[i];

		if (nullptr != skil) {
			if (isAvailSkil(skil, curMIdx)) {
				for (int j = 3; j >= 0; j--) {
					if (mgr->isSlotEmpty(j) == false) {
						if (CanAttack(skil, j)) {
							curSkil = skil;
							heroIdx = j;
							sIdx = i;
							break;
						}
					}
				}
			}
		}
	}

	// ��� ������ ��ų�� �ǰݴ���� ������ ã�����Ƿ� ���ӸŴ������� �ش� ������ ��Ŀ�����ְ�
	// �̋� �ε����� ���ӸŴ����ε���(�����ε�����)
	mgr->SetFocusIndex(heroIdx);
	// ��ų �ε����� ����
	mgr->SetSIndex(sIdx);
	heroSquad->EnableAttackedOverlay(heroIdx);

	// ���� ��ġ���� ��� ������ ��ų �������� ��ų �ε����� ��������

	// �ð��� ��ٸ������� �˾Ƽ� �Ѱܾߵ�
	canCg = true;
}

void CEnemyTurn::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 2.f && canCg) {

		canCg = false;

		// �ƾ����� �����̵� ��ų�� �׻� �Է°��� �ʱ�ȭ ����
		GameMgr* mgr = GameMgr::GetInst();
		CCutScene* cutState = (CCutScene*)(mgr->GetMachine()->GetState(L"CCutScene"));
		cutState->IsPlayerAttack(false);

		ChangeState(GetStateMachine(), L"CCutScene");
	}

}

void CEnemyTurn::Exit()
{
	elapsedTime = 0.f;
}


