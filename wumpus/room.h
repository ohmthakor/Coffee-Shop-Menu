#ifndef ROOM_H
#define ROOM_H 

#include <iostream>
#include <string>
#include <vector>

#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
    Event* event;
    string event_name;
    bool empty;
    bool hit_stal;

public:
    /*********************************************************************
    ** Function: Room::Room()
    ** Description: Default constructor for the Room class. Initializes the Room with no event.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: A Room object is created with no event.
    *********************************************************************/
    Room();


    /*********************************************************************
    ** Function: Room::~Room()
    ** Description: Destructor for the Room class. Deletes the event object if it exists.
    ** Parameters: None
    ** Pre-Conditions: A Room object exists.
    ** Post-Conditions: The Room object is destroyed, and memory for the event is freed.
    *********************************************************************/
    ~Room();


    /*********************************************************************
    ** Function: void Room::operator=(const Room& r)
    ** Description: Assignment operator overload for the Room class. Assigns the values of another Room object to the current object.
    ** Parameters: const Room& r - Reference to the Room object to be assigned.
    ** Pre-Conditions: Both Room objects exist.
    ** Post-Conditions: The current Room object is assigned the values of the provided Room object.
    *********************************************************************/
    void operator=(const Room&);


    /*********************************************************************
    ** Function: Room::Room(string event_name)
    ** Description: Parameterized constructor for the Room class. Initializes the Room with a specific event.
    ** Parameters: string event_name - The name of the event to be added to the Room.
    ** Pre-Conditions: None
    ** Post-Conditions: A Room object is created with the specified event.
    *********************************************************************/
    Room(string event_name);


	Room(Event* event) : event(event) {}

    /*********************************************************************
    ** Function: bool Room::has_event() const
    ** Description: Checks if the Room has an event.
    ** Parameters: None
    ** Pre-Conditions: A Room object exists.
    ** Post-Conditions: Returns true if the Room has an event, false otherwise.
    *********************************************************************/
    bool has_event() const;


    /*********************************************************************
    ** Function: void Room::print_event() const
    ** Description: Prints the character representation of the event in the Room.
    ** Parameters: None
    ** Pre-Conditions: A Room object exists.
    ** Post-Conditions: The character representation of the event is printed if the Room has an event.
    *********************************************************************/
    void print_event() const;


    /*********************************************************************
    ** Function: void Room::print_perc() const
    ** Description: Prints the percept of the event in the Room.
    ** Parameters: None
    ** Pre-Conditions: A Room object exists.
    ** Post-Conditions: The percept of the event is printed if the Room has an event.
    *********************************************************************/
    void print_perc()const;

    /*********************************************************************
    ** Function: void Room::clear_event()
    ** Description: Clears the event from the Room.
    ** Parameters: None
    ** Pre-Conditions: A Room object exists.
    ** Post-Conditions: The Room is emptied, and the event is cleared.
    *********************************************************************/
    void clear_event();

    /*********************************************************************
    ** Function: void Room::print_encounter() const
    ** Description: Prints the encounter message of the event in the Room.
    ** Parameters: None
    ** Pre-Conditions: A Room object exists.
    ** Post-Conditions: The encounter message of the event is printed if the Room has an event.
    *********************************************************************/
    void print_encounter() const;
};

#endif