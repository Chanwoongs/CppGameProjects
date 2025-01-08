#include "PrecompiledHeader.h"
#include "DrawableActor.h"

DrawableActor::DrawableActor(char image)
    : Actor(), image(image)
{
}

void DrawableActor::Draw()
{
    Super::Draw();

    // 그리기
    // 1단계: 콘솔 좌표 옮기기

    // 2단계: 그리기 (콘솔 출력)

}

void DrawableActor::SetPosition(const Vector2& newPosition)
{
}
