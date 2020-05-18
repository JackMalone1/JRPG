#include "StateStack.h"

void StateStack::Update(float elapsedTime)
{
	std::shared_ptr<IState> top = std::make_shared<IState>(stack.top());
	top->update(elapsedTime);
}

void StateStack::Render(sf::RenderWindow& window)
{
	std::shared_ptr<IState> top = std::make_shared<IState>(stack.top());
	top->render(window);
}

void StateStack::Push(std::string name)
{
	std::shared_ptr<IState> state = states[name];
	stack.push(state);
}

void StateStack::Pop()
{
	stack.pop();
}
