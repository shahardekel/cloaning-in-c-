/*
 * DieteticBacteria.cpp
 *
 *  Created on: 1 ????? 2019
 *      Author: Shahar Dekel
 */


#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "Bacteria.h"
#include "DieteticBacteria.h"

using std::endl;
using std::cout;
using std::vector;
using std::string;

typedef enum { OUT_ID=0, OUT_AGE, OUT_FOOD } OutputEnum;
const std::string OUTPUT_FIELDS[]={ "Bacteria ID: ", "Age: ", "Food left: " };

const string DieteticBacteria::name= "Dietetic Bact.";

//destructor
DieteticBacteria::~DieteticBacteria(){}

/* * clone
 * clones the Dietetic Bacteria. checks if the bacteria is ready to clone and is
 * not dead, then resets the age and divides by 2 the current consumed food.
 * then makes a new "son" bacteria with the same parameters as the father, else,
 * returns NULL.
 *
 * @ return pointer to the new bacteria (known as dieteticSon)
 */
Bacteria* DieteticBacteria::clone()
{
	if (isReadyToClone() && !isDead())
	{
		_currentAge = 0;
		_currentFood /= two;
		//_notEaten = 0;
		Bacteria* dieteticSon = new DieteticBacteria (*this);
		return dieteticSon;
	}
	else
	{
		return NULL;
	}

}

/* *print
 * prints Dietetic Bact., then sends to the print function in Bacteria, which
 * prints the bacteria id and current age.
 *
 * @return the name and prints the id and age of the Dietetic Bacteria as
 * constant
 */
 void DieteticBacteria::print() const
{
	cout<< name;
	Bacteria::print();
}




