#include "BattleState.h"

BattleState::BattleState(StateMachine stateMachine)
{
	m_stateMachine.addState("tick", std::make_shared<BattleTick>(m_stateMachine, actions));

	m_stateMachine.addState("execute", std::make_shared<BattleExecute>(m_stateMachine, actions));
}

void BattleState::update(float dt)
{

}

void BattleState::render(sf::RenderWindow& window)
{

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

	for (std::shared_ptr<Entity>& e : entities)
	{
		if (e->playerControlled())
		{

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
