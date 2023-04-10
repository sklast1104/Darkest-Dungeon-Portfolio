#include "stdafx.h"
#include "CMonDiv.h"
#include "CDarkMonster.h"
#include "AnimatorDK.h"
#include "Animation.h"
#include "CSelectedOverlay.h"
#include "CSkill.h"

CMonDiv::CMonDiv(CDarkMonster* _monster)
	: monster{_monster}
{
	CreateAnimator();

	combatAnimName = monster->GetName() + L"_combat";

	float heightFloat = 483.f;

	if (monster->GetName() == L"ÇØ°ñ º´»ç") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\Bone Soldier\\Sprite\\skeleton_militia.sprite.combat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, 180.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(0.f, 180.f));
		attackedAnim->SetMulScale(1.4f);
		

		for (int i = 0; i < 4; i++) {
			CSkill* skill = monster->GetCurSkills()[i];

			if (nullptr != skill) {
				wstring skillName = skill->GetSkilAnimName();
				wstring skillPath = skill->GetAnimPath();

				m_pAnimator->LoadAnimation(skillPath, true, skillName);

				Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
				float animHeight = skillAnim->GetFrameHeight();
				skillAnim->SetAllFrameOffset(Vec2(-150.f, 170.f));
				skillAnim->SetMulScale(1.3f);
			}
		}
	}

	PlayCombatAnim();
	//PlayCurSkilByIdx(0);
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

void CMonDiv::PlayAttackedAnim()
{
	m_pAnimator->Play(monster->GetAttackedAnimName(), true);
}

void CMonDiv::PlayCurSkilByIdx(int _idx)
{
	wstring animName = monster->GetCurSkills()[_idx]->GetSkilAnimName();
	m_pAnimator->Play(animName, true);
}

void CMonDiv::EnableAllChildUI(bool _enable)
{
	vector<UI*> vec = GetChildUI();

	if (_enable) {

		for (int i = 0; i < vec.size(); i++) {
			DivUI* div = dynamic_cast<DivUI*>(vec[i]);
			if (div) {

				if (div->GetName() != L"focusedOverlay_monster") {
					div->SetCanRend(_enable);
				}
			}
		}

	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			DivUI* div = dynamic_cast<DivUI*>(vec[i]);
			if (div) {
				div->SetCanRend(_enable);
			}
		}
	}
}

void CMonDiv::EnableOverlay(bool _isEnable)
{
	if (_isEnable) {
		overlay->SetCanRend(true);
	}
	else {
		overlay->SetCanRend(false);
	}
}

void CMonDiv::UpdateHpBar()
{
	int curHp = monster->GetCurHp();
	int maxHp = monster->GetMaxHp();

	float hpPercent = (float)curHp / maxHp;

	curHpBar->SetScale(Vec2(100.f * hpPercent, 10.f));
}
