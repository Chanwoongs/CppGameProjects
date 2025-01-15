#pragma once

#include <Level/Level.h>

// 소코반 게임 레벨
class DrawableActor;
class Player;
class Box;
class Target;
class GameLevel : public Level
{
    RTTI_DECLARATIONS(GameLevel, Level)

public:
    GameLevel();

    virtual void Draw() override;

private:

    // 벽/땅 액터 배열
    List<DrawableActor*> map;

    // 박스 액터
    List<Box*> boxes;

    // 타겟 액터
    List<Target*> targets;

    // 플레이어 액터
    Player* player = nullptr;
};