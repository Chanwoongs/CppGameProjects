#include <iostream>

#include "Game/Game.h"
#include "Level/TestLevel.h"

int main()
{
    CheckMemoryLeak();
	Game game;
	game.LoadLevel(new TestLevel());
	game.Run();
}