#pragma once

#include <Level/Level.h>

// 소코반 게임 레벨
class DrawableActor;
class GameLevel : public Level
{
    RTTI_DECLARATIONS(GameLevel, Level)

public:
    GameLevel();

private:
    List<DrawableActor*> map;
};