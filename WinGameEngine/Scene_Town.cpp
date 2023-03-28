#include "stdafx.h"
#include "Scene_Town.h"

#include "Core.h"
#include "DivUI.h"
#include "BtnBuilding.h"
#include "BuildingOverCom.h"
#include "BuildingMouseOut.h"
#include "UIMgr.h"
#include "UIFactory.h"

Scene_Town::Scene_Town()
{
}

Scene_Town::~Scene_Town()
{
}

void Scene_Town::Enter()
{
	Vec2 vResolution = Core::GetInst()->GetResolution();
	
#pragma region BackGround

	DivUI* pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);

	DivUI* bg = new DivUI;
	bg->SetScale(vResolution);
	bg->SetPos(Vec2(0.f, 0.f));
	bg->CanTarget(false);
	bg->InitImageModule(L"Darkest_Town_Weather_bg", L"resource\\Background\\town_bg_activity_stress_heal_buff.png");
	bg->SetSrcAlpha(255);

	pseudoUI->AddChild(bg);

	DivUI* ruinBg = new DivUI;
	ruinBg->SetScale(Vec2(1418.f, 438.f));
	ruinBg->SetPos(Vec2(0.f, 100.f));
	ruinBg->CanTarget(false);
	ruinBg->InitImageModule(L"Darkest_Town_Ruin_bg", L"resource\\Background\\ruins.png");
	ruinBg->SetSrcAlpha(235);

	pseudoUI->AddChild(ruinBg);

	DivUI* towerbg = new DivUI;
	towerbg->SetScale(Vec2(1920.f, 835.f));
	towerbg->SetPos(Vec2(0.f, 220.f));
	towerbg->CanTarget(false);
	towerbg->InitImageModule(L"Darkest_Town_Bg", L"resource\\Background\\town_ground.sprite.png");
	towerbg->SetSrcAlpha(255);

	pseudoUI->AddChild(towerbg);

#pragma endregion

