#ifndef HUNGRYBACTERIA_H_
#define HUNGRYBACTERIA_H_


#include "Bacteria.h"

//"son" bacteria
class HungryBacteria: public Bacteria
{
public:
	HungryBacteria(int bacteriaId, int eatingRate, int adultAge, int foodUnits):
		Bacteria(bacteriaId, eatingRate, adultAge, foodUnits * two) {}
	// constructor
	HungryBacteria(): Bacteria() {}
	//default constructor
	HungryBacteria(const HungryBacteria& otherBacteria):
		 	 	 	 	 	 	 	 	 	 	 	 Bacteria(otherBacteria){};
	// copy constructor
	virtual Bacteria* clone();
	virtual void print() const;
	virtual ~HungryBacteria();

private:
	const static std::string name;
};


#endif
