/*
 * BACTERIA_H_.cpp
 *
 *  Created on: 13 ????? 2018
 *      Author: Shahar Dekel
 */

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

#define THREE 3

typedef enum { OUT_ID=0, OUT_AGE, OUT_FOOD } OutputEnum;
const std::string OUTPUT_FIELDS[]={ "Bacteria ID: ", "Age: ", "Food left: " };

//destructor
Bacteria:: ~Bacteria(){}

//copy constructor
Bacteria::Bacteria(const Bacteria& otherBacteria):
									_bacteriaId(otherBacteria._bacteriaId),
									_eatingRate(otherBacteria._eatingRate),
									_adultAge(otherBacteria._adultAge),
									_foodUnits(otherBacteria._foodUnits),
									_notEaten(0),_currentAge(0),
									_currentFood(0) {}

//assignment operator
Bacteria& Bacteria::operator=(const Bacteria& otherBacteria)
{
	_currentAge= otherBacteria._currentAge;
	_currentFood= otherBacteria._currentFood;
	_notEaten= otherBacteria._notEaten;
	return *this;
}

/*
 * * isReadyToClone
 * checks if the bacteria is ready to clone, if the current age is bigger or
 * even to the adult age, and if the current consumed food is bigger than the
 * current age of the bacteria.
 *
 * @return boolean constant result
 */
bool Bacteria::isReadyToClone() const
{
	 return (( _currentAge >= _adultAge ) && ( _currentFood > _currentAge ) ?
			 true : false);
}


/* * grow
 * Making the current age to grow by 1
 *
 * @ return void result
 */
void Bacteria:: grow()
{
	_currentAge++;
}

/* * isReadyToEat
 * Checking if the current age of the bacteria is divided by the eating rate.
 *
 * @ return boolean constant result
 */
bool Bacteria:: isReadyToEat() const
{
	if((_currentAge % _eatingRate) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* * eat
 * Getting the bacteria to eat.
 *
 * @ param foodLeft int& reference to foodLeft
 * @ return void result
 */
void Bacteria:: eat( int& foodLeft )
{
	if(isReadyToEat())
	{
		if(foodLeft == 0)
		{
			_notEaten++;
		}
		else
		{
			_currentFood += (foodLeft >= _foodUnits ? _foodUnits : foodLeft);
			foodLeft = ((foodLeft-_foodUnits) >= 0 ? foodLeft-_foodUnits : 0);
			//_notEaten = 0;
		}
	}
}

/* * isDead
 * Checking if the bacteria has not eated 3 or more times.
 *
 *@ return boolean constant result
 */
bool Bacteria::isDead() const
{
	return ((_notEaten >= THREE) ? true : false);
}

/* * print
 * Prints the id and age of the bacteria.
 *
 * @ return void constant result
 */
void Bacteria::print() const
{
	cout<< OUTPUT_FIELDS[OUT_ID]<< _bacteriaId << " " << OUTPUT_FIELDS[OUT_AGE]
														<< _currentAge<< endl;
}

