/*********************************************************************
** Program Filename: stalactites.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: Implementation of the Stalactites class.
** Input: None
** Output: None
*********************************************************************/

#include "stalactites.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define STALCTITES_NAME = "Stalactites"

//Stalactites Implementation

Stalactites::Stalactites(){

}

void Stalactites::print_percept()const{
    cout << "You hear water dripping." << endl;
}

void Stalactites::print_char()const{
    cout << "S";
}

void Stalactites::encounter_event() const{
    cout << "YOU HAVE ENCOUNTERED STALACTITES" << endl;
}
