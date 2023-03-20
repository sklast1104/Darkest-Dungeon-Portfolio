#include "stdafx.h"
#include "Scene_Test.h"

#include "CRectangle.h"
#include "Core.h"

#include "DivUI.h"

Scene_Test::Scene_Test()
{
}

Scene_Test::~Scene_Test()
{
}

void Scene_Test::Enter()
{
	Vec2 vResolution = Core::GetInst()->GetResolution();

	CRectangle* myRect = new CRectangle;
	myRect->SetScale(Vec2(100.f, 100.f));
	myRect->SetPos(Vec2(960.f, 540.f));

	AddObject(myRect, GROUP_TYPE::PLAYER);

	DivUI* airplane = new DivUI;
	airplane->InitImageModule(L"AirTest", L"texture\\Player.png");
	airplane->SetScale(Vec2(200.f, 200.f));
	airplane->SetPos(Vec2(0.f, 0.f));

	AddObject(airplane, GROUP_TYPE::UI);
}

void Scene_Test::Exit()
{
	Scene::DeleteAll();
}
