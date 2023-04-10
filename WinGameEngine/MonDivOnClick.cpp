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
	// Ŭ������ ���� ����(�ε���, �������ϼ� ����)��
	// ����� ����, ��ų ������ �ƽ� ���·� �Ѱܾߵ�
	// ��Ƽ�����϶��� ���� �ѱ� �ʿ� �����ʳ�..? �׻� ������ ������ ������
	// ���Ͼ����϶��� �ѱ���

	GameMgr* mgr = GameMgr::GetInst();

	// ���� ��Ŀ�� �ε����� �ٷﵵ �ɰŰ�����
	// ��ų�ε����� �̹� �Ѱ��� ������
	
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	CMonSquad* monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	monSquad->SortChildUI();

	int monDivId = monDiv->GetId();

	mgr->SetMonFocusIdx(monDiv->GetId());

	// �Ŵ����� ����Ÿ������ ����Ÿ������������ �˷��൵ ��� ���ڴ�

	// �ƾ����� �����̵� ��ų�� �׻� �Է°��� �ʱ�ȭ ����
	CCutScene* cutState = (CCutScene*)(mgr->GetMachine()->GetState(L"CCutScene"));
	cutState->IsPlayerAttack(true);

	ChangeState(mgr->GetMachine(), L"CCutScene");
}
