#include "Level.h"
//#include "../Actor/Actor.h"
#include "Actor/Actor.h"

#include <iostream>

Level::Level()
	: actors(nullptr), capacity(4), count(0)
{
	// ���� �迭 ����
	actors = new Actor*[capacity];

	// ������ �����͵� �ʱ�ȭ
	memset(actors, 0, sizeof(size_t) * capacity);
}

Level::~Level()
{
	// �޸� ����
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
