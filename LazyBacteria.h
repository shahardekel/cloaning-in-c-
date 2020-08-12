#ifndef LAZYBACTERIA_H_
#define LAZYBACTERIA_H_

#include "Bacteria.h"

//"son" bacteria
class LazyBacteria: public Bacteria
{
public:
	LazyBacteria(int bacteriaId, int eatingRate, int adultAge, int foodUnits):
		Bacteria(bacteriaId, eatingRate * two, adultAge * two,
																foodUnits) {}
	// constructor
	LazyBacteria(): Bacteria() {}
	//default constructor
	LazyBacteria(const LazyBacteria& otherBacteria):
													Bacteria(otherBacteria){};
	// copy constructor
	virtual Bacteria* clone();
	virtual void print() const;
	virtual ~LazyBacteria();

private:
	const static std::string name;
};


#endif
