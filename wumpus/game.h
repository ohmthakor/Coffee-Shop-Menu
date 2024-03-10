#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:

	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	vector<vector<Room>> caveGrid;


	//feel free to add more variables...
	int player_wid;
	int player_len;
	int rope_wid; // to remember starting point
	int rope_len;
	int confusion_count; // when bat encounter
	bool player_gold; // determines if player has gold in possession
	int wumpus_wid;
	int wumpus_len;
	int stalactite_len1; // two different stalactites
	int stalactite_wid1;
	int stalactite_len2;
	int stalactite_wid2;
	bool has_player;
	bool player_dead;
	bool wumpus_dead;
	int gold_len;
	int gold_wid;
	int bat_len1; // two different bats
	int bat_wid1;
	int bat_len2;
	int bat_wid2;
	int arrow_path_len;
	int arrow_path_wid;
	int replay_num;




public:


	/*********************************************************************
	** Function: Game Constructor()
	** Description: Initializes a Game object by setting default values for its member variables, such as length, width, number of arrows, debug view, and creating an empty cave grid.
	** Parameters: None.
	** Pre-Conditions: None.
	** Post-Conditions: A Game object is created with default settings, and an empty cave grid is prepared for setting up the game.
	*********************************************************************/
	Game();


	/*********************************************************************
	** Function: Game Destructor()
	** Description: Cleans up resources and memory allocated for the Game object.
	** Parameters: None.
	** Pre-Conditions: The Game object is no longer in scope or needed.
	** Post-Conditions: Memory allocated for the Game object is released, and the object is properly destroyed.
	*********************************************************************/
	~Game();


	/*********************************************************************
	** Function: set_up(int, int)
	** Description: Initializes the game by setting up the game board, player, and events. This function is called at the beginning of the game.
	** Parameters: 
		- l (int): Length of the game board.
		- w (int): Width of the game board.
	** Pre-Conditions: None.
	** Post-Conditions: The game board is configured, and events, including player and wumpus, are placed randomly on the board.
	*********************************************************************/
	void set_up(int, int);

	/*********************************************************************
	** Function: display_game()
	** Description: Displays the current state of the game board, including the player's position, arrows remaining, and events in each room. The output provides a visual representation of the game's progress.
	** Parameters: None.
	** Pre-Conditions: The game has been set up, and player and event positions have been initialized.
	** Post-Conditions: The game board is printed to the console, showing the player's position, arrows remaining, and events in each room. The output is informative for the player.
	*********************************************************************/
	void display_game() const;


	/*********************************************************************
	** Function: check_win()
	** Description: Checks the current state of the game to determine if the player has won, lost, or if the game is still ongoing. Returns an integer code indicating the result.
	** Parameters: None.
	** Pre-Conditions: The game has been set up, and player and event positions have been initialized.
	** Post-Conditions: Returns an integer code:
						- 0: Game still ongoing.
						- 1: Player has won (reached the goal or completed objectives).
	*********************************************************************/
	int check_win() const;


	/*********************************************************************
	** Function: get_dir()
	** Description: Prompts the player to input a direction for firing an arrow (w for up, a for left, s for down, d for right) and validates the input.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player is prompted to fire an arrow.
	** Post-Conditions: Returns a character representing the chosen direction (w, a, s, or d).
	*********************************************************************/
	char get_dir();


	/*********************************************************************
	** Function: wumpus_move()
	** Description: Simulates the movement of the Wumpus. After a missed arrow shot by the player, there is a 75% chance that the Wumpus relocates to a different room on the game board.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player has fired an arrow (missed).
	** Post-Conditions: If the conditions are met (75% chance), the Wumpus is moved to a random empty room on the game board.
	*********************************************************************/
	void wumpus_move();


	/*********************************************************************
	** Function: fire_arrow()
	** Description: Simulates the player firing an arrow in a chosen direction (up, left, down, right). Checks if the arrow hits the Wumpus and updates the game state accordingly. Decreases the number of arrows the player has.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player chooses to fire an arrow.
	** Post-Conditions: If the arrow hits the Wumpus, the Wumpus is marked as dead. If the arrow misses, the Wumpus may move (75% chance). The number of arrows is decreased by 1.
	*********************************************************************/
	void fire_arrow();


	/*********************************************************************
	** Function: move_up()
	** Description: Moves the player's position upward on the game board. If the player is confused, the movement direction is reversed.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player chooses to move up.
	** Post-Conditions: If the player is not confused and within the bounds, the player's position is moved up. If confused, the player's position is moved down.
	*********************************************************************/
	void move_up();


	/*********************************************************************
	** Function: move_down()
	** Description: Moves the player's position downward on the game board. If the player is confused, the movement direction is reversed.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player chooses to move down.
	** Post-Conditions: If the player is not confused and within the bounds, the player's position is moved down. If confused, the player's position is moved up.
	*********************************************************************/
	void move_down();


	/*********************************************************************
	** Function: move_left()
	** Description: Moves the player's position to the left on the game board. If the player is confused, the movement direction is reversed.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player chooses to move left.
	** Post-Conditions: If the player is not confused and within the bounds, the player's position is moved left. If confused, the player's position is moved right.
	*********************************************************************/
	void move_left();


	/*********************************************************************
	** Function: move_right()
	** Description: Moves the player's position to the right on the game board. If the player is confused, the movement direction is reversed.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player chooses to move right.
	** Post-Conditions: If the player is not confused and within the bounds, the player's position is moved right. If confused, the player's position is moved left.
	*********************************************************************/
	void move_right();


	/*********************************************************************
	** Function: move()
	** Description: Handles player's action based on the input character. Calls the corresponding move function.
	** Parameters: 
	- c (char): Character representing the direction or action (w for up, a for left, s for down, d for right, f for fire).
	** Pre-Conditions: The game is in progress, and the player chooses an action.
	** Post-Conditions: Depending on the input character, the player's position is moved or an arrow is fired.
	*********************************************************************/
	void move(char);


	/*********************************************************************
	** Function: get_input()
	** Description: Prompts the player to input a character representing their desired action (movement or firing an arrow). Validates the input.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player is prompted for input.
	** Post-Conditions: Returns a character representing the player's chosen action.
	*********************************************************************/
	char get_input();


	/*********************************************************************
	** Function: play_game(int, int, bool)
	** Description: Initiates the game loop, allowing the player to navigate through the game board, encounter events, and aim for victory.
	** Parameters: 
	- l (int): Length of the game board.
	- w (int): Width of the game board.
	- d (bool): Debug mode flag.
	** Pre-Conditions: The game has been set up with dimensions and events placed.
	** Post-Conditions: The game loop runs until the player wins, loses, or chooses to exit the game.
	*********************************************************************/
	void play_game(int, int, bool);


	/*********************************************************************
	** Function: move_event(int, int, string, int)
	** Description: Moves an event (Super Bats, Stalactites, Wumpus, Gold, etc.) to a random empty room on the game board.
	** Parameters: 
	- length (int): Length of the game board.
	- width (int): Width of the game board.
	- event_name (string): Name of the event to be moved.
	- unique_event (int): Indicator for certain unique events.
	** Pre-Conditions: The game is in progress, and an event needs to be moved.
	** Post-Conditions: The specified event is moved to a random empty room on the game board.
	*********************************************************************/
	void move_event(int, int, string event_name, int unique_event);


	/*********************************************************************
	** Function: player_setup(int, int)
	** Description: Sets up the player's initial position and related variables when starting a new game or after an event.
	** Parameters: 
	- rand_len (int): Randomized length for the player's position.
	- rand_wid (int): Randomized width for the player's position.
	** Pre-Conditions: A new game is starting, or the player's position needs to be reset.
	** Post-Conditions: Initializes the player's position and related variables.
	*********************************************************************/
	void player_setup(int rand_len, int rand_wid);


	/*********************************************************************
	** Function: player_encounter()
	** Description: Checks if there are any events in adjacent rooms to the player's current position and prints corresponding percept messages.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player's position needs to be checked for adjacent events.
	** Post-Conditions: Prints percept messages for events in adjacent rooms to the player's current position.
	*********************************************************************/
	bool player_encounter();


	/*********************************************************************
	** Function: player_meet_wumpus()
	** Description: Checks if the player's position coincides with the Wumpus's position and updates the game state accordingly.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player's position needs to be checked against the Wumpus's position.
	** Post-Conditions: If the player's position matches the Wumpus's position, the player is marked as dead.
	*********************************************************************/
	void player_meet_wumpus();


	/*********************************************************************
	** Function: player_meet_stalactite()
	** Description: Checks if the player's position coincides with stalactites' positions and updates the game state accordingly.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player's position needs to be checked against stalactites' positions.
	** Post-Conditions: If the player's position matches stalactites' positions, there is a chance the player dies, and a corresponding message is printed.
	*********************************************************************/
	void player_meet_stalactite();


	/*********************************************************************
	** Function: player_meet_gold()
	** Description: Checks if the player's position coincides with the gold's position and updates the game state accordingly.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player's position needs to be checked against the gold's position.
	** Post-Conditions: If the player's position matches the gold's position, the player's gold flag is set to true.
	*********************************************************************/
	void player_meet_gold();

	/*********************************************************************
	** Function: player_meet_bat()
	** Description: Checks if the player's position coincides with bat locations and sets the player's confusion count if true.
	** Parameters: None.
	** Pre-Conditions: The game is in progress, and the player's position needs to be checked against bat locations.
	** Post-Conditions: If the player's position matches bat locations, the player's confusion count is set to 5.
	*********************************************************************/
	void player_meet_bat();


	/*********************************************************************
	** Function: reverse_arrow(char)
	** Description: Reverses the direction of an arrow.
	** Parameters: 
	- dir (char): Direction of the arrow (w, a, s, d).
	** Pre-Conditions: The game is in progress, and the direction of an arrow needs to be reversed.
	** Post-Conditions: Returns the reversed direction of the arrow.
	*********************************************************************/
	char reverse_arrow(char dir);


	/*********************************************************************
	** Function: replay()
	** Description: Prompts the player to input 1 to play again or 0 to exit the game.
	** Parameters: None.
	** Pre-Conditions: The game is over, and the player is prompted to play again or exit.
	** Post-Conditions: Returns the player's choice (1 to play again, 0 to exit).
	*********************************************************************/
	int replay();


	/*********************************************************************
	** Function: reset_game()
	** Description: Resets the game state to its initial values, preparing for a new game.
	** Parameters: None.
	** Pre-Conditions: The game is over, and the player chooses to play again.
	** Post-Conditions: Resets all necessary variables to their initial values and sets up a new game.
	*********************************************************************/
	void reset_game();


};
#endif