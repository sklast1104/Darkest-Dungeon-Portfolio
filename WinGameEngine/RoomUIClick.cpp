#include "stdafx.h"
#include "RoomUIClick.h"
#include "GameMgr.h"
#include "CMap.h"
#include "CNode.h"
#include "CRoom.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Scene_Path.h"

// �⺻������ �濡 �������� �̺�Ʈ ��ϵȴٴ°� �����Ѵ�
// ���ӸŴ����� map�� ���� ���(��)�� ���̵�� �ڽ� ��带 ���Ѵ�
// ��������� ���(�׻� ������常 Ŭ���Ѵٰ� ����) 
// ���� ��� Ŭ���� �ڱ� �� ������ path�� ����ؼ� path���� �־��ش�
// �� ������ Change���� Path������ ȣ���Ѵ�

RoomUIClick::RoomUIClick(int _id)
	: id{_id}
{
}

void RoomUIClick::Execute()
{
	CMap* map = GameMgr::GetInst()->GetMap();
	// 
	CRoom* curNode = (CRoom*)GameMgr::GetInst()->GetMap()->GetCurNode();

	if (curNode->GetId() == id) {
		return;
	}
	else {
		// ������ ���������� �˻簡 ���� �ϴ°� ����
		CRoom* clickedRoom = (CRoom*)map->FindNodeById(id);
		
		CRoom* myRoom = (CRoom*)map->FindNodeById(curNode->GetId());

		int _dir = myRoom->CheckDir(id);

		// �𷺼ǵ� ���� ������ �Ǿ���
		vector<CPathNode*> paths = map->GetPathBtwRoom(curNode, clickedRoom, _dir);

		// paths���� path ���� �� SceneChange
		
		Scene_Path* pScene = (Scene_Path*)SceneMgr::GetInst()->GetSceneByName(L"Scene_Path");
		pScene->SetPath(paths);

		ChangeScene(SCENE_TYPE::PATH);

	}
}
