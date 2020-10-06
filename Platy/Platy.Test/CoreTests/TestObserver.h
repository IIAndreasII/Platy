#ifndef TEST_OBSERVER_H
#define TEST_OBSERVER_H

#include "Platy.Core/Components/CObserver.h"

class CObservable;

class TestObserver : public CObserver
{
public:
	TestObserver() = default;
	~TestObserver() override = default;


	void OnNotified(const CObservable* observable) override;
};

#endif
