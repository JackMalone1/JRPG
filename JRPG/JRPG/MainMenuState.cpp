#include "MainMenuState.h"

MainMenuState::MainMenuState(StateMachine& stateMachine) : m_stateMachine{stateMachine}
{
	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	if (!map.load("Assets\\TileSets\\graphics-vertex-array-tilemap-tileset.png", sf::Vector2u(32, 32), level, 16, 8))
		std::cout << "error loading tileset" << std::endl;
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::render(sf::RenderWindow& window)
{
	window.draw(map);
}

void MainMenuState::onEnter()
{

}

void MainMenuState::onEnter(std::string mapName)
{
}

void MainMenuState::onEnter(std::vector<std::shared_ptr<Entity>>)
{
}

void MainMenuState::onExit()
{

}
