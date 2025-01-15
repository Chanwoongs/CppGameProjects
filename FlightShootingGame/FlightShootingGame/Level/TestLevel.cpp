#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"
#include "Actor/PlayerBullet.h"
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

    // 예외 처리
    // 플레이어가 안나왔던 이유
    // 처음에 몇 프레임은 너무 크기 때문에 안정화가 필요하다
    // 아래에서 delatTime이 1000만이 나와서 이상했다.
    if (deltaTime > 1.0f)
    {
        return;
    }

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

    SpawnActor(deltaTime);

    //플레이어 탄약과 적의 충돌 처리
    ProcessCollisionPlayerBulletAndEnemy();
}

void TestLevel::SpawnActor(float deltaTime)
{
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

void TestLevel::ProcessCollisionPlayerBulletAndEnemy()
{
    // 탄약 및 적 캐릭터 배열 선언
    List<PlayerBullet*> bullets;
    List<Enemy*> enemies;

    // 레벨에 배치된 액터를 순회하면서 리스트 채우기
    for (Actor* actor : actors)
    {
        // 형변환 후 확인해서 리스트 채우기
        PlayerBullet* bullet = actor->As<PlayerBullet>();
        if (bullet)
        {
            bullets.PushBack(bullet);
            continue;
        }
        Enemy* enemy = actor->As<Enemy>();
        if (enemy)
        {
            enemies.PushBack(enemy);
            continue;
        }
    }

    // 예외 처리
    if (bullets.Size() == 0 || enemies.Size() == 0)
    {
        return;
    }

    // 두 배열을 순회하면서 충돌 처리
    for (PlayerBullet* bullet : bullets)
    {
        for (Enemy* enemy : enemies)
        {
            // 적이 비활성화 상태라면 건너뛰기
            if (!enemy->IsActive())
            {
                continue;
            }

            // 충돌 처리
            if (enemy->Intersect(*bullet))
            {
                // 충돌 했으면 적 제거
                enemy->Destroy();
                // 탄약도 제거
                bullet->Destroy();
            }
        }
    }
}