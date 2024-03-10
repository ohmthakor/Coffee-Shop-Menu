/*********************************************************************
** Program Filename: coffee.cpp
** Author: Ohm Thakor
** Date: 11/13/23
** Description: Implementation of coffee.h
*********************************************************************/

#include "coffee.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


Coffee::Coffee() : name(""), small_cost(0), medium_cost(0), large_cost(0) {} // default constructor


Coffee::Coffee(string name, float small_cost, float medium_cost, float large_cost) {
    this->name = name;
    this->small_cost = small_cost;
    this->medium_cost = medium_cost;
    this->large_cost = large_cost;
}

void Coffee::set_name(const string new_name){
    name = new_name;
}

void Coffee::set_small_cost(const float cost){
    small_cost = cost;
}

void Coffee::set_medium_cost(const float cost){
    medium_cost = cost;
}

void Coffee::set_large_cost(const float cost){
    large_cost = cost;
}

string Coffee::get_name()const{
    return name;
}

float Coffee::get_small_cost() const{
    return small_cost;
}

float Coffee::get_medium_cost() const{
    return medium_cost;
}

float Coffee::get_large_cost() const{
    return large_cost;
}

void Coffee::print_coffee() const{
    cout << "Name: " << name << endl;
    cout << "Small Cost: " << small_cost << endl;
    cout << "Medium Cost: " << medium_cost << endl;
    cout << "Large Cost: " << large_cost << endl;
}

void Coffee::print_menu(ofstream& my_outfile) const{
    my_outfile << name << " " << small_cost << " " << medium_cost << " " << large_cost << endl;
}

