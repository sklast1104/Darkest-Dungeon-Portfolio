#include "stdafx.h"
#include "CHighwayMan.h"
#include "CSkill.h"

CHighwayMan::CHighwayMan()
{
	key = L"Highwayman Portrait";
	name = L"�𽺸���";
	job_name = L"��󰭵�";

	curHp = 23;
	hp = 23;

	curStress = 1;
	stress = 99;

	// ���� ����
	hitRate = 0;
	// ȸ����
	avoidanceRate = 10;
	// ġ����
	criticalHitRate = 5;
	// ������ ����
	damageLower = 5;
	// ������ ����
	damageUpper = 10;
	// �ӵ�
	speed = 5;

	InitSkill();
}

CHighwayMan::~CHighwayMan()
{
}

void CHighwayMan::InitSkill()
{
}