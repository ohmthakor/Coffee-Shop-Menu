/*********************************************************************
** Program Filename: game.cpp
** Author: Ohm Thakor
** Date: 11/28/23
** Description: Implementation of game.h
*********************************************************************/

#include "game.h"
#include "room.h"

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;
// MAKE SURE LENGTH AND WIDTH ARE THE SAME ORDER IN ALL PARAMETERS
//Game Implementation

Game::Game() : length (0), width (0), num_arrows(0), debug_view(false), caveGrid() {
} // IS CAVE GRID CORRECTLY IMPLEMENTED ?

Game::~Game(){
	//Game destructor
	//Your code here:
}


void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows
	this->player_dead = false;

	// Finish the remaining...
	//Your code here:

	// created a 2d vector by the name of caveGrid with each Room object set to nullptr


	/*for(int i = 0; i < length; i ++){
		vector<Room> caveGrid;
		for(int j = 0; j < width; j++){
			caveGrid.push_back(Room());
		}
	}
	*/
	caveGrid.resize(length, vector<Room>(width));
	
	// Create the game board: 2D vector of Room objects

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board

	Game::move_event(length, width, "Super Bats", 0); // super bat #1
	Game::move_event(length, width, "Super Bats", 6); // super bat #2
	Game::move_event(length, width, "Stalactites", 3); // stalactite #1
	Game::move_event(length, width, "Stalactites", 5); // stalactite #2
	Game::move_event(length, width, "Wumpus", 2);
	Game::move_event(length, width, "Gold", 4);
	Game::move_event(length, width, "Player", 1);
}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "
			if(debug_view == true){
				if(i != rope_len || j != rope_wid){
					cout << "";
				}	
				else{
					cout << "R";
				}
			}
			if (i != player_len || j != player_wid){
				cout << " ";
			}
			else{
				cout << "*";
			}

			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)

			if(caveGrid[i][j].has_event() == false){
				cout << "  ||";
			}
			else if(debug_view == true){
				caveGrid[i][j].print_event();
				cout << " ||";
			}
			else{
				cout << "  ||";
			}
			//cout << "  ||";
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}
//justification: needed lines to make the display grid up to the standards of the assignment.


int Game::check_win() const{
	if (player_gold == true && player_len == rope_len && player_wid == rope_wid){
		return 1;
	}
	else if (wumpus_dead == true){
		return 1;
	}
	else if (player_dead == true){
		return 1;
	}
	else{
	return 0;
	}
}

void Game::move_up() {
	if(this->confusion_count > 0){
		if(player_len < length - 1){ // checks to see if it can move down
			this->player_len = player_len + 1; // moves down instead of up because of confusion
			this->player_wid = player_wid;
		}
		confusion_count = confusion_count - 1; // decrease confusion count by 1
		cout << "confusion count: " << confusion_count << endl;
	}
	else if (player_len > 0) {
        // clear the current room the player is in
        this->player_len = player_len - 1;
		this->player_wid = player_wid;
	}
	else{
		cout << "cannot move player up, hit bounds of cave grid" << endl;
	}
	return;
}

void Game::move_down() {
	
	if(this->confusion_count > 0){
		if (player_len > 0) {
        // clear the current room the player is in
        this->player_len = player_len - 1;
		this->player_wid = player_wid;
		}
	confusion_count = confusion_count - 1;
	cout << "confusion count: " << confusion_count << endl;
	}	
	else if (player_len < length - 1) {
        // clear the current room the player is in
        this->player_len = player_len + 1;
		this->player_wid = player_wid;
	}
	else{
		cout << "cannot move player down, hit bounds of cave grid" << endl;
	}
	return;
}

void Game::move_left() {
	player_meet_bat(); // this will set the confusion to 5 if they encounter bat
	if(this->confusion_count > 0){
		if(player_wid + 1 < width){ // player will move right
		this->player_len = player_len;
		this->player_wid = player_wid + 1;
		}
	confusion_count = confusion_count - 1;
	cout << "confusion count: " << confusion_count << endl;
	}	
	else if(player_wid > 0){
		this->player_len = player_len;
		this->player_wid = player_wid - 1;
	}
	else{
		cout << "cannot move player left, hit bounds of cave grid" << endl;
	}
	return;
}

