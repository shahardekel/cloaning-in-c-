/*
 * PetriDish.h
 *
 *  Created on: 11 ????? 2018
 *      Author: Shahar Dekel
 */

#ifndef PETRIDISH_H_
#define PETRIDISH_H_
#include "Bacteria.h"
#include <vector>

using std::vector;

class PetriDish
{
public:
	PetriDish(): _food(0), _bacteriaPopulation() {};
	// definition of a Copy constructor: (rule of big 3)
	PetriDish(const PetriDish& orgPetriDish): _food(orgPetriDish._food),
			_bacteriaPopulation(orgPetriDish._bacteriaPopulation) {}
	// definition of a Destructor: (rule of big 3)
	~PetriDish();
	void clean();
	void addFood( int addedAmount );
	void addBacteria( Bacteria* newBacteriaPtr );
	void print() const ;
	void removeDeadBacteria();
	void updatePopulation( int timeUnits );
	// definition of an Assignment operator "=": (rule of big 3)
	const PetriDish& operator = (const PetriDish& anotherPetriDish);
private:
	int _food;
	vector<Bacteria*> _bacteriaPopulation;


};

#endif /* PETRIDISH_H_ */
