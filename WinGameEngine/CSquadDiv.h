#pragma once
#include "DivUI.h"

class CHeroDiv;

class CSquadDiv :
	public DivUI
{
private :

	vector<CHeroDiv*> heros;
	float speed;

public :

	CSquadDiv();
	~CSquadDiv();

	virtual void update() override;

	float GetSpeed() { return speed; }

	void AddHero(CHeroDiv* _hero) { heros.push_back(_hero); }

	void PlayHeroIdleAnim();
	void PlayHeroWalkAnim();
	void PlayHeroCombatAnim();

	// 선택한 리얼 인덱스를 오버레이 키고 나머지는 다 끄는 함수
	// 리얼 인덱스는 heroDiv 순서가 아니라 게임매니저 스쿼드상의 실제 인덱스
	void EnableOverlay(int _realIndex);

	// 현재 선택된 인덱스만 포커싱 가능하게하고 나머지는 전부 타게팅 안되게 변경 및 오버레이도처리
	void EnableFocus(int _realIndex);

	CLONE(CSquadDiv);
};

