/*********************************************************************
** Program Filename: shop.cpp
** Author: Ohm Thakor
** Date: 11/13/23
** Description: Implementation of shop.h, called from display.cpp
*********************************************************************/
#include "shop.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//function defintions from shop.h goes here
Shop::Shop() : m(), phone(""), address(""), revenue(0.00), order_arr(nullptr), num_orders(0) {}

Shop::Shop(string phone, string address, float revenue){
	this->phone = phone;
    this->address = address;
	this->revenue = revenue;
}

Shop::Shop (const Shop & s){
    this->phone = s.phone;
    this->address = s.address;
    this->revenue = s.revenue;	
    
    // Perform a deep copy for order_arr
    this->order_arr = new Order [s.num_orders];
    for (int i = 0; i < s.num_orders; i++){
        this->order_arr[i] = s.order_arr[i];
    }
}

Shop& Shop::operator=(const Shop & s){ //assignment operator overload
	if(this == &s){
		return *this;
	}
	if(this->order_arr != nullptr) {
		delete [] order_arr;
	}
	this->num_orders = s.num_orders;
	this->order_arr = new Order[this->num_orders];
	for(int i = 0; i < num_orders; i++){
		this->order_arr[i] = s.order_arr[i];
	}
	return *this;
}

Shop::~Shop(){
	delete [] order_arr;
	order_arr = nullptr;
}

bool Shop::load_data(){
	bool menu_is_loaded = m.load_data();
	num_orders = 0;
	revenue = 0;
	ifstream my_ifstream;
	my_ifstream.open("shop_info.txt"); // hardcoded
	bool shop_is_loaded = !my_ifstream.fail();
	getline(my_ifstream, phone); // use getline because of spaces within address
	getline(my_ifstream, address);

	my_ifstream.close();

	return menu_is_loaded && shop_is_loaded; // if both are true, return true, if either or both are false, return false
}


void Shop::view_shop_detail(){
	//handle "View shop detail" option
	//print shop address, phone number, revenue, menu, and order
	//Your code goes here: 
	cout << "Address: " << address << endl; 
	cout << "Phone Number: " << phone << endl;
	cout << "Revenue: $" << revenue << endl;

	cout << "Menu:" << endl;

	m.print_price_and_coffee();

	cout << endl;


	cout << "Order info" << endl;
	for (int i = 0; i < num_orders; i++){
		cout << order_arr[i].get_id() << " ";
		cout << order_arr[i].get_name() << " ";
		cout << order_arr[i].get_size() << " ";
		cout << order_arr[i].get_quantity() << endl;
	}
	if(num_orders == 0){
		cout << "(No orders to display)" << endl;
	}

	return;
}

void Shop::add_to_menu(){	
	string name;
	float sml;
	float med;
	float lg;
	
	cout << "what would you like to name the coffee?" << endl;
	cin >> name;
	cout << "what is the price of a small sized coffee?" << endl;
	cin >> sml;
	cout << "what is the price of a medium sized coffee?" << endl;
	cin >> med;
	cout << "what is the price of a large sized coffee?" << endl;
	cin >> lg;

	Coffee coffee_to_add(name, sml, med, lg);
	m.add_to_menu(coffee_to_add);

	//Coffee cofee_to_remove(name);
	return;
}

void Shop::remove_from_menu(){
	m.print_coffees();
	cout << "what coffee would you like to remove? 1-" << m.get_num_coffee() << endl; // accounts for changing menu
	int coffee_remove_choice;
	cin >> coffee_remove_choice;

	m.remove_from_menu(coffee_remove_choice); // we are getting a number which we will print
	return;
}


void Shop::search_by_name(){
	string name;
	cout << "please provide the name of the coffee you are trying to find" << endl;
	cin >> name;
	cout << endl;
	
	Coffee found_coffee = m.search_coffee_by_name(name);

	if(found_coffee.get_name() == name){
		cout << "Coffee found:" << endl << endl;
        cout << "Name: " << found_coffee.get_name() << endl;
        cout << "Small Cost: " << found_coffee.get_small_cost() << endl;
        cout << "Medium Cost: " << found_coffee.get_medium_cost() << endl;
        cout << "Large Cost: " << found_coffee.get_large_cost() << endl;
		cout << endl;
	}
	return;
}

void Shop::search_by_price(){
	float budget;
	cout << "enter a budget are you looking for your coffee" << endl;
	cin >> budget;
	m.search_coffee_by_price(budget);
	
	return;
}

void Shop::place_order() {
	char coffee_size;
	int quantity;
	int order_con;
	string coffee_name;
	m.print_coffees(); // prints coffee options for user to choose
	cout << "what coffee would you like, choose from 1-" << m.get_num_coffee() << endl;
	cin >> order_choice;

	coffee_name = m.size_options(order_choice);

	cout << "enter size: s - small, m - medium, l - large" << endl;
	cin >> coffee_size;

	cout << "enter quantity" << endl;
	cin >> quantity;

	float order_total = m.calc_order_total(coffee_size, quantity, order_choice);
	cout << "your total is $" << order_total << endl;

	cout << "confirm order: 1. yes  2. no | input 1 or 2" << endl;
	cin >> order_con;

	if(order_con == 1){
		revenue = revenue + order_total;
		cout << "your order has been placed Your order number is " << ++num_orders << endl; // num_orders will go from 0 to 1 on the first order
		add_order(order_choice, coffee_size, quantity);
	}
	else if(order_con == 2){
		cout << "your order has been cancelled" << endl;
	}
	else{
		cout << "invalid input, order cancelled" << endl;
	}
// JUSTIFICATION: had to initialize lots of variables and ask user to input values for all of them. 

	return;
}

void Shop::add_order(const int order_choice, const char coffee_size, const int quantity){
	ofstream my_outfile("orders.txt");
	my_outfile << num_orders << endl;
	Order* temp_order_arr = new Order[num_orders];
	for(int i = 0; i < num_orders - 1; i++){
		temp_order_arr[i] = order_arr[i];
	}
	temp_order_arr[num_orders - 1] = Order(num_orders, m.get_coffee_name(order_choice - 1), coffee_size, quantity);
	for (int i = 0; i < num_orders; i++){
		my_outfile << temp_order_arr[i].get_id() << " ";
		my_outfile << temp_order_arr[i].get_name() << " ";
		my_outfile << temp_order_arr[i].get_size() << " ";
		my_outfile << temp_order_arr[i].get_quantity() << endl;
	}
	delete [] order_arr;
	order_arr = temp_order_arr;

	return;
}

Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation
	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}

bool Shop::order_file_validate() {
	ifstream my_ifstream("orders.txt");

	bool file_is_valid = true;
	if(my_ifstream.fail()){
		file_is_valid = false;
	}

	return file_is_valid;
}
