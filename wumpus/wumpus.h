#ifndef WUMPUS_H
#define WUMPUS_H 

#include <iostream>
#include <string>
#include <vector> 
#include "event.h"

//Wumpus Interface

class Wumpus : public Event{
    private:

    public:
        /*********************************************************************
        ** Function: Wumpus::Wumpus()
        ** Description: Default constructor for the Wumpus class.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: A Wumpus object is created.
        *********************************************************************/
        Wumpus();


        /*********************************************************************
        ** Function: void Wumpus::print_percept() const
        ** Description: Implementation of the virtual function to print the percept of the Wumpus event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the percept of Wumpus event.
        *********************************************************************/
        void print_percept()const;


        /*********************************************************************
        ** Function: void Wumpus::print_char() const
        ** Description: Implementation of the virtual function to print the character representing the Wumpus event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the character representing Wumpus.
        *********************************************************************/
        void print_char() const;

        /*********************************************************************
        ** Function: void Wumpus::encounter_event() const
        ** Description: Implementation of the virtual function to handle the encounter event of Wumpus.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints a message indicating encounter with Wumpus and ends the game.
        *********************************************************************/
        void encounter_event() const;

    };




#endif