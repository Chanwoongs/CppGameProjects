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
	// ���� �Ҵ�� ������ ������� Ȯ��
	if (count == capacity)
	{
		// ���� �߰� �Ҵ�
		int newCapacity = capacity * 2;

		// �ӽ� ����
		Actor** temp = new Actor*[newCapacity];

		// ���� �� ����
		memcpy(temp, actors, sizeof(size_t) * capacity);

		// ���� �� ����
		delete[] actors;

		// �迭 ��ü
		actors = temp;

		// ũ�� ����
		capacity = newCapacity;

		// temp�� ���� �����̱� ������ �ڵ����� �����
	}

	// ���� �߰�
	actors[count] = newActor;
	++count;
}
