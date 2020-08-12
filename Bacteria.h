/*
 * Bacteria.h
 *
 *  Created on: 11 ????? 2018
 *      Author: Shahar Dekel
 */

#ifndef BACTERIA_H_
#define BACTERIA_H_

//the "father" bacteria
 class  Bacteria
{
public:
	Bacteria(): _bacteriaId(0), _eatingRate(0), _adultAge(0), _foodUnits(0),
	 _notEaten(0), _currentAge(0), _currentFood(0) {}
	// default constructor
	Bacteria(int bacteriaId, int eatingRate, int adultAge, int foodUnits):
						_bacteriaId(bacteriaId), _eatingRate(eatingRate),
						_adultAge(adultAge), _foodUnits(foodUnits),
						 _notEaten(0),_currentAge(0), _currentFood(0) {}
	// constructor
	virtual ~Bacteria();
	//destructor
	Bacteria(const Bacteria& otherBacteria);
	//copy constructor
	Bacteria& operator=(const Bacteria& otherBacteria);
	// assignment operator

	virtual Bacteria* clone()=0;
	virtual void grow();
	void eat( int& foodLeft);
	virtual void print() const;
	bool isDead() const;
	bool isReadyToClone() const;
	bool isReadyToEat() const;

private:

	 int _bacteriaId;
	 int _eatingRate;
	 int _adultAge;
	 int _foodUnits;
	 int _notEaten; // how many times the bacteria has not eaten


protected:

	 int _currentAge; // at birth currebntAge=0
	 int _currentFood; // at birth eatingAmount=0
	 static const int two = 2;




};

#endif /* BACTERIA_H_ */
