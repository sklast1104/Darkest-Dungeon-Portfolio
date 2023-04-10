#include "stdafx.h"
#include "CCutScene.h"
#include "GameMgr.h"

#include "DivUI.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "GameMgr.h"
#include "CHero.h"
#include "CDarkMonster.h"
#include "CHeroDiv.h"
#include "ViewMgr.h"
#include "Camera.h"
#include "CMonDiv.h"
#include "TimeMgr.h"
#include "CStMachine.h"
#include "CRestoreState.h"
#include "CSkill.h"


CCutScene::CCutScene()
	: CState(L"CCutScene")
	, elapsedTime{0.f}
{
}

CCutScene::~CCutScene()
{
}

void CCutScene::Enter()
{
	// 현재 포커싱된 영웅들과 몬스터Div들을 가져온다

	// 현재 포커싱된 스킬을 가져온다

	// 공격자와 스킬이 정해진다

	// 공격자와 피격자의 선택된 애니메이션을 호출하고 끝나면 웨잇 상태로 다시 복귀한다

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");

	GameMgr* mgr = GameMgr::GetInst();

	int heroIdx = mgr->GetFocusIndex();
	int skillIdx = mgr->GetSIndex();
	int monIdx = mgr->GetMonFocusIdx();

	if (isPlayerAttack) {
		
		CHero* chero = mgr->GetFocusedHero();
		CSkill* hSkill = chero->GetCurSkills()[skillIdx];

		if (!hSkill->GetMulti()) {
			ViewMgr::GetInst()->SetZoomRatio(1.3f);
			Vec2 curLookAt = Camera::GetInst()->GetLookAt();
			curLookAt += Vec2(300.f, 160.f);

			mgr->SetRLook(curLookAt);

			Camera::GetInst()->SetCurLookAt(curLookAt);
			Camera::GetInst()->update();

			heroSquad->DisableAllOverlay();
			heroSquad->EnableAllDivChildUI(false);

			monSquad->EnableAllDivChildUI(false);

			player = heroSquad->GetHeroDivByIdx(heroIdx - (4 - heroSquad->GetSquadNum()));
			// 렌더 y소팅
			heroSquad->MoveToBackRender(heroIdx);
			// 현재 스킬 애니메이션 재생
			player->PlayCurSkillByIdx(skillIdx);

			monsters.push_back(monSquad->GetMonDivByIdx(monIdx));

			//monster = monSquad->GetMonDivByIdx(monIdx);
			// 렌더 y소팅
			monSquad->MoveToBackRender(monIdx);
			// 피격 애니메이션 재생
			monsters[0]->PlayAttackedAnim();
			// 피 공격자는 피격 이펙트 재생

			// 공격자랑 피격자 위치를 강제로 렌더화면 중앙쪽으로 고정시켜야됨..
			Vec2 playerPos = player->GetPos();
			Vec2 monPos = monsters[0]->GetPos();

			int realIdx = monIdx;

			const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

			for (int i = 0; i < monIdx; i++) {
				if (nullptr != monSquad[i]) {
					if (monSquad[i]->IsDead()) {
						realIdx -= 1;
					}
				}
			}

			monsters[0]->SetPos(monsters[0]->GetPos() + Vec2(-150.f * realIdx, 0.f));

			//monPos->SetPos(Vec2()

			// 데미지 처리
			CHero* chero = mgr->GetFocusedHero();
			CDarkMonster* cMon = mgr->GetFocusedMonster();

			CSkill* hSkill = chero->GetCurSkills()[skillIdx];

			int heroDmg = chero->GetDamageLower();
			heroDmg = heroDmg + heroDmg * (hSkill->GetAttackRate() / 100.f);

			cMon->SetCurHp(cMon->GetCurHp() - heroDmg);

			if (cMon->GetCurHp() <= 0) {
				cMon->SetDead();
				GameMgr::GetInst()->CheckCanTurn();
			}
		}
		else {
			ViewMgr::GetInst()->SetZoomRatio(1.3f);
			Vec2 curLookAt = Camera::GetInst()->GetLookAt();
			curLookAt += Vec2(300.f, 160.f);
			mgr->SetRLook(curLookAt);
			Camera::GetInst()->SetCurLookAt(curLookAt);
			Camera::GetInst()->update();

			heroSquad->DisableAllOverlay();
			heroSquad->EnableAllDivChildUI(false);
			monSquad->EnableAllDivChildUI(false);
			player = heroSquad->GetHeroDivByIdx(heroIdx - (4 - heroSquad->GetSquadNum()));
			heroSquad->MoveToBackRender(heroIdx);
			player->PlayCurSkillByIdx(skillIdx);

			vector<int>& mulMonIdxes = mgr->GetMulMonIdx();

			// 여기서 범위로 처리해야함
			for (int i = 0; i < hSkill->GetSkillRange().size(); i++) {

				if (hSkill->GetSkillRange()[i]) {

					// 사이즈가 항상 같음이 보장 되어야됨

					if (i >= mulMonIdxes.size()) continue;

					int realIdx = mulMonIdxes[i];

					monsters.push_back(monSquad->GetMonDivByIdx(realIdx));
					monSquad->MoveToBackRender(i);
					
				}
			}

			for (int i = 0; i < monsters.size(); i++) {
				monsters[i]->PlayAttackedAnim();
			}
			
			for (int i = 0; i < monsters.size(); i++) {

				Vec2 monPos = monsters[i]->GetPos();
				int realIdx = monIdx;
				const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

				for (int i = 0; i < monIdx; i++) {
					if (nullptr != monSquad[i]) {
						if (monSquad[i]->IsDead()) {
							realIdx -= 1;
						}
					}
				}

				monsters[i]->SetPos(monsters[i]->GetPos() + Vec2(-150.f * realIdx, 0.f));
			}

			for (int i = 0; i < mulMonIdxes.size(); i++) {
				CHero* chero = mgr->GetFocusedHero();
				CDarkMonster* cMon = mgr->GetMonsterByIdx(mulMonIdxes[i]);

				CSkill* hSkill = chero->GetCurSkills()[skillIdx];

				int heroDmg = chero->GetDamageLower();
				heroDmg = heroDmg + heroDmg * (hSkill->GetAttackRate() / 100.f);

				cMon->SetCurHp(cMon->GetCurHp() - heroDmg);

				if (cMon->GetCurHp() <= 0) {
					cMon->SetDead();
					GameMgr::GetInst()->CheckCanTurn();
				}
			}
		}

		

	}
	else {
		// 카메라 효과
		ViewMgr::GetInst()->SetZoomRatio(1.3f);

		Vec2 curLookAt = Camera::GetInst()->GetLookAt();
		curLookAt += Vec2(300.f, 160.f);

		mgr->SetRLook(curLookAt);

		Camera::GetInst()->SetCurLookAt(curLookAt);

		Camera::GetInst()->update();

		// 오버레이 효과
		// 오버레이 뿐만이 아니라 UI도 전부다 꺼야함
		heroSquad->DisableAllOverlay();
		heroSquad->EnableAllDivChildUI(false);

		monSquad->DisableAllOverlay();
		monSquad->EnableAllDivChildUI(false);

		player = heroSquad->GetHeroDivByIdx(heroIdx - (4 - heroSquad->GetSquadNum()));
		player->PlayAttackedAnim();

		// 몬스터 스쿼드 y소팅 해야함
		heroSquad->MoveToBackRender(heroIdx);
		monSquad->MoveToBackRender(monIdx);
		monsters.push_back(monSquad->GetMonDivByIdx(monIdx));
		monsters[0]->PlayCurSkilByIdx(skillIdx);

		// 공격자랑 피격자 위치를 강제로 렌더화면 중앙쪽으로 고정시켜야됨..
		Vec2 playerPos = player->GetPos();
		Vec2 monPos = monsters[0]->GetPos();

		int realIdx = monIdx;

		const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

		for (int i = 0; i < monIdx; i++) {
			if (nullptr != monSquad[i]) {
				if (monSquad[i]->IsDead()) {
					realIdx -= 1;
				}
			}
		}

		monsters[0]->SetPos(monsters[0]->GetPos() + Vec2(-150.f * realIdx, 0.f));

		// 데미지 처리
		CHero* chero = mgr->GetFocusedHero();
		CDarkMonster* cMon = mgr->GetFocusedMonster();

		CSkill* hSkill = cMon->GetCurSkills()[skillIdx];

		int monDmg = cMon->GetDamageLower();
		monDmg = monDmg + monDmg * (hSkill->GetAttackRate() / 100.f);

		chero->SetCurHp(chero->GetCurHp() - monDmg);

		if (chero->GetCurHp() <= 0) {
			chero->SetDead();
			GameMgr::GetInst()->CheckCanTurn();
		}
	}

	monsters;
	moveBack = true;
}

