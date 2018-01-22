#include <string.h>
#include <iostream>
#include <map>
#include "Product.h"
using namespace std;

//cart has products
class Cart {
private:
	// map of item id and quantity
	map<string, int> items;
	map<string, Product> pidMap;
	float cartvalue;

public:
	~Cart() {
		items.clear();
		pidMap.clear();
	}
	void addTocart(Product p, int quantity) {
		//if item already exists in the cart increment the quantity
		if (items[p.id]) {
			items[p.id] += 1;
		} else {
			pidMap.insert(pair<string, Product>(p.id, p));
			items[p.id] = quantity;
		}
	}
	void deleteFromCart(string pid) {
		items.erase(pid);
		pidMap.erase(pid);
	}
	map<string, int>& getItems() {
		return items;
	}
	map<string, Product>& getPdMap() {
		return pidMap;
	}
	void printCart() {
		map<string, Product>::iterator itemiter = pidMap.begin();
		for (; itemiter != pidMap.end(); itemiter++) {
			cout << itemiter->first << "  " << "  " << items[itemiter->first]
					<< "  " << endl;
		}
	}
	float getCartValue() {
		map<string, Product>::iterator itemiter = pidMap.begin();
		for (; itemiter != pidMap.end(); itemiter++) {
			cartvalue += items[itemiter->first] * (itemiter->second.getPrice());
		}
		return cartvalue;
	}
};
