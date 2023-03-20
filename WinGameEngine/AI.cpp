#include "stdafx.h"
#include "AI.h"

#include "State.h"

AI::AI()
	: curState{ nullptr }
{
}

AI::~AI()
{
	for (auto it = stateMap.begin(); it != stateMap.end(); ++it) {
		delete it->second;
	}
}

void AI::update()
{
	curState->Update();
}

void AI::AddState(State* _state)
{
	State* state = GetState(_state->GetStateKey());
	assert(!state);

	stateMap.insert(make_pair(_state->GetStateKey(), _state));
	_state->SetStateMachine(this);
}

State* AI::GetState(wstring stateKey)
{
	auto iter = stateMap.find(stateKey);
	if (iter == stateMap.end())
		return nullptr;

	return iter->second;
}

void AI::SetCurState(wstring stateKey)
{
	curState = GetState(stateKey);
}

void AI::ChangeState(wstring stateKey)
{
	State* nextState = GetState(stateKey);

	assert(curState != nextState);

	curState->Exit();

	curState = nextState;

	curState->Enter();
}
