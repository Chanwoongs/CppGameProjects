#pragma once

// 전방 선언
class Actor;

class Level
{
public:
	Level();
	virtual ~Level();

	virtual void Update(float deltaTime);
	virtual void Draw();

	// 액터 추가 함수
	void AddActor(Actor* newActor);

protected:
	// 게임 공간에 배치되는 물체(Actor) 배열.
	Actor** actors;

	// 저장할 수 있는 공간의 크기
	int capacity;

	// 액터의 수
	int count;
};