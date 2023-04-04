#include "stdafx.h"
#include "UIFactory.h"
#include "DivUI.h"
#include "BtnOutCom.h"
#include "BtnOverCom.h"
#include "GameMgr.h"
#include "CHero.h"
#include "CDungeon.h"
#include "Scene_DSelect.h"
#include "CQuest.h"
#include "RadioBtnClickCom.h"
#include "ForwardBtnClick.h"
#include "HeroBtnClick.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "SlotUp.h"
#include "SlotDown.h"
#include "ShopItemClick.h"
#include "BottomNavUpdate.h"
#include "InvItemClick.h"
#include "InvItemDown.h"
#include "InvItemUp.h"
#include "CInvItem.h"
#include "SideNavUpdateVal.h"

DivUI* UIFactory::CreateTitle()
{
	// 타이틀
	DivUI* estateTitle = new DivUI;
	estateTitle->SetScale(Vec2(893.f, 281.f));
	estateTitle->SetPos(Vec2(0.f, 0.f));
	estateTitle->CanTarget(false);
	estateTitle->InitImageModule(L"Darkest_Town_Title", L"resource\\Background\\estate_title.png");
	estateTitle->SetSrcAlpha(215);

	//타이틀 텍스트
	DivUI* titleTxt = new DivUI;
	titleTxt->SetScale(Vec2(600.f, 200.f));
	titleTxt->SetPos(Vec2(270.f, -3.f));
	titleTxt->InitTextModule(L"쥬신 136 영지", 40);
	titleTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	titleTxt->SetTextColor(93, 90, 80);
	//titleTxt->SetFont(L"이순신 돋움체 B");

	estateTitle->AddChild(titleTxt);

	return estateTitle;
}

DivUI* UIFactory::CreateTownDiscUI(Vec2 _vPos, const wstring& _titleName, const wstring& _disc)
{
	DivUI* panel = new DivUI;
	panel->SetScale(Vec2(208.f, 224.f));
	panel->SetScale(panel->GetScale() * 1.f);
	panel->SetPos(_vPos);
	panel->CanTarget(false);
	panel->InitImageModule(L"Darkest_Estate_namebg", L"resource\\Background\\name_bg.png");
	panel->SetSrcAlpha(255);

	// 텍스트 패널
	DivUI* title_txt = new DivUI;
	title_txt->SetScale(Vec2(100.f, 100.f));
	title_txt->SetScale(title_txt->GetScale() * 1.f);
	title_txt->SetPos(Vec2(70.f, 45.f));
	title_txt->CanTarget(false);
	title_txt->SetSrcAlpha(255);
	title_txt->InitTextModule(_titleName, 40);
	title_txt->SetTextColor(201, 185, 129);
	title_txt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	panel->AddChild(title_txt);

	// 설명 패널
	DivUI* disc_txt = new DivUI;
	disc_txt->SetScale(Vec2(200.f, 100.f));
	disc_txt->SetScale(disc_txt->GetScale() * 1.f);
	disc_txt->SetPos(Vec2(70.f, 85.f));
	disc_txt->CanTarget(false);
	disc_txt->SetSrcAlpha(255);
	disc_txt->InitTextModule(_disc, 27);
	disc_txt->SetTextColor(201, 201, 201);
	disc_txt->SetSecondFont();
	disc_txt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	panel->AddChild(disc_txt);

	return panel;
}

