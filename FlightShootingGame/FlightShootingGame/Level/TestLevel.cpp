#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"

#include "Core.h"

TestLevel::TestLevel()
{
    AddActor(new Player("_[..'<A>'..]_"));
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
}
