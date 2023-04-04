#include "stdafx.h"
#include "Scene_Droom.h"
#include "Core.h"
#include "DivUI.h"
#include "UIMgr.h"
#include "Camera.h"
#include "ShopInvUpdateVal.h"
#include "UIFactory.h"
#include "GameMgr.h"
#include "CSquadDiv.h"
#include "CHeroDiv.h"
#include "CSelectedOverlay.h"
#include "KeyMgr.h"

Scene_Droom::Scene_Droom()
{
}

Scene_Droom::~Scene_Droom()
{
}

void Scene_Droom::Enter()
{
	// 드래그 되는 인벤토리용 오브젝트
	itemDragger = new DivUI;
	itemDragger->SetScale(Vec2(72.f, 144.f));
	itemDragger->SetPos(Vec2(960.f, 540.f));
	itemDragger->SetName(L"itemDragger");
	itemDragger->CanTarget(false);
	itemDragger->SetCanRend(false);

	Vec2 vResolution = Core::GetInst()->GetResolution();

	pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);

	DivUI* bg = new DivUI;
	bg->SetPos(Vec2(0.f, 0.f));
	bg->SetScale(Vec2(1920.f, 720.f));
	bg->InitImageModule(L"RuinRoom0", L"resource\\Background\\ruins\\room0.png");
	bg->CanTarget(false);

	pseudoUI->AddChild(bg);

	AddObject(pseudoUI, GROUP_TYPE::UI);

#pragma region Hero

	GameMgr* mgr = GameMgr::GetInst();
	//int squadNum = mgr->GetSquadNum();
	int squadNum = 2;
	float heroXOffset = 200.f;

	// 스케일은 인원수 비례해서 커지고
	// 포지션은 인원수 반비례해서 작아져야함
	CSquadDiv* squad = new CSquadDiv;
	squad->SetScale(Vec2(heroXOffset * squadNum, 500.f));
	squad->SetPos(Vec2(1000.f - (squadNum * heroXOffset), 200.f));
	squad->SetName(L"CSquadDiv");
	
	pseudoUI->AddChild(squad);

	for (int i = 0; i < squadNum; i++) {

		CHeroDiv* hero = new CHeroDiv;
		hero->SetPos(Vec2(i * heroXOffset, 0.f));
		hero->SetScale(Vec2(heroXOffset, 500.f));
		squad->AddChild(hero);
		squad->AddHero(hero);

		CSelectedOverlay* heroOverlay = new CSelectedOverlay;
		heroOverlay->SetPos(Vec2(93.f, 485.f));
		heroOverlay->SetScale(Vec2(175.f, 72.f));
		heroOverlay->SetScale(heroOverlay->GetScale() * 0.9f);
		hero->AddChild(heroOverlay);

		Vec2 overlaybase = Vec2(40.f, 505.f);

		DivUI* hpBar = new DivUI;
		hpBar->SetPos(Vec2(overlaybase.x, overlaybase.y - 15.f));
		hpBar->SetScale(Vec2(100.f, 10.f));
		hpBar->InitImageModule(L"HP_EMPTYBAR_BG", L"resource\\overay\\stress_pip_empty copy.png");
		hpBar->SetCamAffected(true);

		hero->AddChild(hpBar);

		DivUI* curHp = new DivUI;
		curHp->SetPos(Vec2(overlaybase.x, overlaybase.y - 15.f));
		curHp->SetScale(Vec2(60.f, 10.f));
		curHp->InitImageModule(L"HP_BASEBAR_BG", L"resource\\overay\\health_pip_full.png");
		curHp->SetCamAffected(true);

		hero->AddChild(curHp);

		for (int i = 0; i < 10; i++) {

			DivUI* stressUI = new DivUI;
			stressUI->SetScale(Vec2(9.f, 10.f));
			stressUI->SetScale(stressUI->GetScale() * 1.0f);
			stressUI->SetPos(Vec2(overlaybase.x + (i * 10), overlaybase.y));
			stressUI->InitImageModule(L"Stress_empty_bg", L"resource\\overay\\stress_empty.png");
			stressUI->CanTarget(false);
			stressUI->SetCamAffected(true);

			hero->AddChild(stressUI);
		}

		for (int i = 0; i < 6; i++) {
			DivUI* stressFullUI = new DivUI;
			stressFullUI->SetScale(Vec2(9.f, 10.f));
			stressFullUI->SetScale(stressFullUI->GetScale() * 1.0f);
			stressFullUI->SetPos(Vec2(overlaybase.x + (i * 10), overlaybase.y));
			stressFullUI->InitImageModule(L"Stress_full_bg", L"resource\\overay\\stress_full.png");
			stressFullUI->CanTarget(false);
			stressFullUI->SetCamAffected(true);

			hero->AddChild(stressFullUI);
		}
		
		for (int i = 0; i < 4; i++) {
			DivUI* stressOverUI = new DivUI;
			stressOverUI->SetScale(Vec2(9.f, 10.f));
			stressOverUI->SetScale(stressOverUI->GetScale() * 1.0f);
			stressOverUI->SetPos(Vec2(overlaybase.x + (i * 10), overlaybase.y));
			stressOverUI->InitImageModule(L"Stress_Over_bg", L"resource\\overay\\stress_over.png");
			stressOverUI->CanTarget(false);
			stressOverUI->SetCamAffected(true);

			hero->AddChild(stressOverUI);
		}
		// 오버레이랑 hp, stressbar 붙여야됨
		// 오버레이는 UI가 아니라 애매하네
	}
	//