DivUI* UIFactory::CreateBottomNavUI()
{
#pragma region bottom_nav

	DivUI* bottomNavUI = new DivUI;
	bottomNavUI->SetScale(Vec2(1920.f, 138.f));
	bottomNavUI->SetPos(Vec2(0.f, 955.f));
	bottomNavUI->CanTarget(false);
	bottomNavUI->InitImageModule(L"Botton_nav_bg", L"resource\\UI\\progression_bar.png");
	bottomNavUI->InitUpdateValue(new BottomNavUpdate(bottomNavUI));
	bottomNavUI->SetName(L"bottom_nav");

#pragma region icon_list

	// 돈 아이콘

	DivUI* moneyIcon = new DivUI;
	moneyIcon->SetScale(Vec2(88.f, 88.f));
	moneyIcon->SetPos(Vec2(70.f, -5.f));
	moneyIcon->CanTarget(false);
	moneyIcon->InitImageModule(L"Money_Icon", L"resource\\UI\\currency.gold.large_icon.png");

	bottomNavUI->AddChild(moneyIcon);

	DivUI* moneyTxt = new DivUI;
	moneyTxt->SetScale(Vec2(188.f, 108.f));
	moneyTxt->SetPos(Vec2(170.f, 0.f));
	moneyTxt->CanTarget(false);

	int moneyCnt = GameMgr::GetInst()->GetMoney();

	moneyTxt->InitTextModule(to_wstring(moneyCnt), 40);
	moneyTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	moneyTxt->SetTextColor(201, 185, 129);

	bottomNavUI->AddChild(moneyTxt);

	// 흉상
	DivUI* bust = new DivUI;
	bust->SetScale(Vec2(40.f, 40.f));
	bust->SetPos(Vec2(400.f, 35.f));
	bust->CanTarget(false);
	bust->InitImageModule(L"bust_Icon", L"resource\\UI\\currency.bust.icon.png");

	bottomNavUI->AddChild(bust);

	DivUI* bustTxt = new DivUI;
	bustTxt->SetScale(Vec2(50.f, 40.f));
	bustTxt->SetPos(Vec2(440.f, 35.f));
	bustTxt->CanTarget(false);

	int bustCnt = GameMgr::GetInst()->GetBustCnt();

	bustTxt->InitTextModule(to_wstring(bustCnt), 20);
	bustTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	bustTxt->SetTextColor(201, 185, 129);
	bustTxt->SetFont(L"이순신 돋움체 B");

	bottomNavUI->AddChild(bustTxt);

	// 초상화
	DivUI* portrait = new DivUI;
	portrait->SetScale(Vec2(40.f, 40.f));
	portrait->SetPos(Vec2(480.f, 35.f));
	portrait->CanTarget(false);
	portrait->InitImageModule(L"portrait_Icon", L"resource\\UI\\currency.portrait.icon.png");

	bottomNavUI->AddChild(portrait);

	DivUI* portraitTxt = new DivUI;
	portraitTxt->SetScale(Vec2(50.f, 40.f));
	portraitTxt->SetPos(Vec2(520.f, 35.f));
	portraitTxt->CanTarget(false);

	int portraitCnt = GameMgr::GetInst()->GetBustCnt();

	portraitTxt->InitTextModule(to_wstring(portraitCnt), 20);
	portraitTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	portraitTxt->SetTextColor(201, 185, 129);
	portraitTxt->SetFont(L"이순신 돋움체 B");

	bottomNavUI->AddChild(portraitTxt);

	// 증서
	DivUI* certificate = new DivUI;
	certificate->SetScale(Vec2(40.f, 40.f));
	certificate->SetPos(Vec2(560.f, 35.f));
	certificate->CanTarget(false);
	certificate->InitImageModule(L"certificate_Icon", L"resource\\UI\\currency.deed.icon.png");

	bottomNavUI->AddChild(certificate);

	DivUI* certificateTxt = new DivUI;
	certificateTxt->SetScale(Vec2(50.f, 40.f));
	certificateTxt->SetPos(Vec2(600.f, 35.f));
	certificateTxt->CanTarget(false);

	int certCnt = GameMgr::GetInst()->GetCertCnt();

	certificateTxt->InitTextModule(to_wstring(certCnt), 20);
	certificateTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	certificateTxt->SetTextColor(201, 185, 129);
	certificateTxt->SetFont(L"이순신 돋움체 B");

	bottomNavUI->AddChild(certificateTxt);

	// 문장
	DivUI* buckler = new DivUI;
	buckler->SetScale(Vec2(40.f, 40.f));
	buckler->SetPos(Vec2(640.f, 35.f));
	buckler->CanTarget(false);
	buckler->InitImageModule(L"crest_Icon", L"resource\\UI\\currency.crest.icon.png");

	bottomNavUI->AddChild(buckler);

	DivUI* bucklerTxt = new DivUI;
	bucklerTxt->SetScale(Vec2(50.f, 40.f));
	bucklerTxt->SetPos(Vec2(680.f, 35.f));
	bucklerTxt->CanTarget(false);

	int bucklerCnt = GameMgr::GetInst()->GetBucklerCnt();

	bucklerTxt->InitTextModule(to_wstring(bucklerCnt), 20);
	bucklerTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	bucklerTxt->SetTextColor(201, 185, 129);
	bucklerTxt->SetFont(L"이순신 돋움체 B");

	bottomNavUI->AddChild(bucklerTxt);

#pragma endregion

	// 출정 버튼

	DivUI* forwardBtn = new DivUI;
	forwardBtn->SetScale(Vec2(312.f, 52.f));
	forwardBtn->SetPos(Vec2(810.f, 25.f));
	forwardBtn->CanTarget(true);
	forwardBtn->InitImageModule(L"forward_btn", L"resource\\UI\\foward_btn.png");
	forwardBtn->InitTextModule(L"출정", 35);
	forwardBtn->SetTextColor(184, 29, 11);
	forwardBtn->InitOnMouseClick(new ForwardBtnClick);

	bottomNavUI->AddChild(forwardBtn);

	DivUI* forwardBtnOver = new DivUI;
	forwardBtnOver->SetScale(Vec2(311.f, 24.f));
	forwardBtnOver->SetPos(Vec2(810.f, 12.f));
	forwardBtnOver->CanTarget(false);
	forwardBtnOver->SetCanRend(false);
	forwardBtnOver->InitImageModule(L"forward_btn_over", L"resource\\UI\\progression_forward_selected_overlay.png");

	forwardBtn->InitOnMouseOver(new BtnOverCom(forwardBtnOver));
	forwardBtn->InitOnMouseOut(new BtnOutCom(forwardBtnOver));

	bottomNavUI->AddChild(forwardBtnOver);

	return bottomNavUI;
}

