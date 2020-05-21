#include "BattleTick.h"

BattleTick::BattleTick(StateMachine& stateMachine, std::vector<std::shared_ptr<Action>>& t_actions) : states{ stateMachine }, actions{t_actions}
{
}

void BattleTick::update(float dt)
{
	for (std::shared_ptr<Action>& a : actions)
	{
		a->update(dt);
	}

	if (actions.at(0)->isReady())
	{
		states.changeState("execute", actions.at(0));
		actions.erase(actions.begin() + 0);
	}
}

void BattleTick::render(sf::RenderWindow& window)
{
}

void BattleTick::onEnter()
{
}

void BattleTick::onEnter(std::string mapName)
{
}

void BattleTick::onEnter(std::vector<std::shared_ptr<Entity>> t_entities)
{
}

void BattleTick::onExit()
{
}
