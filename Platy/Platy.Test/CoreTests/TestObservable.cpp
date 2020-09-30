#include "TestObservable.h"

TestObservable::TestObservable(CObserver* observer, const int data)
	:
	CObservable(),
	myData(data)
{
	AddObserver(observer);
}

void TestObservable::UpdateData(const int newData)
{
	myData = newData;
	NotifyObservers(this);
}