void Game::move_right() {
	player_meet_bat(); // this will set the confusion to 5 if they encounter bat
	if(this->confusion_count > 0){
		if(player_wid > 0){
		this->player_len = player_len;
		this->player_wid = player_wid - 1;
		}
	confusion_count = confusion_count - 1;
	cout << "confusion count: " << confusion_count << endl;
	}
	else if(player_wid + 1 < width){
		this->player_len = player_len;
		this->player_wid = player_wid + 1;
	}
	else{
		cout << "cannot move player right, hit bounds of cave grid" << endl;
	}
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "w-up" << endl;
	cout << "a-left" << endl;
	cout << "s-down" << endl;
	cout << "d-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	bool x = true;

	do{
	if (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd'){
		cout << "invalid input" << endl;
		x = false;
		cout << "Enter direction: " << endl;
		cin >> dir;
	}
	else{
		x = true;
	}
	} while (x == false);

	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room
	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move
	int move_chance = rand() % 4;
	bool z = true;
	while (z == true){
		if(move_chance != 0){
			int new_wumpus_wid = rand() % width;
			int new_wumpus_len = rand() % length; 

			if(caveGrid[new_wumpus_len][new_wumpus_wid].has_event() == false){
				// place the existing wumpus in the new wumpus location
				caveGrid[new_wumpus_len][new_wumpus_wid] = caveGrid[wumpus_len][wumpus_wid]; 
				//set old wumpus location to empty room
				caveGrid[wumpus_len][wumpus_wid] = Room();
				// set the new wumpus length to the wumpus length
				this->wumpus_len = new_wumpus_len;
				this->wumpus_wid = new_wumpus_wid;
				cout << "wumpus has relocated" << endl;
				break;
			}
		}
		else{
		z = false;
		}
	}
	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();
	
	if (confusion_count > 0){
		cout << "you are currently confused, your arrows are firing backwards" << endl;
		dir = reverse_arrow(dir); // reverse the get_dir();
	}
	this->arrow_path_len = 0;
	this->arrow_path_wid = 0;

	if (num_arrows == 0){
		cout << "you have run out of arrows" << endl;
	}

	else if (dir == 'w'){
		arrow_path_len = -1;
		for (int i = 1; i < 4; i++){
			if (player_len + (arrow_path_len * i) == wumpus_len &&
				player_wid + (arrow_path_wid * i) == wumpus_wid){
					cout << "your arrow has pierced the Wumpus' heart and killed the wumpus, hooray!" << endl;
					wumpus_dead = true;
			}
		}
		if (wumpus_dead == false) {
			wumpus_move();
		}
		num_arrows = num_arrows - 1;
	}
	else if (dir == 'a'){
		arrow_path_wid = -1;
		for (int i = 1; i < 4; i++){
			if (player_len + (arrow_path_len * i) == wumpus_len &&
				player_wid + (arrow_path_wid * i) == wumpus_wid){
					cout << "your arrow has pierced the Wumpus' hear and killed the wumpus, hooray!" << endl;
					wumpus_dead = true;
			}
		}
		if (wumpus_dead == false) {
			wumpus_move();
		}
		num_arrows = num_arrows - 1;
	}
	else if (dir == 's'){
		arrow_path_len = 1;
		for (int i = 1; i < 4; i++){
			if (player_len + (arrow_path_len * i) == wumpus_len &&
				player_wid + (arrow_path_wid * i) == wumpus_wid){
					cout << "your arrow has pierced the Wumpus' hear and killed the wumpus, hooray!" << endl;
					wumpus_dead = true;
			}
		}
		if (wumpus_dead == false) {
			wumpus_move();
		}
		num_arrows = num_arrows - 1;
	}
	else if (dir == 'd'){
		arrow_path_wid = 1;
		for (int i = 1; i < 4; i++){
			if (player_len + (arrow_path_len * i) == wumpus_len &&
				player_wid + (arrow_path_wid * i) == wumpus_wid){
					cout << "your arrow has pierced the Wumpus' hear and killed the wumpus, hooray!" << endl;
					wumpus_dead = true;
			}
		}
		if (wumpus_dead == false) {
			wumpus_move();
		}
		num_arrows = num_arrows - 1;
	}
	return;
}
// justification: I was experiencing a lot of issues from only using a single for loop. I am not sure if those issues are stil persistent or not.

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	/*if (c == 'f'){
		Game::fire_arrow();
		return;
	}*/
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
		case 'f':
			Game::fire_arrow();
			break;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "w-up" << endl;
	cout << "a-left" << endl;
	cout << "s-down" << endl;
	cout << "d-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int l, int w, bool d){


	Game::set_up(l, w);
	this->debug_view = d;

	char input, arrow_input;
	
	while (Game::check_win() == 0){
		//print game board
		Game::display_game();

		

		input = Game::get_input();

		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		player_encounter();
		player_meet_bat(); // this will set the confusion to 5 if they encounter bat
		player_meet_gold();
		player_meet_stalactite();
		player_meet_wumpus();
// stalctite killing player message should be here
	}
	if (player_dead == true){
		cout << "game over" << endl;
	}
	else{
		cout << "YOU WIN!!" << endl;
	}
	return;
}

