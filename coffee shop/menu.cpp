#include "menu.h"
#include <iostream>
#include <string>

using namespace std;

//function defintions from menu.h goes here

Menu::Menu() : num_coffee(0), coffee_arr(nullptr){}

Menu::Menu(int size){
	this->num_coffee = size;
	this->coffee_arr = new Coffee [size];
}

Menu::Menu (const Menu & m){
	// Copy the number of coffee items
	this->num_coffee = m.num_coffee; 
	// Delete existing coffee_arr if not nullptr
	if (this->coffee_arr != nullptr) {
		delete [] this->coffee_arr;
	}
	this->coffee_arr = new Coffee [this->num_coffee];
	for(int i = 0; i < num_coffee; i++){
		this->coffee_arr[i] = m.coffee_arr[i];
	}
}


Menu& Menu::operator=(const Menu & m){ // Copy assignment operator overload
	// Check for self-assignment
	if(this == &m){
		return *this;
	}
	// Delete existing coffee_arr if not nullptr
	if(this->coffee_arr != nullptr) {
		delete [] coffee_arr;
	}

	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee[this->num_coffee];
	// Copy each Coffee object from the source menu to the current menu
	for(int i = 0; i < num_coffee; i++){
		this->coffee_arr[i] = m.coffee_arr[i];
	}
	return *this;
}

Menu::~Menu(){
	delete [] coffee_arr;
	coffee_arr = nullptr;
}

bool Menu::load_data(){
	ifstream my_ifstream;
	my_ifstream.open("menu.txt");
	if (my_ifstream.fail()) {
		return false;
	} // stops code from running any further, gracefully terminates
	my_ifstream >> num_coffee;

	coffee_arr = new Coffee[num_coffee];

	for (int i = 0; i < num_coffee; i++){
		string name; 
		float cost;
		my_ifstream >> name;
		coffee_arr[i].set_name(name);

		my_ifstream >> cost;
		coffee_arr[i].set_small_cost(cost);

		my_ifstream >> cost;
		coffee_arr[i].set_medium_cost(cost);

		my_ifstream >> cost;
		coffee_arr[i].set_large_cost(cost);
	}
	my_ifstream.close();
	return true;
}
// JUSTIFICATION: needed extra lines to ensure that if the file wasn't able to be opened, program would end.

Coffee Menu::search_coffee_by_name(string name) {
	Coffee found;
	bool found_it = false;
	for (int i = 0; i < num_coffee; i++){
		if(coffee_arr[i].get_name() == name){
			found = coffee_arr[i];
			found_it = true;
			break;
		}
	}
	if(found_it == false){
		cout << "no coffee found with provided name, sorry" << endl;
	}
	return found;
}


void Menu::search_coffee_by_price(float budget){
	bool found = false;
	for (int i = 0; i < num_coffee; i++){
		if (coffee_arr[i].get_small_cost() <= budget){
			cout << i + 1 << ". " << coffee_arr[i].get_name() << endl;
			cout << "   small - " << coffee_arr[i].get_small_cost() << endl;
			found = true;
		}	
		if (coffee_arr[i].get_medium_cost() <= budget){
			cout << "   Medium - " << coffee_arr[i].get_medium_cost() << endl;
		}
		if (coffee_arr[i].get_large_cost() <= budget){
			cout << "   Large - " << coffee_arr[i].get_large_cost() << endl;
		}
		cout << endl;
	}
	if (found == false){
		cout << "No coffees found within the specified budget." << endl;
	}
	return;
}

