#include "BattleState.h"

BattleState::BattleState(StateMachine stateMachine)
{
	m_stateMachine.addState("tick", std::make_shared<BattleTick>(m_stateMachine, actions));

	m_stateMachine.addState("execute", std::make_shared<BattleExecute>(m_stateMachine, actions));
}

void BattleState::update(float dt)
{
	m_stateMachine.update(dt);
}

void BattleState::render(sf::RenderWindow& window)
{
	m_stateMachine.render(window);
}

void BattleState::onEnter()
{
	m_stateMachine.changeState("tick");
}

void BattleState::onEnter(std::string mapName)
{
	m_stateMachine.changeState("tick");
}

void BattleState::onEnter(std::vector<std::shared_ptr<Entity>> t_entities)
{
	m_stateMachine.changeState("tick");

	entities = t_entities;

	if (t_entities.empty())
	{
		return;
	}

	for (std::shared_ptr<Entity>& e : entities)
	{
		actions.push_back(e->getAction());
	}

	if (actions.size() > 0)
	{
		for (int i = 0; i < actions.size() - 2; i++)
		{
			if (sortByTime(actions.at(i), actions.at(i + 1)))
			{
				std::shared_ptr<Action> temp = actions.at(i);
				actions.at(i) = actions.at(i + 1);
				actions.at(i + 1) = temp;
			}
		}
	}
	
}

void BattleState::onExit()
{

}

bool BattleState::sortByTime(std::shared_ptr<Action> a, std::shared_ptr<Action> b)
{
	return a->timeRemaining() > b->timeRemaining();
}
