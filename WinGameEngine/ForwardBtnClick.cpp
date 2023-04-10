#include "stdafx.h"
#include "ForwardBtnClick.h"

#include "Scene.h"
#include "SceneMgr.h"
#include "GameMgr.h"
#include "CMap.h"

void ForwardBtnClick::Execute()
{
	Scene* curScene = SceneMgr::GetInst()->GetCurScene();

	if (curScene->GetName() == L"Scene_Town") {
		ChangeScene(SCENE_TYPE::DSELECT);
	}
	else if (curScene->GetName() == L"Scene_DSelect") {
		ChangeScene(SCENE_TYPE::SHOP);
	}
	else if (curScene->GetName() == L"Scene_Shop") {

		// 여기서만 현재노드를 시작노드로 바꿔야함
		CMap* map = GameMgr::GetInst()->GetMap();
		map->SetCurNode(map->getStartRoom());

		ChangeScene(SCENE_TYPE::DROOM);
	}
}
