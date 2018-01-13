#include<string.h>
#include<iostream>
#include "store.h"
using namespace std;

// Customer can add product to cart
// Customer delete product from cart
// Customer can pay
// Customer can checkout
class payment {
	string cardNumber;
	int pin;
	int cvv;
};
class Customer {
private:
	string name;
	int mobileNum;
	string payment;
public:
	Cart* cart;
	bill checkoutBill;
public:
	Customer(string name, int mob_num) :
			name(name), mobileNum(mob_num) {
		cart = new Cart();
	}
	string getName(){
		return name;
	}

};
