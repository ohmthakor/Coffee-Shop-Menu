/*********************************************************************
** Program Filename: bats.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: Implementation of the Bats class.
** Input: None
** Output: None
*********************************************************************/

#ifndef BATS_H
#define BATS_H 

#include "event.h"
#include <iostream>
#include <string>
#include <vector>

#define BATS_NAME = "Super Bats"

//Bats Interface
class Bats : public Event{

    private: 
        
    public:

        /*********************************************************************
        ** Function: Bats::Bats()
        ** Description: Default constructor for the Bats class.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: A Bats object is created.
        *********************************************************************/
        Bats();


        /*********************************************************************
        ** Function: void Bats::print_percept() const
        ** Description: Implementation of the virtual function to print the percept of the bats event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the percept of bats event.
        *********************************************************************/
        void print_percept()const;


        /*********************************************************************
        ** Function: void Bats::encounter_event() const
        ** Description: Implementation of the virtual function to handle the encounter event of bats.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints a message indicating encounter with bats.
        *********************************************************************/
        void encounter_event()const;


        /*********************************************************************
        ** Function: void Bats::print_char() const
        ** Description: Implementation of the virtual function to print the character representing the bats event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the character representing bats.
        *********************************************************************/
        void print_char() const;
        

};


#endif