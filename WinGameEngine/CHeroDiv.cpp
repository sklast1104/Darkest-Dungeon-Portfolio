#include "stdafx.h"
#include "CHeroDiv.h"
#include "AnimatorDK.h"
#include "Animation.h"

CHeroDiv::CHeroDiv()
{
	CreateAnimator();

	wstring heroName = L"������";
	wstring idleAnimName = L"heroname_idle";
	wstring walkAnimName = L"heroname_walk";
	wstring combatAnimName = L"heroname_combat";

	if (heroName == L"������") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.idle-idle.atlas", idleAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.walk-walk.atlas", walkAnimName);
		// �ִϸ��̼� yũ�Ⱑ ���� �ٸ��� �� ũ�⸦ �޾ƿͼ� ���� ũ��� �˾Ƽ� ������ ���������� �ڵ�����
		// ����ϴ� ������ ¥ ���� �Ǵ��� ���

		Animation* idleAnim = m_pAnimator->FindAnimation(idleAnimName);
		idleAnim->SetAllFrameOffset(Vec2(0.f, 130.f));

		Animation* walkAnim = m_pAnimator->FindAnimation(walkAnimName);
		walkAnim->SetAllFrameOffset(Vec2(0.f, 131.f));

		// �⺻ �ִϸ��̼� ������ �߽���ġ ����ε�
		// ui�� ��ġ�� lefttop�̶� �̰��� ����

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
