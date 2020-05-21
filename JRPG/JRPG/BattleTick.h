#pragma once
#include "IState.h"
#include "StateMachine.h"
#include "Action.h"
class BattleTick :
	public IState
{
	StateMachine& states;
	std::vector<std::shared_ptr<Action>>& actions;
public:
	BattleTick(StateMachine& stateMachine, std::vector<std::shared_ptr<Action>>& t_actions);
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void onEnter() override;
	virtual void onEnter(std::string mapName) override;
	virtual void onEnter(std::vector<std::shared_ptr<Entity>> t_entities) override;
	virtual void onEnter(std::shared_ptr<Action>) override {};
	virtual void onExit() override;
};

