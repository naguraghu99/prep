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
	private:
		int    id;
		string category;
		float  price;
	public:
		Product(int id,string category,float price,int quantity):id(id),category(category),
		price(price){

		}
		void modify_price(float modprice){
			price = modprice;
		}
		~Product(){
			id = 0;
			category.clear();
			price = 0;
		}
};
