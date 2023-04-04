#pragma once
#include "Scene.h"

class Scene_Droom :
	public Scene
{
private :

	DivUI* dragRenderer;
	DivUI* itemDragger;

public :

	Scene_Droom();
	~Scene_Droom();

	virtual void Enter() override;
	virtual void update() override;

};