#pragma endregion

#pragma region DungeonPanel

	DivUI* panel = new DivUI;
	panel->SetPos(Vec2(0.f, 720.f));
	panel->SetScale(Vec2(1920.f, 360.f));
	panel->CanTarget(false);

	pseudoUI->AddChild(panel);

	DivUI* leftSide = new DivUI;
	leftSide->SetScale(Vec2(250.f, 360.f));
	leftSide->SetPos(Vec2(0.f, 0.f));
	leftSide->CanTarget(false);
	leftSide->InitImageModule(L"Side_Decor_Panel", L"resource\\panels\\side_decor.png");

	panel->AddChild(leftSide);

	DivUI* rightSide = new DivUI;
	rightSide->SetScale(Vec2(250.f, 360.f));
	rightSide->SetPos(Vec2(1920.f - 250.f, 0.f));
	rightSide->CanTarget(false);
	rightSide->InitImageModule(L"Side_Decor_Panel2", L"resource\\panels\\side_decor2.png");

	panel->AddChild(rightSide);

	DivUI* mainPanel = new DivUI;
	mainPanel->SetScale(Vec2(1420.f, 360.f));
	mainPanel->SetPos(Vec2(250.f, 0.f));

	panel->AddChild(mainPanel);
	
	DivUI* mainLeftPanel = new DivUI;
	mainLeftPanel->SetScale(Vec2(710.f, 360.f));
	mainLeftPanel->SetPos(Vec2(0.f, 0.f));

	mainPanel->AddChild(mainLeftPanel);

	// 스킬 패널 파트

	DivUI* skillPanel = new DivUI;
	skillPanel->SetScale(Vec2(710.f, 134.f));
	skillPanel->SetPos(Vec2(0.f, 0.f));
	skillPanel->InitImageModule(L"SKill_Panel2", L"resource\\panels\\skill_panel2.png");
	
	mainLeftPanel->AddChild(skillPanel);

	DivUI* heroPortrait = new DivUI;
	heroPortrait->SetScale(Vec2(85.f, 85.f));
	heroPortrait->SetPos(Vec2(23.f, 33.f));
	heroPortrait->InitImageModule(L"Crusader Portrait", L"resource\\heros\\crusader.png");

	skillPanel->AddChild(heroPortrait);

	DivUI* heroName = new DivUI;
	heroName->SetScale(Vec2(125.f, 25.f));
	heroName->SetPos(Vec2(125.f, 45.f));
	heroName->InitTextModule(L"레이널드", 25);
	heroName->SetFormat(DT_RIGHT);
	heroName->SetTextColor(177, 161, 108);

	skillPanel->AddChild(heroName);

	DivUI* heroJob = new DivUI;
	heroJob->SetScale(Vec2(100.f, 20.f));
	heroJob->SetPos(Vec2(150.f, 75.f));
	heroJob->InitTextModule(L"성전사", 20);
	heroJob->SetFormat(DT_RIGHT);
	heroJob->SetTextColor(106, 105, 98);
	heroJob->SetFont(L"이순신 돋움체 M");

	skillPanel->AddChild(heroJob);

	// 스킬 구현 파트

	DivUI* skillContainer = new DivUI;
	skillContainer->SetPos(Vec2(270.f, 35.f));
	skillContainer->SetScale(Vec2(380.f, 72.f));
	
	skillPanel->AddChild(skillContainer);

	for (int i = 0; i < 5; i++) {
		DivUI* skill1 = new DivUI;
		skill1->SetScale(Vec2(72.f, 72.f));
		skill1->SetPos(Vec2((i * 76.f), 0.f));
		skill1->InitImageModule(L"강타 1 gray", L"resource\\heros\\crusader\\ab1_gray.png");

		skillContainer->AddChild(skill1);
	}

	DivUI* skipBtn = new DivUI;
	skipBtn->SetScale(Vec2(20.f, 72.f));
	skipBtn->SetPos(Vec2(379.f, 0.f));
	skipBtn->InitImageModule(L"ability_pass_gray", L"resource\\panels\\icons_ability\\ability_pass_gray.png");

	skillContainer->AddChild(skipBtn);

	// 장비 패널 파트

	DivUI* equipPanel = new DivUI;
	equipPanel->SetPos(Vec2(-10.f, 134.f));
	equipPanel->SetScale(Vec2(720.f, 226.f));
	equipPanel->InitImageModule(L"Equip_panel", L"resource\\panels\\panel_hero.png");

	mainLeftPanel->AddChild(equipPanel);

