#include "Player.h"

#include "Engine/Engine.h"

Player::Player(const Vector2& position)
    : DrawableActor("P")
{
    this->position = position;

    color = Color::White;
}

void Player::Update(float deltaTime)
{
    Super::Update(deltaTime);

    if (Engine::Get().GetKeyDown(VK_ESCAPE))
    {
        Engine::Get().QuitGame();
    }

    // 상하좌우
    if (Engine::Get().GetKeyDown(VK_LEFT))
    {
        position.x -= 1;
        position.x = position.x < 0 ? 0 : position.x;
    }   
    if (Engine::Get().GetKeyDown(VK_RIGHT))
    {
        position.x += 1;
        position.x = position.x >= Engine::Get().ScreenSize().x ? Engine::Get().ScreenSize().x : position.x;
    }
    if (Engine::Get().GetKeyDown(VK_UP))
    {
        position.y -= 1;
        position.y = position.y < 0 ? 0 : position.y;
    }
    if (Engine::Get().GetKeyDown(VK_DOWN))
    {
        position.y += 1;
        position.y = position.y >= Engine::Get().ScreenSize().y ? Engine::Get().ScreenSize().y : position.y;
    }
}
