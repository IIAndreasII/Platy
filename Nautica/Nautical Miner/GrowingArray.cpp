#include "pch.h"
#include "GrowingArray.h"

template<typename T>
inline GrowingArray<T>::GrowingArray() :
	myCapacity(DEFAULT_CAPACITY)
{
	myArray = T[myCapacity];
}

template<typename T>
inline GrowingArray<T>::~GrowingArray()
{
	Clear();
	SafeDelete(myArray);
}

template<typename T>
inline void GrowingArray<T>::Add(T element)
{
	if ((mySize + 1) / myCapacity > DEFAULT_LOAD_FACTOR) {
		Resize();
	}
	myArray[mySize] = element;
	mySize++;
}

template<typename T>
void GrowingArray<T>::RemoveAt(const unsigned index)
{
	SafeDelete(myArray[index]);
	for (size_t i = index; i < size; i++)
	{
		myArray[i] = myArray[i + 1];
	}
	size--;
}

template<typename T>
const T& GrowingArray<T>::At(const unsigned index)
{
	return myArray[index];
}

template<typename T>
void GrowingArray<T>::Clear()
{
	for (auto it : myArray) 
	{
		SafeDelete(it);
	}
	SafeDelete(myArray);
	myCapacity = DEFAULT_CAPACITY;
	myArray = T[myCapacity];
	size = 0;
}

template<typename T>
const unsigned& GrowingArray<T>::size()
{
	return mySize;
}

template<typename T>
inline void GrowingArray<T>::Resize()
{
	myCapacity *= 2;
	T* tempArray = new T[myCapacity];
	for (size_t i = 0; i < mySize; i++)
	{
		tempArray[i] = myArray[i];
	}
	SafeDelete(myArray);
	myArray = tempArray;
}