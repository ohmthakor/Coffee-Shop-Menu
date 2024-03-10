/*********************************************************************
** Program Filename: prog.cpp
** Author: Ohm Thakor
** Date: 11/13/23
** Description: Implementation of the main function
*********************************************************************/
#include <iostream>
#include "display.h"

using namespace std;

/*********************************************************************
** Function: main()
** Description: This is where the coffee shop program stars. 
**				Initializes a Shop object, loads data, and enters a loop to interact with
**              the user based on their choices. The loop continues
**              until the user decides to quit.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Program execution terminates after the user chooses
**                  to quit or if there are issues loading data.
*********************************************************************/
int main()
{
	//your main function lives here
	cout << "Welcome to Coffee++" << endl;
	int choice = -1;
	Shop s;
	//populate your Shop:
	bool loaded_properly = s.load_data() && s.order_file_validate(); //checks to see if correct files are implemented, if not, terminate.
	
	

	while (choice != QUIT && loaded_properly){
		choice = get_choice(s);
		perform_action(s, choice);
	}

	if (!loaded_properly) {
		cout << "File failed to open. Terminating gracefully" << endl;
	}
	cout << "Bye!" << endl;
	

	return 0;
}
