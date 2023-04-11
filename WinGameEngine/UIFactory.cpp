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
#include "CSquadDiv.h"
#include "CHeroDiv.h"
#include "HeroDivClick.h"
#include "CSelectedOverlay.h"
#include "CMonSquad.h"
#include "CMonDiv.h"
#include "MonDivOnClick.h"
#include "CDarkMonster.h"
#include "MainLeftUpdateCom.h"
#include "SkillContainerUpdate.h"
#include "SkillOnclick.h"
#include "CSkill.h"
#include "ShopInvUpdateVal.h"
#include "MapBtnClick.h"
#include "InvBtnClick.h"
#include "CMap.h"
#include "CNode.h"
#include "CRoom.h"
#include "CPathNode.h"
#include "DroomUI.h"
#include "DpathUI.h"
#include "RoomUIClick.h"
#include "DMapUI.h"
#include "AnimatorDK.h"
#include "HEffectDiv.h"
#include "MEffectDiv.h"
#include "DamageDiv.h"

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
	invCount->SetViewAffected(false);

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

CSquadDiv* UIFactory::CreateSquadDiv()
{
	GameMgr* mgr = GameMgr::GetInst();
	mgr->MoveSquadRight();

	const array<CHero*, 4> curSquad = mgr->GetSquad();

	int squadNum = mgr->GetSquadNum();
	float heroXOffset = 170.f;

	CSquadDiv* squad = new CSquadDiv;
	squad->SetScale(Vec2(heroXOffset * squadNum, 500.f));
	squad->SetPos(Vec2(800.f - (squadNum * heroXOffset), 170.f));
	squad->SetName(L"CSquadDiv");
	squad->SetCamAffected(true);

	for (int i = 0; i < squadNum; i++) {

		int realIndex = i + (curSquad.size() - squadNum);

		CHero* heroVal = curSquad[i + (curSquad.size() - squadNum)];

		CHeroDiv* hero = new CHeroDiv(heroVal);
		hero->SetPos(Vec2(i * heroXOffset, 0.f));
		hero->SetScale(Vec2(heroXOffset, 500.f));
		hero->SetId(realIndex);
		hero->SetCamAffected(true);

		// 클릭당하면 현재 인덱스로 게임매니저 포커싱을 바꾸고 셀렉티드 오버레이도 켜주고
		// MainLeftPanel도 업데이트해줌 MainLeftPanel은 그냥 pseudoUI로부터 가져오자
		hero->InitOnMouseClick(new HeroDivClick(squad, realIndex));

		squad->AddChild(hero);
		squad->AddHero(hero);

		HEffectDiv* heroEffect = new HEffectDiv(heroVal);
		heroEffect->SetPos(Vec2(0.f, 0.f));
		heroEffect->SetScale(hero->GetScale());
		heroEffect->SetId(realIndex);
		heroEffect->SetCamAffected(true);
		//heroEffect->SetViewAffected(true);
		heroEffect->CanTarget(false);
		heroEffect->CreateAnimator(new AnimatorDK);
		heroEffect->Init();
		heroEffect->SetName(L"heroEffect");

		hero->SetEffect(heroEffect);
		hero->AddChild(heroEffect);

		CSelectedOverlay* heroOverlay = new CSelectedOverlay;
		heroOverlay->SetPos(Vec2(93.f, 515.f));
		heroOverlay->SetScale(Vec2(175.f, 72.f));
		heroOverlay->SetScale(heroOverlay->GetScale() * 0.9f);
		heroOverlay->SetCanRend(false);

		if (i + (curSquad.size() - squadNum) == mgr->GetFocusIndex()) {
			heroOverlay->SetCanRend(true);
		}

		hero->SetOverlay(heroOverlay);
		hero->AddChild(heroOverlay);

		Vec2 overlaybase = Vec2(40.f, 535.f);

		DivUI* focusedOverlay = new DivUI;
		focusedOverlay->SetPos(Vec2(overlaybase.x - 5.f, overlaybase.y - 72.f));
		focusedOverlay->SetScale(Vec2(113.f, 76.f));
		focusedOverlay->InitImageModule(L"Attack_focused", L"resource\\overay\\target_1_crop.png");
		focusedOverlay->SetCamAffected(true);
		focusedOverlay->SetName(L"focusedOverlay_hero");
		focusedOverlay->SetCanRend(false);

		hero->SetAttackedOverlay(focusedOverlay);
		hero->AddChild(focusedOverlay);

		DivUI* hpBar = new DivUI;
		hpBar->SetPos(Vec2(overlaybase.x, overlaybase.y - 15.f));
		hpBar->SetScale(Vec2(100.f, 10.f));
		hpBar->InitImageModule(L"HP_EMPTYBAR_BG", L"resource\\overay\\stress_pip_empty copy.png");
		hpBar->SetCamAffected(true);
		hpBar->SetName(L"hpBar");

		hero->AddChild(hpBar);

		DivUI* curHp = new DivUI;
		curHp->SetPos(Vec2(overlaybase.x, overlaybase.y - 15.f));
		// 스케일이 체력 비율에 따라 변화해야 하며 기준 스케일은 100

		float hpPercent = heroVal->GetCurHp() / (float)heroVal->GetHp();

		curHp->SetScale(Vec2(100.f * hpPercent, 10.f));
		curHp->InitImageModule(L"HP_BASEBAR_BG", L"resource\\overay\\health_pip_full.png");
		curHp->SetCamAffected(true);

		hero->SetCurHpBar(curHp);
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

		int curStress = heroVal->GetCurStress();
		if (curStress > 100) curStress = 100;

		for (int i = 0; i < curStress / 10; i++) {
			DivUI* stressFullUI = new DivUI;
			stressFullUI->SetScale(Vec2(9.f, 10.f));
			stressFullUI->SetScale(stressFullUI->GetScale() * 1.0f);
			stressFullUI->SetPos(Vec2(overlaybase.x + (i * 10), overlaybase.y));
			stressFullUI->InitImageModule(L"Stress_full_bg", L"resource\\overay\\stress_full.png");
			stressFullUI->CanTarget(false);
			stressFullUI->SetCamAffected(true);

			hero->AddChild(stressFullUI);
		}

		int curStress2 = heroVal->GetCurStress();
		if (curStress2 <= 100) curStress2 = 0;

		curStress2 = curStress2 - 100;

		for (int i = 0; i < curStress2 / 10; i++) {
			DivUI* stressOverUI = new DivUI;
			stressOverUI->SetScale(Vec2(9.f, 10.f));
			stressOverUI->SetScale(stressOverUI->GetScale() * 1.0f);
			stressOverUI->SetPos(Vec2(overlaybase.x + (i * 10), overlaybase.y));
			stressOverUI->InitImageModule(L"Stress_Over_bg", L"resource\\overay\\stress_over.png");
			stressOverUI->CanTarget(false);
			stressOverUI->SetCamAffected(true);

			hero->AddChild(stressOverUI);
		}

	}

	return squad;
}

