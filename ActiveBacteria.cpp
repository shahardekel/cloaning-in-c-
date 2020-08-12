/*
 * ActiveBacteia.cpp
 *
 *  Created on: 30 בדצמ× 2018
 *      Author: Yamit Gvinter
 *
 */
#include <sstream>
#include <iostream>
#include <string>
#include <vector>


#include "Bacteria.h"
#include "ActiveBacteria.h"

using std::endl;
using std::cout;
using std::vector;
using std::string;

typedef enum { OUT_ID=0, OUT_AGE, OUT_FOOD } OutputEnum;
const std::string OUTPUT_FIELDS[]={ "Bacteria ID: ", "Age: ", "Food left: " };

const string ActiveBacteria::name= "Active Bact.";


 //destructor
 ActiveBacteria:: ~ActiveBacteria(){}


/* * clone
 * clones the Active Bacteria. checks if the bacteria is ready to clone and is
 * not dead, then multiply the age and resets the current consumed food.
 * then makes a new "son" bacteria with the same parameters as the father, else,
 * returns NULL.
 *
 * @ return pointer to the new bacteria (known as activeSon)
 */
Bacteria* ActiveBacteria:: clone()
 {
	if (isReadyToClone() && !isDead())
	{
	_currentAge *= two;
	_currentFood = 0;
	Bacteria* activeSon = new ActiveBacteria(*this);
	return activeSon;
	}
	else
	{
		return NULL;
	}
}

/* *print
 * prints Active Bact., then sends to the print function in Bacteria, which
 * prints the bacteria id and current age.
 *
 * @return the name and prints the id and age of the Active Bacteria as constant
 */
 void ActiveBacteria:: print() const
{
	 cout<< name;
	 Bacteria::print();
}

