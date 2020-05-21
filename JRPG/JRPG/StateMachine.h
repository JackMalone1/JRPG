#pragma once
#include <map>
#include <string>
#include "IState.h"
#include "EmptyState.h"
#include <SFML/Graphics.hpp>
#include <memory>
class StateMachine
{
	std::map<std::string, std::shared_ptr<IState>> states;
	std::shared_ptr<IState> currentState;
public:
	StateMachine();
	void update(float dt);
	void render(sf::RenderWindow& window);
	void changeState(std::string stateName);
	void changeState(std::string stateName, std::string mapName);
	void changeState(std::string stateName, std::shared_ptr<Action> action);
	void addState(std::string stateName, std::shared_ptr<IState> state);
	std::map<std::string, std::shared_ptr<IState>> getMap() { return states; }
};

