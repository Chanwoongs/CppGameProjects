﻿#include "Engine.h"

#include <iostream>
#include <Windows.h>

#include "Level/Level.h"

// 스태틱 변수 초기화
Engine* Engine::Instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr)
{
	// 싱글톤 객체 설정
	Instance = this;
}

Engine::~Engine()
{
}

void Engine::Run()
{
	// 시작 타임 스탬프
	// timeGetTime 함수는 ms(1/1000초) 단위
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTIme = 0;

	// CPU 시계 사용
	// 시스템 시계 -> 고해상도 카운터
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

		// 프레임 시간 계산 (1000만으로 나눠서 초를 구함)
		float deltaTime = static_cast<float>(currentTime - previousTime) / 
			static_cast<float>(frequency.QuadPart);

		// 프레임 확인
		if (deltaTime >= targetOneFrameTime)
		{
			// 입력 처리 (현재 키의 눌림 상태 확인)
			ProcessInput();

			Update(deltaTime);
			Draw();

			// 키 상태 저장
			SavePreviousKeyStates();

			// 이전 프레임 시간 저장
			previousTime = currentTime;
		}
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// 기존 레벨이 있다면 삭제 후 교체

	// 메인 레벨 설정
	mainLevel = newLevel;
}

bool Engine::GetKey(int key)
{
	return keyState[key].isKeyDown;
}

bool Engine::GetKeyDown(int key)
{
	return keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

bool Engine::GetKeyUp(int key)
{
	return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
	quit = true;
}

Engine& Engine::Get()
{
	return *Instance;
}

void Engine::ProcessInput()
{
	for (int i = 0; i < 255; i++)
	{
		// (GetAsyncKeyState(i) & 0x8000) 현재 프레임에 눌렸는지 저장
		keyState[i].isKeyDown = (GetAsyncKeyState(i) & 0x8000) ? true : false;
	}
}

void Engine::Update(float deltaTime)
{
	// 레벨 업데이트
	if (mainLevel != nullptr)
	{
		mainLevel->Update(deltaTime);
	}
}

void Engine::Draw()
{
	// 레벨 그리기
	if (mainLevel != nullptr)
	{
		mainLevel->Draw();
	}
}

void Engine::SavePreviousKeyStates()
{
	for (int i = 0; i < 255; i++)
	{
		keyState[i].wasKeyDown = keyState[i].isKeyDown;
	}
}
