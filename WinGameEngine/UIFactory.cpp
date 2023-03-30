#include "stdafx.h"
#include "UIFactory.h"
#include "DivUI.h"
#include "BtnOutCom.h"
#include "BtnOverCom.h"
#include "GameMgr.h"
#include "CHero.h"

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

	const vector<CHero*>& curLoster = GameMgr::GetInst()->GetCurLoster();

	for (int i = 0; i < curLoster.size(); i++) {

		CHero* hero = curLoster[i];

#pragma region hero_panel

		DivUI* heroPanel = new DivUI;
		heroPanel->SetScale(Vec2(355.f, 104.f));
		heroPanel->SetPos(Vec2(0.f, 0 + i * (105.f) ) );
		heroPanel->InitImageModule(L"hero_roster_panel_bg", L"resource\\roster\\roster_bg.png");

		DivUI* heroPortrait = new DivUI;
		heroPortrait->SetScale(Vec2(85.f, 85.f));
		heroPortrait->SetPos(Vec2(20.f, 8.f));
		heroPortrait->InitImageModule(hero->GetKey(), hero->GetPath());

		heroPanel->AddChild(heroPortrait);

		DivUI* heroTxt = new DivUI;
		heroTxt->SetScale(Vec2(200.f, 50.f));
		heroTxt->SetPos(Vec2(120.f, 0.f));
		heroTxt->InitTextModule(hero->GetName(), 25);
		heroTxt->SetBold(FW_MEDIUM);
		heroTxt->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		heroTxt->SetTextColor(191, 172, 105);

		heroPanel->AddChild(heroTxt);

		for (int i = 0; i < 10; i++) {

			DivUI* stressUI = new DivUI;
			stressUI->SetScale(Vec2(9.f, 10.f));
			stressUI->SetScale(stressUI->GetScale() * 1.0f);
			stressUI->SetPos(Vec2(120.f + (i * 10), 43.f));
			stressUI->InitImageModule(L"Stress_empty_bg", L"resource\\overay\\stress_empty.png");

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

		heroPanel->AddChild(weaponLv);

		DivUI* shieldLv = new DivUI;
		shieldLv->SetScale(Vec2(30.f, 30.f));
		shieldLv->SetPos(Vec2(212.f, 66.f));
		shieldLv->InitTextModule(hero->GetArmorLevel(), 22);
		shieldLv->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		shieldLv->SetFont(L"이순신 돋움체 B");
		shieldLv->SetBold(FW_BOLD);
		shieldLv->SetTextColor(172, 170, 160);

		heroPanel->AddChild(shieldLv);

		float curExpScale = hero->GetCurExp() * 5;
		float curExpStartHeight = 85 - curExpScale;

		DivUI* levelFull = new DivUI;
		levelFull->SetScale(Vec2(27.f,curExpScale));
		levelFull->SetPos(Vec2(255.f, curExpStartHeight));
		levelFull->InitImageModule(L"Level_full_bg", L"resource\\roster\\hp_full.png");

		heroPanel->AddChild(levelFull);

		DivUI* levelBar = new DivUI;
		levelBar->SetScale(Vec2(37.f, 59.f));
		levelBar->SetPos(Vec2(255.f, 35.f));
		levelBar->InitImageModule(L"Level_mask_bg", L"resource\\roster\\level_bar.png");

		heroPanel->AddChild(levelBar);

		DivUI* levelNum = new DivUI;
		levelNum->SetScale(Vec2(64.f, 64.f));
		levelNum->SetPos(Vec2(240.f, 0.f));
		levelNum->InitImageModule(L"Level_Number_bg", L"resource\\roster\\lv2_num.png");

		heroPanel->AddChild(levelNum);

		DivUI* levelTxt = new DivUI;
		levelTxt->SetScale(Vec2(64.f, 64.f));
		levelTxt->SetPos(Vec2(240.f, 0.f));
		levelTxt->InitTextModule(L"1", 25);
		levelTxt->SetFont(L"이순신 돋움체 B");
		levelTxt->SetTextColor(0, 0, 0);
		levelTxt->SetBold(FW_BOLD);

		heroPanel->AddChild(levelTxt);

		heroSideNav->AddChild(heroPanel);

#pragma endregion

	}

	return heroSideNav;
}
