#pragma once
#include "Scene.h"

class DivUI;
class CDungeon;


class Scene_DSelect :
	public Scene
{

private :

	vector<DivUI*> radioBtns;

	CDungeon* ruin; // ����
	CDungeon* court; // ����
	CDungeon* bay; // �ؾ� ��

	void InitDungeon();

	// sidebar ui
	// ex ����
	DivUI* questTitle;
	// ex ������ ������ ����...
	DivUI* questText;
	// ex x0
	DivUI* campingText;
	// ex ª�� |
	DivUI* pathLengText;
	// ex �߽� (1����)
	DivUI* pathLevText;
	// ex �� ������ 100% ~
	DivUI* goalDisc;

public :

	Scene_DSelect();
	~Scene_DSelect();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void update() override;

	void turnOffRadioBtn();

	friend class UIFactory;
	friend class RadioBtnClickCom;
};

