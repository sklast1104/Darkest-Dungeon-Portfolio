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
			// 메인 레프트 패널도 갱신 해줘야함
			// 이 함수를 호출하는 순간 포커싱은 이미 계산되있다고 가정
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
