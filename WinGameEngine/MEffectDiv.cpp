#include "stdafx.h"
#include "MEffectDiv.h"
#include "CSkill.h"
#include "Animator.h"
#include "Animation.h"

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
}