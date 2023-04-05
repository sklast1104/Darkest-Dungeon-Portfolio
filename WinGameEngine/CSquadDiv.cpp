#include "stdafx.h"
#include "CSquadDiv.h"
#include "CHeroDiv.h"
#include "GameMgr.h"
#include "DarkestMachine.h"
#include "SceneMgr.h"
#include "Scene.h"

CSquadDiv::CSquadDiv()
	: speed{300.f}
{
}

CSquadDiv::~CSquadDiv()
{
}

void CSquadDiv::update()
{
	GameMgr::GetInst()->GetMachine()->update();

	DivUI::update();
}

void CSquadDiv::PlayHeroIdleAnim()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->PlayHeroIdleAnim();
	}
}

void CSquadDiv::PlayHeroWalkAnim()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->PlayHeroWalkAnim();
	}
}

void CSquadDiv::PlayHeroCombatAnim()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->PlayHeroCombatAnim();
	}
}

void CSquadDiv::EnableOverlay(int _realIndex)
{
	for (int i = 0; i < heros.size(); i++) {
		if (heros[i]->GetId() == _realIndex) {
			heros[i]->EnableOverlay(true);
		}
		else {
			heros[i]->EnableOverlay(false);
		}
	}
}

void CSquadDiv::EnableFocus(int _realIndex)
{
	for (int i = 0; i < heros.size(); i++) {

		if (heros[i]->GetId() == _realIndex) {
			heros[i]->CanTarget(true);
			heros[i]->EnableOverlay(true);
			// ���� ����Ʈ �гε� ���� �������
			// �� �Լ��� ȣ���ϴ� ���� ��Ŀ���� �̹� �����ִٰ� ����
			DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
			DivUI* mainLeftPanel = (DivUI*)FindUIByName(pseudoUI, L"mainLeftPanel");

			mainLeftPanel->updateValue();
		}
		else {
			heros[i]->CanTarget(false);
			heros[i]->EnableOverlay(false);
		}

	}
}
