#pragma once

// pch를 사용하면
// 빌드 프로세스의 속도를 높임, 시간 단축, 컴파일 시간이 오래 걸린다.
// Header를 하나 정해서 컴파일을 미리 해놓고, 컴파일 된 헤더를 가져다 쓴다.

// 미리 컴파일된 헤더
#include <iostream>
#include <Windows.h>

#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 메모리 삭제 함수
template<typename T>
void SafeDelete(T* pointer)
{
	if (pointer != nullptr)
	{
		delete pointer;
		pointer = nullptr;
	}
}

// 디버깅 용도
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

#if ENGINE_BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif