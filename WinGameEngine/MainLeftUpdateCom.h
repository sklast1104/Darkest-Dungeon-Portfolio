#pragma once
#include "CCommand.h"

class DivUI;

class MainLeftUpdateCom :
	public CCommand
{

private :

	DivUI* mainLeftPanel;

public :

	MainLeftUpdateCom(DivUI* _mainLeftPanel);
	~MainLeftUpdateCom() {}

	virtual void Execute() override;
};

