#include "Engine.h"

#include <iostream>
#include <Windows.h>

Engine::Engine()
	: quit(false)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// 시작 타임 스탬프
	unsigned long currentTime = timeGetTime();
	unsigned long previousTIme = 0;

	// 프레임 제한
	float targetFrameRate = 60.0f;

	// 한 프레임 시간 계산
	float targetOneFrameTime = 1.0f / targetFrameRate;

	// Game Loop
	while (true)
	{
		if (quit)
		{
			break;
		}

		// 현재 프레임 시간 저장
		currentTime = timeGetTime();

		// 프레임 시간 계산
		float deltaTime = static_cast<float>(currentTime - previousTIme) / 1000.0f;

		// 프레임 확인
		if (deltaTime >= targetOneFrameTime)
		{
			ProcessInput();
			Update(deltaTime);
			Draw();

			// 이전 프레임 시간 저장
			previousTIme = currentTime;
		}
	}
}

void Engine::ProcessInput()
{
}

void Engine::Update(float deltaTime)
{
	std::cout << "DeltaTime: " << deltaTime << ", Fps: " << (1.0f / deltaTime) << '\n';
}

void Engine::Draw()
{
}
