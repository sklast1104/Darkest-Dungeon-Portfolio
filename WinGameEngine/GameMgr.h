#pragma once

class CHero;
class CItem;
class DarkestMachine;

class GameMgr
{
private :

	// 돈
	int moneyCnt;
	// 흉상
	int bustCnt;
	// 초상화
	int portraitCnt;
	// 증서
	int certCnt;
	// 문장
	int bucklerCnt;

	// 현재 영지에서 가지고 있는 히어로 로스터들
	vector<CHero*> curHeros;

	// 현재 스쿼드
	array<CHero*, 4> curSquad;

	// 인벤토리 관리
	array<CItem*, 16> curItems;

	// 상태머신
	DarkestMachine* machine;

public :

	void init();

	int GetMoney() { return moneyCnt; }
	void SetMoney(int _money) { moneyCnt = _money; }

	int GetBustCnt() { return bustCnt; }
	void SetBust(int _bustCnt) { bustCnt = _bustCnt; }

	int GetPortraitCnt() { return portraitCnt; }
	void SetPortraitCnt(int _portraitCnt) { portraitCnt = _portraitCnt; }

	int GetCertCnt() { return certCnt; }
	void SetCertCnt(int _certCnt) { certCnt = _certCnt; }

	int GetBucklerCnt() { return bucklerCnt; }
	void SetBucklerCnt(int _bucklercnt) { bucklerCnt = _bucklercnt; }

	const vector<CHero*>& GetCurLoster() { return curHeros; }

	// 로스터에서 찾는 함수
	CHero* FindHeroByName(const wstring& _heroName);
	
	// 스쿼드에서 찾는 함수
	int FindIndexByName(const wstring& _heroName);
	void MakeEmpySlot(int _index) { curSquad[_index] = nullptr; }
	void AddSquad(int _index, const wstring& _heroName);
	bool isSlotEmpty(int _index);
	const array<CHero*, 4>& GetSquad() { return curSquad; }

	void SwapSquad(int _from, int _to);
	void CleanSqaud();
	CHero* GetHeroBySquad(int _index);
	int GetSquadNum();

	// 인벤토리 관리 함수
	array<CItem*, 16>& GetInventory() { return curItems; }
	void CreateItem(wstring _key, int _index);
	void MoveInventory(int _from, int _to);
	void SwapInventory(int _from, int _to);
	void RemoveItem(int _index);
	void ClearInventory();

	// 상태머신 관련
	DarkestMachine* GetMachine() { return machine; }
public :
	SINGLE(GameMgr);
};

