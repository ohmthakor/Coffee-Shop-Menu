#ifndef GOLD_H
#define GOLD_H 

#include "event.h"
#include <iostream>
#include <string>
#include <vector>

//Gold Interface

class Gold : public Event{
    private:

    public:

        /*********************************************************************
        ** Function: Gold::Gold()
        ** Description: Default constructor for the Gold class.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: A Gold object is created.
        *********************************************************************/
            Gold();

        /*********************************************************************
        ** Function: void Gold::encounter_event() const
        ** Description: Implementation of the virtual function to handle the encounter event of gold.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints a message indicating encounter with gold.
        *********************************************************************/
        void encounter_event() const;


        /*********************************************************************
        ** Function: void Gold::print_percept() const
        ** Description: Implementation of the virtual function to print the percept of the gold event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the percept of gold event.
        *********************************************************************/
        void print_percept()const;


        /*********************************************************************
        ** Function: void Gold::print_char() const
        ** Description: Implementation of the virtual function to print the character representing the gold event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Prints the character representing gold.
        *********************************************************************/
        void print_char() const;


};

#endif