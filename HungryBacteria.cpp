/*
 * HungryBacteria.cpp
 *
 *  Created on: 1 ????? 2019
 *      Author: Shahar Dekel
 */

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "Bacteria.h"
#include "HungryBacteria.h"

using std::endl;
using std::cout;
using std::vector;
using std::string;

typedef enum { OUT_ID=0, OUT_AGE, OUT_FOOD } OutputEnum;
const std::string OUTPUT_FIELDS[]={ "Bacteria ID: ", "Age: ", "Food left: " };

const string HungryBacteria::name= "Hungry Bact.";


//destructor
HungryBacteria::~HungryBacteria(){}


/* * clone
 * clones the Hungry Bacteria. checks if the bacteria is ready to clone and is
 * not dead, then divides the age by 2 and resets the current consumed food.
 * then makes a new "son" bacteria with the same parameters as the father, else,
 * returns NULL.
 *
 * @ return pointer to the new bacteria (known as hungrySon)
 */
Bacteria* HungryBacteria::clone()
{
	if (isReadyToClone() && !isDead())
	{
		_currentAge /= two;
		_currentFood = 0;
		//_notEaten = 0;
		Bacteria* hungrySon = new HungryBacteria (*this);
		return hungrySon;
	}
	else
	{
		return NULL;
	}
}

/* *print
 * prints Hungry Bact., then sends to the print function in Bacteria, which
 * prints the bacteria id and current age.
 *
 * @return the name and prints the id and age of the Hungry Bacteria as constant
 */
void HungryBacteria::print() const
{
	cout<< name;
	Bacteria::print();
}




