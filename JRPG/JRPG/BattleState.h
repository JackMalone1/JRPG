#pragma once
#include "IState.h"
#include "StateMachine.h"
#include <vector>
#include <memory>
#include "Action.h"
#include "Entity.h"
#include "BattleExecute.h"
#include "BattleTick.h"
#include <algorithm>

class BattleState :
	public IState
{
	StateMachine m_stateMachine;
	std::vector<std::shared_ptr<Action>> actions;
	std::vector<std::shared_ptr<Entity>> entities;
public:
	BattleState(StateMachine stateMachine);
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void onEnter() override;
	virtual void onEnter(std::string mapName) override;
	virtual void onEnter(std::vector<std::shared_ptr<Entity>> t_entities) override;
	virtual void onEnter(std::shared_ptr<Action>) override {};
	virtual void onExit() override;
	static bool sortByTime(std::shared_ptr<Action> a, std::shared_ptr<Action> b);
};

