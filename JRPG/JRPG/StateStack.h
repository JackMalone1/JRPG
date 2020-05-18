#pragma once
#include <map>
#include <string>
#include "IState.h"
#include "EmptyState.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
class StateStack
{
	std::map<std::string, std::shared_ptr<IState>> states;
	std::stack<std::shared_ptr<IState>> stack;
public:
	void Update(float elapsedTime);
	void Render(sf::RenderWindow& window);
	void Push(std::string name);
	void Pop();
	void setMap(std::map<std::string, std::shared_ptr<IState>> t_states) { states = t_states; }
};

