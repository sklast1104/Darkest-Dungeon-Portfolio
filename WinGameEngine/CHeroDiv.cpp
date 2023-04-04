#include "stdafx.h"
#include "CHeroDiv.h"
#include "AnimatorDK.h"
#include "Animation.h"

CHeroDiv::CHeroDiv()
{
	CreateAnimator();

	wstring heroName = L"성전사";
	wstring idleAnimName = L"heroname_idle";
	wstring walkAnimName = L"heroname_walk";
	wstring combatAnimName = L"heroname_combat";

	if (heroName == L"성전사") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.idle-idle.atlas", idleAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.walk-walk.atlas", walkAnimName);
		// 애니메이션 y크기가 각자 다른데 이 크기를 받아와서 기준 크기로 알아서 오프셋 내려가도록 자동으로
		// 계산하는 로직을 짜 봐야 되는지 고민

		Animation* idleAnim = m_pAnimator->FindAnimation(idleAnimName);
		idleAnim->SetAllFrameOffset(Vec2(0.f, 130.f));

		Animation* walkAnim = m_pAnimator->FindAnimation(walkAnimName);
		walkAnim->SetAllFrameOffset(Vec2(0.f, 131.f));

		// 기본 애니메이션 설정은 중심위치 기반인데
		// ui는 위치가 lefttop이라 이격이 있음

		m_pAnimator->Play(idleAnimName, true);
	}
}

void CHeroDiv::CreateAnimator()
{
	m_pAnimator = new AnimatorDK;

	m_pAnimator->SetOwnerObject(this);
}

void CHeroDiv::PlayHeroIdleAnim()
{
	m_pAnimator->Play(L"heroname_idle", true);
}

void CHeroDiv::PlayHeroWalkAnim()
{
	m_pAnimator->Play(L"heroname_walk", true);
}

void CHeroDiv::PlayHeroCombatAnim()
{
}
