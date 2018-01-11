/*
 *OBJECTIVE:
 *	 Please design a class hierarchy to represent the transactions in a grocery store. 
 *
 *REQUIREMENTS:
 * 	a grocery store can have multiple registers. 
 * 	Customers come into the store and checkout items using one of the registers.
 * 	They checkout different items and bill gets generated.
 * 	Keep track of the items (you can use a few items as example) that leave the store (inventory)
 * 	and the total sales.
 *
 *PROGRAM FLOW:
 *  Write a small program that initializes the items in the store,
 * 	prints out the inventory and performs a few transactions and then at the end of these transactions,
 * 	prints out the remaining items in the store and then finally prints out the total sales during the day.
 * 	Other features include the ability to apply a discount at an item level or a class of items.
 *
 *APPROACH:
 *	Its like basic store management app. There is a store which contains products which will be purchased by the customers.
 *	when the purchase is done the inventory needs to be updated, bill should be generated and total sales for the day
 *
 *	Class:
 *		Store
 *			Basically has  products class objects
 *			- Inventory [InStock and Sales Done]
 *			- Interface to update the inventory
 *			- Discount class
 *			- cart for checkout
 *			- Customers
 *		Products
 *			- Product details [id,category,price]
 *		customer
 *			- Customer details [Name,mobilenumber]
 *		bill
 *			- Calculates cart value
 *			- Apply Discounts
 *			- Accepts payments
 *			- Generates bill
 * */

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello Welcome to store!!!" << endl;
	return 0;
}
