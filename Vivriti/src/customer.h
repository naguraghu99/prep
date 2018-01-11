#include<string.h>
#include<iostream>
#include "cart.h"
#include "product.h"
using namespace std;

// Customer can add product to cart
// Customer delete product from cart
// Customer can pay
// Customer can checkout
class payment {
	string cardNumber;
	float  Balance;
	string currency;
};
class Customer{
private:
	string name;
	int	   mobileNum;
	string payment;
	Cart  cart;
public:
	Customer(string name,int mob_num):string(name),mobileNum(mob_num){
		cart = new Cart();
	}


};
