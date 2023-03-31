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
	
	// 로스터들만 해제해 줌 스쿼드는 로스터에서 빌려쓰기때문에 약한 참조 관계
	Safe_Delete_Vec<CHero*>(curHeros);
}

void GameMgr::init()
{
	// 게임 시작할떄 로스터 기본 영웅으로 성전사와 노상강도를 둠
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