CMonSquad* UIFactory::CreateMonSquadDiv()
{
	GameMgr* mgr = GameMgr::GetInst();

	const array<CDarkMonster*, 4> monSquad = mgr->GetMonSquad();

	int monSquadNum = mgr->GetMonSquadNum();

	float monsterXOffset = 150.f;

	CMonSquad* monSquadDiv = new CMonSquad;
	monSquadDiv->SetScale(Vec2(monsterXOffset * monSquadNum, 500.f));
	monSquadDiv->SetPos(Vec2(1050.f, 170.f));
	monSquadDiv->SetName(L"CMonSquad");
	monSquadDiv->SetCanRend(false);
	monSquadDiv->SetCamAffected(true);

	for (int i = 0; i < monSquadNum; i++) {

		// 임시 테스트에서는 nullptr일수 있음
		CDarkMonster* monster = monSquad[i];

		CMonDiv* monDiv = new CMonDiv(monster);
		monDiv->SetPos(Vec2(i * monsterXOffset, 0.f));
		monDiv->SetScale(Vec2(monsterXOffset, 500.f));
		// 몬스터 Div는 왼쪽방향을 바라보기때문에 인덱스 순서가 일치함
		monDiv->SetId(i);
		monDiv->InitOnMouseClick(new MonDivOnClick(monDiv));
		monDiv->CanTarget(false);
		monDiv->SetCamAffected(true);

		monSquadDiv->AddMonster(monDiv);
		monSquadDiv->AddChild(monDiv);

		MEffectDiv* mEffect = new MEffectDiv(monster);
		mEffect->SetPos(Vec2(0.f, 0.f));
		mEffect->SetScale(monDiv->GetScale());
		mEffect->SetId(i);
		mEffect->SetCamAffected(true);
		//heroEffect->SetViewAffected(true);
		mEffect->CanTarget(false);
		mEffect->CreateAnimator(new AnimatorDK);
		mEffect->Init();
		mEffect->SetName(L"mEffect");

		monDiv->SetEffect(mEffect);
		monDiv->AddChild(mEffect);



		Vec2 overlaybase = Vec2(55.f, 535.f);

		CSelectedOverlay* monOverlay = new CSelectedOverlay;
		monOverlay->SetPos(Vec2(113.f, 515.f));
		monOverlay->SetScale(Vec2(175.f, 72.f));
		monOverlay->SetScale(monOverlay->GetScale() * 0.9f);
		monOverlay->SetCanRend(false);

		monDiv->SetOverlay(monOverlay);
		monDiv->AddChild(monOverlay);

		DivUI* focusedOverlay = new DivUI;
		focusedOverlay->SetPos(Vec2(overlaybase.x - 5.f, overlaybase.y - 72.f));
		focusedOverlay->SetScale(Vec2(113.f, 76.f));
		focusedOverlay->InitImageModule(L"Attack_focused", L"resource\\overay\\target_1_crop.png");
		focusedOverlay->SetCamAffected(true);
		focusedOverlay->SetName(L"focusedOverlay_monster");
		focusedOverlay->SetCanRend(false);
		focusedOverlay->SetId(i);

		monDiv->AddChild(focusedOverlay);

		DivUI* hpBar = new DivUI;
		hpBar->SetPos(Vec2(overlaybase.x, overlaybase.y - 15.f));
		hpBar->SetScale(Vec2(100.f, 10.f));
		hpBar->InitImageModule(L"HP_EMPTYBAR_BG", L"resource\\overay\\stress_pip_empty copy.png");
		hpBar->SetCamAffected(true);

		monDiv->AddChild(hpBar);

		DivUI* curHp = new DivUI;
		curHp->SetPos(Vec2(overlaybase.x, overlaybase.y - 15.f));
		// 스케일이 체력 비율에 따라 변화해야 하며 기준 스케일은 100

		float hpPercent = monster->GetCurHp() / (float)monster->GetMaxHp();

		curHp->SetScale(Vec2(100.f * hpPercent, 10.f));
		curHp->InitImageModule(L"HP_BASEBAR_BG", L"resource\\overay\\health_pip_full.png");
		curHp->SetCamAffected(true);

		monDiv->SetCuHpBar(curHp);
		monDiv->AddChild(curHp);
	}

	return monSquadDiv;
}

