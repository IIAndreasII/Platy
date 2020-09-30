#ifndef C_OBSERVER_H
#define C_OBSERVER_H

class CObservable;

class CObserver
{
public:
	virtual ~CObserver() = default;

	virtual void OnNotified(const CObservable* observable) = 0;

protected:
	CObserver() = default;
};

#endif
