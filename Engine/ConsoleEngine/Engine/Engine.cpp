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
	unsigned long currentTime = timeGetTime();
	unsigned long previousTIme = 0;

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
		currentTime = timeGetTime();

		// ������ �ð� ���
		float deltaTime = static_cast<float>(currentTime - previousTIme) / 1000.0f;

		// ������ Ȯ��
		if (deltaTime >= targetOneFrameTime)
		{
			ProcessInput();
			Update(deltaTime);
			Draw();

			// ���� ������ �ð� ����
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
