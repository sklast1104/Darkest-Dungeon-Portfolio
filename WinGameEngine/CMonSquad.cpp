#include "stdafx.h"
#include "CMonSquad.h"
#include "GameMgr.h"
#include "DarkestMachine.h"
#include "CMonDiv.h"

CMonSquad::CMonSquad()
{
}

CMonSquad::~CMonSquad()
{
}

void CMonSquad::update()
{
	GameMgr::GetInst()->GetMachine()->update();

	DivUI::update();
}

void CMonSquad::PlayIdleCombatAnim()
{
	for (int i = 0; i < monDivs.size(); i++) {
		//monDivs[i]->
	}
}
