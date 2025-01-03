#include "TestLevel.h"

#include <Windows.h>

#include "Actor/Actor.h"
#include "Engine/Engine.h"

TestLevel::TestLevel()
{
	// �׽�Ʈ�� ���� �߰�
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