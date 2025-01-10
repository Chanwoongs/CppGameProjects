﻿#include "TextScrollActor.h"

#include "Engine/Engine.h"

TextScrollActor::TextScrollActor(const char* message)
{
    // 문자열 길이 구하기.
    length = strlen(message);
    
    // 문자열 복사.
    string = new char[length + 1];
    strcpy_s(string, length + 1, message);

    // 커서 감추기.
    Engine::Get().SetCursorType(CursorType::NoCursor);
}

TextScrollActor::~TextScrollActor()
{
    delete[] string;
}

void TextScrollActor::Update(float deltaTime)
{
    elapsedTime += deltaTime;

    if (Engine::Get().GetKeyDown(VK_ESCAPE))
    {
        Engine::Get().QuitGame();
    }

    // 딜레이 계산
    if (elapsedTime < delayTime)
    {
        return;
    }

    elapsedTime = 0.0f;
    
    // 화면에 그릴 문자열의 시작 인덱스 업데이트.
    index = (index + 1) % length;
}

void TextScrollActor::Draw()
{
    // 임시 문자열 버퍼.
    char* temp = new char[printWidth + 1];
    int tempIndex = index;

    for (int i = 0; i < printWidth; i++)
    {
        temp[i] = string[tempIndex];
        tempIndex = (tempIndex + 1) % length;
    }

    temp[printWidth] = '\0';
    Log(temp);

    delete[] temp;
    Engine::Get().SetCursorPosition(0, 0);
}