#include <string.h>
#include <iostream>
#include "product.h"
#include <map>
using namespace std;

//cart has products
class Cart {

	// map of item id and quantity
	map<int,int> items;
	map<int,Product> productmap;
	float   totalprice;

public:
	Cart(){
		totalprice = 0;
	}
	~Cart(){
		items.clear();
		productmap.clear();
		totalprice = 0;
	}
	void addTocart(Product p){
		//if item already exists in the cart increment the quantity
		if(productmap[p.id]){
			items[p.id] +=1;
		}else {
			productmap[p.id] = p;
			items[p.id] += 1;
		}
	}
	void deleteFromCart(Product p){
		productmap.erase(p.id);
		items.erase(p.id);
	}
};
