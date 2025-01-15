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
}
