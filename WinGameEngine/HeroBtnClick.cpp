#include "stdafx.h"
#include "HeroBtnClick.h"

#include "SceneMgr.h"
#include "Scene.h"
#include "Scene_DSelect.h"
#include "DivUI.h"
#include "CHero.h"

HeroBtnClick::HeroBtnClick(CHero* _hero)
	: hero{_hero}
{
}

void HeroBtnClick::Execute()
{
	Scene* curScene = SceneMgr::GetInst()->GetCurScene();

	if (curScene->GetName() == L"Scene_DSelect") {
		
		DivUI* renderer = ((Scene_DSelect*)curScene)->GetRenderer();
		
		renderer->SetCanRend(true);
		renderer->InitImageModule(hero->GetKey(), hero->GetPath());
		renderer->SetName(hero->GetName());
	}
}

