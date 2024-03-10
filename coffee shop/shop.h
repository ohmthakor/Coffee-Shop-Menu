#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Order o;
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
    int order_choice;
  public:

    /*********************************************************************
    ** Constructor: Shop ()
    ** Description: default contructor, initializes a Shop object with default values.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions:
    **   - The Shop object is initialized with the following default values:
    **       - m is constructed using its default constructor.
    **       - phone is set to an empty string.
    **       - address is set to an empty string.
    **       - revenue is set to 0.00.
    **       - order_arr is set to nullptr.
    **       - num_orders is set to 0.
    *********************************************************************/
    Shop();


    /*********************************************************************
    ** Constructor: Shop ()
    ** Description: non-default constructor, initializes a Shop object with specified values for its members.
    ** Parameters:
    **   - phone: A string representing the phone number of the shop.
    **   - address: A string representing the address of the shop.
    **   - revenue: A float representing the revenue of the shop.
    ** Pre-Conditions: None
    ** Post-Conditions:
    **   - The Shop object is initialized with the provided values:
    **       - phone is set to the specified phone number.
    **       - address is set to the specified address.
    **       - revenue is set to the specified revenue.
    **       - m is constructed using its default constructor.
    **       - order_arr is set to nullptr.
    **       - num_orders is set to 0.
    *********************************************************************/
    Shop(string, string, float);


    /*********************************************************************
    ** Constructor: Shop (Copy Constructor)
    ** Description: Creates a new Shop object by copying the contents of another Shop object.
    ** Parameters:
    **   - s: A constant reference to a Shop object to be copied.
    ** Pre-Conditions: None
    ** Post-Conditions:
    **   - A new Shop object is created with the same values as the provided Shop object (s).
    **   - Deep copy is performed for the order_arr member to avoid shallow copying.
    *********************************************************************/
    Shop (const Shop & s);


    /*********************************************************************
    ** Operator: =()
    ** Description: Overloads the assignment operator to copy the contents of another Shop object.
    ** Parameters:
    **   - s: A constant reference to a Shop object whose contents will be copied.
    ** Returns:
    **   - A reference to the modified Shop object.
    ** Pre-Conditions: None
    ** Post-Conditions:
    **   - The contents of the current Shop object are replaced with the contents of the provided Shop object (s).
    **   - If the current Shop object had dynamically allocated memory, it is deallocated before copying.
    **   - Deep copy is performed for the order_arr member to avoid shallow copying.
    *********************************************************************/
    Shop& operator=(const Shop & s);


    /*********************************************************************
    ** Destructor: ~Shop()
    ** Description: Deallocates dynamic memory and performs cleanup for a Shop object.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions:
    **   - Dynamic memory allocated for the order_arr member is deallocated.
    **   - order_arr is set to nullptr to avoid dangling pointers.
    *********************************************************************/
    ~Shop();

    /*********************************************************************
    ** Function: load_data
    ** Description: Loads menu data and shop information from external files.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: Menu data and shop information are loaded from files. 
    **                  Returns true if both operations are successful, false otherwise.
    *********************************************************************/
    bool load_data();

    /*********************************************************************
    ** Function: view_shop_detail()
    ** Description: Displays detailed information about the shop, including
    **              address, phone number, revenue, menu, and order information.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: Shop details, menu, and order information are printed to the console.
    *********************************************************************/
    void view_shop_detail();


    /*********************************************************************
    ** Function: add_to_menu()
    ** Description: Prompts the user to input details for a new coffee, 
    **              creates a Coffee object, and adds it to the shop's menu.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: A new coffee is added to the menu with the specified details.
    *********************************************************************/
    void add_to_menu();


    /*********************************************************************
    ** Function: remove_from_menu()
    ** Description: Displays the menu, prompts the user to choose a coffee 
    **              to remove by number, and removes the selected coffee 
    **              from the shop's menu.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: The selected coffee is removed from the menu.
    *********************************************************************/
    void remove_from_menu();


    /*********************************************************************
    ** Function: search_by_name()
    ** Description: Prompts the user to enter the name of the coffee they are 
    **              trying to find and searches for it in the shop's menu.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: If the coffee is found, its details are displayed; 
    **                  otherwise, a message indicating that the coffee was not found is shown.
    *********************************************************************/
    void search_by_name();


    /*********************************************************************
    ** Function: search_by_price()
    ** Description: Prompts the user to enter a budget and searches for 
    **              coffee options within the specified budget in the shop's menu.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: Coffee options within the specified budget are displayed.
    *********************************************************************/
    void search_by_price();

    /*********************************************************************
    ** Function: place_order()
    ** Description: Initiates the process of placing an order by prompting
    **              the user to choose a coffee, select its size and quantity,
    **              and confirm the order. Updates shop revenue and order
    **              information accordingly.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: The order is placed and relevant information is updated.
    *********************************************************************/
    void place_order();


    /*********************************************************************
    ** Function: add_order()
    ** Description: Adds a new order to the shop, updating order information
    **              and writing the details to the "orders.txt" file.
    ** Parameters:
    **   - order_choice: Index of the selected coffee in the menu.
    **   - coffee_size: Size of the ordered coffee (s - small, m - medium, l - large).
    **   - quantity: Number of units of the selected coffee in the order.
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: The order is added, and relevant information is updated.
    *********************************************************************/
    void add_order(const int order_choice, const char coffee_size, const int quantity);


    /*********************************************************************
    ** Function: clone_shop()
    ** Description: Clones the current shop object using both the assignment
    **              operator and copy constructor. This function is intended
    **              for testing the big three (copy constructor, assignment
    **              operator, and destructor) implementation.
    ** Parameters: None
    ** Pre-Conditions: The Shop object must be properly initialized.
    ** Post-Conditions: The cloned shop is created and displayed.
    *********************************************************************/
    Shop clone_shop();


    /*********************************************************************
    ** Function: order_file_validate()
    ** Description: Validates the existence and accessibility of the "orders.txt"
    **              file by attempting to open it. Returns true if the file
    **              can be opened, and false otherwise.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The status of the "orders.txt" file is determined.
    *********************************************************************/
    bool order_file_validate();
};

#endif
