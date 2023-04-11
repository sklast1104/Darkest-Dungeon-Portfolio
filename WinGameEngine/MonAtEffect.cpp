#include "stdafx.h"
#include "MonAtEffect.h"
#include "CSkill.h"
#include "Animator.h"
#include "Animation.h"

void MonAtEffect::PlayPskAttacked(CSkill* _playerSkill)
{
	if (L"노상강도" == _playerSkill->GetOwnerJobName()) {
		wstring attackedAnimName = _playerSkill->GetAttackedName();
		wstring attackedAnimPath = _playerSkill->GetAttackedPath();

		//LoadAnimation(realAnimPath, realAnimName, false);
		if (L"" != attackedAnimName) {
			m_pAnimator->LoadAnimation(attackedAnimPath, true, attackedAnimName);
			m_pAnimator->FindAnimation(attackedAnimName)->SetAllFrameOffset(Vec2(0.f, 240.f));
			m_pAnimator->Play(attackedAnimName, false);
			m_pAnimator->GetCurAnimation()->SetFrame(0);
		}
	}
	}

	
