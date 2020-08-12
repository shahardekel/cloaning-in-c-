/*
 * ActiveBacteria.h
 *
 *  Created on: 30 בדצמ× 2018
 *      Author: Yamit Gvinter
 */
#include "Bacteria.h"

#ifndef ACTIVEBACTERIA_H_
#define ACTIVEBACTERIA_H_

using std::string;

//"son" bacteria
class ActiveBacteria: public Bacteria
{
public:

	 ActiveBacteria(int bacteriaId, int eatingRate, int adultAge,
			 int foodUnits):
		 Bacteria(bacteriaId, eatingRate / two, adultAge / two,
				 	 	 	 	 	 	 	 	 	 	 	 	 foodUnits) {}
	 //constructor
	 ActiveBacteria(): Bacteria(){}
	//default constructor
	 ActiveBacteria(const ActiveBacteria& otherBacteria):
		 	 	 	 	 	 	 	 	 	 	 	 Bacteria(otherBacteria){};
	 // copy constructor
	 virtual Bacteria* clone();
	 virtual void print() const;
	 virtual ~ActiveBacteria();
	 //Destructor

private:

	const static string name;

};

#endif /* ACTIVEBACTERIA_H_ */
