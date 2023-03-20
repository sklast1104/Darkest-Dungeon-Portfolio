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
	// ChangeState�� ���� ȣ���ϸ� ������ �����Ƿ� private�� �ɾ������ friend Class�� �߰��ϴ� �κе� ���
	void ChangeState(wstring stateKey);
};

