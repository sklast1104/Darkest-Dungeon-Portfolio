#pragma once
#include "CCommand.h"

class DivUI;

class SkillOnclick :
	public CCommand
{
private :

	DivUI* skillUI;

public :

	SkillOnclick(DivUI* _skillUI);
	~SkillOnclick() {}

	virtual void Execute() override;
};

