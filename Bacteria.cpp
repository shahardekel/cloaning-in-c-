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

using std::endl;
using std::cout;
using std::vector;

typedef enum { OUT_ID=0, OUT_AGE, OUT_FOOD } OutputEnum;
const std::string OUTPUT_FIELDS[]={ "Bacteria ID: ", "Age: ", "Food left: " };

/* * isReadyToClone
 * Checking if the current age is bigger than the age of adultness, and if the
 * food in the petri dish is bigger than the current age.
 *
 * @ return boolean constant result
 */
bool Bacteria::isReadyToClone() const
{
	 return (( _currentAge >= _adultAge ) && ( _currentFood >= _currentAge ) ?
			 true : false);
}

/* * clone
 * Making a new "son" bacteria that gets the same parameters as the "father" and
 * resets the age, food and how many time has not eated to 0, both for the "son"
 * and the "father" bacteria.
 *
 * @ return Bacteria* result
 */
Bacteria* Bacteria:: clone()
{
	if (isReadyToClone())
	{
		_currentAge = 0;
		_currentFood = 0;
		_notEaten = 0;
		Bacteria* ptrSon = new Bacteria (_bacteriaId, _eatingRate,
				_adultAge, _foodUnits);

		return ptrSon;
	}
	else
	{
		return NULL;
	}
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
 * @ param foodLeft int&
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
		_currentFood += (foodLeft >= _foodUnits ? _foodUnits : foodLeft);
		 foodLeft = ((foodLeft-_foodUnits) >= 0 ? foodLeft-_foodUnits : 0);
	}
}

/* * isDead
 * Checking if the bacteria has not eated 3 or more times.
 *
 *@ return boolean constant result
 */
bool Bacteria::isDead() const
{
	return ((_notEaten >= 3) ? true : false);
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

