#include "stdafx.h"
#include "MonDivOnClick.h"

#include "GameMgr.h"
#include "CMonDiv.h"
#include "DarkestMachine.h"
#include "CCutScene.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CMonSquad.h"

MonDivOnClick::MonDivOnClick(CMonDiv* _monDiv)
	: monDiv{_monDiv}
{
}

void MonDivOnClick::Execute()
{
	// 클릭당한 적의 정보(인덱스, 여러개일수 있음)와
	// 히어로 정보, 스킬 정보를 컷신 상태로 넘겨야됨
	// 멀티어택일때는 굳이 넘길 필요 없지않나..? 항상 때리는 범위가 고정임
	// 단일어택일때만 넘기자

	GameMgr* mgr = GameMgr::GetInst();

	// 몬스터 포커싱 인덱스로 다뤄도 될거같은데
	// 스킬인덱스는 이미 넘겨진 상태임
	
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	CMonSquad* monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	monSquad->SortChildUI();

	int monDivId = monDiv->GetId();

	mgr->SetMonFocusIdx(monDiv->GetId());

	// 매니저에 단일타격인지 동시타격인지정도는 알려줘도 상관 없겠다

	// 컷씬으로 상태이동 시킬떄 항상 입력값을 초기화 하자
	CCutScene* cutState = (CCutScene*)(mgr->GetMachine()->GetState(L"CCutScene"));
	cutState->IsPlayerAttack(true);

	ChangeState(mgr->GetMachine(), L"CCutScene");
}
