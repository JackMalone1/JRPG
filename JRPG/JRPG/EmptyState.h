#pragma once
#include "IState.h"
class EmptyState :
	public IState
{
public:
	virtual void update(float dt) override;
	virtual void render(sf::RenderWindow& window) override;
	virtual void onEnter() override;
	virtual void onEnter(std::string mapName) override;
	virtual void onEnter(std::vector<std::shared_ptr<Entity>>) override;
	virtual void onEnter(std::shared_ptr<Action>) override {};
	virtual void onExit() override;
};

