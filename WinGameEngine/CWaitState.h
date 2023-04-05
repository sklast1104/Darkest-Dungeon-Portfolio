#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;

class CWaitState :
	public CState
{
private :

	// ¿µ¿õ ½ºÄõµå
	CSquadDiv* heroSquad;

	// ¸ó½ºÅÍ ½ºÄõµå
	CMonSquad* monSquad;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CWaitState();
	~CWaitState();

};

