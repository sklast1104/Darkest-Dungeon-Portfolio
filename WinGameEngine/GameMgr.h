#pragma once

class CHero;

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

	// ���� ����Ʈ



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

public :
	SINGLE(GameMgr);
};

