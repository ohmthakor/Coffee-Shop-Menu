/*********************************************************************
** Program Filename: order.cpp
** Author: Ohm Thakor
** Date: 11/13/23
** Description: Implementation of order.h, called from shop.cpp
*********************************************************************/
#include "order.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Order::Order() : id(-1), coffee_name(""), coffee_size(), quantity(-1){}


Order::Order(int i, string name, char size, int k) : id(i), coffee_name(name), coffee_size(size), quantity(k){}


int Order::get_id() const {
	return id;
}	

string Order::get_name() const {
    return coffee_name;
}

char Order::get_size() const{
    return coffee_size;
}

int Order::get_quantity() const{
    return quantity;
}