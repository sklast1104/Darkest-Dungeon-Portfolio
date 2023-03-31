#pragma once

class CHero;

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

	// 던전 리스트



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

