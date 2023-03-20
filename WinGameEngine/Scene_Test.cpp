#include "stdafx.h"
#include "Scene_Test.h"

#include "CRectangle.h"
#include "Core.h"
#include "DivUI.h"

#include "ViewMgr.h"
#include "KeyMgr.h"
#include "Camera.h"

Scene_Test::Scene_Test()
{
}

Scene_Test::~Scene_Test()
{
}

void Scene_Test::update()
{
	if (KEY_TAP(KEY::Q)) {
		//ViewMgr::GetInst()->SetZoomRatio(2.f);
		ViewMgr::GetInst()->animateZoom(2.f, 1.1f);
	}

	if (KEY_TAP(KEY::R)) {
		//ViewMgr::GetInst()->SetZoomRatio(1.f);
		ViewMgr::GetInst()->animateZoom(1.f, 1.1f);
	}

	if (KEY_TAP(KEY::LBTN)) {
		
		Vec2 mousePos = Camera::GetInst()->GetRealPos(MOUSE_POS);
		Camera::GetInst()->SetLookAt(mousePos);
	}

	Scene::update();
}

void Scene_Test::Enter()
{
	//ViewMgr::GetInst()->SetZoomRatio(2.f);

	Vec2 vResolution = Core::GetInst()->GetResolution();

	CRectangle* myRect = new CRectangle;
	myRect->SetScale(Vec2(100.f, 100.f));
	myRect->SetPos(Vec2(960.f, 540.f));

	AddObject(myRect, GROUP_TYPE::PLAYER);

	CRectangle* obstacle = new CRectangle;
	obstacle->SetScale(Vec2(100.f, 100.f));
	obstacle->SetPos(Vec2(560.f, 540.f));
	obstacle->SetIsPlayer(false);

	AddObject(obstacle, GROUP_TYPE::MONSTER);

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


