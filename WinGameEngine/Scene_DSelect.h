#pragma once
#include "Scene.h"

class DivUI;
class CDungeon;


class Scene_DSelect :
	public Scene
{

private :

	vector<DivUI*> radioBtns;

	CDungeon* ruin; // 폐허
	CDungeon* court; // 궁정
	CDungeon* bay; // 해안 만

	void InitDungeon();

	// sidebar ui
	// ex 정찰
	DivUI* questTitle;
	// ex 스러진 선조의 광기...
	DivUI* questText;
	// ex x0
	DivUI* campingText;
	// ex 짧음 |
	DivUI* pathLengText;
	// ex 견습 (1레벨)
	DivUI* pathLevText;
	// ex 방 전투의 100% ~
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

