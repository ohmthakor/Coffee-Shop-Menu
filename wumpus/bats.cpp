#include "bats.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Bats Implementation

Bats::Bats(){

}

void Bats::print_percept()const {
    cout << "You hear wings flapping." << endl;
}

void Bats::encounter_event() const{
    cout << "YOU HAVE ENCOUNTERED BATS AND ARE NOW CONFUSED" << endl;
}

void Bats::print_char() const{
    cout << "B";
}