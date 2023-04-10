#include "stdafx.h"
#include "CBoneSoldier.h"

#include "CSkill.h"

CBoneSoldier::CBoneSoldier()
{
	name = L"�ذ� ����";
	resPath = L"";
	monsterType = L"�Ұ�";

	curHp = 10;
	maxHp = 10;

	avoidRate = 0;
	shieldRate = 15;
	speed = 2;

	faintResist = 25;
	toxinResist = 10;
	bleedResist = 200;
	weakResist = 15;
	moveResist = 20;

	damageLower = 3;
	damageUpper = 8;

	CSkill* slash = new CSkill;
	slash->SetSkillName(L"���� ������");
	slash->SetSkillPath(L"");

	slash->GetSkillRange()[0] = true;
	slash->GetSkillRange()[1] = true;
	slash->GetSkillRange()[2] = true;
	slash->GetSkillRange()[3] = true;

	slash->GetSkillPos()[0] = true;
	slash->GetSkillPos()[1] = true;
	slash->GetSkillPos()[2] = true;
	slash->GetSkillPos()[3] = true;

	slash->SetHitRate(82);
	slash->SetCritRate(6);
	slash->SetAttackRate(0);
	slash->SetSkillAnimName(L"���� ������");
	slash->SetAnimPath(L"resource\\animations\\monster\\Bone Soldier\\Sprite\\attack\\pack.atlas");

	curSkillArray[0] = slash;

	attackedAnimName = L"�ذ� ���� �ǰ�";
	attackedAnimPath = L"resource\\animations\\monster\\Bone Soldier\\Sprite\\defend\\pack.atlas";
}

CBoneSoldier::~CBoneSoldier()
{
}
