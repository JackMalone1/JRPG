#pragma once
#include "IState.h"
#include "StateMachine.h"
#include "TileMap.h"
#include <iostream>
#include <imgui.h>
#include <imgui-SFML.h>

class MainMenuState :
	public IState
{
	StateMachine& m_stateMachine;
	TileMap map;
public:
	MainMenuState(StateMachine& stateMachine);
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void onEnter() override;
	virtual void onEnter(std::string mapName) override;
	virtual void onEnter(std::vector<std::shared_ptr<Entity>>) override;
	virtual void onEnter(std::shared_ptr<Action>) override {};
	virtual void onExit() override;
};

