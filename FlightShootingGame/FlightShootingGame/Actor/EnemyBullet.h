#pragma once

#include <Actor/DrawableActor.h>

class EnemyBullet : DrawableActor
{
    RTTI_DECLARATIONS(EnemyBullet, DrawableActor)

public:
    EnemyBullet(const Vector2& position);
    ~EnemyBullet() = default;

    virtual void Update(float deltaTime) override;

private:
    // 이동 관련 변수(속성)
    float speed = 15.0f;
    float yPosition = 0.0f;
};