/*
 * Bacteria.h
 *
 *  Created on: 11 ????? 2018
 *      Author: Shahar Dekel
 */

#ifndef BACTERIA_H_
#define BACTERIA_H_

class Bacteria
{
public:
	Bacteria(): _bacteriaId(0), _eatingRate(0), _adultAge(0), _foodUnits(0),
		_currentAge(0), _currentFood(0), _notEaten(0) {}
	// default constructor
	Bacteria(int bacteriaId, int eatingRate, int adultAge, int foodUnits):
						_bacteriaId(bacteriaId), _eatingRate(eatingRate),
						_adultAge(adultAge), _foodUnits(foodUnits),
						_currentAge(0), _currentFood(0), _notEaten(0) {}
	// constructor
	bool isReadyToClone() const;
	Bacteria* clone();
	void grow();
	bool isReadyToEat() const;
	void eat( int& foodLeft);
	void print() const;
	bool isDead() const;


private:
	int _bacteriaId;
	int _eatingRate;
	int _adultAge;
	int _foodUnits;
	int _currentAge; // at birth currebntAge=0
	int _currentFood; // at birth eatingAmount=0
	int _notEaten; // how many times the bacteria has not eaten

};

#endif /* BACTERIA_H_ */
