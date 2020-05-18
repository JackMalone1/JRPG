#pragma once
#include "IState.h"
#include "StateMachine.h"

class MainMenuState :
	public IState
{
	StateMachine& m_stateMachine;
public:
	MainMenuState(StateMachine& stateMachine);
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void onEnter() override;
	virtual void onEnter(std::string mapName) override;
	virtual void onExit() override;
};
