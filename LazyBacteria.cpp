/*
 * LazyBacteria.cpp
 *
 *  Created on: 1 ????? 2019
 *      Author: Shahar Dekel
 */

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "Bacteria.h"
#include "LazyBacteria.h"

using std::endl;
using std::cout;
using std::vector;
using std::string;

typedef enum { OUT_ID=0, OUT_AGE, OUT_FOOD } OutputEnum;
const std::string OUTPUT_FIELDS[]={ "Bacteria ID: ", "Age: ", "Food left: " };

const string LazyBacteria::name= "Lazy Bact.";


 //destructor
 LazyBacteria::~LazyBacteria(){}

 /* * clone
  * clones the Lazy Bacteria. checks if the bacteria is ready to clone and is
  * not dead, then makes a new "son" bacteria with the same parameters as the
  * father, else, returns NULL.
  *
  * @ return pointer to the new bacteria (known as lazySon)
  */
 Bacteria* LazyBacteria::clone()
{
	if (isReadyToClone() && !isDead())
	{
		//_notEaten = 0;
		Bacteria* lazySon = new LazyBacteria (*this);

		return lazySon;
	}
	else
	{
		return NULL;
	}


}

 /* *print
  * prints Lazy Bact., then sends to the print function in Bacteria, which
  * prints the bacteria id and current age.
  *
  * @return the name and prints the id and age of the Lazy Bacteria as constant
  */
 void LazyBacteria::print() const
{
	cout<< name;
	Bacteria::print();
}




