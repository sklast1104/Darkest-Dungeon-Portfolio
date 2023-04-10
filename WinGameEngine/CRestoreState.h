#pragma once
#include "CState.h"

class CHeroDiv;
class CMonDiv;

class CRestoreState :
	public CState
{
private :

	CHeroDiv* player;
	CMonDiv* monster;

	float curTime;
	float lerpTime;

	Vec2 pSPos;
	Vec2 pEPos;

	Vec2 mSPos;
	Vec2 mEPos;

	bool canCg;

public :

	CRestoreState();
	~CRestoreState();

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	void SetPlayer(CHeroDiv* _player) { player = _player; }
	void SetMonster(CMonDiv* _monster) { monster = _monster; }
};

