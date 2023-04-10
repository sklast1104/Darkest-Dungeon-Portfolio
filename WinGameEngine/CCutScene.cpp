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
	// ���� ��Ŀ�̵� ������� ����Div���� �����´�

	// ���� ��Ŀ�̵� ��ų�� �����´�

	// �����ڿ� ��ų�� ��������

	// �����ڿ� �ǰ����� ���õ� �ִϸ��̼��� ȣ���ϰ� ������ ���� ���·� �ٽ� �����Ѵ�

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
		
		// ī�޶� ȿ��
		ViewMgr::GetInst()->SetZoomRatio(1.3f);
		// 960, 540 �������� 300, 160 �̵��� ��ǥ�Ƿ� curView �������� ����� �ʿ� �ִ�
		Vec2 curLookAt = Camera::GetInst()->GetLookAt();
		curLookAt += Vec2(300.f, 160.f);

		mgr->SetRLook(curLookAt);

		Camera::GetInst()->SetCurLookAt(curLookAt);
		//Camera::GetInst()->SetCurLookAt(Vec2(1260.f, 700.f));
		Camera::GetInst()->update();

		// �������� ȿ��
		// �������� �Ӹ��� �ƴ϶� UI�� ���δ� ������
		heroSquad->DisableAllOverlay();
		heroSquad->EnableAllDivChildUI(false);

		monSquad->EnableAllDivChildUI(false);

		player = heroSquad->GetHeroDivByIdx(heroIdx - (4 - heroSquad->GetSquadNum()));
		// ���� y����
		heroSquad->MoveToBackRender(heroIdx);
		// ���� ��ų �ִϸ��̼� ���
		player->PlayCurSkillByIdx(skillIdx);

		monster = monSquad->GetMonDivByIdx(monIdx );
		// ���� y����
		monSquad->MoveToBackRender(monIdx);
		// �ǰ� �ִϸ��̼� ���
		monster->PlayAttackedAnim();
		// �� �����ڴ� �ǰ� ����Ʈ ���

		// �����ڶ� �ǰ��� ��ġ�� ������ ����ȭ�� �߾������� �������Ѿߵ�..
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

		// ������ ó��
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
		// ī�޶� ȿ��
		ViewMgr::GetInst()->SetZoomRatio(1.3f);

		Vec2 curLookAt = Camera::GetInst()->GetLookAt();
		curLookAt += Vec2(300.f, 160.f);

		mgr->SetRLook(curLookAt);

		Camera::GetInst()->SetCurLookAt(curLookAt);

		Camera::GetInst()->update();

		// �������� ȿ��
		// �������� �Ӹ��� �ƴ϶� UI�� ���δ� ������
		heroSquad->DisableAllOverlay();
		heroSquad->EnableAllDivChildUI(false);

		monSquad->DisableAllOverlay();
		monSquad->EnableAllDivChildUI(false);

		player = heroSquad->GetHeroDivByIdx(heroIdx - (4 - heroSquad->GetSquadNum()));
		player->PlayAttackedAnim();

		// ���� ������ y���� �ؾ���
		heroSquad->MoveToBackRender(heroIdx);
		monSquad->MoveToBackRender(monIdx);
		monster = monSquad->GetMonDivByIdx(monIdx );
		monster->PlayCurSkilByIdx(skillIdx);

		// �����ڶ� �ǰ��� ��ġ�� ������ ����ȭ�� �߾������� �������Ѿߵ�..
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

		// ������ ó��
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
	// ���⼭ �÷��̾� �����̸� ������, �ǰ��� ��� ���������� �̵�
	// �ƴϸ� �������� �̵���Ű��

	elapsedTime += fDT;

	if (elapsedTime <= 1.f) {

		Camera::GetInst()->EnableShake(true);

	}
	else {
		Camera::GetInst()->EnableShake(false);
	}

	if (elapsedTime <= 3.f) {

		if (isPlayerAttack) {

			// �����ǥ�� �ؾߵ�
			Vec2 playerPos = player->GetPos();

			float speed = 40.f;

			player->SetPos(Vec2(playerPos.x + (fDT * speed), playerPos.y));

			DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
			pseudoUI->SendToBack(L"CSquadDiv");

			// �÷��̾� ������ �� �ڷ� �����ߵ�

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

	// ���⼭ ���� ������� ����� ������ ü�¹� ������Ʈ��Ű�°� �ؾ���
	monster->UpdateHpBar();
	player->UpdateHpBar();

	// ���� �׾����� ���⼭ ���� ������ �׸��� ���� ���� ó���� wait���� �ðܺ���
	GameMgr* mgr = GameMgr::GetInst();

	CHero* chero = mgr->GetFocusedHero();
	CDarkMonster* cMon = mgr->GetFocusedMonster();
	
	// ���⼭ �״� ����Ʈ ����� ������
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


