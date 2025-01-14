#include "Enemy.h"

#include "Engine/Engine.h"

Enemy::Enemy(const char* image, int yPosition)
    : DrawableActor(image)
{
    this->position = Vector2(0, yPosition);
}

void Enemy::Update(float deltaTime)
{
    xPosition += speed * deltaTime;
    position.x = (int)xPosition;

    if (xPosition > Engine::Get().ScreenSize().x)
    {
        Destroy();
        return;
    }
}
