#pragma once
#include <SFML/Graphics.hpp>
class IState
{
public:
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void onEnter() = 0;
	virtual void onEnter(std::string mapName) = 0;
	virtual void onExit() = 0;
};

