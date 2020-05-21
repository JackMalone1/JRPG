#pragma once
#include <SFML/Graphics.hpp>
class Action
{
protected:
	sf::Clock timer;
public:
	virtual int timeRemaining() = 0;
	virtual void update(float dt) = 0;
	virtual bool isReady() = 0;
};

