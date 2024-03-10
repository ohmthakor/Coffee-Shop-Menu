/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: Implementation of the Wumpus class.
** Input: None
** Output: None
*********************************************************************/

#include "wumpus.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Wumpus::Wumpus(){

}

void Wumpus::print_percept()const{
    cout << "You smell a terrible stench." << endl;
}
void Wumpus::print_char() const{
    cout << "W";
}
void Wumpus::encounter_event() const{
    cout << "YOU HAVE ENCOUNTERED THE WUMPUS" << endl;
    cout << "you were killed by the Wumpus, game over :(" << endl;
}
//Wumpus Implementation
