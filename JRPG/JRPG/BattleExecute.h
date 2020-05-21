#pragma once
#include "IState.h"
#include "StateMachine.h"
#include "Action.h"
class BattleExecute : public IState
{
public:
	BattleExecute(StateMachine& stateMachine, std::vector<std::shared_ptr<Action>>);
	virtual void update(float dt) override {};
	virtual void render(sf::RenderWindow& window) override {};
	virtual void onEnter() override {};
	virtual void onEnter(std::string mapName) override {};
	virtual void onEnter(std::vector<std::shared_ptr<Entity>>) override {};
	virtual void onEnter(std::shared_ptr<Action>) override {};
	virtual void onExit() override {};
};

