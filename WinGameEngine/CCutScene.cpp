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
		attacker = mgr->GetSquad()[heroIdx];
		victim = mgr->GetMonSquad()[monIdx];
	}
	else {
		attacker = mgr->GetMonSquad()[monIdx];
		victim = mgr->GetSquad()[heroIdx];
	}

	if (isPlayerAttack) {
		
		// 카메라 효과
		ViewMgr::GetInst()->SetZoomRatio(1.3f);
		// 960, 540 기준으로 300, 160 이동한 좌표므로 curView 기준으로 잡아줄 필요 있다
		Vec2 curLookAt = Camera::GetInst()->GetLookAt();
		curLookAt += Vec2(300.f, 160.f);

		mgr->SetRLook(curLookAt);

		Camera::GetInst()->SetCurLookAt(curLookAt);
		//Camera::GetInst()->SetCurLookAt(Vec2(1260.f, 700.f));
		Camera::GetInst()->update();

		// 오버레이 효과
		// 오버레이 뿐만이 아니라 UI도 전부다 꺼야함
		heroSquad->DisableAllOverlay();
		heroSquad->EnableAllDivChildUI(false);

		monSquad->EnableAllDivChildUI(false);

		player = heroSquad->GetHeroDivByIdx(heroIdx - (4 - heroSquad->GetSquadNum()));
		// 렌더 y소팅
		heroSquad->MoveToBackRender(heroIdx);
		// 현재 스킬 애니메이션 재생
		player->PlayCurSkillByIdx(skillIdx);

		monster = monSquad->GetMonDivByIdx(monIdx );
		// 렌더 y소팅
		monSquad->MoveToBackRender(monIdx);
		// 피격 애니메이션 재생
		monster->PlayAttackedAnim();
		// 피 공격자는 피격 이펙트 재생

		// 공격자랑 피격자 위치를 강제로 렌더화면 중앙쪽으로 고정시켜야됨..
		Vec2 playerPos = player->GetPos();
		Vec2 monPos = monster->GetPos();

		int realIdx = monIdx;

		const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

		for (int i = 0; i < monIdx; i++) {
			if (nullptr != monSquad[i]) {
				if (monSquad[i]->IsDead()) {
					realIdx -= 1;
				}
			}
		}

		monster->SetPos(monster->GetPos() + Vec2(-150.f * realIdx, 0.f));
		
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
		monster = monSquad->GetMonDivByIdx(monIdx );
		monster->PlayCurSkilByIdx(skillIdx);

		// 공격자랑 피격자 위치를 강제로 렌더화면 중앙쪽으로 고정시켜야됨..
		Vec2 playerPos = player->GetPos();
		Vec2 monPos = monster->GetPos();

		int realIdx = monIdx;

		const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

		for (int i = 0; i < monIdx; i++) {
			if (nullptr != monSquad[i]) {
				if (monSquad[i]->IsDead()) {
					realIdx -= 1;
				}
			}
		}

		monster->SetPos(monster->GetPos() + Vec2(-150.f * realIdx, 0.f));

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

			Vec2 monPos = monster->GetPos();

			monster->SetPos(Vec2(monPos.x + (fDT * speed), monPos.y));
		}
		else {
			Vec2 playerPos = player->GetPos();

			float speed = 40.f;

			player->SetPos(Vec2(playerPos.x + (fDT * -speed), playerPos.y));

			Vec2 monPos = monster->GetPos();

			monster->SetPos(Vec2(monPos.x + (fDT * -speed), monPos.y));
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
	state->SetMonster(monster);

	elapsedTime = 0.f;

	// 여기서 몬스터 스쿼드랑 히어로 스쿼드 체력바 업데이트시키는거 해야함
	monster->UpdateHpBar();
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

	if (cMon->IsDead()) {
		monster->SetCanRend(false);
		monster->CanTarget(false);

		int monIdx = mgr->GetMonFocusIdx();

		//monSquad->EraseDiv(monIdx);
	}

	//ViewMgr::GetInst()->animateZoom(1.0f, 0.3f);
	//Camera::GetInst()->SetLookAt(Vec2(960.f, 540.f));
}