DivUI* UIFactory::CreateDungeonPanel()
{
	GameMgr* mgr = GameMgr::GetInst();
	const array<CHero*, 4> curSquad = mgr->GetSquad();

	CHero* heroVal = curSquad[mgr->GetFocusIndex()];

	DivUI* panel = new DivUI;
	panel->SetPos(Vec2(0.f, 720.f));
	panel->SetScale(Vec2(1920.f, 360.f));
	panel->CanTarget(false);
	panel->SetViewAffected(false);

	DivUI* leftSide = new DivUI;
	leftSide->SetScale(Vec2(250.f, 360.f));
	leftSide->SetPos(Vec2(0.f, 0.f));
	leftSide->CanTarget(false);
	leftSide->InitImageModule(L"Side_Decor_Panel", L"resource\\panels\\side_decor.png");
	leftSide->SetViewAffected(false);

	panel->AddChild(leftSide);

	DivUI* rightSide = new DivUI;
	rightSide->SetScale(Vec2(250.f, 360.f));
	rightSide->SetPos(Vec2(1920.f - 250.f, 0.f));
	rightSide->CanTarget(false);
	rightSide->InitImageModule(L"Side_Decor_Panel2", L"resource\\panels\\side_decor2.png");
	rightSide->SetViewAffected(false);

	panel->AddChild(rightSide);

	DivUI* mainPanel = new DivUI;
	mainPanel->SetScale(Vec2(1420.f, 360.f));
	mainPanel->SetPos(Vec2(250.f, 0.f));
	mainPanel->SetViewAffected(false);

	panel->AddChild(mainPanel);

	DivUI* mainLeftPanel = new DivUI;
	mainLeftPanel->SetScale(Vec2(710.f, 360.f));
	mainLeftPanel->SetPos(Vec2(0.f, 0.f));
	mainLeftPanel->SetName(L"mainLeftPanel");
	// 업데이트는 그냥 자기 자신에서 처리하고 히어로는 현재 포커싱된 인덱스 기반으로
	// 게임 매니저에서 가져오자
	mainLeftPanel->InitUpdateValue(new MainLeftUpdateCom(mainLeftPanel));
	mainLeftPanel->SetViewAffected(false);

	mainPanel->AddChild(mainLeftPanel);

	// 스킬 패널 파트

	DivUI* skillPanel = new DivUI;
	skillPanel->SetScale(Vec2(710.f, 134.f));
	skillPanel->SetPos(Vec2(0.f, 0.f));
	skillPanel->InitImageModule(L"SKill_Panel2", L"resource\\panels\\skill_panel2.png");
	skillPanel->SetViewAffected(false);

	mainLeftPanel->AddChild(skillPanel);

	DivUI* heroPortrait = new DivUI;
	heroPortrait->SetScale(Vec2(85.f, 85.f));
	heroPortrait->SetPos(Vec2(23.f, 33.f));
	heroPortrait->InitImageModule(heroVal->GetKey(), heroVal->GetPath());
	heroPortrait->SetName(L"heroPortrait");
	heroPortrait->SetViewAffected(false);

	skillPanel->AddChild(heroPortrait);

	DivUI* heroName = new DivUI;
	heroName->SetScale(Vec2(125.f, 25.f));
	heroName->SetPos(Vec2(125.f, 45.f));
	heroName->InitTextModule(heroVal->GetName(), 25);
	heroName->SetFormat(DT_RIGHT);
	heroName->SetTextColor(177, 161, 108);
	heroName->SetName(L"heroName");
	heroName->SetViewAffected(false);

	skillPanel->AddChild(heroName);

	DivUI* heroJob = new DivUI;
	heroJob->SetScale(Vec2(100.f, 20.f));
	heroJob->SetPos(Vec2(150.f, 75.f));
	heroJob->InitTextModule(heroVal->GetJobName(), 20);
	heroJob->SetFormat(DT_RIGHT);
	heroJob->SetTextColor(106, 105, 98);
	heroJob->SetFont(L"이순신 돋움체 M");
	heroJob->SetName(L"heroJob");
	heroJob->SetViewAffected(false);

	skillPanel->AddChild(heroJob);



	// 스킬 구현 파트

	DivUI* skillContainer = new DivUI;
	skillContainer->SetPos(Vec2(270.f, 35.f));
	skillContainer->SetScale(Vec2(380.f, 72.f));
	skillContainer->SetName(L"skillContainer");
	skillContainer->InitUpdateValue(new SkillContainerUpdate(skillContainer));
	skillContainer->SetViewAffected(false);

	skillPanel->AddChild(skillContainer);

	for (int i = 0; i < 4; i++) {
		DivUI* skill1 = new DivUI;
		skill1->SetScale(Vec2(72.f, 72.f));
		skill1->SetPos(Vec2((i * 76.f), 0.f));
		skill1->InitOnMouseClick(new SkillOnclick(skill1));
		skill1->SetId(i);
		skill1->SetViewAffected(false);

		CSkill* heroSkill = heroVal->GetCurSkills()[i];

		if (heroSkill->IsAlive()) {
			skill1->InitImageModule(heroSkill->GetSkillName(), heroSkill->GetSkillPath());
		}
		else {
			skill1->InitImageModule(heroSkill->GetSkillName() + L"_gray", heroSkill->GetGraySkillPath());
		}

		skillContainer->AddChild(skill1);
	}

	for (int i = 0; i < 4; i++) {
		DivUI* skillSelected = new DivUI;
		skillSelected->SetScale(Vec2(110.f, 110.f));
		skillSelected->SetScale(skillSelected->GetScale() * 0.9f);
		skillSelected->SetPos(Vec2((i * 76.f) - 14.f, 0.f - 14.f));
		skillSelected->InitImageModule(L"skill_selected", L"resource\\panels\\icons_ability\\selected_ability.png");
		skillSelected->SetCanRend(false);
		skillSelected->SetName(L"skillSelected");
		skillSelected->SetId(i);
		skillSelected->CanTarget(false);
		skillSelected->SetViewAffected(false);

		skillContainer->AddChild(skillSelected);
	}

	DivUI* skill = new DivUI;
	skill->SetScale(Vec2(72.f, 72.f));
	skill->SetPos(Vec2((4 * 76.f), 0.f));
	skill->InitImageModule(L"hero_skill_move", L"resource\\heros\\ability\\ability_move.png");
	skill->SetViewAffected(false);

	skillContainer->AddChild(skill);

	DivUI* skipBtn = new DivUI;
	skipBtn->SetScale(Vec2(20.f, 72.f));
	skipBtn->SetPos(Vec2(379.f, 0.f));
	skipBtn->InitImageModule(L"ability_pass_gray", L"resource\\panels\\icons_ability\\ability_pass_gray.png");
	skipBtn->SetViewAffected(false);

	skillContainer->AddChild(skipBtn);

	// 장비 패널 파트

	DivUI* equipPanel = new DivUI;
	equipPanel->SetPos(Vec2(-10.f, 134.f));
	equipPanel->SetScale(Vec2(720.f, 226.f));
	equipPanel->InitImageModule(L"Equip_panel", L"resource\\panels\\panel_hero.png");
	equipPanel->SetViewAffected(false);

	mainLeftPanel->AddChild(equipPanel);



#pragma region Status

	// 스테이터스 전용 패널
	DivUI* statusPanel = new DivUI;
	statusPanel->SetPos(Vec2(20.f, 10.f));
	statusPanel->SetScale(Vec2(230.f, 200.f));
	statusPanel->SetViewAffected(false);

	equipPanel->AddChild(statusPanel);

	DivUI* curHp = new DivUI;
	curHp->SetScale(Vec2(60.f, 30.f));
	curHp->SetPos(Vec2(70.f, 0.f));

	curHp->InitTextModule(heroVal->GetCurHp(), 20);
	curHp->SetFormat(DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
	curHp->SetTextColor(179, 0, 0);
	curHp->SetFont(L"이순신 돋움체 B");
	curHp->SetBold(200);
	curHp->SetName(L"curHp");
	curHp->SetViewAffected(false);

	statusPanel->AddChild(curHp);

	DivUI* maxHp = new DivUI;

	maxHp->SetScale(Vec2(80.f, 30.f));
	maxHp->SetPos(Vec2(130.f, 0.f));
	maxHp->InitTextModule(L" / " + to_wstring(heroVal->GetHp()), 20);
	maxHp->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	maxHp->SetTextColor(179, 0, 0);
	maxHp->SetFont(L"이순신 돋움체 B");
	maxHp->SetBold(200);
	maxHp->SetName(L"maxHp");
	maxHp->SetViewAffected(false);

	statusPanel->AddChild(maxHp);

	DivUI* curStress = new DivUI;
	curStress->SetScale(Vec2(60.f, 30.f));
	curStress->SetPos(Vec2(70.f, 30.f));
	curStress->InitTextModule(heroVal->GetCurStress(), 20);
	curStress->SetFormat(DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
	curStress->SetTextColor(148, 148, 148);
	curStress->SetFont(L"이순신 돋움체 B");
	curStress->SetBold(200);
	curStress->SetName(L"curStress");
	curStress->SetViewAffected(false);

	statusPanel->AddChild(curStress);

	DivUI* maxStress = new DivUI;

	maxStress->SetScale(Vec2(80.f, 30.f));
	maxStress->SetPos(Vec2(130.f, 30.f));
	maxStress->InitTextModule(L" / 200", 20);
	maxStress->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	maxStress->SetTextColor(148, 148, 148);
	maxStress->SetFont(L"이순신 돋움체 B");
	maxStress->SetBold(200);
	maxStress->SetViewAffected(false);

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
	hitRate->SetViewAffected(false);

	statusPanel->AddChild(hitRate);

	DivUI* hitRateVal = new DivUI;
	hitRateVal->SetScale(Vec2(50.f, 23.f));
	hitRateVal->SetPos(Vec2(160.f, 65.f));
	hitRateVal->InitTextModule(heroVal->GetHitRate(), textSize_y);
	hitRateVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	hitRateVal->SetTextColor(172, 170, 160);
	hitRateVal->SetFont(L"이순신 돋움체 M");
	hitRateVal->SetBold(100);
	hitRateVal->SetName(L"hitRateVal");
	hitRateVal->SetViewAffected(false);

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
	critRate->SetViewAffected(false);

	statusPanel->AddChild(critRate);

	DivUI* critRateVal = new DivUI;
	critRateVal->SetScale(Vec2(50.f, 23.f));
	critRateVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 1)));
	critRateVal->InitTextModule(to_wstring(heroVal->GetCriticalHitRate()) + L".0%", textSize_y);
	critRateVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	critRateVal->SetTextColor(172, 170, 160);
	critRateVal->SetFont(L"이순신 돋움체 M");
	critRateVal->SetBold(500);
	critRateVal->SetName(L"critRateVal");
	critRateVal->SetViewAffected(false);

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
	damage->SetViewAffected(false);

	statusPanel->AddChild(damage);

	DivUI* damageVal = new DivUI;
	damageVal->SetScale(Vec2(50.f, 23.f));
	damageVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 2)));

	wstring minDam = to_wstring(heroVal->GetDamageLower());
	wstring maxDam = to_wstring(heroVal->GetDamageUppder());
	wstring damageStr = minDam + L"-" + maxDam;

	damageVal->InitTextModule(damageStr, textSize_y);
	damageVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	damageVal->SetTextColor(172, 170, 160);
	damageVal->SetFont(L"이순신 돋움체 M");
	damageVal->SetBold(500);
	damageVal->SetName(L"damageVal");
	damageVal->SetViewAffected(false);

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
	avoid->SetViewAffected(false);

	statusPanel->AddChild(avoid);

	DivUI* avoidVal = new DivUI;
	avoidVal->SetScale(Vec2(50.f, 23.f));
	avoidVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 3)));
	avoidVal->InitTextModule(heroVal->GetAvoidanceRate(), textSize_y);
	avoidVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	avoidVal->SetTextColor(172, 170, 160);
	avoidVal->SetFont(L"이순신 돋움체 M");
	avoidVal->SetBold(500);
	avoidVal->SetName(L"avoidVal");
	avoidVal->SetViewAffected(false);

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
	shield->SetViewAffected(false);

	statusPanel->AddChild(shield);

	DivUI* shieldVal = new DivUI;
	shieldVal->SetScale(Vec2(50.f, 23.f));
	shieldVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 4)));
	shieldVal->InitTextModule(to_wstring(heroVal->GetDefenseRate()) + L"%", textSize_y);
	shieldVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	shieldVal->SetTextColor(172, 170, 160);
	shieldVal->SetFont(L"이순신 돋움체 M");
	shieldVal->SetBold(500);
	shieldVal->SetName(L"shieldVal");
	shieldVal->SetViewAffected(false);

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
	speed->SetViewAffected(false);

	statusPanel->AddChild(speed);

	DivUI* speedVal = new DivUI;
	speedVal->SetScale(Vec2(50.f, 23.f));
	speedVal->SetPos(Vec2(160.f, 65.f + (yOffset_second * 5)));
	speedVal->InitTextModule(heroVal->GetSpeed(), textSize_y);
	speedVal->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	speedVal->SetTextColor(172, 170, 160);
	speedVal->SetFont(L"이순신 돋움체 M");
	speedVal->SetBold(500);
	speedVal->SetName(L"speedVal");
	speedVal->SetViewAffected(false);

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
	weaponLv->SetViewAffected(false);

	equipPanel->AddChild(weaponLv);

	DivUI* shieldLv = new DivUI;
	shieldLv->SetPos(Vec2(425.f, 15.f));
	shieldLv->SetScale(Vec2(25.f, 25.f));
	shieldLv->InitTextModule(L"1", 23);
	shieldLv->SetFormat(DT_LEFT);
	shieldLv->SetFont(L"이순신 돋움체 B");
	shieldLv->SetTextColor(174, 172, 162);
	shieldLv->SetBold(600);
	shieldLv->SetViewAffected(false);

	equipPanel->AddChild(shieldLv);

	// 장비 그림

	DivUI* weaponPortrait = new DivUI;
	weaponPortrait->InitImageModule(heroVal->GetEquipKey(), heroVal->GetEquipPath());
	weaponPortrait->SetScale(Vec2(72.f, 144.f));
	weaponPortrait->SetPos(Vec2(271.f, 53.f));
	weaponPortrait->SetName(L"weaponPortrait");
	weaponPortrait->SetViewAffected(false);

	equipPanel->AddChild(weaponPortrait);

	DivUI* shieldPortrait = new DivUI;
	shieldPortrait->InitImageModule(heroVal->GetArmourKey(), heroVal->GetArmourPath());
	shieldPortrait->SetScale(Vec2(72.f, 144.f));
	shieldPortrait->SetPos(Vec2(362.f, 53.f));
	shieldPortrait->SetName(L"shieldPortrait");
	shieldPortrait->SetViewAffected(false);

	equipPanel->AddChild(shieldPortrait);

	// 메인 패널 오른쪽
	DivUI* mainRightPanel = new DivUI;
	mainRightPanel->SetScale(Vec2(710.f, 360.f));
	mainRightPanel->SetPos(Vec2(710.f, 0.f));
	mainRightPanel->CanTarget(false);
	mainRightPanel->SetViewAffected(false);

	mainPanel->AddChild(mainRightPanel);

	// 인벤토리 파트
	DivUI* inventoryPanel = new DivUI;
	inventoryPanel->SetScale(Vec2(720.f, 360.f));
	inventoryPanel->SetPos(Vec2(0.f, 0.f));
	inventoryPanel->InitImageModule(L"D_INV_Panle", L"resource\\panels\\panel_inventory.png");
	inventoryPanel->SetName(L"shopInvPanel");
	inventoryPanel->InitUpdateValue(new ShopInvUpdateVal(inventoryPanel));
	inventoryPanel->SetViewAffected(false);

	mainRightPanel->AddChild(inventoryPanel);

	Vec2 startPos = Vec2(64.f, 30.f);

	float xOffset = 80.f;
	float yOffset = 160.f;

	for (int i = 0; i < 16; i++) {

		float coord_x = 24.f + ((i % 8) * 80.f);
		float coord_y = 30.f + (i / 8) * 160.f;

		DivUI* invItem = UIFactory::CreateInvItem(Vec2(coord_x, coord_y), L"item_food", L"resource\\items\\provision\\food.png", i);
		//invItem->CanTarget(false);
		invItem->SetViewAffected(false);

		inventoryPanel->AddChild(invItem);
	}

	inventoryPanel->updateValue();

	DMapUI* mapPanel = new DMapUI;
	mapPanel->SetScale(Vec2(720.f, 360.f));
	mapPanel->SetPos(Vec2(0.f, 0.f));
	mapPanel->InitImageModule(L"MAP_PANEL_KEY", L"resource\\panels\\panel_map.png");
	mapPanel->SetCanRend(false);
	mapPanel->CanTarget(false);
	mapPanel->SetViewAffected(false);
	mapPanel->SetName(L"mapPanel");

	MakeBFSMap(mapPanel);

	mainRightPanel->AddChild(mapPanel);

	// 맵, 인벤토리 버튼

	DivUI* mapBtn = new DivUI;
	mapBtn->SetScale(Vec2(44.f, 80.f));
	mapBtn->SetPos(Vec2(673.f, 160.f));
	// 맵 패널 및 자식 오브젝트를 모두 캔타겟 트루 및 캔 렌더
	// 인벤토리 패널 및 자식 오브젝트들 모두 캔 타겟 펄스 및 캔 렌더 펄스
	mapBtn->InitOnMouseClick(new MapBtnClick(mapPanel, inventoryPanel));
	mapBtn->SetViewAffected(false);

	mainRightPanel->AddChild(mapBtn);

	// 맵패널 렌드 끄기, 맵 패널 상호작용 모두 canTargetFalse로 & 인벤토리 패널 렌드 키기 및 인벤토리 패널 모두 catargetTrue
	DivUI* invBtn = new DivUI;
	invBtn->SetScale(Vec2(44.f, 82.f));
	invBtn->SetPos(Vec2(673.f, 244.f));
	invBtn->InitOnMouseClick(new InvBtnClick(inventoryPanel, mapPanel));
	invBtn->SetViewAffected(false);

	mainRightPanel->AddChild(invBtn);


	return panel;
}

