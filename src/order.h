/******************************************
Module Name : 	order.h
Description :	Class represent current state of order book.
		Update order book on every message. 
		Provide functionality to add , remove or modify action based on orderId.

Revision History:
Ver   	Date          	Who   		Why
001	18 Feb 2019	Sagar Shedge	Created

*******************************************/
#ifndef _ORDER_H_
#define _ORDER_H_

#include <unordered_map>
#include <vector>
#include "common.h"

using namespace std;

#define ADD_ACTION "a"
#define REMOVE_ACTION "x"
#define MODIFY_ACTION "m"

enum SIDE { BUY = 0, SELL};


struct order_info {
	double		mPrice;
	SIDE		mSide;
	unsigned int 	mQuantity;

	explicit order_info() {
		mPrice = 0;
		mSide = BUY;
		mQuantity = 0;
	}

	explicit order_info(double price, SIDE side, unsigned int quantity) {
		mPrice = price;
		mSide = side;
		mQuantity = quantity;
	}
};

class Order
{
	public:
		Order() = default;
		~Order();
		void ProcessMessage(const vector<std::string>);
		void PrintCurrentOrderBook(ostream &os)const;

	private:
		bool addEntry(unsigned int orderId, SIDE side, unsigned int quantity, double price);
		bool removeEntry(unsigned int orderId, SIDE side, unsigned int quantity, double price);
		bool modifyEntry(unsigned int orderId, SIDE side, unsigned int quantity, double price);

		unordered_multimap<unsigned int, order_info> mOrderBook;	
		err_stats mStat;

};

#endif
