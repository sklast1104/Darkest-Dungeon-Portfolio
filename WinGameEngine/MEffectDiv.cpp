#include "stdafx.h"
#include "MEffectDiv.h"
#include "CSkill.h"
#include "Animator.h"
#include "Animation.h"
#include "CDarkMonster.h"

MEffectDiv::MEffectDiv(CDarkMonster* _dMon)
	: dMon{_dMon}
{
}

void MEffectDiv::PlaySkillAnim(CSkill* skill)
{
	wstring realAnimName = skill->GetRealAnimName();
	wstring realAnimPath = skill->GetRealAnimPath();

	//LoadAnimation(realAnimPath, realAnimName, false);
	if (L"" != realAnimName) {
		m_pAnimator->Play(realAnimName, false);
		m_pAnimator->GetCurAnimation()->SetFrame(0);
	}
}

// �÷��̾� ��ų�� �޾Ƽ� ��ų�� �ش��ϴ� �ǰ� ����Ʈ�� ������ ���� ��������ش�
void MEffectDiv::PlayDamagedAnim(int damage)
{
	m_pAnimator->Play(L"bloodSplatter_monster", false);
	m_pAnimator->GetCurAnimation()->SetFrame(0);
}

void MEffectDiv::Init()
{
	m_pAnimator->LoadAnimation(L"resource\\animations\\fx\\blood_splat_anim\\blood_splatter.sprite-blood_splatter.atlas", false, L"bloodSplatter_monster");
	Animation* bloodSplatAnim = m_pAnimator->FindAnimation(L"bloodSplatter_monster");
	bloodSplatAnim->SetAllFrameOffset(Vec2(0.f, 150.f));

	if (dMon->GetName() == L"�ذ� ����") {

		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-200.f, 200.f));
		}

	}
	else if (dMon->GetName() == L"�ذ� ��") {
		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-200.f, 300.f));
		}
	}
	else if (dMon->GetName() == L"�ذ� �ü�") {
		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-200.f, 200.f));
		}
	}
	else if (dMon->GetName() == L"�ذ� ���°�") {
		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-300.f, 140.f));
		}
	}
}