#include "stdafx.h"
#include "GameMgr.h"

#include "CHero.h"
#include "CCrusader.h"
#include "CHighwayMan.h"

GameMgr::GameMgr() 
	: moneyCnt{0}, bustCnt{0}
	, portraitCnt{0}, certCnt{0}
	, bucklerCnt{0}, curHeros{}
	, curSquad{}
{

}

GameMgr::~GameMgr() {
	
	// �ν��͵鸸 ������ �� ������� �ν��Ϳ��� �������⶧���� ���� ���� ����
	Safe_Delete_Vec<CHero*>(curHeros);
}

void GameMgr::init()
{
	// ���� �����ҋ� �ν��� �⺻ �������� ������� ��󰭵��� ��
	CHero* cru = new CCrusader;
	curHeros.push_back(cru);

	CHero* hMan = new CHighwayMan;
	curHeros.push_back(hMan);

	bustCnt = 16;
	portraitCnt = 11;
	certCnt = 2;
	bucklerCnt = 14;

	moneyCnt = 10070;


}
