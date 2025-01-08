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

private:

};