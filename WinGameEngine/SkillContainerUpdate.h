#pragma once
#include "CCommand.h"

class DivUI;

class SkillContainerUpdate :
	public CCommand
{
private :

	DivUI* skillContainer;

public :

	// 그냥 여기서 포커싱된 히어로랑 위치에 따른 스킬 사용 가능 계산 전부 해버리자
	SkillContainerUpdate(DivUI* _skillContainer);
	~SkillContainerUpdate();

	virtual void Execute() override;

};

