#include "Game.h"

Game::Game() : m_window{ sf::VideoMode{ 512, 256 }, "JRPG" }
{
	gamepad.connect();
	stateMachine.addState((std::string)"mainmenu", std::make_shared<MainMenuState>(stateMachine));
	stateMachine.addState((std::string)"localmap", std::make_shared<LocalMap>(stateMachine));
	stateMachine.addState((std::string)"worldmap", std::make_shared<WorldMap>(stateMachine));
	stateMachine.addState((std::string)"battle", std::make_shared<BattleState>(stateMachine));
	stateMachine.addState((std::string)"ingamemenu", std::make_shared<InGameMenuState>(stateMachine));

	stateMachine.changeState("mainmenu");

	m_window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(m_window);
}

Game::~Game()
{
	ImGui::SFML::Shutdown();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // at least 60 fps
		ImGui::SFML::Update(m_window, clock.restart());
		update(timePerFrame);
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(event);
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		if (event.KeyPressed)
		{
			processKeyPress(event);
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	gamepad.update();
	stateMachine.update(t_deltaTime.asSeconds());
}

void Game::render()
{
	m_window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
	m_window.clear(sf::Color::White);
	stateMachine.render(m_window);
	m_window.display();
}

void Game::processKeyPress(sf::Event t_event)
{
}

void Game::setUpText()
{

}