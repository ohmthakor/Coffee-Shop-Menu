/*********************************************************************
** Program Filename: event.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: Implementation of the Event class.
** Input: None
** Output: None
*********************************************************************/

#ifndef EVENT_H
#define EVENT_H 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event {

    protected:

        /*********************************************************************
        ** Function: Event::Event()
        ** Description: Default constructor for the Event class.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: An Event object is created.
        *********************************************************************/
        Event();

    public:
        /*********************************************************************
        ** Function: virtual void print_percept() const
        ** Description: Abstract function to print the percept of the event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Pure virtual function.
        *********************************************************************/
        virtual void print_percept() const= 0;


        /*********************************************************************
        ** Function: virtual void encounter_event() const
        ** Description: Abstract function to handle the encounter event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Pure virtual function.
        *********************************************************************/
        virtual void encounter_event() const = 0;


        /*********************************************************************
        ** Function: virtual void print_char() const
        ** Description: Abstract function to print the character representing the event.
        ** Parameters: None
        ** Pre-Conditions: None
        ** Post-Conditions: Pure virtual function.
        *********************************************************************/
        virtual void print_char() const = 0;
        
};
#endif