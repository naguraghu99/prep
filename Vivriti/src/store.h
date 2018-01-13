/*	Store has products
 * 		- Maintains inventory
 * 		- Performs sale
 * 		- Generates bill
 * 		- Gives discounts products
 */
#include <iostream>
#include <map>
#include "cart.h"
#include  "bill.h"
using namespace std;

class inventory {
private:
	map<string, int> itemQuantity;
	map<string, Product> productCatalog;
	map<string, int> totalsale; //<prodId,numitemssold>
public:
	inventory() {
		itemQuantity.insert(pair<string,int>("BISGD001",50));
		Product p1("BISGD001","FOOD", 9.5,3);
		productCatalog.insert(pair<string,Product>("BISGD001",p1));
		itemQuantity.insert(pair<string,int>("OILSUN0002",50));
		Product p2("OILSUN0002","FOOD", 9.5,3);
		productCatalog.insert(pair<string,Product>("OILSUN0002",p2));
		itemQuantity.insert(pair<string,int>("CHIPS0002",50));
		Product p3("CHIPS0002","FOOD", 9.5,3);
		productCatalog.insert(pair<string,Product>("CHIPS0002",p3));
	}
	~inventory() {
		itemQuantity.clear();
		productCatalog.clear();
		totalsale.clear();
	}
	// Adds product to inventory
	void addProductToInventory(string pid, string category, float price,
			int quantity, int discount) {
		Product p(pid, category, price, discount);
		productCatalog.insert(pair<string, Product>(pid, p));
		itemQuantity.insert(pair<string, int>(pid, quantity));
	}
	// Remove products from inventory
	void removeProductFromInventory(string productId) {

	}
	// Updates inventory with cart information
	void updateInventory(map<string, int> items) {
		map<string, int>::iterator itemsiter = items.begin();
		for (; itemsiter != items.end(); itemsiter++) {
			if (!itemQuantity[itemsiter->first])
				continue;
			// update the quantity
			itemQuantity[itemsiter->first] = itemQuantity[itemsiter->first]
					- (itemsiter->second);
			// update sale
			totalsale[itemsiter->first] = totalsale[itemsiter->first]
					+ (itemsiter->second);
			if (itemQuantity[itemsiter->first] == 0) {
				productCatalog.erase(itemsiter->first);
			}
		}
	}
	void updateInventory(string prodId, int quantity) {

	}
	Product getProductById(string prodId) {
		return productCatalog[prodId];
	}
};
class checkoutregister: public inventory {
public:
	bill checkout(Cart *cart) {
		int tax = 3;
		// Updates cart and generated bill
		updateInventory(cart->getItems());
		bill cartBill(*cart, tax);
		return cartBill;
	}
};

class store {
private:
	inventory *storeInventory;
	static store* mystore;
	store() {
		// Initializes inventory
		storeInventory = new inventory();
	}
	~store() {
		// Clear inventory
		if (storeInventory)
			delete storeInventory;
	}
public:
	static store* getStore();
	void addProductToStore(string pid, string category, float price,
			int quantity, int discount) {
		storeInventory->addProductToInventory(pid, category, price, quantity,
				discount);
	}
	bill checkout(Cart *cart) {
		checkoutregister ckregister;
		return ckregister.checkout(cart);
	}
	Product getProductById(string id) {
		return storeInventory->getProductById(id);
	}
};
store* store::mystore = NULL;
store* store::getStore() {
	if (mystore)
		return mystore;
	else {
		mystore = new store();
		return mystore;
	}
}

