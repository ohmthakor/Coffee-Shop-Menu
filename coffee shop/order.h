#ifndef ORDER_H
#define ORDER_H 

#include <string>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	/*********************************************************************
	** Function: Order ()
	** Description: default constructor, initializes an Order object with default values.
	** Parameters: None
	** Pre-Conditions: None
	** Post-Conditions:
	**   - The Order object is initialized with the following default values:
	**       - id is set to -1.
	**       - coffee_name is set to an empty string.
	**       - coffee_size is set to a default character value (e.g., ' ').
	**       - quantity is set to -1.
	*********************************************************************/
	Order();


	/*********************************************************************
	** Function: Order ()
	** Description: Non-default constructor,nitializes an Order object with specified values for its members.
	** Parameters:
	**   - i: An integer representing the order ID.
	**   - name: A string representing the coffee name.
	**   - size: A character representing the coffee size.
	**   - k: An integer representing the quantity of coffee in the order.
	** Pre-Conditions: None
	** Post-Conditions:
	**   - The Order object is initialized with the provided values:
	**       - id is set to the specified order ID (i).
	**       - coffee_name is set to the specified coffee name (name).
	**       - coffee_size is set to the specified coffee size (size).
	**       - quantity is set to the specified quantity (k).
	*********************************************************************/
	Order(int i, string name, char size, int k);


	/*********************************************************************
	** Function: get_id()
	** Description: gets the ID of the Order.
	** Parameters: None
	** Pre-Conditions: The Order object must be properly initialized.
	** Post-Conditions:
	**   - The ID of the Order is returned.
	*********************************************************************/
	int get_id() const;


	/*********************************************************************
	** Function: get_name()
	** Description: gets the name of the Order.
	** Parameters: None
	** Pre-Conditions: The Order object must be properly initialized.
	** Post-Conditions:
	**   - The name of the Order is returned.
	*********************************************************************/
	string get_name() const;


	/*********************************************************************
	** Function: get_size()
	** Description: gets the size of the Order.
	** Parameters: None
	** Pre-Conditions: The Order object must be properly initialized.
	** Post-Conditions:
	**   - The size of the Order is returned.
	*********************************************************************/
	char get_size() const;


	/*********************************************************************
	** Function: get_quantity()
	** Description: gets the quantity of the Order.
	** Parameters: None
	** Pre-Conditions: The Order object must be properly initialized.
	** Post-Conditions:
	**   - The quantity of the Order is returned.
	*********************************************************************/
	int get_quantity() const;
};
#endif