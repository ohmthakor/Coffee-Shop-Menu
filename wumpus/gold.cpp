#include "gold.h"

#include <iostream>
#include <string>
#include <vector>

/*********************************************************************
** Program Filename: gold.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: Implementation of the Gold class.
** Input: None
** Output: None
*********************************************************************/

using namespace std;

#define GOLD_NAME = "Gold"

//Gold Implementation

Gold::Gold(){

}

void Gold::encounter_event() const {
    cout << "YOU HAVE FOUND THE GOLD, now make your way back to the rope" << endl;
}

void Gold::print_percept() const{

    cout << "you see a glimmer nearby." << endl;
}

void Gold::print_char() const{
    cout << "G";
}