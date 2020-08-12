/*
 * main.cpp
 *
 *  Created on: 11 12 2018
 *      Author: Shahar Dekel
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Bacteria.h"
#include "PetriDish.h"

typedef enum { ADD_BACTERIA=0, ADD_FOOD, CLEAN_PETRI,
								PRINT, UPDATE_TIME, QUIT_CODE } CommandsEnum;
const std::string consoleCommands[]=
	{"add_bacteria", "add_food", "clean_petri", "print","update_time", "quit" };

int main()
{
    std::string input;
    std::cin >> input;
    PetriDish bioPerti;

    while ( input != consoleCommands[QUIT_CODE] )
    {
      if (  input == consoleCommands[ADD_BACTERIA] )
      {
            int bacteriaId(0), eatingRate(0), adultAge(0), foodUnits(0);
            std::cin >> bacteriaId >> eatingRate >> adultAge >> foodUnits;
            Bacteria* bacteriaPtr =
            	new  Bacteria( bacteriaId, eatingRate, adultAge, foodUnits );
            bioPerti.addBacteria( bacteriaPtr );
      }
      else if (  input == consoleCommands[ADD_FOOD] )
      {
            int foodCount(0);
            std::cin >> foodCount;
            bioPerti.addFood( foodCount );
      }
      else if (  input == consoleCommands[CLEAN_PETRI] )
      {
            bioPerti.clean();
      }
      else if (  input == consoleCommands[PRINT] )
      {
            bioPerti.print();
      }
      else if (  input == consoleCommands[UPDATE_TIME] )
      {
            int addedTime(0);
            std::cin >> addedTime;
            bioPerti.updatePopulation( addedTime );
      }
      std::cin >> input;
    }

    return EXIT_SUCCESS;
}
