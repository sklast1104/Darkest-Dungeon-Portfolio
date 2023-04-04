#include "stdafx.h"
#include "CSquadDiv.h"
#include "CHeroDiv.h"
#include "GameMgr.h"
#include "DarkestMachine.h"

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
}
