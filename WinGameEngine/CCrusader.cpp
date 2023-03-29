#include "stdafx.h"
#include "CCrusader.h"
#include "CSkill.h"

CCrusader::CCrusader()
{
	key = L"Crusader Portrait";
	name = L"레이널드";
	job_name = L"성전사";

	curHp = 33;
	hp = 33;

	curStress = 1;
	stress = 99;

	// 명중 보정
	hitRate = 0;
	// 회피율
	avoidanceRate = 5;
	// 치명율
	criticalHitRate = 3;
	// 데미지 하한
	damageLower = 6;
	// 데미지 상한
	damageUpper = 12;
	// 속도
	speed = 1;

	InitSkill();
}

CCrusader::~CCrusader()
{
}

void CCrusader::InitSkill()
{
	// 강타
	CSkill* powerAttack = new CSkill;
	powerAttack->SetSkillName(L"강타 1");
	powerAttack->SetSkillPath(L"");
	powerAttack->GetSkillPos()[2] = true;
	powerAttack->GetSkillPos()[3] = true;

	powerAttack->GetSkillRange()[0] = true;
	powerAttack->GetSkillRange()[1] = true;

	powerAttack->SetHitRate(85);
	powerAttack->SetAttackRate(15);

	skillArray[0] = powerAttack;

	// 광신적 고발
	CSkill* denunciation = new CSkill;
	denunciation->SetSkillName(L"광신적 고발 1");
	denunciation->SetSkillPath(L"");
	denunciation->GetSkillPos()[2] = true;
	denunciation->GetSkillPos()[3] = true;

	denunciation->SetMultiAttack(true);
	denunciation->GetSkillRange()[0] = true;
	denunciation->GetSkillRange()[1] = true;

	denunciation->SetHitRate(85);
	denunciation->SetAttackRate(-40);
	denunciation->SetCritRate(-4);

	skillArray[1] = denunciation;

	// 기절의 일격
	CSkill* stunAttack = new CSkill;
	stunAttack->SetSkillName(L"기절의 일격 1");
	stunAttack->SetSkillPath(L"");
	stunAttack->GetSkillPos()[2] = true;
	stunAttack->GetSkillPos()[3] = true;

	stunAttack->GetSkillRange()[0] = true;
	stunAttack->GetSkillRange()[1] = true;

	stunAttack->SetHitRate(90);
	stunAttack->SetAttackRate(-50);

	skillArray[2] = stunAttack;

	// 신앙의 방패
	CSkill* shield = new CSkill;
	shield->SetSkillName(L"신앙의 방패 1");
	shield->SetSkillPath(L"");
	shield->GetSkillPos()[2] = true;
	shield->GetSkillPos()[3] = true;

	skillArray[3] = shield;

	// 전투 치유
	CSkill* battleHeal = new CSkill;
	battleHeal->SetSkillName(L"전투 치유 1");
	battleHeal->SetSkillPath(L"");
	battleHeal->GetSkillPos()[0] = true;
	battleHeal->GetSkillPos()[1] = true;
	battleHeal->GetSkillPos()[2] = true;
	battleHeal->GetSkillPos()[3] = true;

	skillArray[4] = battleHeal;

	// 성스러운 돌격
	CSkill* chargeAttack = new CSkill;
	chargeAttack->SetSkillName(L"기절의 일격 1");
	chargeAttack->SetSkillPath(L"");
	chargeAttack->GetSkillPos()[0] = true;
	chargeAttack->GetSkillPos()[1] = true;

	chargeAttack->GetSkillRange()[1] = true;
	chargeAttack->GetSkillRange()[2] = true;
	chargeAttack->GetSkillRange()[3] = true;

	chargeAttack->SetHitRate(85);
	chargeAttack->SetAttackRate(15);
	chargeAttack->SetCritRate(6.5f);

	skillArray[5] = chargeAttack;

	// 격려의 함성
	CSkill* cheer = new CSkill;
	cheer->SetSkillName(L"격려의 함성 1");
	cheer->SetSkillPath(L"");
	cheer->GetSkillPos()[0] = true;
	cheer->GetSkillPos()[1] = true;
	cheer->GetSkillPos()[2] = true;
	cheer->GetSkillPos()[3] = true;

	skillArray[6] = cheer;

	curSkillArray[0] = powerAttack;
	curSkillArray[1] = denunciation;
	curSkillArray[2] = stunAttack;
	curSkillArray[3] = chargeAttack;
}
