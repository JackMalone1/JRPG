#pragma once
#include "IState.h"
#include "StateMachine.h"
#include "Action.h"
class BattleTick :
	public IState
{
public:
	BattleTick(StateMachine& stateMachine, std::vector<std::shared_ptr<Action>>);
};

