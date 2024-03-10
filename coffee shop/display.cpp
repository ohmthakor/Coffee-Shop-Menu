/*********************************************************************
** Program Filename: display.cpp
** Author: Ohm Thakor
** Date: 11/13/23
** Description: Implementation of display.h, called from prog.cpp
*********************************************************************/
#include <iostream>
#include "display.h"

using namespace std;

/* name: print_options()
 * description: print possible options to the user
 * parameters: none
 * pre-condition: none
 * post-conditon: none
 */
void print_options(Shop& s) {
	cout << endl; 
	cout << "What would you like to do: " << endl;
	cout << "  1. View shop info " << endl;
	cout << "  2. Add an item to menu " << endl;
	cout << "  3. Remove an item from menu " << endl;
	cout << "  4. Search by coffee name " << endl;
	cout << "  5. Search by price " << endl;
	cout << "  6. Place an order " << endl;
	cout << "  7. Clone a shop " << endl;
	cout << "  8. Log out " << endl;
	cout << endl;
}

int get_choice(Shop& s) {
	int choice = -1; 
	do {
		print_options(s);
		cout << "Selection: ";
		cin >> choice;
	}while (!(choice >= 1 && choice <= QUIT));

	return choice; 
}

void perform_action(Shop& s, int choice) {
	switch (choice){
		case 1:
			s.view_shop_detail();
			break;
		case 2:
			s.add_to_menu();
			break;
		case 3:
			s.remove_from_menu();
			break;
		case 4:
			s.search_by_name();
			break;
		case 5:
			s.search_by_price();
			break;
		case 6:
			s.place_order();
			break;
		case 7:
			s.clone_shop();
			break;
	}

	return;
}
