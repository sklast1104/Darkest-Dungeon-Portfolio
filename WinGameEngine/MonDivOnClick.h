#pragma once
#include "CCommand.h"

class CMonDiv;
class CMonDiv;

class MonDivOnClick :
	public CCommand
{

private :

	CMonDiv* monDiv;

public :

	MonDivOnClick(CMonDiv* _monDiv);
	~MonDivOnClick() {}

	virtual void Execute() override;
};

