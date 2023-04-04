#pragma once

class CHero;
class CItem;
class DarkestMachine;

class GameMgr
{
private :

	// ��
	int moneyCnt;
	// ���
	int bustCnt;
	// �ʻ�ȭ
	int portraitCnt;
	// ����
	int certCnt;
	// ����
	int bucklerCnt;

	// ���� �������� ������ �ִ� ����� �ν��͵�
	vector<CHero*> curHeros;

	// ���� ������
	array<CHero*, 4> curSquad;

	// �κ��丮 ����
	array<CItem*, 16> curItems;

	// ���¸ӽ�
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

	// �ν��Ϳ��� ã�� �Լ�
	CHero* FindHeroByName(const wstring& _heroName);
	
	// �����忡�� ã�� �Լ�
	int FindIndexByName(const wstring& _heroName);
	void MakeEmpySlot(int _index) { curSquad[_index] = nullptr; }
	void AddSquad(int _index, const wstring& _heroName);
	bool isSlotEmpty(int _index);
	const array<CHero*, 4>& GetSquad() { return curSquad; }

	void SwapSquad(int _from, int _to);
	void CleanSqaud();
	CHero* GetHeroBySquad(int _index);
	int GetSquadNum();

	// �κ��丮 ���� �Լ�
	array<CItem*, 16>& GetInventory() { return curItems; }
	void CreateItem(wstring _key, int _index);
	void MoveInventory(int _from, int _to);
	void SwapInventory(int _from, int _to);
	void RemoveItem(int _index);
	void ClearInventory();

	// ���¸ӽ� ����
	DarkestMachine* GetMachine() { return machine; }
public :
	SINGLE(GameMgr);
};

