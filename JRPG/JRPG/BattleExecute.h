#pragma once
#include "IState.h"
#include "StateMachine.h"
#include "Action.h"
class BattleExecute : public IState
{
public:
	BattleExecute(StateMachine& stateMachine, std::vector<std::shared_ptr<Action>>);
};

