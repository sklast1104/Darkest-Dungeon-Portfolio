#include "stdafx.h"
#include "CMonDiv.h"
#include "CDarkMonster.h"
#include "AnimatorDK.h"
#include "Animation.h"

CMonDiv::CMonDiv(CDarkMonster* _monster)
	: monster{_monster}
{
	CreateAnimator();

	combatAnimName = monster->GetName() + L"_combat";

	if (monster->GetName() == L"ÇØ°ñ º´»ç") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\Bone Soldier\\Sprite\\skeleton_militia.sprite.combat-combat.atlas", true, combatAnimName);

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		combatAnim->SetAllFrameOffset(Vec2(0.f, 180.f));
	}

	PlayCombatAnim();
}

void CMonDiv::CreateAnimator()
{
	m_pAnimator = new AnimatorDK;

	m_pAnimator->SetOwnerObject(this);
}

void CMonDiv::PlayCombatAnim()
{
	m_pAnimator->Play(combatAnimName, true);
}
