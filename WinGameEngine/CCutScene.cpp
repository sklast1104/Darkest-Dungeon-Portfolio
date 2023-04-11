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
#include "HEffectDiv.h"
#include "Sound.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "DamageDiv.h"

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
			// ���� y����
			heroSquad->MoveToBackRender(heroIdx);
			// ���� ��ų �ִϸ��̼� ���
			player->PlayCurSkillByIdx(skillIdx);
			// ��ų ���� ���

			wstring soundName = hSkill->GetSoundName();
			wstring soundPath = hSkill->GetSoundPath();

			/*ResMgr::GetInst()->LoadSound(soundName, soundPath);
			Sound* denuSound = ResMgr::GetInst()->FindSound(soundName);
			denuSound->Play(false);*/

			monsters.push_back(monSquad->GetMonDivByIdx(monIdx));

			//monster = monSquad->GetMonDivByIdx(monIdx);
			// ���� y����
			monSquad->MoveToBackRender(monIdx);
			// �ǰ� �ִϸ��̼� ���
			monsters[0]->PlayAttackedAnim(hSkill);
			// �ǰ� ���� ���
			monsters[0]->PlayMonAttackedSoud();
			// �� �����ڴ� �ǰ� ����Ʈ ���

			// ȭ�� �� ������ ����Ʈ ���
			DivUI* bloodSplatLeftFx = (DivUI*)FindUIByName(pseudoUI, L"bloodSplatLeftFx");
			bloodSplatLeftFx->SetCanRend(true);
			bloodSplatLeftFx->GetAnimator()->GetCurAnimation()->SetAllFrameDuration(0.14f);
			bloodSplatLeftFx->GetAnimator()->GetCurAnimation()->SetFrame(0);

			DivUI* bloodSplatRightFx = (DivUI*)FindUIByName(pseudoUI, L"bloodSplatRightFx");
			bloodSplatRightFx->SetCanRend(true);
			bloodSplatRightFx->GetAnimator()->GetCurAnimation()->SetAllFrameDuration(0.14f);
			bloodSplatRightFx->GetAnimator()->GetCurAnimation()->SetFrame(0);

			// �����ڶ� �ǰ��� ��ġ�� ������ ����ȭ�� �߾������� �������Ѿߵ�..
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

			// ������ ó��
			CHero* chero = mgr->GetFocusedHero();
			CDarkMonster* cMon = mgr->GetFocusedMonster();

			CSkill* hSkill = chero->GetCurSkills()[skillIdx];

			int heroDmg = chero->GetDamageLower();
			heroDmg = heroDmg + heroDmg * (hSkill->GetAttackRate() / 100.f);

			monDmgUIs[0]->InitTextModule(heroDmg, 55);
			monDmgUIs[0]->StartMove();

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
			// ��ų ���� ���

			wstring soundName = hSkill->GetSoundName();
			wstring soundPath = hSkill->GetSoundPath();

			/*ResMgr::GetInst()->LoadSound(soundName, soundPath);
			Sound* skilSound = ResMgr::GetInst()->FindSound(soundName);
			skilSound->Play(false);*/

			// ȭ�� �� ������ ����Ʈ ���
			DivUI* bloodSplatLeftFx = (DivUI*)FindUIByName(pseudoUI, L"bloodSplatLeftFx");
			bloodSplatLeftFx->SetCanRend(true);
			bloodSplatLeftFx->GetAnimator()->GetCurAnimation()->SetAllFrameDuration(0.14f);
			bloodSplatLeftFx->GetAnimator()->GetCurAnimation()->SetFrame(0);

			DivUI* bloodSplatRightFx = (DivUI*)FindUIByName(pseudoUI, L"bloodSplatRightFx");
			bloodSplatRightFx->SetCanRend(true);
			bloodSplatRightFx->GetAnimator()->GetCurAnimation()->SetAllFrameDuration(0.14f);
			bloodSplatRightFx->GetAnimator()->GetCurAnimation()->SetFrame(0);

			vector<int>& mulMonIdxes = mgr->GetMulMonIdx();

			// ���⼭ ������ ó���ؾ���
			for (int i = 0; i < hSkill->GetSkillRange().size(); i++) {

				if (hSkill->GetSkillRange()[i]) {

					// ����� �׻� ������ ���� �Ǿ�ߵ�

					if (i >= mulMonIdxes.size()) continue;

					int realIdx = mulMonIdxes[i];

					monsters.push_back(monSquad->GetMonDivByIdx(realIdx));
					monSquad->MoveToBackRender(i);
					
				}
			}

			for (int i = 0; i < monsters.size(); i++) {
				monsters[i]->PlayAttackedAnim(hSkill);
				monsters[i]->PlayMonAttackedSoud();
				// ���⼭ ���� ���
				
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

				monDmgUIs[i]->InitTextModule(heroDmg, 55);
				monDmgUIs[i]->StartMove();

				cMon->SetCurHp(cMon->GetCurHp() - heroDmg);

				if (cMon->GetCurHp() <= 0) {
					cMon->SetDead();
					GameMgr::GetInst()->CheckCanTurn();
				}
			}

			//monDmgUIs.clear();
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

		DivUI* bloodSplatLeftFx = (DivUI*)FindUIByName(pseudoUI, L"bloodSplatLeftFx");
		bloodSplatLeftFx->SetCanRend(true);
		bloodSplatLeftFx->GetAnimator()->GetCurAnimation()->SetAllFrameDuration(0.14f);
		bloodSplatLeftFx->GetAnimator()->GetCurAnimation()->SetFrame(0);

		DivUI* bloodSplatRightFx = (DivUI*)FindUIByName(pseudoUI, L"bloodSplatRightFx");
		bloodSplatRightFx->SetCanRend(true);
		bloodSplatRightFx->GetAnimator()->GetCurAnimation()->SetAllFrameDuration(0.14f);
		bloodSplatRightFx->GetAnimator()->GetCurAnimation()->SetFrame(0);

		// ���� ������ y���� �ؾ���
		heroSquad->MoveToBackRender(heroIdx);
		monSquad->MoveToBackRender(monIdx);
		monsters.push_back(monSquad->GetMonDivByIdx(monIdx));
		monsters[0]->PlayCurSkilByIdx(skillIdx);

		// �����ڶ� �ǰ��� ��ġ�� ������ ����ȭ�� �߾������� �������Ѿߵ�..
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

		// ������ ó��
		CHero* chero = mgr->GetFocusedHero();
		CDarkMonster* cMon = mgr->GetFocusedMonster();

		CSkill* hSkill = cMon->GetCurSkills()[skillIdx];

		int monDmg = cMon->GetDamageLower();
		monDmg = monDmg + monDmg * (hSkill->GetAttackRate() / 100.f);

		// ������ �ִϸ��̼�
		heroDmgUI->InitTextModule(monDmg, 55);
		heroDmgUI->StartMove();

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
			//player->GetEffect()->SetPos(Vec2(playerPos.x + (fDT * speed), playerPos.y));

			DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
			pseudoUI->SendToBack(L"CSquadDiv");

			// �÷��̾� ������ �� �ڷ� �����ߵ�

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

	// ���⼭ ���� ������� ����� ������ ü�¹� ������Ʈ��Ű�°� �ؾ���

	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->UpdateHpBar();
	}

	
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

	monsters.clear();

	cout << player->GetEffect()->GetCanRend();
}


