#pragma once
#include "Entity.h"
#include "Action.h"
#include "AIDecide.h"
class AI :
	public Entity
{
private:
	std::shared_ptr<Action> action{ std::make_shared<AIDecide>() };
public:
	std::shared_ptr<Action> getAction() { return action; }
};

