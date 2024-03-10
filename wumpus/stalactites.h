#ifndef STALACTITES_H
#define STALACTITES_H 

#include <iostream>
#include <string>
#include <vector>
#include "event.h"

//Stalactites Interface

class Stalactites : public Event{
    private:

    public:
        /*********************************************************************
        ** Function: Stalactites::Stalactites()
        ** Description: Default constructor for the Stalactites class.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: A Stalactites object is created.
        *********************************************************************/
        Stalactites();


        /*********************************************************************
        ** Function: void Stalactites::print_percept() const
        ** Description: Implementation of the virtual function to print the percept of the stalactites event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the percept of stalactites event.
        *********************************************************************/
        void print_percept()const;


        /*********************************************************************
        ** Function: void Stalactites::print_char() const
        ** Description: Implementation of the virtual function to print the character representing the stalactites event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the character representing stalactites.
        *********************************************************************/
        void print_char()const;


        /*********************************************************************
        ** Function: void Stalactites::encounter_event() const
        ** Description: Implementation of the virtual function to handle the encounter event of stalactites.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints a message indicating encounter with stalactites.
        *********************************************************************/
        void encounter_event() const;

};


#endif