DivUI* UIFactory::CreateSkilTitle()
{
	DivUI* skilTitle = new DivUI;
	skilTitle->SetPos(Vec2(1150.f, 90.f));
	skilTitle->SetScale(Vec2(619.f, 136.f));
	skilTitle->InitImageModule(L"skill_title_ui", L"resource\\panels\\quest_complete_choice_shared_frame.png");
	skilTitle->SetName(L"skilTitle");

	skilTitle->InitTextModule(L"괴이한 밀침", 40);
	skilTitle->SetTextColor(202, 186, 122);
	skilTitle->SetBold(700);
	skilTitle->SetCanRend(false);

	return skilTitle;
}

DivUI* UIFactory::CreateBStartDiv()
{
	DivUI* bStartAnim = new DivUI;
	bStartAnim->SetScale(Vec2(448.f, 436.f));
	bStartAnim->SetPos(Vec2(960.f, 540.f) - (bStartAnim->GetScale() / 2.f) - Vec2(0.f, 200.f));
	bStartAnim->CreateAnimator(new AnimatorDK);
	//bStartAnim->LoadAnimation(L"combat_start_Animation", L"resource\\animations\\combatAnim\\combat.sprite-start.atlas", true);
	bStartAnim->SetCanRend(false);
	bStartAnim->SetName(L"bStartAnim");
	bStartAnim->SetCamAffected(false);

	return bStartAnim;
}

DivUI* UIFactory::CreateLeftBlood()
{
	DivUI* bloodSplatLeftFx = new DivUI;
	bloodSplatLeftFx->SetScale(Vec2(500.f, 721.f));
	bloodSplatLeftFx->SetPos(Vec2(0.f, 0.f));
	bloodSplatLeftFx->CreateAnimator(new AnimatorDK);
	bloodSplatLeftFx->LoadAnimation(L"resource\\animations\\fx\\attacked_hit\\attack_overlay.sprite-hit.atlas", true, L"bloodSplatAnim", false);
	bloodSplatLeftFx->SetCamAffected(false);
	bloodSplatLeftFx->SetName(L"bloodSplatLeftFx");
	bloodSplatLeftFx->SetViewAffected(false);
	bloodSplatLeftFx->SetCanRend(false);

	return bloodSplatLeftFx;
}

DivUI* UIFactory::CreateRightBlood()
{
	DivUI* bloodSplatRightFx = new DivUI;
	bloodSplatRightFx->SetScale(Vec2(500.f, 721.f));
	bloodSplatRightFx->SetPos(Vec2(1420.f, 0.f));
	bloodSplatRightFx->CreateAnimator(new AnimatorDK);
	bloodSplatRightFx->LoadAnimation(L"bloodSplatRightAnim", L"resource\\animations\\fx\\attacked_hit_right\\attack_overlay.sprite-hit_right.atlas", false);
	bloodSplatRightFx->SetCamAffected(false);
	bloodSplatRightFx->SetName(L"bloodSplatRightFx");
	bloodSplatRightFx->SetViewAffected(false);
	bloodSplatRightFx->SetCanRend(false);

	return bloodSplatRightFx;
}

