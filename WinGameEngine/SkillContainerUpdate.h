#pragma once
#include "CCommand.h"

class DivUI;

class SkillContainerUpdate :
	public CCommand
{
private :

	DivUI* skillContainer;

public :

	// �׳� ���⼭ ��Ŀ�̵� ����ζ� ��ġ�� ���� ��ų ��� ���� ��� ���� �ع�����
	SkillContainerUpdate(DivUI* _skillContainer);
	~SkillContainerUpdate();

	virtual void Execute() override;

};

