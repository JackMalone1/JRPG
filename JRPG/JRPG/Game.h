#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gamepad.h"
#include "StateMachine.h"
#include "BattleState.h"
#include "EmptyState.h"
#include "InGameMenuState.h"
#include "LocalMap.h"
#include "MainMenuState.h"
#include "WorldMap.h"
#include "entt.hpp"
#include <imgui.h>
#include <imgui-SFML.h>

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void processKeyPress(sf::Event t_event);
	void setUpText();
private:
	sf::RenderWindow m_window;
	sf::Font m_font;
	Gamepad gamepad;
	StateMachine stateMachine;
};