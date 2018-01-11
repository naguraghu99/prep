/*
 * Product Class
 * 	Product Id
 * 	Product Category
 * 	Product Quantity
 * 	Product Price
 * */
#include<string.h>
using namespace std;
class Product{
	private:
		int    id;
		string category;
		float  price;
		int    quantity;
	public:
		Product(int id,string category,float price,int quantity):id(id),category(category),
		price(price),quantity(quantity){

		}
		void modify_price(float modprice){
			price = modprice;
		}
		void reduce_quantity(int mod_quantity){
			if(mod_quantity < quantity)
				cout<<"Under stock"<<endl;
			quantity -= quantity;
		}
		void add_quantity(int mod_quantity) {
			quantity += quantity;
		}
}