void CCutScene::Update()
{
	// 여기서 플레이어 공격이면 공격자, 피격자 모두 오른쪽으로 이동
	// 아니면 왼쪽으로 이동시키자

	elapsedTime += fDT;

	if (elapsedTime <= 1.f) {

		Camera::GetInst()->EnableShake(true);

	}
	else {
		Camera::GetInst()->EnableShake(false);
	}

	if (elapsedTime <= 3.f) {

		if (isPlayerAttack) {

			// 상대좌표로 해야됨
			Vec2 playerPos = player->GetPos();

			float speed = 40.f;

			player->SetPos(Vec2(playerPos.x + (fDT * speed), playerPos.y));

			DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
			pseudoUI->SendToBack(L"CSquadDiv");

			// 플레이어 렌더를 맨 뒤로 보내야됨

			for (int i = 0; i < monsters.size(); i++) {
				Vec2 monPos = monsters[i]->GetPos();

				monsters[i]->SetPos(Vec2(monPos.x + (fDT * speed), monPos.y));
			}

			
		}
		else {
			Vec2 playerPos = player->GetPos();

			float speed = 40.f;

			player->SetPos(Vec2(playerPos.x + (fDT * -speed), playerPos.y));

			for (int i = 0; i < monsters.size(); i++) {
				Vec2 monPos = monsters[i]->GetPos();

				monsters[i]->SetPos(Vec2(monPos.x + (fDT * -speed), monPos.y));
			}
		}
	}
	else if (elapsedTime > 3.f && moveBack) {

		moveBack = false;

		ChangeState(GetStateMachine(), L"CRestoreState");
	}
}

