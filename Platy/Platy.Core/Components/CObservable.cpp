#include "CObservable.h"
#include "CObserver.h"

#include <algorithm>

void CObservable::AddObserver(CObserver* observer)
{
	myObservers.push_back(observer);
}

void CObservable::RemoveObserver(CObserver* observer)
{
	const auto it = std::find(myObservers.begin(), myObservers.end(), observer);
	if (it != myObservers.end())
	{
		myObservers.erase(it);
	}
}

void CObservable::NotifyObservers()
{
	for (auto* it : myObservers)
	{
		it->OnNotified(nullptr);
	}
}

void CObservable::NotifyObservers(CObservable* observable)
{
	for (auto* it : myObservers)
	{
		it->OnNotified(this);
	}
}
