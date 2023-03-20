#pragma once

class AI;

class State
{
private :
	// State�ӽ��� State�ӽſ��� ���� �������ش�
	AI* ai;
	wstring stateKey;

public :

	State(wstring _stateKey);
	virtual ~State();

	void SetStateMachine(AI* _aI) { ai = _aI; }
	AI* GetStateMachine() const { return ai; }
	const wstring& GetStateKey() const { return stateKey; }

	virtual void Update() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;
};

