/*
 * PETRIDISH_H_.cpp
 *
 *  Created on: 13 ????? 2018
 *      Author: Shahar Dekel
 */
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "Bacteria.h"
#include "PetriDish.h"
#include "ActiveBacteria.h"
#include "HungryBacteria.h"
#include "DieteticBacteria.h"
#include "LazyBacteria.h"

using std::endl;
using std::cout;
using std::vector;

typedef enum { OUT_ID=0, OUT_AGE, OUT_FOOD } OutputEnum;
const std::string OUTPUT_FIELDS[]={ "Bacteria ID: ", "Age: ", "Food left: " };


 // destructor
PetriDish::~PetriDish() //definition of a destructor (rule of big 3)
{
	clean();
}


// assignment operator
const PetriDish& PetriDish::operator = ( const PetriDish& anotherPetriDish )
	{
		if ( this == &anotherPetriDish ) return *this;
		_food = anotherPetriDish._food;
		 _bacteriaPopulation = anotherPetriDish. _bacteriaPopulation;
		return *this;
	}


/* * clean
 * Cleans the petri dish from bacteria population and food.
 *
 * @ return void result
 */

void PetriDish::clean()
{
	for(vector<Bacteria*>::iterator iter= _bacteriaPopulation.begin();
									iter != _bacteriaPopulation.end(); iter++)
	{
		delete *iter;
	}
	_food = 0;
	_bacteriaPopulation.clear();
}

/* * addFood
 * Adding food to the petri dish.
 *
 * @ param addedAmount int
 * @ return void result
 */
void PetriDish::addFood( int addedAmount )
{
	_food += addedAmount;
}

/* * addBacteria
 * Adding the pointer of a new bacteria to the vector - adding a new bacteria
 * to the petri dish.
 *
 * @ param newBacteriaPtr pointer to Bacteria
 * @ return void result
 */
void PetriDish::addBacteria( Bacteria* newBacteriaPtr )
{
	if (newBacteriaPtr != NULL)
		{
		_bacteriaPopulation.push_back(newBacteriaPtr);
		}
}

/* * print
 * sends each bacteria to the function print in Bacteria class, and prints the
 * food in the petri dish.
 *
 * @ return void constant result
 */
void PetriDish::print() const
{
	for(vector<Bacteria*>::const_iterator iter= _bacteriaPopulation.begin();
									iter != _bacteriaPopulation.end(); iter++)
	{
		(*iter)->print();
	}
	cout<< OUTPUT_FIELDS[OUT_FOOD] << _food << endl;
}

/* * removeDeadBacteria
 * Removes all dead bacteria in the vector by checking each bacteria if is dead.
 *
 * @ return void result
 */
void PetriDish::removeDeadBacteria()
{

	for(size_t i = 0; i < _bacteriaPopulation.size(); i++)
	{
		if(_bacteriaPopulation[i]->isDead())
		{
			delete _bacteriaPopulation[i];
			_bacteriaPopulation.erase(_bacteriaPopulation.begin() + i);
			i--;
		}
	}
}

/* * updatePopulation
 * Updates the populution of each bacteria according to time given.
 *
 * @param timeUnits int
 * @return void result
 *
 */
void PetriDish::updatePopulation( int timeUnits )
{
	for(int j = 0; j < timeUnits; j++)
	{
		size_t size = _bacteriaPopulation.size();
		for(size_t i = 0; i < size; i++)
		{
			_bacteriaPopulation[i]->eat(_food);
			Bacteria* ptrCloned;
			ptrCloned = _bacteriaPopulation[i]->clone();
			PetriDish::addBacteria(ptrCloned);
			if(!ptrCloned)
			{
				_bacteriaPopulation[i]->grow();
			}
		}
		removeDeadBacteria();
	}
}

