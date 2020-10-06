#ifndef TEST_OBSERVABLE_H
#define TEST_OBSERVABLE_H

#include "Platy.Core/Components/CObservable.h"

class CObserver;

class TestObservable : public CObservable
{
public:
	TestObservable(CObserver* observer, int data);
	~TestObservable() override = default;

	void UpdateData(int newData);

private:
	int myData;
};

#endif
