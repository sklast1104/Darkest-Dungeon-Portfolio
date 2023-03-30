#include "stdafx.h"
#include "CHighwayMan.h"
#include "CSkill.h"

CHighwayMan::CHighwayMan()
{
	key = L"Highwayman Portrait";
	path = L"resource\\heros\\highwayman.png";
	name = L"�𽺸���";
	job_name = L"��󰭵�";

	curHp = 23;
	hp = 23;

	curStress = 60;
	stress = 200;
	curExp = 5;

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
	curSkillArray.fill(nullptr);

	for (int i = 0; i < 7; i++) {
		Safe_Delete<CSkill*>(skillArray[i]);
	}

	for (int i = 0; i < 4; i++) {
		Safe_Delete<CSkill*>(curSkillArray[i]);
	}
}

void CHighwayMan::InitSkill()
{
	// ����� Į��
	CSkill* evilBlade = new CSkill;
	evilBlade->SetSkillName(L"����� Į�� 1");
	evilBlade->SetSkillPath(L"resource\\heros\\highwayman\\ab0.png");
	evilBlade->SetGraySkillPath(L"resource\\heros\\highwayman\\ab0_gray.png");
	evilBlade->GetSkillPos()[1] = true;
	evilBlade->GetSkillPos()[2] = true;
	evilBlade->GetSkillPos()[3] = true;

	evilBlade->GetSkillRange()[0] = true;
	evilBlade->GetSkillRange()[1] = true;

	evilBlade->SetHitRate(85);
	evilBlade->SetAttackRate(15);
	evilBlade->SetCritRate(5.f);

	skillArray[0] = evilBlade;

	// ���� ��� 1
	CSkill* pistolShot = new CSkill;
	pistolShot->SetSkillName(L"���� ��� 1");
	pistolShot->SetSkillPath(L"resource\\heros\\highwayman\\ab1.png");
	pistolShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab1_gray.png");
	pistolShot->GetSkillPos()[0] = true;
	pistolShot->GetSkillPos()[1] = true;
	pistolShot->GetSkillPos()[2] = true;

	pistolShot->SetMultiAttack(true);
	pistolShot->GetSkillRange()[1] = true;
	pistolShot->GetSkillRange()[2] = true;
	pistolShot->GetSkillRange()[3] = true;

	pistolShot->SetHitRate(85);
	pistolShot->SetAttackRate(-15);
	pistolShot->SetCritRate(7.5f);

	skillArray[1] = pistolShot;

	// ���Ÿ� ���
	CSkill* zeroShot = new CSkill;
	zeroShot->SetSkillName(L"���Ÿ� ��� 1");
	zeroShot->SetSkillPath(L"resource\\heros\\highwayman\\ab2.png");
	zeroShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab2_gray.png");
	zeroShot->GetSkillPos()[3] = true;

	zeroShot->GetSkillRange()[0] = true;

	zeroShot->SetHitRate(95);
	zeroShot->SetAttackRate(50);
	zeroShot->SetCritRate(5);

	skillArray[2] = zeroShot;

	// ����ź �߻�
	CSkill* grapeShot = new CSkill;
	grapeShot->SetSkillName(L"����ź �߻� 1");
	grapeShot->SetSkillPath(L"resource\\heros\\highwayman\\ab3.png");
	grapeShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab3_gray.png");
	grapeShot->GetSkillPos()[1] = true;
	grapeShot->GetSkillPos()[2] = true;

	pistolShot->SetMultiAttack(true);
	pistolShot->GetSkillRange()[0] = true;
	pistolShot->GetSkillRange()[1] = true;
	pistolShot->GetSkillRange()[2] = true;

	pistolShot->SetHitRate(75);
	pistolShot->SetAttackRate(-50);
	pistolShot->SetCritRate(-9.f);

	skillArray[3] = grapeShot;

	// ����ź
	CSkill* traceShot = new CSkill;
	traceShot->SetSkillName(L"����ź 1");
	traceShot->SetSkillPath(L"resource\\heros\\highwayman\\ab4.png");
	traceShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab4_gray.png");
	traceShot->GetSkillPos()[0] = true;
	traceShot->GetSkillPos()[1] = true;
	traceShot->GetSkillPos()[2] = true;
	traceShot->GetSkillPos()[3] = true;

	traceShot->SetMultiAttack(true);
	traceShot->GetSkillRange()[1] = true;
	traceShot->GetSkillRange()[2] = true;
	traceShot->GetSkillRange()[3] = true;

	traceShot->SetHitRate(75);
	traceShot->SetAttackRate(-50);
	traceShot->SetCritRate(-9.f);

	skillArray[4] = traceShot;

	// �������� ����
	CSkill* advanceAttack = new CSkill;
	advanceAttack->SetSkillName(L"�������� ���� 1");
	advanceAttack->SetSkillPath(L"resource\\heros\\highwayman\\ab5.png");
	advanceAttack->SetGraySkillPath(L"resource\\heros\\highwayman\\ab5_gray.png");
	advanceAttack->GetSkillPos()[0] = true;
	advanceAttack->GetSkillPos()[1] = true;
	advanceAttack->GetSkillPos()[2] = true;

	advanceAttack->GetSkillRange()[0] = true;
	advanceAttack->GetSkillRange()[1] = true;
	advanceAttack->GetSkillRange()[2] = true;

	advanceAttack->SetHitRate(90);
	advanceAttack->SetAttackRate(-20);
	advanceAttack->SetCritRate(5.f);

	skillArray[5] = advanceAttack;

	// ����
	CSkill* incision = new CSkill;
	incision->SetSkillName(L"���� 1");
	incision->SetSkillPath(L"resource\\heros\\highwayman\\ab6.png");
	incision->SetGraySkillPath(L"resource\\heros\\highwayman\\ab6_gray.png");

	incision->GetSkillPos()[1] = true;
	incision->GetSkillPos()[2] = true;
	incision->GetSkillPos()[3] = true;

	incision->GetSkillRange()[0] = true;
	incision->GetSkillRange()[1] = true;

	incision->SetHitRate(95);
	incision->SetAttackRate(-15);

	skillArray[6] = incision;

	curSkillArray[0] = evilBlade;
	curSkillArray[1] = pistolShot;
	curSkillArray[2] = grapeShot;
	curSkillArray[3] = advanceAttack;
}