#pragma region Status

	// 스테이터스 전용 패널
	DivUI* statusPanel = new DivUI;
	statusPanel->SetPos(Vec2(20.f, 10.f));
	statusPanel->SetScale(Vec2( 230.f, 200.f ));

	equipPanel->AddChild(statusPanel);

	DivUI* curHp = new DivUI;
	curHp->SetScale(Vec2(60.f, 30.f));
	curHp->SetPos(Vec2(70.f, 0.f));
	curHp->InitTextModule(L"33", 20);
	curHp->SetFormat(DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
	curHp->SetTextColor(179, 0, 0);
	curHp->SetFont(L"이순신 돋움체 B");
	curHp->SetBold(200);

	statusPanel->AddChild(curHp);

	DivUI* maxHp = new DivUI;

	maxHp->SetScale(Vec2(80.f, 30.f));
	maxHp->SetPos(Vec2(130.f, 0.f));
	maxHp->InitTextModule(L" / 33", 20);
	maxHp->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	maxHp->SetTextColor(179, 0, 0);
	maxHp->SetFont(L"이순신 돋움체 B");
	maxHp->SetBold(200);

	statusPanel->AddChild(maxHp);

	DivUI* curStress = new DivUI;
	curStress->SetScale(Vec2(60.f, 30.f));
	curStress->SetPos(Vec2(70.f, 30.f));
	curStress->InitTextModule(L"21", 20);
	curStress->SetFormat(DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
	curStress->SetTextColor(148, 148, 148);
	curStress->SetFont(L"이순신 돋움체 B");
	curStress->SetBold(200);

	statusPanel->AddChild(curStress);

	DivUI* maxStress = new DivUI;

	maxStress->SetScale(Vec2(80.f, 30.f));
	maxStress->SetPos(Vec2(130.f, 30.f));
	maxStress->InitTextModule(L" / 200", 20);
	maxStress->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	maxStress->SetTextColor(148, 148, 148);
	maxStress->SetFont(L"이순신 돋움체 B");
	maxStress->SetBold(200);

	statusPanel->AddChild(maxStress);

	float yOffset_stat = 21.f;
	float yOffset_second = 21.f;
	float textSize_y = 20.f;

	// 명중
	DivUI* hitRate = new DivUI;
	hitRate->SetScale(Vec2(80.f, 23.f));
	hitRate->SetPos(Vec2(40.f, 65.f));
	hitRate->InitTextModule(L"명중", 22);
	hitRate->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	hitRate->SetTextColor(172, 170, 160);
	hitRate->SetFont(L"이순신 돋움체 M");
	hitRate->SetBold(100);

	statusPanel->AddChild(hitRate);

	DivUI* hitRateVal = new DivUI;
	hitRateVal->SetScale(Vec2(50.f, 23.f));
	hitRateVal->SetPos(Vec2(160.f, 65.f));
	hitRateVal->InitTextModule(L"0", textSize_y);
	hitRateVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	hitRateVal->SetTextColor(172, 170, 160);
	hitRateVal->SetFont(L"이순신 돋움체 M");
	hitRateVal->SetBold(100);

	statusPanel->AddChild(hitRateVal);

	// 치명타
	DivUI* critRate = new DivUI;
	critRate->SetScale(Vec2(80.f, 23.f));
	critRate->SetPos(Vec2(40.f, 65.f + (yOffset_stat * 1)));
	critRate->InitTextModule(L"치명타", 22);
	critRate->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	critRate->SetTextColor(172, 170, 160);
	critRate->SetFont(L"이순신 돋움체 M");
	critRate->SetBold(500);

	statusPanel->AddChild(critRate);

	DivUI* critRateVal = new DivUI;
	critRateVal->SetScale(Vec2(50.f, 23.f));
	critRateVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 1)));
	critRateVal->InitTextModule(L"5.0%", textSize_y);
	critRateVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	critRateVal->SetTextColor(172, 170, 160);
	critRateVal->SetFont(L"이순신 돋움체 M");
	critRateVal->SetBold(500);

	statusPanel->AddChild(critRateVal);

	

	// 피해
	DivUI* damage = new DivUI;
	damage->SetScale(Vec2(80.f, 23.f));
	damage->SetPos(Vec2(40.f, 65.f + (yOffset_stat * 2)));
	damage->InitTextModule(L"피해", 22);
	damage->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	damage->SetTextColor(172, 170, 160);
	damage->SetFont(L"이순신 돋움체 M");
	damage->SetBold(500);

	statusPanel->AddChild(damage);

	DivUI* damageVal = new DivUI;
	damageVal->SetScale(Vec2(50.f, 23.f));
	damageVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 2)));
	damageVal->InitTextModule(L"5-10", textSize_y);
	damageVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	damageVal->SetTextColor(172, 170, 160);
	damageVal->SetFont(L"이순신 돋움체 M");
	damageVal->SetBold(500);

	statusPanel->AddChild(damageVal);

	// 회피
	DivUI* avoid = new DivUI;
	avoid->SetScale(Vec2(80.f, 23.f));
	avoid->SetPos(Vec2(40.f, 65.f + (yOffset_stat * 3)));
	avoid->InitTextModule(L"회피", 22);
	avoid->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	avoid->SetTextColor(172, 170, 160);
	avoid->SetFont(L"이순신 돋움체 M");
	avoid->SetBold(500);

	statusPanel->AddChild(avoid);

	DivUI* avoidVal = new DivUI;
	avoidVal->SetScale(Vec2(50.f, 23.f));
	avoidVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 3)));
	avoidVal->InitTextModule(L"14", textSize_y);
	avoidVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	avoidVal->SetTextColor(172, 170, 160);
	avoidVal->SetFont(L"이순신 돋움체 M");
	avoidVal->SetBold(500);

	statusPanel->AddChild(avoidVal);

	// 방어
	DivUI* shield = new DivUI;
	shield->SetScale(Vec2(80.f, 23.f));
	shield->SetPos(Vec2(40.f, 65.f + (yOffset_stat * 4)));
	shield->InitTextModule(L"방어", 22);
	shield->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	shield->SetTextColor(172, 170, 160);
	shield->SetFont(L"이순신 돋움체 M");
	shield->SetBold(500);

	statusPanel->AddChild(shield);

	DivUI* shieldVal = new DivUI;
	shieldVal->SetScale(Vec2(50.f, 23.f));
	shieldVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 4)));
	shieldVal->InitTextModule(L"0%", textSize_y);
	shieldVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	shieldVal->SetTextColor(172, 170, 160);
	shieldVal->SetFont(L"이순신 돋움체 M");
	shieldVal->SetBold(500);

	statusPanel->AddChild(shieldVal);

	// 속도
	DivUI* speed = new DivUI;
	speed->SetScale(Vec2(80.f, 23.f));
	speed->SetPos(Vec2(40.f, 65.f + (yOffset_stat * 5)));
	speed->InitTextModule(L"속도", 22);
	speed->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	speed->SetTextColor(172, 170, 160);
	speed->SetFont(L"이순신 돋움체 M");
	speed->SetBold(500);

	statusPanel->AddChild(speed);

	DivUI* speedVal = new DivUI;
	speedVal->SetScale(Vec2(50.f, 23.f));
	speedVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 5)));
	speedVal->InitTextModule(L"7", textSize_y);
	speedVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	speedVal->SetTextColor(172, 170, 160);
	speedVal->SetFont(L"이순신 돋움체 M");
	speedVal->SetBold(500);

	statusPanel->AddChild(speedVal);

