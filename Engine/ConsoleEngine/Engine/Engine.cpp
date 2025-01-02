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
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTIme = 0;

	// CPU 
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency); // CPU가 가지고 있는 hz 반환

	// 시작 시간 및 이전 시간을 위한 변수
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	// long long == __int64 == int64_t
	int64_t currentTime = time.QuadPart; // 64bit 한 번에 저장
	int64_t previousTime = 0;

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
		// currentTime = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// 프레임 시간 계산
		float deltaTime = static_cast<float>(currentTime - previousTime) / 
			static_cast<float>(frequency.QuadPart);

		// 프레임 확인
		if (deltaTime >= targetOneFrameTime)
		{
			ProcessInput();
			Update(deltaTime);
			Draw();

			// 이전 프레임 시간 저장
			previousTime = currentTime;
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
