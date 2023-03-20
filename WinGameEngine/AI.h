#pragma once

class State;

class AI
{
protected :

	unordered_map<wstring, State*> stateMap;

	State* curState;

public :

	AI();
	virtual ~AI();

	void update();

	void AddState(State* _state);
	State* GetState(wstring stateKey);

	void SetCurState(wstring stateKey);
	// ChangeState는 직접 호출하면 문제가 있으므로 private로 걸어버리고 friend Class로 추가하는 부분도 고려
	void ChangeState(wstring stateKey);
};

