/*
 * Product Class
 * 	Product Id
 * 	Product Category
 * 	Product Quantity
 * 	Product Price
 * */
#include<iostream>
#include<string.h>
#include "discount.h"
using namespace std;

class Product: public discount{
public:
	string id;
private:
	string category;
	float price;
public:
	Product(){
		price = 0;
		setDiscount(0);
	}
	Product(string id, string category, float price, float disc) :
			id(id), category(category), price(price){
		setDiscount(disc);

	}
	void modify_price(float modprice) {
		price = modprice;
	}
	~Product() {
		id = "";
		category.clear();
		price = 0;
	}
	void modify_discount(int disc) {
		setDiscount(disc);
	}
	float getPrice(){
		return price;
	}
	virtual float calculateDiscount(){
		return (price*getDiscount())/100;
	}

};

