#pragma once

#include <Actor/DrawableActor.h>

class Enemy : public DrawableActor
{
    RTTI_DECLARATIONS(Enemy, DrawableActor)

public:
    // 그릴 때 사용할 문자열 값과 생성 y위치를 전달 받음
    Enemy(const char* image, int yPosition);
    ~Enemy() = default;

    virtual void Update(float deltaTime);

private:

    //  좌우 이동에 필요한 변수
    float xPosition = 0.0f;
    float speed = 5.0f;
};