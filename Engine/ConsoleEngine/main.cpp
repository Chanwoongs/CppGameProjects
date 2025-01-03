#include <iostream>

#include "Engine/Engine.h"
#include "TestLevel.h"

int main()
{
	Engine engine;

	//////////////////////
	// 로그 시스템 초기화
	//////////////////////

	engine.LoadLevel(new TestLevel());
	engine.Run();
}