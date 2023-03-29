#include "stdafx.h"
#include "CHero.h"

CHero::CHero()
	: name{ L"" }, key{ L"" }, path{ L"" }
	, hp{ 0 }, hitRate{ 0 }, avoidanceRate{ 0 }, criticalHitRate{ 0 }
	, defenseRate{ 0 }, damageLower{ 0 }, damageUpper{ 0 }
	, speed{ 0 }, level{ 1 }
{
}

CHero::~CHero()
{
	for (int i = 0; i < 7; i++) {
		Safe_Delete<CSkill*>(skillList[i]);
	}

	for (int i = 0; i < 4; i++) {
		Safe_Delete<CSkill*>(curSkillList[i]);
	}
}
