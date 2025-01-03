#pragma once

// ���� ����
class Actor;

class Level
{
public:
	Level();
	virtual ~Level();

	virtual void Update(float deltaTime);
	virtual void Draw();

	// ���� �߰� �Լ�
	void AddActor(Actor* newActor);

protected:
	// ���� ������ ��ġ�Ǵ� ��ü(Actor) �迭.
	Actor** actors;

	// ������ �� �ִ� ������ ũ��
	int capacity;

	// ������ ��
	int count;
};