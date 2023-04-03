#include "stdafx.h"
#include "ForwardBtnClick.h"

#include "Scene.h"
#include "SceneMgr.h"

void ForwardBtnClick::Execute()
{
	Scene* curScene = SceneMgr::GetInst()->GetCurScene();

	if (curScene->GetName() == L"Scene_Town") {
		ChangeScene(SCENE_TYPE::DSELECT);
	}
	else if (curScene->GetName() == L"Scene_DSelect") {
		ChangeScene(SCENE_TYPE::SHOP);
	}
}
