#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"

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

    // 적 생성
    static float elapsedTime = 0.0f;
    static float spawnTime = RandomPercent(1.0f, 3.0f);

    // 타이머
    elapsedTime += deltaTime;
    if (elapsedTime < spawnTime)
    {
        return;
    }

    // 타이머 리셋
    elapsedTime = 0.0f;
    spawnTime = RandomPercent(1.0f, 3.0f);

    // 적 생성
    AddActor(new Enemy("^_^", Random(1, 10)));
}
