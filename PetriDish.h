/*
 * PetriDish.h
 *
 *  Created on: 11 ????? 2018
 *      Author: Shahar Dekel
 */

#ifndef PETRIDISH_H_
#define PETRIDISH_H_
#include "Bacteria.h"
#include "ActiveBacteria.h"
#include "LazyBacteria.h"
#include "HungryBacteria.h"
#include "DieteticBacteria.h"

#include <vector>

using std::vector;

class PetriDish
{
public:
	PetriDish(): _food(0), _bacteriaPopulation() {};

	//Destructor
	~PetriDish();
	void clean();
	void addFood( int addedAmount );
	void addBacteria( Bacteria* newBacteriaPtr );
	void print() const ;
	void removeDeadBacteria();
	void updatePopulation( int timeUnits );
	//Assignment operator "="
	const PetriDish& operator = (const PetriDish& anotherPetriDish);


private:

	//Copy constructor
	PetriDish(const PetriDish& orgPetriDish): _food(orgPetriDish._food),
				_bacteriaPopulation(orgPetriDish._bacteriaPopulation) {}
	int _food;
	vector<Bacteria*> _bacteriaPopulation;

};

#endif /* PETRIDISH_H_ */
