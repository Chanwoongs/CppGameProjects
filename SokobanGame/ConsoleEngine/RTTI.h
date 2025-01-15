﻿#pragma once

// @refactor : 경고를 일부러 무시 시켰기 때문에 문제가 된다면 고쳐야 함
// ctrl + shift + t 에서 @refactor를 검색
// 작성자 : 방찬웅
// - 경고를 일부러 무시 시켰기 때문에 문제가 된다면 고쳐야 함
#pragma warning (disable : 4172)

#include "Core.h"

// 상속 관계에 있는 클래스 간의
// 동적(실행중에) 형변환을 빠르게 하기 위해 사용하는 클래스.
// RunTime-Type-Information.
class ENGINE_API RTTI
{
public:
	virtual const size_t& TypeIdInstance() const = 0;

	virtual bool Is(const size_t id) const
	{
		return false;
	}

	template<typename T>
	T* As()
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}

	template<typename T>
	const T* As() const
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}
};

// 런타임에 빠르게 타입을 확인하기 위한 작업
// dynamic_cast 연산자를 활용해야 하는데 성능을 위해 커스텀 버전 사용
// 최적화를 하려면 재귀보단 Caching을 해서 추론한 타입들은 미리 저장해놓을 수 있게
#define RTTI_DECLARATIONS(Type, ParentType)												\
public:																					\
	using Super = ParentType;															\
	virtual const size_t& TypeIdInstance() const { return Type::TypeIdClass(); }		\
	static const size_t TypeIdClass()													\
	{																					\
		static int runTimeTypeId = 0;													\
		return reinterpret_cast<size_t>(&runTimeTypeId);								\
	}																					\
	virtual bool Is(const size_t id) const												\
	{																					\
		if (id == TypeIdClass())														\
		{																				\
			return true;																\
		}																				\
		else																			\
		{																				\
			return Super::Is(id);														\
		}																				\
	}