DivUI* UIFactory::CreateSideNavUI()
{
	DivUI* heroSideNav = new DivUI;
	heroSideNav->SetScale(Vec2(355.f, 832.f));
	heroSideNav->SetPos(Vec2(1565.f, 100.f));
	heroSideNav->CanTarget(true);
	heroSideNav->InitUpdateValue(new SideNavUpdateVal(heroSideNav));
	heroSideNav->SetName(L"heroSideNav");
	heroSideNav->CanTarget(false);

	const vector<CHero*>& curLoster = GameMgr::GetInst()->GetCurLoster();

	for (int i = 0; i < curLoster.size(); i++) {

		CHero* hero = curLoster[i];

#pragma region hero_panel

		DivUI* heroPanel = new DivUI;
		heroPanel->SetScale(Vec2(355.f, 104.f));
		heroPanel->SetPos(Vec2(0.f, 0 + i * (105.f) ) );
		heroPanel->InitImageModule(L"hero_roster_panel_bg", L"resource\\roster\\roster_bg.png");
		heroPanel->InitOneMouseDown(new HeroBtnClick(hero));
		heroPanel->SetId(hero->GetPKey());
		heroPanel->SetName(L"heroPanel");
		
		DivUI* heroPortrait = new DivUI;
		heroPortrait->SetScale(Vec2(85.f, 85.f));
		heroPortrait->SetPos(Vec2(20.f, 8.f));
		heroPortrait->InitImageModule(hero->GetKey(), hero->GetPath());
		heroPortrait->CanTarget(false);

		heroPanel->AddChild(heroPortrait);

		DivUI* heroTxt = new DivUI;
		heroTxt->SetScale(Vec2(200.f, 50.f));
		heroTxt->SetPos(Vec2(120.f, 0.f));
		heroTxt->InitTextModule(hero->GetName(), 25);
		heroTxt->SetBold(FW_MEDIUM);
		heroTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		heroTxt->SetTextColor(191, 172, 105);
		heroTxt->CanTarget(false);

		heroPanel->AddChild(heroTxt);

		for (int i = 0; i < 10; i++) {

			DivUI* stressUI = new DivUI;
			stressUI->SetScale(Vec2(9.f, 10.f));
			stressUI->SetScale(stressUI->GetScale() * 1.0f);
			stressUI->SetPos(Vec2(120.f + (i * 10), 43.f));
			stressUI->InitImageModule(L"Stress_empty_bg", L"resource\\overay\\stress_empty.png");
			stressUI->CanTarget(false);

			heroPanel->AddChild(stressUI);
		}

		int curStress = hero->GetCurStress();
		if (curStress > 100) curStress = 100;

		for (int i = 0; i < curStress / 10; i++) {
			DivUI* stressFullUI = new DivUI;
			stressFullUI->SetScale(Vec2(9.f, 10.f));
			stressFullUI->SetScale(stressFullUI->GetScale() * 1.0f);
			stressFullUI->SetPos(Vec2(120.f + (i * 10), 43.f));
			stressFullUI->InitImageModule(L"Stress_full_bg", L"resource\\overay\\stress_full.png");
			stressFullUI->CanTarget(false);

			heroPanel->AddChild(stressFullUI);
		}

		int curStress2 = hero->GetCurStress();
		if (curStress2 <= 100) curStress2 = 0;

		curStress2 = curStress2 - 100;


		for (int i = 0; i < curStress2 / 10; i++) {
			DivUI* stressOverUI = new DivUI;
			stressOverUI->SetScale(Vec2(9.f, 10.f));
			stressOverUI->SetScale(stressOverUI->GetScale() * 1.0f);
			stressOverUI->SetPos(Vec2(120.f + (i * 10), 43.f));
			stressOverUI->InitImageModule(L"Stress_Over_bg", L"resource\\overay\\stress_over.png");
			stressOverUI->CanTarget(false);

			heroPanel->AddChild(stressOverUI);
		}

		DivUI* weaponLv = new DivUI;
		weaponLv->SetScale(Vec2(30.f, 30.f));
		weaponLv->SetPos(Vec2(145.f, 66.f));
		weaponLv->InitTextModule(hero->GetEquipLevel(), 22);
		weaponLv->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		weaponLv->SetFont(L"이순신 돋움체 B");
		weaponLv->SetBold(FW_BOLD);
		weaponLv->SetTextColor(172, 170, 160);
		weaponLv->CanTarget(false);

		heroPanel->AddChild(weaponLv);

		DivUI* shieldLv = new DivUI;
		shieldLv->SetScale(Vec2(30.f, 30.f));
		shieldLv->SetPos(Vec2(212.f, 66.f));
		shieldLv->InitTextModule(hero->GetArmorLevel(), 22);
		shieldLv->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		shieldLv->SetFont(L"이순신 돋움체 B");
		shieldLv->SetBold(FW_BOLD);
		shieldLv->SetTextColor(172, 170, 160);
		shieldLv->CanTarget(false);

		heroPanel->AddChild(shieldLv);

		float curExpScale = hero->GetCurExp() * 5;
		float curExpStartHeight = 85 - curExpScale;

		DivUI* levelFull = new DivUI;
		levelFull->SetScale(Vec2(27.f,curExpScale));
		levelFull->SetPos(Vec2(255.f, curExpStartHeight));
		levelFull->InitImageModule(L"Level_full_bg", L"resource\\roster\\hp_full.png");
		levelFull->CanTarget(false);

		heroPanel->AddChild(levelFull);

		DivUI* levelBar = new DivUI;
		levelBar->SetScale(Vec2(37.f, 59.f));
		levelBar->SetPos(Vec2(255.f, 35.f));
		levelBar->InitImageModule(L"Level_mask_bg", L"resource\\roster\\level_bar.png");
		levelBar->CanTarget(false);

		heroPanel->AddChild(levelBar);

		DivUI* levelNum = new DivUI;
		levelNum->SetScale(Vec2(64.f, 64.f));
		levelNum->SetPos(Vec2(240.f, 0.f));
		levelNum->InitImageModule(L"Level_Number_bg", L"resource\\roster\\lv2_num.png");
		levelNum->CanTarget(false);

		heroPanel->AddChild(levelNum);

		DivUI* levelTxt = new DivUI;
		levelTxt->SetScale(Vec2(64.f, 64.f));
		levelTxt->SetPos(Vec2(240.f, 0.f));
		levelTxt->InitTextModule(L"1", 25);
		levelTxt->SetFont(L"이순신 돋움체 B");
		levelTxt->SetTextColor(0, 0, 0);
		levelTxt->SetBold(FW_BOLD);
		levelTxt->CanTarget(false);

		heroPanel->AddChild(levelTxt);

		heroSideNav->AddChild(heroPanel);

#pragma endregion

	}

	heroSideNav->updateValue();

	return heroSideNav;
}

DivUI* UIFactory::CreateSlotContainer(Vec2 _vPos, DivUI* _dragRenderer)
{
	DivUI* slotRect = new DivUI;
	slotRect->SetScale(Vec2(340.f, 85.f));
	slotRect->SetPos(_vPos);

	const array<CHero*, 4> squad = GameMgr::GetInst()->GetSquad();

	for (int i = 0; i < 4; i++) {
		DivUI* slot = new DivUI;
		slot->SetScale(Vec2(85.f, 85.f));
		slot->SetPos(Vec2(0.f + (i * 85.f), 0.f));
		slot->InitImageModule(L"slot_bg", L"resource\\roster\\slot1.png");
		slot->CanTarget(false);

		slotRect->AddChild(slot);

		// 던전 선택 씬에서만 이벤트 등록해줘야 할 수도 있음
		DivUI* heroPortrait = new DivUI;
		heroPortrait->SetScale(Vec2(68.f, 68.f));
		heroPortrait->SetPos(Vec2(9.f, 9.f));

		if (SceneMgr::GetInst()->GetCurScene()->GetName() == L"Scene_DSelect") {
			heroPortrait->InitOnMouseUp(new SlotUp(heroPortrait, _dragRenderer, i, slotRect));
			heroPortrait->InitOneMouseDown(new SlotDown(heroPortrait, _dragRenderer, i));
		}

		heroPortrait->SetCanRendImg(false);

		if (nullptr != squad[i]) {
			heroPortrait->InitImageModule(squad[i]->GetKey(), squad[i]->GetPath());
			heroPortrait->SetCanRendImg(true);
			heroPortrait->SetName(squad[i]->GetName());
		}

		slot->AddChild(heroPortrait);
	}

	return slotRect;
}

