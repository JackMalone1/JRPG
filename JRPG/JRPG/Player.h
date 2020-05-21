#pragma once
#include "Entity.h"
#include "PlayerDecide.h"
class Player :
	public Entity
{
private:
	std::shared_ptr<Action> action{ std::make_shared<PlayerDecide>() };
public:
	std::shared_ptr<Action> getAction() { return action; }
};