void Menu::add_to_menu(Coffee& coffee_to_add){
	ofstream my_outfile;
	my_outfile.open("menu.txt");

	num_coffee ++; //adding one more coffee to array

	Coffee* temp_coffee_arr = new Coffee[num_coffee]; // creating new array

	for(int i = 0; i < num_coffee - 1; i++){
		temp_coffee_arr[i] = coffee_arr[i];
	}
	temp_coffee_arr[num_coffee - 1] = coffee_to_add;

	delete [] coffee_arr;

	coffee_arr = temp_coffee_arr;

	set_num_coffee(num_coffee);

	my_outfile << num_coffee << endl;

    for (int i = 0; i < num_coffee; i++) {
        my_outfile << coffee_arr[i].get_name() << " ";
        my_outfile << coffee_arr[i].get_small_cost() << " ";
        my_outfile << coffee_arr[i].get_medium_cost() << " ";
        my_outfile << coffee_arr[i].get_large_cost() << endl;
    }

    my_outfile.close();
// by adding a coffee, the last coffee that is already in the menu is being replaced.
	return;
} // JUSTIFICATION: barely went over 15 lines, could shorten by having a single outfile but it looks less proper.


void Menu::remove_from_menu(int coffee_remove_choice){
	ofstream my_outfile;
	my_outfile.open("menu.txt");
	num_coffee --; // removing one coffee from array

	// remove coffee_remove_choice - 1 (this gets us the right index)
	Coffee* temp_coffee_arr = new Coffee[num_coffee];
	int index = 0;
	for(int i = 0; i < num_coffee + 1; i++){
		if(i != coffee_remove_choice - 1){
			temp_coffee_arr[index] = coffee_arr[i];
			index++;
		}
	}

	delete [] coffee_arr;
	coffee_arr = temp_coffee_arr;

	my_outfile << num_coffee << endl;

    for (int i = 0; i < num_coffee; i++) {
        my_outfile << coffee_arr[i].get_name() << " ";
        my_outfile << coffee_arr[i].get_small_cost() << " ";
        my_outfile << coffee_arr[i].get_medium_cost() << " ";
        my_outfile << coffee_arr[i].get_large_cost() << endl;
    }
    my_outfile.close();

	cout << "this drink has been successfully removed from the menu" << endl;

	return;
} //JUSTIFICATION: lines were taken from creating new array and copying info from old array to new one.

void Menu::print_coffees() {
	for(int i = 0; i < num_coffee; i++){
		cout << i + 1 << ". "<< coffee_arr[i].get_name() << endl;
	}
}

void Menu::print_price_and_coffee(){
	for (int i = 0; i < num_coffee; i++) {
		cout << i + 1 <<". " << coffee_arr[i].get_name() << endl;
		cout << "   Small - " << coffee_arr[i].get_small_cost() << endl;
		cout << "   Medium - " << coffee_arr[i].get_medium_cost() << endl;
		cout << "   Large - " << coffee_arr[i].get_large_cost() << endl << endl;
	}
}

void Menu::set_num_coffee(const int num_coffee){
    this->num_coffee = num_coffee;
}

int Menu::get_num_coffee() const {
	return num_coffee;
}	

string Menu::get_coffee_name(int num) const {
	string coffee_name = coffee_arr[num].get_name();
	return coffee_name;
}


Coffee* Menu::get_coffee_arr() const {
	return coffee_arr;
}

string Menu::size_options(int order_choice){
	string coffee_name;
	cout << coffee_arr[order_choice - 1].get_name() << endl;
	cout << "Small: " << coffee_arr[order_choice - 1].get_small_cost() << endl;
	cout << "Medium: " << coffee_arr[order_choice - 1].get_medium_cost() << endl;
	cout << "Large: " << coffee_arr[order_choice - 1].get_large_cost() << endl;

	coffee_name = coffee_arr[order_choice - 1].get_name();

	return coffee_name;
}

float Menu::calc_order_total(char coffee_size, int quantity, int order_choice){
	float total; 
	bool choice = false;
	do{
		if(coffee_size == 's'){
			total = quantity * coffee_arr[order_choice - 1].get_small_cost(); // calculate total cost per order
			choice = true;
		}
		else if(coffee_size == 'm'){
			total = quantity * coffee_arr[order_choice - 1].get_medium_cost();
			choice = true;
		}
		else if(coffee_size == 'l'){
			total = quantity * coffee_arr[order_choice - 1].get_large_cost();
			choice = true;
		}
		else{
			cout << "invalid input, try again" << endl;
			choice = false;
		}
	} while (choice == false);
	

	return total;
} // JUSTIFICATION: lines were taken from setting choice boolean. 

