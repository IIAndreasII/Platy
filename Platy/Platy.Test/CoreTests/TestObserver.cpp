#include "TestObserver.h"

#include <iostream>

#include "Platy.Core/Components/CObservable.h"

void TestObserver::OnNotified(const CObservable* observable)
{
	std::cout << "I was notified!" << std::endl;
}
