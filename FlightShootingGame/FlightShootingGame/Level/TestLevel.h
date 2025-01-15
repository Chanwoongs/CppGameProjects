#pragma once

#include "Level/Level.h"

class TestLevel : public Level
{
    // RTTI
    RTTI_DECLARATIONS(TestLevel, Level)

public:
	TestLevel();
	~TestLevel();

	virtual void Update(float deltaTime) override;

    void SpawnActor(float deltaTime);

private:
    // 적 생성 함수
};