#pragma region Estate

	// 추상 팩토리 패턴으로 관리해야 할 필요성 있을수도 있음
	
	// 수도원
	DivUI* abbey_active = new DivUI;
	abbey_active->SetScale(Vec2(779.f, 901.f));
	abbey_active->SetScale(abbey_active->GetScale() * 0.5f);
	abbey_active->SetPos(Vec2(904.f, 144.f));
	abbey_active->CanTarget(false);
	abbey_active->InitImageModule(L"Darkest_Estate_abbey_active", L"resource\\estate\\abbey\\active.png");
	abbey_active->SetSrcAlpha(235);
	abbey_active->SetCanRendImg(false);

	pseudoUI->AddChild(abbey_active);

	// 설명 패널
	DivUI* abbey_disc = UIFactory::CreateTownDiscUI(Vec2(884.f, 124.f), L"수도원", L"스트레스 해소");

	BtnBuilding* abbey = new BtnBuilding(new BuildingMouseOut(abbey_active, abbey_disc));
	abbey->SetScale(Vec2(800.f, 987.f));
	abbey->SetScale(abbey->GetScale() * 0.5f);
	abbey->SetPos(Vec2(900.f, 150.f));
	abbey->CanTarget(true);
	abbey->InitImageModule(L"Darkest_Estate_abbey", L"resource\\estate\\abbey\\idle.png");
	abbey->SetSrcAlpha(235);
	abbey->InitOnMouseOver(new BuildingOverCom(abbey_active, abbey_disc));

	pseudoUI->AddChild(abbey);
	pseudoUI->AddChild(abbey_disc);

	// 묘지

	DivUI* graveyard = new DivUI;
	graveyard->SetScale(Vec2(573.f, 289.f));
	graveyard->SetScale(graveyard->GetScale() * 0.5f);
	graveyard->SetPos(Vec2(860.f, 490.f));
	graveyard->CanTarget(false);
	graveyard->InitImageModule(L"Darkest_Estate_graveyard", L"resource\\estate\\graveyard\\idle.png");
	graveyard->SetSrcAlpha(235);

	pseudoUI->AddChild(graveyard);

	// 요양원
	DivUI* sanitarium_active = new DivUI;
	sanitarium_active->SetScale(Vec2(666.f, 883.f));
	sanitarium_active->SetScale(sanitarium_active->GetScale() * 0.5f);
	sanitarium_active->SetPos(Vec2(602.f, 262.f));
	sanitarium_active->CanTarget(false);
	sanitarium_active->InitImageModule(L"Darkest_Estate_Sanitarium_active", L"resource\\estate\\sanitarium\\active.png");
	sanitarium_active->SetSrcAlpha(235);
	sanitarium_active->SetCanRendImg(false);

	pseudoUI->AddChild(sanitarium_active);

	DivUI* sanitarium_disc = UIFactory::CreateTownDiscUI(Vec2(558.f, 184.f), L"요양원", L"기벽과 질병 치료");

	BtnBuilding* sanitarium = new BtnBuilding(new BuildingMouseOut(sanitarium_active, sanitarium_disc));
	sanitarium->SetScale(Vec2(764.f, 965.f));
	sanitarium->SetScale(sanitarium->GetScale() * 0.5f);
	sanitarium->SetPos(Vec2(600.f, 270.f));
	sanitarium->CanTarget(true);
	sanitarium->InitImageModule(L"Darkest_Estate_Sanitarium", L"resource\\estate\\sanitarium\\idle.png");
	sanitarium->SetSrcAlpha(235);
	sanitarium->InitOnMouseOver(new BuildingOverCom(sanitarium_active, sanitarium_disc));

	pseudoUI->AddChild(sanitarium);
	pseudoUI->AddChild(sanitarium_disc);

	// 여관
	DivUI* tavern_active = new DivUI;
	tavern_active->SetScale(Vec2(768.f, 753.f));
	tavern_active->SetScale(tavern_active->GetScale() * 0.5f);
	tavern_active->SetPos(Vec2(355.f, 413.f));
	tavern_active->CanTarget(false);
	tavern_active->InitImageModule(L"Darkest_Estate_tavern_active", L"resource\\estate\\tavern\\active.png");
	tavern_active->SetSrcAlpha(235);
	tavern_active->SetCanRendImg(false);

	pseudoUI->AddChild(tavern_active);

	DivUI* tavern_disc = UIFactory::CreateTownDiscUI(Vec2(328.f, 304.f), L"여관", L"스트레스 해소");

	BtnBuilding* tavern = new BtnBuilding(new BuildingMouseOut(tavern_active, tavern_disc));
	tavern->SetScale(Vec2(770.f, 806.f));
	tavern->SetScale(tavern->GetScale() * 0.5f);
	tavern->SetPos(Vec2(350.f, 420.f));
	tavern->CanTarget(true);
	tavern->InitImageModule(L"Darkest_Estate_tavern", L"resource\\estate\\tavern\\idle.png");
	tavern->SetSrcAlpha(235);
	tavern->InitOnMouseOver(new BuildingOverCom(tavern_active, tavern_disc));

	pseudoUI->AddChild(tavern);
	pseudoUI->AddChild(tavern_disc);

	// 길드
	DivUI* guild_active = new DivUI;
	guild_active->SetScale(Vec2(648.f, 656.f));
	guild_active->SetScale(guild_active->GetScale() * 0.5f);
	guild_active->SetPos(Vec2(1147.f, 412.f));
	guild_active->CanTarget(false);
	guild_active->InitImageModule(L"Darkest_Estate_guild_active", L"resource\\estate\\guild\\active.png");
	guild_active->SetSrcAlpha(235);
	guild_active->SetCanRendImg(false);

	pseudoUI->AddChild(guild_active);

	DivUI* guild_disc = UIFactory::CreateTownDiscUI(Vec2(1130.f, 254.f), L"길드", L"전투기술 강화");

	BtnBuilding* guild = new BtnBuilding(new BuildingMouseOut(guild_active, guild_disc));
	guild->SetScale(Vec2(683.f, 693.f));
	guild->SetScale(guild->GetScale() * 0.5f);
	guild->SetPos(Vec2(1150.f, 420.f));
	guild->CanTarget(true);
	guild->InitImageModule(L"Darkest_Estate_guild", L"resource\\estate\\guild\\idle.png");
	guild->SetSrcAlpha(235);
	guild->InitOnMouseOver(new BuildingOverCom(guild_active, guild_disc));

	pseudoUI->AddChild(guild);
	pseudoUI->AddChild(guild_disc);

#pragma endregion

	AddObject(pseudoUI, GROUP_TYPE::UI);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);
}

void Scene_Town::Exit()
{
}
