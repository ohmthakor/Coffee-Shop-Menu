/*********************************************************************
** Program Filename: main.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: This program plays a game where the player navigates through a cave, encounters various events, and tries to win the game by reaching the gold or defeating the wumpus.
** Input: User inputs for setting the length and width of the cave, choosing debug mode, and playing the game.
** Output: Game status, cave layout, and event notifications during gameplay.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));

	int wid;
	int len;

	do{
	cout << "what would you like to set the length as?" << endl;
	cin >> len;
	} while(len < 4 || len > 50);

	do{
	cout << "what would you like to set the width as?" << endl;
	cin >> wid;
	} while(wid < 4 || wid > 50);
	
	
	string debug_choice;

	bool debug;

	bool x;

	do{
		cout << "enter 'true' for debug mode, enter 'false' for normal mode" << endl;
		cin >> debug_choice;

		if (debug_choice == "true"){
			debug = true;
			x = false;
		}
		else if (debug_choice == "false"){
			debug = false;
			x = false;
		}
		else{
			cout << "invalid input" << endl;
			x = true;
		}
	} while (x == true);
	
	Game g;
	g.play_game(len, wid, debug);

	return 0;
}