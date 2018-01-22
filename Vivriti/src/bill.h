/*
 *  Bill class will have following things
 *  	- Amount of each item with discount
 *  	- total price of the cart
 *  	- tax
 *  	- Final payable amount
 * */

#include <iostream>
using namespace std;
class bill{
	Cart cartItems;
	int  tax;
	float payableAmount;
	float totalPrice;
public:
    float customer_discount;
	public:
		bill (){
			tax = 0;
			payableAmount = 0;
			totalPrice = 0;
			customer_discount = 0;
		}
		bill(Cart cartItems,int tax):cartItems(cartItems),tax(tax){
			payableAmount = 0;
			totalPrice = 0;
			customer_discount = 0;
		}
		void print_bill(){
			int sno = 1;
			map<string,int>::iterator itemiter = cartItems.getItems().begin();
			map<string,Product> pmap = cartItems.getPdMap();
			for(;itemiter != cartItems.getItems().end();itemiter++){
				float price = (itemiter->second * pmap[itemiter->first].getPrice());
				float disc  = (itemiter->second * pmap[itemiter->first].calculateDiscount());
				cout<<"SNO:"<<sno<<"  ProductId:"<<pmap[itemiter->first].id<<"  Quantity:"<<itemiter->second
						<<"  Discount:"<<pmap[itemiter->first].calculateDiscount()<<"  Price:"<<price;
				cout<<endl;
				sno++;
				totalPrice += price-disc;
			}
			cout<<"Total Amount: "<<totalPrice<<endl;
			cout<<"Customer Discount: "<<customer_discount<<endl;
			cout<<"Total Payable amount is  "<<totalPrice-customer_discount<<endl;
			cout<<endl;
		}
};
