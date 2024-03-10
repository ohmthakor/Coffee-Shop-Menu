#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    /*********************************************************************
    ** Constructor: Menu()
    ** Description: Default constructor for the Menu class. Initializes
    **              num_coffee to 0 and coffee_arr to nullptr.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Menu object is properly initialized.
    *********************************************************************/
    Menu();

    /*********************************************************************
    ** Constructor: Menu()
    ** Description: non-default constructor for the Menu class. Initializes
    **              num_coffee to the given size and allocates memory for
    **              coffee_arr based on the specified size.
    ** Parameters:
    **   - size: The int size of the coffee array to be created.
    ** Pre-Conditions: None
    ** Post-Conditions: Menu object is properly initialized with the given size.
    *********************************************************************/
    Menu(int);
    
    
    /*********************************************************************
    ** Copy Constructor: Menu()
    ** Description: Copy constructor for the Menu class. Creates a deep copy
    **              of the provided Menu object, copying the number of coffees
    **              and allocating memory for a new coffee_arr.
    ** Parameters:
    **   - m: The Menu object to be copied.
    ** Pre-Conditions: None
    ** Post-Conditions: A new Menu object is created as a deep copy of the
    **                  provided Menu object.
    *********************************************************************/
    Menu(const Menu &);


    /*********************************************************************
    ** Operator Overload: Assignment Operator=()
    ** Description: Overloads the assignment operator for the Menu class,
    **              allowing for deep copying of menu data.
    ** Parameters:
    **   - m: Reference to the Menu object to be copied.
    ** Returns: Reference to the current Menu object (*this).
    ** Pre-Conditions: None
    ** Post-Conditions: The Menu object is assigned the values of the provided Menu.
    *********************************************************************/
    Menu& operator=(const Menu &);

    /*********************************************************************
    ** Destructor: ~Menu()
    ** Description: Destructor for the Menu class. Deallocates the memory
    **              used by the coffee_arr member.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Dynamically allocated memory is freed, and
    **                  coffee_arr is set to nullptr.
    *********************************************************************/
    ~Menu();

    /*********************************************************************
    ** Function: load_data()
    ** Description: Reads coffee menu data from a file and populates the
    **              Menu object with the read data.
    ** Parameters: None
    ** Returns:
    **   - true if the data is loaded successfully.
    **   - false if the file cannot be opened or if loading fails.
    ** Pre-Conditions: None
    ** Post-Conditions:
    **   - The Menu object is populated with coffee data from the file.
    *********************************************************************/
    bool load_data();


    /*********************************************************************
    ** Function: search_coffee_by_name()
    ** Description: Searches for a coffee in the menu by its name.
    ** Parameters:
    **   - name: The name of the coffee to search for.
    ** Returns:
    **   - A Coffee object representing the found coffee.
    **     If the coffee is not found, a default-constructed Coffee object
    **     is returned (assuming Coffee has a default constructor).
    ** Pre-Conditions: None
    ** Post-Conditions:
    **   - If a coffee with the provided name is found, the found coffee
    **     is returned. Otherwise, a message is printed, and a default-
    **     constructed Coffee object is returned.
    *********************************************************************/
    Coffee search_coffee_by_name(string name); 


    /*********************************************************************
    ** Function: search_coffee_by_price()
    ** Description: Searches and prints coffees within the specified budget.
    **              Displays coffee name, small, medium, and large costs for
    **              each coffee found within the budget.
    ** Parameters:
    **   - budget: The budget within which the user is searching for coffees.
    ** Pre-Conditions: None
    ** Post-Conditions: Prints the details of coffees within the specified budget.
    *********************************************************************/
    void search_coffee_by_price(float budget); 


    /*********************************************************************
    ** Function: add_to_menu()
    ** Description: Adds a new coffee to the menu and updates the menu file.
    **              Increases the num_coffee count, creates a new array with
    **              updated size, copies the existing coffees, adds the new
    **              coffee, and writes the updated menu to the menu file.
    ** Parameters:
    **   - coffee_to_add: The Coffee object to be added to the menu.
    ** Pre-Conditions: None
    ** Post-Conditions: Menu is updated with the new coffee, and the menu
    **                  file is updated accordingly.
    *********************************************************************/
    void add_to_menu(Coffee& coffee_to_add);


    /*********************************************************************
    ** Function: remove_from_menu()
    ** Description: Removes a coffee from the menu based on the user's choice
    **              and updates the menu file accordingly. Decreases the
    **              num_coffee count, creates a new array with the updated
    **              size, copies the existing coffees excluding the chosen
    **              one, and writes the updated menu to the menu file.
    ** Parameters:
    **   - coffee_remove_choice: The index of the coffee to be removed from the menu.
    ** Pre-Conditions: None
    ** Post-Conditions: Coffee is removed from the menu, and the menu file is
    **                  updated accordingly.
    *********************************************************************/
    void remove_from_menu(int coffee_remove_choice); 


    /*********************************************************************
    ** Function: print_coffees()
    ** Description: Prints the names of all the coffees in the menu along
    **              with their corresponding indices.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Coffee names and indices are printed to the console.
    *********************************************************************/
    void print_coffees();


    /*********************************************************************
    ** Function: print_price_and_coffee()
    ** Description: Prints the names and prices of all the coffees in the menu
    **              along with their corresponding indices.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: Coffee names, prices, and indices are printed to the console.
    *********************************************************************/  
    void print_price_and_coffee();


    /*********************************************************************
    ** Function: set_num_coffee()
    ** Description: Sets the number of coffee items in the menu.
    ** Parameters:
    **   - num_coffee: The new value for the number of coffee items.
    ** Pre-Conditions: None
    ** Post-Conditions: The number of coffee items is updated to the specified value.
    *********************************************************************/
    void set_num_coffee(const int new_num_coffee);


    /*********************************************************************
    ** Function: get_num_coffee()
    ** Description: Retrieves the number of coffee items in the menu.
    ** Parameters: None
    ** Pre-Conditions: None
    ** Post-Conditions: The number of coffee items is returned.
    *********************************************************************/
    int get_num_coffee() const;


    /*********************************************************************
    ** Function: get_coffee_name()
    ** Description: Retrieves the name of a coffee item in the menu based on the provided index.
    ** Parameters:
    **   - num: The index of the coffee item.
    ** Pre-Conditions: The menu and coffee items must be properly initialized.
    ** Post-Conditions: The name of the specified coffee item is returned.
    *********************************************************************/
    string get_coffee_name(int num) const;


    /*********************************************************************
    ** Function: get_coffee_arr()
    ** Description: Retrieves the array of Coffee objects in the menu.
    ** Parameters: None
    ** Pre-Conditions: The menu and coffee items must be properly initialized.
    ** Post-Conditions: The array of Coffee objects in the menu is returned.
    *********************************************************************/
    Coffee* get_coffee_arr() const;


    /*********************************************************************
    ** Function: size_options()
    ** Description: Displays the size options (small, medium, large) for
    **              the selected coffee and returns the name of the coffee.
    ** Parameters:
    **   - order_choice: The index of the selected coffee in the menu.
    ** Pre-Conditions: The menu and coffee items must be properly initialized.
    ** Post-Conditions: The size options are displayed, and the name of the
    **                  selected coffee is returned.
    *********************************************************************/
    string size_options(int order_choice);


    /*********************************************************************
    ** Function: calc_order_total()
    ** Description: Calculates the total cost of an order based on the
    **              selected coffee size and quantity.
    ** Parameters:
    **   - coffee_size: The selected size of the coffee (s, m, or l).
    **   - quantity: The quantity of coffee items in the order.
    **   - order_choice: The index of the selected coffee in the menu.
    ** Pre-Conditions: The menu and coffee items must be properly initialized.
    ** Post-Conditions: The total cost of the order is calculated and returned.
    *********************************************************************/
    float calc_order_total(char coffee_size, int quantity, int order_choice);
};

#endif