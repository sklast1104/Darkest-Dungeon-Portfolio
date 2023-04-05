#include "stdafx.h"
#include "CHeroDiv.h"
#include "AnimatorDK.h"
#include "Animation.h"
#include "CHero.h"
#include "CSelectedOverlay.h"

CHeroDiv::CHeroDiv(CHero* _hero)
	: hero{_hero}
{
	CreateAnimator();

	idleAnimName = hero->GetJobName() + L"_idle";
	walkAnimName = hero->GetJobName() + L"_walk";
	combatAnimName = hero->GetJobName() + L"_combat";

	float heightFloat = 483.f;

	if (hero->GetJobName() == L"������") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.idle-idle.atlas", idleAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.walk-walk.atlas", walkAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.combat-combat.atlas", combatAnimName);
		// �ִϸ��̼� yũ�Ⱑ ���� �ٸ��� �� ũ�⸦ �޾ƿͼ� ���� ũ��� �˾Ƽ� ������ ���������� �ڵ�����
		// ����ϴ� ������ ¥ ���� �Ǵ��� ���

		// ������ ���� ��ġ�� 353 + 130 = 483
		// 

		Animation* idleAnim = m_pAnimator->FindAnimation(idleAnimName);
		float idleHeight = idleAnim->GetFrameHeight();
		idleAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - idleHeight));

		Animation* walkAnim = m_pAnimator->FindAnimation(walkAnimName);
		float walkHeight = walkAnim->GetFrameHeight();
		walkAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - walkHeight));

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - combatHeight));

		// �⺻ �ִϸ��̼� ������ �߽���ġ ����ε�
		// ui�� ��ġ�� lefttop�̶� �̰��� ����

		m_pAnimator->Play(idleAnimName, true);
	}
	else if (hero->GetJobName() == L"��󰭵�") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.idle-idle.atlas", idleAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.walk-walk.atlas", walkAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.combat-combat.atlas", combatAnimName);

		Animation* idleAnim = m_pAnimator->FindAnimation(idleAnimName);
		float idleHeight = idleAnim->GetFrameHeight();
		idleAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - idleHeight));

		Animation* walkAnim = m_pAnimator->FindAnimation(walkAnimName);
		float walkHeight = walkAnim->GetFrameHeight();
		walkAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - walkHeight));

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - combatHeight));

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
	m_pAnimator->Play(idleAnimName, true);
}

void CHeroDiv::PlayHeroWalkAnim()
{
	m_pAnimator->Play(walkAnimName, true);
}

void CHeroDiv::PlayHeroCombatAnim()
{
	m_pAnimator->Play(combatAnimName, true);
}

void CHeroDiv::EnableOverlay(bool _isEnable)
{
	if (_isEnable) {
		overlay->SetCanRend(true);
	}
	else {
		overlay->SetCanRend(false);
	}
}
