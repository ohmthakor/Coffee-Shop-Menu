/*********************************************************************
** Program Filename: room.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: Implementation of the room class
** Input: None
** Output: None
*********************************************************************/

#include "room.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Room Implementation
//Room::Room() : event(nullptr), event_name(""), event_percept("") {
//}

Room::Room() : event(nullptr), event_name(""), empty(true) {
}
Room::~Room(){
    if (this->event != nullptr){
        delete this->event;
        this->event = nullptr;
    }
    
}

void Room::operator=(const Room& r) {
    this->event_name = r.event_name;
    if (!this->empty) {
        delete this->event;
    }  
    this->empty = r.empty;

    if (event_name == "Super Bats") {
        this->event = new Bats();
    } else  if (event_name == "Stalactites") {
        this->event = new Stalactites();
    } else if (event_name == "Wumpus") {
        this->event = new Wumpus();
    } else  if (event_name == "Gold") {
        this->event = new Gold();
    }
}


Room::Room(string event_name) : event_name(event_name), event(nullptr) {
    if (event_name == "Super Bats") { // checks by inputted event name and creates new event object accordingly.
        this->event = new Bats();
    } else  if (event_name == "Stalactites") {
        this->event = new Stalactites();
    } else if (event_name == "Wumpus") {
        this->event = new Wumpus();
    } else  if (event_name == "Gold") {
        this->event = new Gold();
    }
    empty = false;
}


bool Room::has_event() const {
    if (empty) {
        return false;
    }  else {
        return true;
    }
}

void Room::print_event()const {
    if (has_event()) { // if room has event
        event->print_char(); // print that event's char
    }
}

void Room::print_perc()const {
    if(this->event != nullptr){ // if room is not empty  
        this->event->print_percept(); // print that event's percept
    }
}

void Room::clear_event() {
    this->empty = true;
    this->event_name = "";
}

void Room::print_encounter()const {
    if(this->event != nullptr){ // if room is not empty  
        this->event->encounter_event(); // print that event's percept
    }
}
