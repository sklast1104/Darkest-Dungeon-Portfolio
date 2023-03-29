#include "stdafx.h"
#include "CHighwayMan.h"
#include "CSkill.h"

CHighwayMan::CHighwayMan()
{
	key = L"Highwayman Portrait";
	name = L"디스마스";
	job_name = L"노상강도";

	curHp = 23;
	hp = 23;

	curStress = 1;
	stress = 99;

	// 명중 보정
	hitRate = 0;
	// 회피율
	avoidanceRate = 10;
	// 치명율
	criticalHitRate = 5;
	// 데미지 하한
	damageLower = 5;
	// 데미지 상한
	damageUpper = 10;
	// 속도
	speed = 5;

	InitSkill();
}

CHighwayMan::~CHighwayMan()
{
}

void CHighwayMan::InitSkill()
{
}