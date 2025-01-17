﻿#pragma once

#pragma warning (disable : 4251)

#include <iostream>

// template에는 dllexport를 쓰는게 아니다.
template <typename T>
class List
{
public:
    List()
    {
        ReAllocate(2);
    }

    ~List()
    {
        if (data != nullptr)
        {
            delete[] data;
        }
    }

    void PushBack(const T& value)
    {
        if (size == capacity)
        {
            ReAllocate(capacity * 2);
        }

        data[size] = value;
        size++;
    }

    void PushBack(T&& value)
    {
        if (size <= capacity)
        {
            ReAllocate(capacity * 2);
        }

        data[size] = std::move(value);
        size++;
    }

    int Size() const
    {
        return size;
    }

    int Capacity() const
    {
        return capacity;
    }

    const T& operator[](int index) const
    {
        if (index >= size)
        {
            __debugbreak();
        }

        return data[index];
    }

    T& operator[](int index)
    {
        if (index >= size)
        {
            __debugbreak();
        }

        return data[index];
    }

	T* begin() const
	{
		return data;
	}
	
	T* end() const
	{
		return data + size;
	}

private:
    void ReAllocate(int newCapacity)
    {
        T* newBlock = new T[newCapacity];
        memset(newBlock, 0, sizeof(T) * newCapacity);

        if (newCapacity < size)
        {
            size = newCapacity;
        }

        memcpy(newBlock, data, sizeof(T) * capacity);

        delete[] data;
        data = newBlock;
        capacity = newCapacity;
    }

private:
    T* data = nullptr;
    int size = 0;
    int capacity = 0;
};