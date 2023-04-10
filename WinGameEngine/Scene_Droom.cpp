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
#include "CHero.h"
#include "CSkill.h"
#include "MapBtnClick.h"
#include "InvBtnClick.h"
#include "MainLeftUpdateCom.h"
#include "HeroDivClick.h"
#include "CMonSquad.h"
#include "CMonDiv.h"
#include "TimeMgr.h"
#include "SoundMgr.h"
#include "Sound.h"
#include "ResMgr.h"
#include "SkillContainerUpdate.h"
#include "SkillOnclick.h"
#include "MonDivOnClick.h"
#include "ViewMgr.h"
#include "CDarkMonster.h"
#include "DarkestMachine.h"
#include "CMap.h"
#include "CRoom.h"
#include "DMapUI.h"

Scene_Droom::Scene_Droom()
	: firstVisit{true}
{
	elapseTime = 0.f;
	debug = true;
}

Scene_Droom::~Scene_Droom()
{
}

void Scene_Droom::render(HDC _dc)
{
	Scene::render(_dc);

	TextOutA(_dc, 20, 20, camCoordText.c_str(), camCoordText.length());

	TextOutA(_dc, 20, 40, playerCoordText.c_str(), playerCoordText.length());

	wstring stateName = GameMgr::GetInst()->GetMachine()->GetCurStateName();
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::string str = conv.to_bytes(stateName);

	TextOutA(_dc, 20, 80, str.c_str(), str.length());
}

void Scene_Droom::Enter()
{
	// 맵 초기화
	dMap = GameMgr::GetInst()->GetMap();
	CRoom* curRoom = (CRoom*)dMap->GetCurNode();

	Camera::GetInst()->SetCurLookAt(Vec2(960.f, 540.f));

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
	bg->InitImageModule(curRoom->GetRKey() , curRoom->GetRPath());
	bg->CanTarget(false);
	bg->SetCamAffected(true);

	pseudoUI->AddChild(bg);

	AddObject(pseudoUI, GROUP_TYPE::UI);

#pragma region Hero

	// 스케일은 인원수 비례해서 커지고
	// 포지션은 인원수 반비례해서 작아져야함
	squad = UIFactory::CreateSquadDiv();
	
	pseudoUI->AddChild(squad);
	
#pragma endregion

#pragma region Monster

	CMonSquad* monSquadDiv = UIFactory::CreateMonSquadDiv();
	monSquadDiv->SetCanRend(false);

	pseudoUI->AddChild(monSquadDiv);

#pragma endregion

#pragma region DungeonPanel

	DivUI* panel = UIFactory::CreateDungeonPanel();

	pseudoUI->AddChild(panel);

#pragma endregion

	pseudoUI->AddChild(itemDragger);

	if (firstVisit) {
		firstVisit = false;
		CMap* map = GameMgr::GetInst()->GetMap();
		map->SetCurNode(map->getStartRoom());
	}
	else {
		CMap* map = GameMgr::GetInst()->GetMap();
		CRoom* curRoom2 = (CRoom*)map->FindNodeById(GameMgr::GetInst()->GetCurNodeIdx());
		map->SetCurNode(curRoom2);
	}

	DMapUI* mapPanel = (DMapUI*)FindUIByName(pseudoUI, L"mapPanel");

	mapPanel->EnableAllIndicator(false);
	int curNodeId = GameMgr::GetInst()->GetMap()->GetCurNode()->GetId();
	mapPanel->EnableIndibyIdx(curNodeId);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

	// 효과
	Camera::GetInst()->FadeIn(0.5f);

	// 사운드
	ResMgr::GetInst()->LoadSound(L"RuinsLevel1Bgm", L"resource\\sound\\Music\\Explore_Vaults_Level_1_Loop {a2068a43-0914-44b6-b2ec-e3cc8160dab9}.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"RuinsLevel1Bgm");

	pTitleSound->SetVolume(20.f);
	pTitleSound->PlayToBGM(true);
}

void Scene_Droom::update()
{
	elapseTime += fDT;


	//if (elapseTime >= 1.f && debug) {
	//	debug = false;
	//	ChangeState((CStMachine*)GameMgr::GetInst()->GetMachine(), L"CBStartState");
	//}

	cameraCoord = Camera::GetInst()->GetLookAt();
	camCoordText = "Camera Coord : (" + std::to_string(cameraCoord.x) + ", " + std::to_string(cameraCoord.y) + ")";

	playerCoord = squad->GetFinalPos();
	playerCoordText = "Player Coord : (" + std::to_string(playerCoord.x) + ", " + std::to_string(playerCoord.y) + ")";

	//if (KEY_TAP(KEY::LBTN)) {

	//	Vec2 mousePos = Camera::GetInst()->GetRealPos(MOUSE_POS);
	//	//mousePos = ViewMgr::GetInst()->GetViewPortPos(mousePos);
	//	Camera::GetInst()->SetLookAt(mousePos);
	//}

	Scene::update();

	if (KEY_TAP(KEY::ESC)) {
		ChangeScene(SCENE_TYPE::SHOP);
	}

	Vec2 mPos = MOUSE_POS;
	Vec2 iScale = itemDragger->GetScale();

	itemDragger->SetPos(mPos - iScale / 2.f);

	if (KEY_AWAY(KEY::LBTN)) {
		itemDragger->SetCanRend(false);
	}
}