DivUI* UIFactory::DungeonPgPanel(Vec2 _vPos, CDungeon* _dungeon, Scene_DSelect* _dScene)
{
	DivUI* dunProgBar = new DivUI;
	dunProgBar->SetScale(Vec2(282.f, 84.f));
	dunProgBar->InitImageModule(L"Dungeion_Prog_bar", L"resource\\quest_select\\dungeon_progressionbar.png");
	dunProgBar->SetPos(_vPos);

	DivUI* dunTitle = new DivUI;
	dunTitle->SetScale(Vec2(100.f, 35.f));
	dunTitle->SetPos(Vec2(96.f, 7.f));
	dunTitle->InitTextModule(_dungeon->GetName(), 25);
	dunTitle->SetTextColor(200, 180, 110);
	dunTitle->SetFormat(DT_RIGHT);

	dunProgBar->AddChild(dunTitle);

	DivUI* dunLevel = new DivUI;
	dunLevel->SetScale(Vec2(35.f, 35.f));
	dunLevel->SetPos(Vec2(206.f, 29.f));
	dunLevel->InitTextModule(L"0", 20);
	dunLevel->SetFont(L"이순신 돋움체 B");
	dunLevel->SetTextColor(172, 170, 160);
	dunLevel->SetBold(FW_NORMAL);

	dunProgBar->AddChild(dunLevel);

	const vector<CQuest*>& quests = _dungeon->GetQuests();

	for (int i = 0; i < quests.size(); i++) {

		float x_offset = 60.f;

		DivUI* spanBg = new DivUI;
		spanBg->SetScale(Vec2(192.f, 192.f));
		spanBg->SetScale(spanBg->GetScale() * 0.8f);
		spanBg->SetPos(Vec2(-40.f + (i * x_offset), 10.f));
		spanBg->InitImageModule(L"Quest_Select_Selected", L"resource\\quest_select\\quest_select_selected.png");
		spanBg->SetCanRend(false);
		spanBg->CanTarget(false);
		spanBg->SetName(_dungeon->GetName() + to_wstring(i) + L"bg");
		_dScene->radioBtns.push_back(spanBg);

		dunProgBar->AddChild(spanBg);

		DivUI* questSpan = new DivUI;
		questSpan->SetScale(Vec2(96.f, 96.f));
		questSpan->SetScale(questSpan->GetScale() * 0.8f);
		questSpan->SetPos(Vec2(0.f + (i * x_offset), 50.f));
		questSpan->InitImageModule(L"Quest_Select_Pan", L"resource\\quest_select\\quest_select_0.png");
		questSpan->CanTarget(false);

		dunProgBar->AddChild(questSpan);

		DivUI* spanFill = new DivUI;
		spanFill->SetScale(Vec2(48.f, 48.f));
		spanFill->SetScale(questSpan->GetScale() * 0.6f);
		spanFill->SetPos(Vec2(15.f + (i * x_offset), 65.f));
		spanFill->InitImageModule(quests[i]->GetFillKey(), quests[i]->GetFillPath());
		spanFill->InitOnMouseClick(new RadioBtnClickCom(spanBg, quests[i], _dScene));

		dunProgBar->AddChild(spanFill);
	}

	return dunProgBar;
}

