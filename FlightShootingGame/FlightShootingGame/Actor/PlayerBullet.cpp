#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(const Vector2& position)
    : DrawableActor("!")
{
    // 탄약 위치 설정
    this->position = position;
    yPosition = (float)position.y;
}

void PlayerBullet::Update(float deltaTime)
{
    Super::Update(deltaTime);

    // 위치 갱신
    //// 프레임 단위 이동
    //--position.y;

    // 프레임 시간을 고려한 이동 
    // 5칸 * 60번 * (x) = 5칸, x == deltaTime
    yPosition -= speed * deltaTime;
    position.y = (int)yPosition;

    // y 좌표가 화면을 벗어나면 액터 삭제
    if (yPosition < 0.0f) // 0.0f으로 해야 잔상이 안남음. position.y로 하면 -0.1일 때 0이기 때문에 오류.
    {
        Destroy();
        return;
    }
}