#include "TextScrollActor.h"

#include "Engine/Engine.h"

TextScrollActor::TextScrollActor(const char* message)
{
    // 문자열 길이 구하기.
    length = strlen(message);
    
    // 문자열 복사.
    string = new char[length + 1];
    tempString = new char[length + 1];
    strcpy_s(string, length + 1, message);

    // 커서 감추기.
    Engine::Get().SetCursorType(CursorType::NoCursor);
}

TextScrollActor::~TextScrollActor()
{
    delete[] string;
    delete[] tempString;
}

void TextScrollActor::Update(float deltaTime)
{
    elapsedTime += deltaTime;

    if (Engine::Get().GetKeyDown(VK_ESCAPE))
    {
        Engine::Get().QuitGame();
    }

    // 좌우 방향키 입력 처리
    if (Engine::Get().GetKey(VK_LEFT))
    {
        // 방향 설정
        direction = Direction::Left;
        shouldUpdate = true;
    }
    if (Engine::Get().GetKey(VK_RIGHT))
    {
        direction = Direction::Right;
        shouldUpdate = true;
    }

    // 방향키가 안눌렸는지 확인
    if (!Engine::Get().GetKey(VK_LEFT) && !Engine::Get().GetKey(VK_RIGHT))
    {
        shouldUpdate = false;
    }

    // 딜레이 계산
    if (elapsedTime < delayTime)
    {
        return;
    }

    elapsedTime = 0.0f;
    

    if (shouldUpdate)
    {
        // 화면에 그릴 문자열의 시작 인덱스 업데이트.
        if (direction == Direction::Right)
        {
            index = (index + 1) % length;
        }
        else if (direction == Direction::Left)
        {
            index = (index - 1 + length) % length;
        }
    }    
}

void TextScrollActor::Draw()
{
    // 임시 문자열 버퍼.
    int tempIndex = index;

    for (int i = 0; i < printWidth; i++)
    {
        tempString[i] = string[tempIndex];
        tempIndex = (tempIndex + 1) % length;
    }

    tempString[printWidth] = '\0';
    Log(tempString);

    Engine::Get().SetCursorPosition(0, 0);
}