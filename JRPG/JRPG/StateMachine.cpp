#include "StateMachine.h"

StateMachine::StateMachine()
{
	currentState = std::make_shared<EmptyState>();
}

void StateMachine::update(float dt)
{
	currentState->update(dt);
}

void StateMachine::render(sf::RenderWindow& window)
{
	currentState->render(window);
}

void StateMachine::changeState(std::string stateName)
{
	currentState->onExit();
	currentState = states[stateName];
	currentState->onEnter();
}

void StateMachine::changeState(std::string stateName, std::string mapName)
{
	currentState->onExit();
	currentState = states[stateName];
	currentState->onEnter(mapName);
}

void StateMachine::changeState(std::string stateName, std::shared_ptr<Action> action)
{
	currentState->onExit();
	currentState = states[stateName];
	currentState->onEnter(mapName);
}

void StateMachine::addState(std::string stateName, std::shared_ptr<IState> state)
{
	states[stateName] = state;
}
