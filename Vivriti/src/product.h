/*
 * Product Class
 * 	Product Id
 * 	Product Category
 * 	Product Quantity
 * 	Product Price
 * */
#include<iostream>
#include<string.h>
using namespace std;

class Product{
public:
	string id;
private:
	string category;
	float price;
	int discount; //In percentage
public:
	Product(){
		price = 0;
		discount = 0;
	}
	Product(string id, string category, float price, int disc) :
			id(id), category(category), price(price), discount(disc) {

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
		discount = disc;
	}
	float getPrice(){
		return price;
	}
	int getDiscount(){
		return discount;
	}

};

