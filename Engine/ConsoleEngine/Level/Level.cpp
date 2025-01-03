#include "Level.h"
//#include "../Actor/Actor.h"
#include "Actor/Actor.h"

#include <iostream>

Level::Level()
	: actors(nullptr), capacity(4), count(0)
{
	// 동적 배열 생성
	actors = new Actor*[capacity];

	// 공간의 포인터들 초기화
	memset(actors, 0, sizeof(size_t) * capacity);
}

Level::~Level()
{
	// 메모리 해제
	for (int i = 0; i < count; i++)
	{
		delete actors[i];
	}
	delete[] actors;
}

void Level::Update(float deltaTime)
{
}

void Level::Draw()
{
}

void Level::AddActor(Actor* newActor)
{
}
