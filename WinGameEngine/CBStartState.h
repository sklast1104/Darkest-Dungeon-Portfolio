#pragma once
#include "CState.h"

class CBStartState :
	public CState
{
private :

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CBStartState();
	~CBStartState();

};

