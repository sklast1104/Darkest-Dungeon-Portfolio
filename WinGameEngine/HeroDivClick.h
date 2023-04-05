#pragma once
#include "CCommand.h"

class CSquadDiv;

class HeroDivClick :
	public CCommand
{
private :

	CSquadDiv* squadDiv;
	int realIndex;

public :

	HeroDivClick(CSquadDiv* _squadDiv, int _realIndex);
	~HeroDivClick() {}

	virtual void Execute() override;
};

