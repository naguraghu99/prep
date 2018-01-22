/*
 * discount.h
 *
 *  Created on: Jan 22, 2018
 *      Author: nraghuna
 */

#ifndef DISCOUNT_H_
#define DISCOUNT_H_

// This class would basically implementing the discount logic
class discount {
	float discount_rate;

public:
	discount(){}
	void setDiscount(float discount) {
		discount_rate = discount;
	}
	virtual float calculateDiscount() = 0;
	float getDiscount(){return discount_rate;}
	virtual ~discount(){}
};


#endif /* DISCOUNT_H_ */
