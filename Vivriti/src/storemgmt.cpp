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
 *			- Discount
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
#include "customer.h"
using namespace std;

int main() {
	cout << "!!!Hello Welcome to store!!!" << endl;\
	// Create a store object which will create inventory and checkoutregister objects and initializes them
	store* mystore = store::getStore();

	// Creating customer objects
	Customer *c1 = new Customer("nagu", 12345);
	c1->addDiscount(3);
	Customer *c2 = new Customer("raghu", 5678);
	c2->addDiscount(10);

	// Customers will add products in the store to his cart
	// Assumption here is the products are physically available so need not check the availability
	Product p = mystore->getProductById("BISGD0001");
	c1->cart->addTocart(p, 3);
	c2->cart->addTocart(p, 5);
	p = mystore->getProductById("OILSU0002");
	c1->cart->addTocart(p, 10);
	p = mystore->getProductById("CHIPS0002");
	c2->cart->addTocart(p, 5);

	mystore->addProductToStore("BISMG0001", "FOOD", 9.5,50,3);
	mystore->addProductToStore("BISMG0002", "FOOD", 20.5,50,3);
	p = mystore->getProductById("BISMG0001");
	c1->cart->addTocart(p, 4);
	c2->cart->addTocart(p, 3);
	p = mystore->getProductById("BISMG0002");
	c1->cart->addTocart(p, 6);
	c2->cart->addTocart(p, 7);

	// store will initiate checkout
	// Store will update the inventory, generate bill and sales numbers
	c1->checkoutBill = mystore->checkout(c1->cart);
	c2->checkoutBill = mystore->checkout(c2->cart);
	mystore->updateInventory(c1->cart->getItems());
	mystore->updateInventory(c2->cart->getItems());
	cout<<"BILL FOR CUSTOMER "<<c1->getName()<<endl;
	c1->checkoutBill.customer_discount = c1->calculateDiscount();
	c2->checkoutBill.customer_discount = c2->calculateDiscount();
	c1->checkoutBill.print_bill();
	cout<<"BILL FOR CUSTOMER "<<c2->getName()<<endl;
	c2->checkoutBill.print_bill();
    mystore->getSale();
	return 0;
}
