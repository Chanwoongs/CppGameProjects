#include "PrecompiledHeader.h"

#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{
}

Level::~Level()
{
	// 메모리 해제
    for (Actor* actor : actors)
    {
        delete actor;
    }
}

void Level::Update(float deltaTime)
{
	// 레벨에 포함된 액터를 순회하면서 Update 함수 호출
    for (Actor* actor : actors)
    {
        if (!actor->isActive || actor->isExpired)
        {
            continue;
        }
        actor->Update(deltaTime);
    }
}

void Level::Draw()
{	
	// 레벨에 포함된 액터를 순회하면서 Draw 함수 호출
    for (Actor* actor : actors)
    {
        actor->Draw();
    }
}

void Level::AddActor(Actor* newActor)
{
    //actors.PushBack(newActor);
    addRequestedActor = newActor;
}

void Level::ProcessAddedAndDestroyActor()
{
    // 삭제 요청된 액터 처리
    for (int i = 0; i < actors.Size();)
    {
        if (actors[i]->isExpired)
        {
            delete actors[i];
            actors[i] = nullptr;
            actors.Erase(i);
        }
        ++i;
    }

    // 추가 요청된 액터 처리
    if (addRequestedActor)
    {
        actors.PushBack(addRequestedActor);
        addRequestedActor = nullptr;
    }
}

//void Level::DestroyActor()
//{
//    for (int i = 0; i < actors.Size();)
//    {
//        if (actors[i]->isExpired)
//        {
//            delete actors[i];
//            actors[i] = nullptr;
//            actors.Erase(i);
//        }
//        ++i;
//    }
//}