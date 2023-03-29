#include "stdafx.h"
#include "CCrusader.h"
#include "CSkill.h"

CCrusader::CCrusader()
{
	key = L"Crusader Portrait";
	name = L"���̳ε�";
	job_name = L"������";

	curHp = 33;
	hp = 33;

	curStress = 1;
	stress = 99;

	// ���� ����
	hitRate = 0;
	// ȸ����
	avoidanceRate = 5;
	// ġ����
	criticalHitRate = 3;
	// ������ ����
	damageLower = 6;
	// ������ ����
	damageUpper = 12;
	// �ӵ�
	speed = 1;

	InitSkill();
}

CCrusader::~CCrusader()
{
}

void CCrusader::InitSkill()
{
	// ��Ÿ
	CSkill* powerAttack = new CSkill;
	powerAttack->SetSkillName(L"��Ÿ 1");
	powerAttack->SetSkillPath(L"");
	powerAttack->GetSkillPos()[2] = true;
	powerAttack->GetSkillPos()[3] = true;

	powerAttack->GetSkillRange()[0] = true;
	powerAttack->GetSkillRange()[1] = true;

	powerAttack->SetHitRate(85);
	powerAttack->SetAttackRate(15);

	skillArray[0] = powerAttack;

	// ������ ���
	CSkill* denunciation = new CSkill;
	denunciation->SetSkillName(L"������ ��� 1");
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

	// ������ �ϰ�
	CSkill* stunAttack = new CSkill;
	stunAttack->SetSkillName(L"������ �ϰ� 1");
	stunAttack->SetSkillPath(L"");
	stunAttack->GetSkillPos()[2] = true;
	stunAttack->GetSkillPos()[3] = true;

	stunAttack->GetSkillRange()[0] = true;
	stunAttack->GetSkillRange()[1] = true;

	stunAttack->SetHitRate(90);
	stunAttack->SetAttackRate(-50);

	skillArray[2] = stunAttack;

	// �ž��� ����
	CSkill* shield = new CSkill;
	shield->SetSkillName(L"�ž��� ���� 1");
	shield->SetSkillPath(L"");
	shield->GetSkillPos()[2] = true;
	shield->GetSkillPos()[3] = true;

	skillArray[3] = shield;

	// ���� ġ��
	CSkill* battleHeal = new CSkill;
	battleHeal->SetSkillName(L"���� ġ�� 1");
	battleHeal->SetSkillPath(L"");
	battleHeal->GetSkillPos()[0] = true;
	battleHeal->GetSkillPos()[1] = true;
	battleHeal->GetSkillPos()[2] = true;
	battleHeal->GetSkillPos()[3] = true;

	skillArray[4] = battleHeal;

	// �������� ����
	CSkill* chargeAttack = new CSkill;
	chargeAttack->SetSkillName(L"������ �ϰ� 1");
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

	// �ݷ��� �Լ�
	CSkill* cheer = new CSkill;
	cheer->SetSkillName(L"�ݷ��� �Լ� 1");
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
