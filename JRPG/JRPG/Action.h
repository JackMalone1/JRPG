#pragma once
#include <SFML/Graphics.hpp>
class Action
{
protected:
	sf::Clock timer;
public:
	virtual int timeRemaining() = 0;
};

