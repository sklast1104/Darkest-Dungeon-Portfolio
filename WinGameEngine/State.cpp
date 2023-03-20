#include "stdafx.h"
#include "State.h"

State::State(wstring _stateKey)
	: stateKey{ _stateKey }
	, ai{ nullptr }
{
}

State::~State()
{
}
