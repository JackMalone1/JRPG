#pragma once
#include "Action.h"
#include <memory>
class Entity
{
public:
	bool playerControlled();
	virtual std::shared_ptr<Action> getAction() = 0;
};