#pragma endregion

	// 장비 레벨

	DivUI* weaponLv = new DivUI;
	weaponLv->SetPos(Vec2(335.f, 15.f));
	weaponLv->SetScale(Vec2(25.f, 25.f));
	weaponLv->InitTextModule(L"1", 23);
	weaponLv->SetFormat(DT_LEFT);
	weaponLv->SetFont(L"이순신 돋움체 B");
	weaponLv->SetTextColor(174, 172, 162);
	weaponLv->SetBold(600);
	
	equipPanel->AddChild(weaponLv);

	DivUI* shieldLv = new DivUI;
	shieldLv->SetPos(Vec2(425.f, 15.f));
	shieldLv->SetScale(Vec2(25.f, 25.f));
	shieldLv->InitTextModule(L"1", 23);
	shieldLv->SetFormat(DT_LEFT);
	shieldLv->SetFont(L"이순신 돋움체 B");
	shieldLv->SetTextColor(174, 172, 162);
	shieldLv->SetBold(600);

	equipPanel->AddChild(shieldLv);

	// 장비 그림

	DivUI* weaponPortrait = new DivUI;
	weaponPortrait->InitImageModule(L"Crusader Weapon", L"resource\\heros\\crusader\\sword1.png");
	weaponPortrait->SetScale(Vec2(72.f, 144.f));
	weaponPortrait->SetPos(Vec2(271.f, 53.f));

	equipPanel->AddChild(weaponPortrait);

	DivUI* shieldPortrait = new DivUI;
	shieldPortrait->InitImageModule(L"Crusader Armour", L"resource\\heros\\crusader\\armour1.png");
	shieldPortrait->SetScale(Vec2(72.f, 144.f));
	shieldPortrait->SetPos(Vec2(362.f, 53.f));

	equipPanel->AddChild(shieldPortrait);

	// 메인 패널 오른쪽
	DivUI* mainRightPanel = new DivUI;
	mainRightPanel->SetScale(Vec2(710.f, 360.f));
	mainRightPanel->SetPos(Vec2(710.f, 0.f));

	mainPanel->AddChild(mainRightPanel);

	// 인벤토리 파트
	DivUI* inventoryPanel = new DivUI;
	inventoryPanel->SetScale(Vec2(720.f, 360.f));
	inventoryPanel->SetPos(Vec2(0.f, 0.f));
	inventoryPanel->InitImageModule(L"D_INV_Panle", L"resource\\panels\\panel_inventory.png");
	inventoryPanel->SetName(L"shopInvPanel");
	inventoryPanel->InitUpdateValue(new ShopInvUpdateVal(inventoryPanel));

	mainRightPanel->AddChild(inventoryPanel);

	Vec2 startPos = Vec2(64.f, 30.f);

	float xOffset = 80.f;
	float yOffset = 160.f;

	for (int i = 0; i < 16; i++) {

		float coord_x = 24.f + ((i % 8) * 80.f);
		float coord_y = 30.f + (i / 8) * 160.f;

		DivUI* invItem = UIFactory::CreateInvItem(Vec2(coord_x, coord_y), L"item_food", L"resource\\items\\provision\\food.png", i);
		//invItem->CanTarget(false);

		inventoryPanel->AddChild(invItem);
	}

	DivUI* mapPanel = new DivUI;
	mapPanel->SetScale(Vec2(720.f, 360.f));
	mapPanel->SetPos(Vec2(0.f, 0.f));
	mapPanel->InitImageModule(L"MAP_PANEL_KEY", L"resource\\panels\\panel_map.png");
	mapPanel->SetCanRend(false);
	mapPanel->CanTarget(false);

	mainRightPanel->AddChild(mapPanel);

	// 맵, 인벤토리 버튼

	DivUI* mapBtn = new DivUI;
	mapBtn->SetScale(Vec2(44.f, 80.f));
	mapBtn->SetPos(Vec2(673.f, 160.f));

	mainRightPanel->AddChild(mapBtn);

	// 맵패널 렌드 끄기, 맵 패널 상호작용 모두 canTargetFalse로 & 인벤토리 패널 렌드 키기 및 인벤토리 패널 모두 catargetTrue
	DivUI* invBtn = new DivUI;
	invBtn->SetScale(Vec2(44.f, 82.f));
	invBtn->SetPos(Vec2(673.f, 244.f));

	mainRightPanel->AddChild(invBtn);

#pragma endregion

	pseudoUI->AddChild(itemDragger);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

	// 효과
	Camera::GetInst()->FadeIn(0.5f);
}

void Scene_Droom::update()
{
	Scene::update();

	if (KEY_TAP(KEY::ESC)) {
		ChangeScene(SCENE_TYPE::SHOP);
	}
}
