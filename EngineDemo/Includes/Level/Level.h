#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Container/List.h"

// 전방 선언
class Actor;

class ENGINE_API Level : public RTTI
{
    // RTTI 정의
    RTTI_DECLARATIONS(Level, RTTI)

public:
	Level();
	virtual ~Level();

	virtual void Update(float deltaTime);
	virtual void Draw();

	// 액터 추가 함수
	void AddActor(Actor* newActor);

protected:
    // 게임 공간에 배치되는 물체(Actor) 배열.
    List<Actor*> actors;
};