void CCutScene::Exit()
{
	CRestoreState* state =  (CRestoreState *)GetStateMachine()->GetState(L"CRestoreState");
	state->SetPlayer(player);
	//state->SetMonster(monsters[0]);
	state->SetMonsters(monsters);

	elapsedTime = 0.f;

	// 여기서 몬스터 스쿼드랑 히어로 스쿼드 체력바 업데이트시키는거 해야함

	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->UpdateHpBar();
	}

	
	player->UpdateHpBar();

	// 만약 죽었으면 여기서 렌더 꺼주자 그리고 죽은 유닛 처리는 wait한테 맡겨보자
	GameMgr* mgr = GameMgr::GetInst();

	CHero* chero = mgr->GetFocusedHero();
	CDarkMonster* cMon = mgr->GetFocusedMonster();
	
	// 여기서 죽는 이펙트 재생도 가능함
	if (chero->IsDead()) {
		player->SetCanRend(false);
		player->CanTarget(false);
	}

	vector<int>& mulMonIdxes = mgr->GetMulMonIdx();

	for (int i = 0; i < mulMonIdxes.size(); i++) {
		CDarkMonster* cMon = mgr->GetMonsterByIdx(mulMonIdxes[i]);

		if (cMon->IsDead()) {

			for (int j = 0; j < monsters.size(); j++) {
				
				if (monsters[j]->GetId() == mulMonIdxes[i]) {
					monsters[j]->SetCanRend(false);
					monsters[j]->CanTarget(false);
				}
			}

			

		}
	}

	//if (cMon->IsDead()) {

	//	for (int i = 0; i < monsters.size(); i++) {
	//		monsters[i]->SetCanRend(false);
	//		monsters[i]->CanTarget(false);
	//	}

	//	int monIdx = mgr->GetMonFocusIdx();
	//}

	monsters.clear();
}


