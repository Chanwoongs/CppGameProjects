#include "TestLevel.h"

#include <Windows.h>

#include "Actor/Actor.h"
#include "Engine/Engine.h"

TestLevel::TestLevel()
{
	// 테스트로 액터 추가
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
	AddActor(new Actor());
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
}