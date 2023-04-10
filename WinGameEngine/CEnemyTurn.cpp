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

	// 현재 턴인 몬스터는 오버레이 켜주고 
	monSquad->EnableOverlay(curMIdx);

	// 공격 대상인 캐릭터는 피격 오버레이 켜줘야됨
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

	// 사용 가능한 스킬과 피격대상인 영웅을 찾았으므로 게임매니저에서 해당 영웅을 포커싱해주고
	// 이떄 인덱스는 게임매니저인덱스(실제인덱스임)
	mgr->SetFocusIndex(heroIdx);
	// 스킬 인덱스도 세팅
	mgr->SetSIndex(sIdx);
	heroSquad->EnableAttackedOverlay(heroIdx);

	// 현재 위치에서 사용 가능한 스킬 바탕으로 스킬 인덱스를 지정해줌

	// 시간을 기다린다음에 알아서 넘겨야됨
	canCg = true;
}

void CEnemyTurn::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 2.f && canCg) {

		canCg = false;

		// 컷씬으로 상태이동 시킬떄 항상 입력값을 초기화 하자
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


