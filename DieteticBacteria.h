#ifndef DIETETICBACTERIA_H_
#define DIETETICBACTERIA_H_


#include "Bacteria.h"

//"son" bacteria
class DieteticBacteria: public Bacteria
{
public:

	DieteticBacteria(int bacteriaId, int eatingRate, int adultAge,
			int foodUnits):
		Bacteria(bacteriaId, eatingRate, adultAge, foodUnits / two) {}
	// constructor
	DieteticBacteria(): Bacteria() {}
	//default constructor
	DieteticBacteria(const DieteticBacteria& otherBacteria):
													Bacteria(otherBacteria){};
	// copy constructor
	virtual Bacteria* clone();
	virtual void print() const;
	virtual ~DieteticBacteria();

private:

	const static std::string name;

};


#endif 
