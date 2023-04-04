#include "stdafx.h"
#include "GameMgr.h"

#include "CHero.h"
#include "CCrusader.h"
#include "CHighwayMan.h"

#include "CInvItem.h"
#include "DarkestMachine.h"

GameMgr::GameMgr() 
	: moneyCnt{0}, bustCnt{0}
	, portraitCnt{0}, certCnt{0}
	, bucklerCnt{0}, curHeros{}
	, curSquad{}, machine{nullptr}
{
	for (int i = 0; i < 4; i++) {
		curSquad[i] = nullptr;
	}

	for (int i = 0; i < 16; i++) {
		curItems[i] = nullptr;
	}
}

GameMgr::~GameMgr() {
	
	// 로스터들만 해제해 줌 스쿼드는 로스터에서 빌려쓰기때문에 약한 참조 관계
	Safe_Delete_Vec<CHero*>(curHeros);

	for (int i = 0; i < 16; i++) {
		Safe_Delete<CItem*>(curItems[i]);
	}

	Safe_Delete(machine);
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

	machine = new DarkestMachine;
}

CHero* GameMgr::FindHeroByName(const wstring& _heroName)
{
	for (const auto& hero : curHeros) {

		if (hero->GetName() == _heroName) {
			return hero;
		}

	}

	return nullptr;
}

int GameMgr::FindIndexByName(const wstring& _heroName)
{
	for (int i = 0; i < 4; i++) {

		if (nullptr != curSquad[i]) {
			
			if (curSquad[i]->GetName() == _heroName) {
				return i;
			}
		}
	}

	return -1;
}

void GameMgr::AddSquad(int _index, const wstring& _heroName)
{
	CHero* hero = FindHeroByName(_heroName);

	curSquad[_index] = hero;
}

bool GameMgr::isSlotEmpty(int _index)
{
	if (nullptr == curSquad[_index]) {
		return true;
	}
	else {
		return false;
	}

	return false;
}

void GameMgr::SwapSquad(int _from, int _to)
{
	CHero* temp = curSquad[_to];
	curSquad[_to] = curSquad[_from];
	curSquad[_from] = temp;
}

void GameMgr::CleanSqaud()
{
	for (int i = 0; i < 4; i++) {
		curSquad[i] = nullptr;
	}
}

CHero* GameMgr::GetHeroBySquad(int _index)
{
	CHero* hero = curSquad[_index];

	int a = 3;

	return hero;
}

int GameMgr::GetSquadNum()
{
	int num = 0;

	for (int i = 0; i < 4; i++) {
		if (nullptr != curSquad[i]) {
			num += 1;
		}
	}

	return num;
}

void GameMgr::CreateItem(wstring _key, int _index)
{
	if (nullptr == curItems[_index]) {
		CItem* newItem = new CInvItem(_key);
		curItems[_index] = newItem;
	}
}

void GameMgr::MoveInventory(int _from, int _to)
{
	if (nullptr != curItems[_from]) {

		if (nullptr == curItems[_to]) {
			curItems[_to] = curItems[_from];
			curItems[_from] = nullptr;
		}
	}
}

void GameMgr::SwapInventory(int _from, int _to)
{
	CItem* temp = curItems[_from];
	curItems[_from] = curItems[_to];
	curItems[_to] = temp;
}

void GameMgr::RemoveItem(int _index)
{
	if (nullptr != curItems[_index]) {
		Safe_Delete<CItem*>(curItems[_index]);
	}
}

void GameMgr::ClearInventory()
{
	for (int i = 0; i < 16; i++) {
		if (nullptr != curItems[i]) {

			// 코스트도 아이템에 추가해야할듯
			CInvItem* item = (CInvItem*)curItems[i];
			int cashBack = item->GetCost() * item->GetCurCount();

			moneyCnt += cashBack;

			Safe_Delete<CItem*>(curItems[i]);
		}
	}
}
