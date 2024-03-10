#ifndef COFFEE_H
#define COFFEE_H

#include <iostream>
#include <string>

using namespace std;
class Coffee{
private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;

public:
    /*********************************************************************
    ** Function: Coffee()
    ** Description: Default constructor for coffee
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: Coffee object with its values set to default
    *********************************************************************/
    Coffee(); //Coffee constructor


    /*********************************************************************
    ** Function: Coffee()
    ** Description: non-Default constructor for coffee
    ** Parameters:  string - Coffee name
                    float - small cost
                    float - medium cost
                    float large cost
    ** Pre-Conditions: none
    ** Post-Conditions: Coffee object with its inputted values is created
    *********************************************************************/
    Coffee(string, float, float, float);


    /*********************************************************************
    ** Function: set_name()
    ** Description: setter for the name member of coffee class
    ** Parameters: string - name
    ** Pre-Conditions: none
    ** Post-Conditions: 
    *********************************************************************/
    void set_name (const string);


    /*********************************************************************
    ** Function: set_small_cost()
    ** Description: setter for the small_cost member of coffee class
    ** Parameters: float - cost
    ** Pre-Conditions: none
    ** Post-Conditions: created for lab
    *********************************************************************/
    void set_small_cost(const float);


    /*********************************************************************
    ** Function: set_medium_cost()
    ** Description: setter for the medium_cost member of coffee class
    ** Parameters: float - cost
    ** Pre-Conditions: none
    ** Post-Conditions: created for lab
    *********************************************************************/
    void set_medium_cost(const float);


    /*********************************************************************
    ** Function: set_large_cost()
    ** Description: setter for the large_cost member of coffee class
    ** Parameters: float - cost
    ** Pre-Conditions: none
    ** Post-Conditions: created for lab
    *********************************************************************/
    void set_large_cost(const float);


    /*********************************************************************
    ** Function: get_name()
    ** Description: getter for the name member of coffee class, used in
                    Shop::view_shop_detail()
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: returns the name member when called, cannot change it
    *********************************************************************/
    string get_name() const;


    /*********************************************************************
    ** Function: get_small_cost()
    ** Description: getter for the small_cost member of coffee class, used in
                    Shop::view_shop_detail()
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: returns the small_cost member when called, cannot change it
    *********************************************************************/
    float get_small_cost () const;


    /*********************************************************************
    ** Function: get_medium_cost()
    ** Description: getter for the medium_cost member of coffee class, used in
                    Shop::view_shop_detail()
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: returns the medium_cost member when called, cannot change it
    *********************************************************************/
    float get_medium_cost () const;


    /*********************************************************************
    ** Function: get_large_cost()
    ** Description: getter for the large_cost member of coffee class, used in
                    Shop::view_shop_detail()
    ** Parameters: none
    ** Pre-Conditions: none
    ** Post-Conditions: returns the large_cost member when called, cannot change it
    *********************************************************************/
    float get_large_cost () const;


    /*********************************************************************
    ** Function: print_coffee()
    ** Description: prints each member of the coffee object, used in shop.cpp (Shop::remove_from_menu())
    ** Parameters: none
    ** Pre-Conditions: The Coffee object must be properly initialized with
    **                 valid values for its name, small_cost, medium_cost,
    **                 and large_cost members.
    ** Post-Conditions: The details of the coffee are printed
    *********************************************************************/
    void print_coffee() const;


    /*********************************************************************
    ** Function: print_menu()
    ** Description: Writes the details of a coffee object to an output file stream,
    **              including its name, small cost, medium cost, and large cost.
    ** Parameters:
    **   - my_outfile: An output file stream where the coffee details will be written.
    ** Pre-Conditions:
    **   - The Coffee object must be properly initialized with valid values for
    **     its name, small_cost, medium_cost, and large_cost members.
    **   - The provided output file stream (my_outfile) must be open and in a writable state.
    ** Post-Conditions:
    **   - The details of the coffee are written to the specified output file stream.
    *********************************************************************/
    void print_menu(ofstream& my_outfile) const;
};

#endif