void Game::move_event(int length, int width, string event_name, int unique_event){
	
	bool x = true;
	while (x == true){
		int random_width = rand() % width;
		int random_length = rand() % length; 

		if(caveGrid[random_length][random_width].has_event() == false){
		
			if(unique_event == 1){ // unique for only players
				player_setup(random_length, random_width);
			}
			else if (unique_event == 0){ // bats only
				caveGrid[random_length][random_width] = Room(event_name);
				this->bat_len1 = random_length;
				this->bat_wid1 = random_width;
			}
			else if (unique_event == 6){
				caveGrid[random_length][random_width] = Room(event_name);
				this->bat_len2 = random_length;
				this->bat_wid2 = random_width;
			}
			else if (unique_event == 2){ //unique for wumpus event
				caveGrid[random_length][random_width] = Room(event_name);
				this->wumpus_wid = random_width;
				this->wumpus_len = random_length;
			}
			else if (unique_event == 3){ // unique for stalactite
				caveGrid[random_length][random_width] = Room(event_name);
				this->stalactite_len1 = random_length;
				this->stalactite_wid1 = random_width;
			}
			else if (unique_event == 4){
				caveGrid[random_length][random_width] = Room(event_name);
				this->gold_len = random_length;
				this->gold_wid = random_width;
			}
			else if (unique_event == 5){
				caveGrid[random_length][random_width] = Room(event_name);
				this->stalactite_len2 = random_length;
				this->stalactite_wid2 = random_width;
			}
			break;
		}
	}
	return;
} //Justification: I have so many lines in this function mainly because I try to seperate each event that was created, even the events that are the same type.

void Game::player_setup(int rand_len, int rand_wid){
	confusion_count = 0;
	player_gold = false;

	this->player_wid = rand_wid;
	this->player_len = rand_len;

	this->rope_wid = rand_wid;
	this->rope_len = rand_len;

	return;
}

bool Game::player_encounter(){
	// checks if there is an event around player
	if (player_len - 1 >= 0) { // checks bounds above
		if(caveGrid[player_len - 1][player_wid].has_event()){ // if it has an event above, it will print that event's percept
			caveGrid[player_len - 1][player_wid].print_perc();
		}
	}
	if(player_len + 1 < length){ // checks bounds below
		if(caveGrid[player_len + 1][player_wid].has_event()){
			caveGrid[player_len + 1][player_wid].print_perc();
		}
	}
	if(player_wid - 1 >= 0){ //checks bounds to the left of
		if(caveGrid[player_len][player_wid - 1].has_event()){ 
			caveGrid[player_len][player_wid - 1].print_perc();
		}
	}
	if(player_wid + 1 < width){ // checks bounds to the right of
		if (caveGrid[player_len][player_wid + 1].has_event()){
			caveGrid[player_len][player_wid + 1].print_perc();
		}
	}
	if(caveGrid[player_len][player_wid].has_event()){
			caveGrid[player_len][player_wid].print_encounter();
		}
	return false;
} // exactly 15 lines

void Game::player_meet_wumpus(){
	if(player_dead == false){
		if (player_len == wumpus_len && player_wid == wumpus_wid){
			cout << endl;
			player_dead = true;
		}
		else{
			player_dead = false;
		}
	}
}

void Game::player_meet_stalactite() {
	if (player_dead == false){
		if (player_len == stalactite_len1 && player_wid == stalactite_wid1){
			cout << endl;
			int x = rand() % 2;
			if (x == 1){
				cout << "a stalactite fell on you and you died" << endl;
				player_dead = true;
			}
			else{
				cout << "a stalactite fell but narrowly missed you, keep moving" << endl;
				player_dead = false;
			}
		}
		if (player_len == stalactite_len2 && player_wid == stalactite_wid2){
			cout << endl;
			int x = rand() % 2;
			if (x == 0){
				cout << "a stalactite fell on you and you died" << endl;
				player_dead = true;
			}
			else{
				cout << "a stalactite fell but narrowly missed you, keep moving" << endl;
				player_dead = false;
			}
		}
	}
}
// Justification: I use lines to print out messages as well as set values like player_dead to true/false accordingly.

void Game::player_meet_gold(){
	if (player_len == gold_len && player_wid == gold_wid){
		this->player_gold = true;
		caveGrid[gold_len][gold_wid].clear_event();
	}
}

void Game::player_meet_bat(){
	if(player_len == bat_len1 && player_wid == bat_wid1){
		this->confusion_count = 5; 
	}
	if(player_len == bat_len2 && player_wid == bat_wid2){
		this->confusion_count = 5; 
	}
}

char Game::reverse_arrow(char dir) {
	if (dir == 'w'){
		return 's';
	}
	else if (dir == 's'){
		return 'w';
	}
	else if (dir == 'a'){
		return 'd';
	}
	else if (dir == 'd'){
		return 'a';
	}
	else {
		cout << "invalid input" << endl;
		return 'f';
	}
}

int Game::replay(){
	if (check_win() == 1 || check_win() == 0){
		cout << "enter 1 to play again and 0 to exit game" << endl;
		cin >> this->replay_num;
		return replay_num;
	}
	else{
		return 3;
	}
}


void Game::reset_game() {
    // Reset all necessary variables to their initial values
    length = 0;
    width = 0;
    num_arrows = 0;
    debug_view = false;
    // Reset other variables...

    // Clear the caveGrid and set it up again
    caveGrid.clear();
    caveGrid.resize(length, vector<Room>(width));

    // Set up the game with the same length and width
    set_up(length, width);
}
