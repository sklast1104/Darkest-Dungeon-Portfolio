#pragma once
#include "CState.h"

class CSquadDiv;

class CIdleState :
	public CState
{
private :

	CSquadDiv* hero;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

public :

	CIdleState();
	~CIdleState();
};