DivUI* UIFactory::CreateVignBg()
{
	DivUI* vignBg = new DivUI;
	vignBg->SetScale(Vec2(1920.f, 720.f));
	vignBg->InitImageModule(L"vignBg", L"resource\\Background\\vignBg2.png");
	vignBg->SetPos(Vec2(0.f, 0.f));
	vignBg->SetSrcAlpha(255);
	vignBg->SetViewAffected(false);
	

	return vignBg;
}

void UIFactory::MakeBFSMap(DMapUI* mapPanel)
{
	Vec2 mapScale = mapPanel->GetScale();

	Vec2 startCoord = Vec2(0.f, 0.f);
	float yOffset = 36.f;
	float xOffset = 36.f;

	float xPathOffset = mapScale.x * 0.03f;
	float yPathOffset = mapScale.x * 0.03f;

	CMap* map = GameMgr::GetInst()->GetMap();
	map->MakeVisitedFalse();

	deque<CNode*> q;
	q.push_back(map->getStartRoom());

	deque<Vec2> vq;
	vq.push_back(startCoord);

	//deque<Vec2> prev_vq;
	//prev_vq.push_back(startCoord);

	while (!q.empty()) {

		CNode* node = q.front();
		Vec2 curCoord = vq.front();

		map->SetCurNode(node);
		q.pop_front();
		vq.pop_front();

		if (node->GetVisited()) continue;

		//std::wcout << node->GetNodeType();
		//std::cout << " " << curCoord.x << " " << curCoord.y << "\n";

		//여기서 방이나 복도를 만들던지 해야함
 		MakeRoomUI(curCoord, mapPanel, node);

		node->SetVisited(true);

		if (CRoom* roomNode = dynamic_cast<CRoom*>(node)) {
			if (roomNode->GetUpNode() != nullptr) {

				q.push_back(roomNode->GetUpNode());
				Vec2 newCoord = curCoord + Vec2(0.f, -yPathOffset);
				vq.push_back(newCoord);;
			}
			if (roomNode->GetDownNode() != nullptr) {
				q.push_back(roomNode->GetDownNode());
				Vec2 newCoord = curCoord + Vec2(0.f, yOffset);
				vq.push_back(newCoord);
			}
			if (roomNode->GetLeftNode() != nullptr) {
				q.push_back(roomNode->GetLeftNode());
				Vec2 newCoord = curCoord + Vec2(-xPathOffset, 0.f);
				vq.push_back(newCoord);
			}
			if (roomNode->GetRightNode() != nullptr) {
				q.push_back(roomNode->GetRightNode());
				Vec2 newCoord = curCoord + Vec2(xOffset, 0.f);
				vq.push_back(newCoord);
			}
		}
		else if (CPathNode* pathNode = dynamic_cast<CPathNode*>(node)) {

			// 여기서는 복도의 좌표를 설정할떄 Direction에 따라 달라진다.. 일단 단순하게 왼쪽 오른쪽으로만 해보자


			if (pathNode->GetLeftNode() != nullptr) {
				q.push_back(pathNode->GetLeftNode());

				if (pathNode->GetDir() == PATH_DIR::LEFT) {
					
					if (pathNode->GetLeftNode()->GetNodeType() == L"CRoom") {
						Vec2 newCoord = curCoord + Vec2(xOffset, 0.f);
						vq.push_back(newCoord);
					}
					else {
						Vec2 newCoord = curCoord + Vec2(xPathOffset, 0.f);
						vq.push_back(newCoord);
					}
					
				}
				else if (pathNode->GetDir() == PATH_DIR::RIGHT) {
					Vec2 newCoord = curCoord + Vec2(-xPathOffset, 0.f);
					vq.push_back(newCoord);
				}
				else if (pathNode->GetDir() == PATH_DIR::TOP) {
					Vec2 newCoord = curCoord + Vec2(0.f, yPathOffset);
					vq.push_back(newCoord);
				}
				else if (pathNode->GetDir() == PATH_DIR::BOTTOM) {
					Vec2 newCoord = curCoord + Vec2(0.f, -yPathOffset);
					vq.push_back(newCoord);
				}
				
			}
			if (pathNode->GetRightNode() != nullptr) {
				q.push_back(pathNode->GetRightNode());

				if (pathNode->GetDir() == PATH_DIR::LEFT) {

					if (pathNode->GetRightNode()->GetNodeType() == L"CRoom") {
						Vec2 newCoord = curCoord + Vec2(-xOffset, 0.f);
						vq.push_back(newCoord);
					}
					else {
						Vec2 newCoord = curCoord + Vec2(-xPathOffset, 0.f);
						vq.push_back(newCoord);
					}

				}
				else if (pathNode->GetDir() == PATH_DIR::RIGHT) {
					Vec2 newCoord = curCoord + Vec2(xPathOffset, 0.f);
					vq.push_back(newCoord);
				}
				else if (pathNode->GetDir() == PATH_DIR::TOP) {

					if (pathNode->GetRightNode()->GetNodeType() == L"CRoom") {
						Vec2 newCoord = curCoord + Vec2(0.f, -yOffset);
						vq.push_back(newCoord);
					}
					else {
						Vec2 newCoord = curCoord + Vec2(0.f, -yPathOffset);
						vq.push_back(newCoord);
					}	
				}
				else if (pathNode->GetDir() == PATH_DIR::BOTTOM) {
					Vec2 newCoord = curCoord + Vec2(0.f, yPathOffset);
					vq.push_back(newCoord);
				}

				/*Vec2 newCoord = curCoord + Vec2(xPathOffset, 0.f);
				vq.push_back(newCoord);*/
			}
		}
		// 한 탐색에 4방향, 2방향을 전부 큐에 넣음
	}

	// 그래프 순회끝나면 다시 시작노드로 옮겨줌
}

