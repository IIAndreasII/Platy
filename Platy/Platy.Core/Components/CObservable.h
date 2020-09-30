#ifndef C_OBSERVABLE_H
#define C_OBSERVABLE_H

#include <vector>

class CObserver;

class CObservable
{
public:
	virtual ~CObservable() = default;

	void AddObserver(CObserver* observer);
	void RemoveObserver(CObserver* observer);

protected:
	CObservable() = default;

	void NotifyObservers();
	void NotifyObservers(CObservable* observable);

private:

	std::vector<CObserver*> myObservers;
};

#endif