DivUI* UIFactory::CreateShopItem(Vec2 _vPos, wstring _key, wstring _path, int _count, int _cost, DivUI* shopInvPanel)
{
	DivUI* itContainer = new DivUI;
	itContainer->SetScale(Vec2(72.f, 170.f));
	itContainer->SetPos(_vPos);
	itContainer->CanTarget(false);

	DivUI* foodIt = new DivUI;
	foodIt->SetScale(Vec2(72.f, 144.f));
	foodIt->SetPos(Vec2(0.f, 0.f));
	foodIt->InitImageModule(_key, _path);
	foodIt->InitOnMouseClick(new ShopItemClick(foodIt, shopInvPanel, _cost));

	itContainer->AddChild(foodIt);

	DivUI* foodCount = new DivUI;
	foodCount->SetScale(Vec2(40.f, 40.f));
	foodCount->SetPos(Vec2(8.f, 0.f));
	foodCount->InitTextModule(to_wstring(_count), 25);
	foodCount->SetTextColor(194, 174, 107);
	foodCount->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	foodCount->CanTarget(false);

	foodIt->AddChild(foodCount);

	DivUI* goldIcon = new DivUI;
	goldIcon->SetScale(Vec2(24.f, 24.f));
	goldIcon->SetPos(Vec2(0.f, 150.f));
	goldIcon->InitImageModule(L"gold_icon", L"resource\\items\\goldicon.png");
	goldIcon->CanTarget(false);

	itContainer->AddChild(goldIcon);

	DivUI* countText = new DivUI;
	countText->SetScale(Vec2(36.f, 20.f));
	countText->SetPos(Vec2(30.f, 150.f));
	countText->InitTextModule(to_wstring(_cost), 20);
	countText->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	countText->SetFont(L"이순신 돋움체 B");
	countText->SetTextColor(194, 174, 107);
	countText->CanTarget(false);

	itContainer->AddChild(countText);

	return itContainer;
}

DivUI* UIFactory::CreateInvItem(Vec2 _vPos, wstring _key, wstring _path, int _index)
{
	DivUI* invItem = new DivUI;
	invItem->SetScale(Vec2(72.f, 144.f));
	invItem->SetPos(_vPos);
	invItem->CanTarget(true);
	

	if (SceneMgr::GetInst()->GetCurScene()->GetName() == L"Scene_Shop") {
		invItem->InitOneMouseDown(new InvItemDown(invItem, _index));
		invItem->InitOnMouseClick(new InvItemClick(invItem, _index));
		invItem->InitOnMouseUp(new InvItemUp(invItem, _index));
	}
	else if (SceneMgr::GetInst()->GetCurScene()->GetName() == L"Scene_Droom") {
		invItem->InitOneMouseDown(new InvItemDown(invItem, _index));
		invItem->InitOnMouseUp(new InvItemUp(invItem, _index));
	}

	DivUI* invCount = new DivUI;
	invCount->SetScale(Vec2(40.f, 40.f));
	invCount->SetPos(Vec2(8.f, 0.f));
	invCount->InitTextModule(to_wstring(_index), 25);
	invCount->SetTextColor(194, 174, 107);
	invCount->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	invCount->CanTarget(false);
	invCount->SetCanRend(false);

	invItem->AddChild(invCount);

	return invItem;
}

DivUI* UIFactory::CreateToolTip(Vec2 _vPos, CInvItem* _invItem)
{
	DivUI* toolTip = new DivUI;
	toolTip->SetPos(_vPos);
	toolTip->SetScale(Vec2(220.f, 40.f + _invItem->GetRowNum() * 23.f));
	toolTip->InitImageModule(L"toolTip_Image", L"resource\\Background\\tooltip_crop.png");
	toolTip->SetSrcAlpha(215);
	toolTip->CanTarget(true);
	toolTip->SetCanRend(false);

	DivUI* toolTipTitle = new DivUI;
	toolTipTitle->SetPos(Vec2(0.f, 10.f));
	toolTipTitle->SetScale(Vec2(220.f, 22.f));
	toolTipTitle->InitTextModule(_invItem->GetTitle(), 22);
	toolTipTitle->SetFont(L"이순신 돋움체 M");
	toolTipTitle->SetTextColor(194, 174, 107);

	toolTip->AddChild(toolTipTitle);

	DivUI* toolTipDisc = new DivUI;
	toolTipDisc->SetPos(Vec2(0.f, 35.f));
	toolTipDisc->SetScale(Vec2(220.f, 150.f));
	toolTipDisc->InitTextModule(_invItem->GetDisc(), 22);
	toolTipDisc->SetFont(L"이순신 돋움체 M");
	toolTipDisc->SetTextColor(172, 170, 160);
	toolTipDisc->SetFormat(DT_CENTER | DT_EDITCONTROL);

	toolTip->AddChild(toolTipDisc);

	return toolTip;
}