void UIFactory::MakeRoomUI(Vec2 pos, DMapUI* mapPanel, CNode* node)
{
	Vec2 mapScale = mapPanel->GetScale();
	Vec2 newPos = mapScale * 0.5f + pos;

	int nodeId = node->GetId();


	if (CRoom* roomNode = dynamic_cast<CRoom*>(node)) {

		Vec2 roomScale = Vec2(mapScale.x * 0.05f, mapScale.x * 0.05f);

		DroomUI* roomUI = new DroomUI;
		roomUI->InitImageModule(L"ROOM_EMPTY", L"resource\\panels\\icons_map\\room_empty.png");
		roomUI->SetScale(Vec2(36.f, 36.f));
		roomUI->SetPos(newPos);
		roomUI->CanTarget(true);
		roomUI->SetId(roomNode->GetId());
		roomUI->InitOnMouseClick(new RoomUIClick(roomNode->GetId()));
		roomUI->SetViewAffected(false);

		DivUI* indicator = new DivUI;
		indicator->SetScale(roomUI->GetScale());
		indicator->SetPos(Vec2(0.f, 0.f));
		indicator->InitImageModule(L"ROOM_INDICATOR", L"resource\\panels\\icons_map\\indicator.png");
		indicator->SetCanRend(false);
		indicator->CanTarget(false);
		indicator->SetName(L"indicator");
		indicator->SetViewAffected(false);


		roomUI->SetIndicator(indicator);
		roomUI->AddChild(indicator);

		mapPanel->AddRoom(roomUI);
		mapPanel->AddChild(roomUI);

		CMap* map = GameMgr::GetInst()->GetMap();
		if (map->getStartRoom()->GetId() == roomNode->GetId()) {
			roomUI->InitImageModule(L"ROOM_ENTRANCE", L"resource\\panels\\icons_map\\room_entrance.png");
			indicator->SetCanRend(true);
		}
		
	}
	else if (CPathNode* pathNode = dynamic_cast<CPathNode*>(node)) {

		Vec2 pathScale = Vec2(mapScale.x * 0.03f, mapScale.x * 0.03f);

		DpathUI* pathUI = new DpathUI;
		pathUI->InitImageModule(L"HALL_DARK", L"resource\\panels\\icons_map\\hall_dim.png");
		pathUI->SetScale(Vec2(21.f, 21.f));
		pathUI->SetPos(newPos);
		pathUI->CanTarget(true);
		pathUI->SetId(pathNode->GetId());
		pathUI->SetViewAffected(false);

		DivUI* indicator = new DivUI;
		indicator->SetScale(pathUI->GetScale());
		indicator->SetPos(Vec2(0.f, 0.f));
		indicator->InitImageModule(L"ROOM_INDICATOR", L"resource\\panels\\icons_map\\indicator.png");
		indicator->SetCanRend(false);
		indicator->CanTarget(false);
		indicator->SetName(L"indicator");
		indicator->SetViewAffected(false);

		pathUI->SetIndicator(indicator);
		pathUI->AddChild(indicator);

		mapPanel->AddPath(pathUI);
		mapPanel->AddChild(pathUI);
	}
}
