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
	// ���� Ÿ�� ������
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTIme = 0;

	// CPU 
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency); // CPU�� ������ �ִ� hz ��ȯ

	// ���� �ð� �� ���� �ð��� ���� ����
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	// long long == __int64 == int64_t
	int64_t currentTime = time.QuadPart; // 64bit �� ���� ����
	int64_t previousTime = 0;

	// ������ ����
	float targetFrameRate = 60.0f;

	// �� ������ �ð� ���
	float targetOneFrameTime = 1.0f / targetFrameRate;

	// Game Loop
	while (true)
	{
		if (quit)
		{
			break;
		}

		// ���� ������ �ð� ����
		// currentTime = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// ������ �ð� ���
		float deltaTime = static_cast<float>(currentTime - previousTime) / 
			static_cast<float>(frequency.QuadPart);

		// ������ Ȯ��
		if (deltaTime >= targetOneFrameTime)
		{
			ProcessInput();
			Update(deltaTime);
			Draw();

			// ���� ������ �ð� ����
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
