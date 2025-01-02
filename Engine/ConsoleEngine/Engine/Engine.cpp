#include "Engine.h"

Engine::Engine()
	: quit(false)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// Game Loop
	while (true)
	{
		ProcessInput();
		Update();
		Draw();
	}
}

void Engine::ProcessInput()
{
}

void Engine::Update(float deltaTime)
{
}

void Engine::Draw()
{
}
