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
class customerDiscount: public discount{

public:
	virtual float calculateDiscount(){
		return getDiscount();
	}
};
class Customer {
private:
	string name;
	int mobileNum;
	string payment;
	discount *custDiscount;
public:
	Cart* cart;
	bill checkoutBill;
public:
	Customer(string name, int mob_num) :
			name(name), mobileNum(mob_num) {
		cart = new Cart();
		custDiscount = new customerDiscount();
	}
	~Customer(){
		if(cart)
			delete cart;
		if(custDiscount)
			delete custDiscount;
	}
	string getName(){
		return name;
	}
    void addDiscount(float discount){
    	custDiscount->setDiscount(discount);
    }
    float calculateDiscount(){
    	return (cart->getCartValue() * custDiscount->calculateDiscount())/100;
    }
};
