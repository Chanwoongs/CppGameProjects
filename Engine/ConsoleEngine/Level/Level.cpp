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
	// 레벨에 포함된 액터를 순회하면서 Update 함수 호출
	for (int i = 0; i < count; i++)
	{
		actors[i]->Update(deltaTime);
	}
}

void Level::Draw()
{	
	// 레벨에 포함된 액터를 순회하면서 Draw 함수 호출
	for (int i = 0; i < count; i++)
	{
		actors[i]->Draw();
	}
}


void Level::AddActor(Actor* newActor)
{
	// 현재 할당된 공간이 충분한지 확인
	if (count == capacity)
	{
		// 공간 추가 할당
		int newCapacity = capacity * 2;

		// 임시 공간
		Actor** temp = new Actor*[newCapacity];

		// 기존 값 복사
		memcpy(temp, actors, sizeof(size_t) * capacity);

		// 기존 값 삭제
		delete[] actors;

		// 배열 교체
		actors = temp;

		// 크기 변경
		capacity = newCapacity;

		// temp는 로컬 변수이기 때문에 자동으로 사라짐
	}

	// 액터 추가
	actors[count] = newActor;
	++count;
}
