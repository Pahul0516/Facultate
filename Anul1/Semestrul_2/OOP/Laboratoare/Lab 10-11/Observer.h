#pragma once
#include <vector>

using std::vector;

class Observer
{
public:
	virtual void update() = 0;
};

class Observable {

	vector<Observer*> interesati;

public:
	void notify();
	void addObserver(Observer* o);
	void removeObserver(Observer* o);

};
