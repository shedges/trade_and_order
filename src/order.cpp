/******************************************
Module Name :   order.cpp
Description :   Class represent current state of order book.
                Update order book on every message.
                Provide functionality to add , remove or modify action based on orderId.

Revision History:
Ver     Date            Who             Why
001     18 Feb 2019     Sagar Shedge    Created

*******************************************/

#include <iostream>
#include <string.h>
#include <cerrno>
#include <cstdlib>
#include <limits.h>
#include "order.h"


typedef unordered_multimap<unsigned int, order_info>::iterator orderBookItr;

Order::~Order()
{
	cout << endl << "Order Stats : corrupted message count - "<< mStat.mCorruptMessage << ", Duplicate message count - "<< mStat.mDuplicateEntry << ", Invalid entry count - " << mStat.mInvalidEntry << endl ;
}

bool Order::addEntry(unsigned int orderId, SIDE side, unsigned int quantity, double price)
{
	bool ret = false;

	if(mOrderBook.find(orderId) != mOrderBook.end()) {
		mStat.mDuplicateEntry++;
	} else {
		order_info orderInfoEntry {price, side, quantity};
		mOrderBook.insert(make_pair(orderId, orderInfoEntry));
		ret = true;
	}
	return ret;
}

bool Order::removeEntry(unsigned int orderId, SIDE side, unsigned int quantity, double price)
{
	bool ret = false;

	orderBookItr tmpItr = mOrderBook.find(orderId);

	if(tmpItr != mOrderBook.end()) {
		order_info orderInfoEntry = (order_info) tmpItr->second;
		if( (orderInfoEntry.mPrice == price) && (orderInfoEntry.mSide == side)) {
			mOrderBook.erase(tmpItr);
			ret = true;
		} else {
			mStat.mInvalidEntry++;
		}
	} else {
		mStat.mInvalidEntry++;
	}

	return ret;
}

bool Order::modifyEntry(unsigned int orderId, SIDE side, unsigned int quantity, double price)
{
	bool ret = false;
	if( removeEntry(orderId, side, quantity, price) ) {
		ret = addEntry(orderId, side, quantity, price);
	} 

	return ret;
}

void Order::ProcessMessage(const std::vector<std::string> messageInfo)
{
	if(messageInfo.size() != 5) {
		mStat.mCorruptMessage++;
		return;
	}

	unsigned int orderId, quantity;
	double price;

	auto action = messageInfo[0].c_str();

	if(!convertStrToUINT(messageInfo[1], orderId)) {
		mStat.mInvalidEntry++;
		return;
	}

	SIDE side;
	if(!convertStrToUINT(messageInfo[3], quantity)) {
		mStat.mInvalidEntry++;
		return;
	}

	if(!convertStrToDouble(messageInfo[4], price)) {
		mStat.mInvalidEntry++;
		return;
	}

	if(strncasecmp(messageInfo[2].c_str(), "b", strlen(messageInfo[2].c_str())) == 0) {
		side = BUY;
	} else if (strncasecmp(messageInfo[2].c_str(), "s", strlen(messageInfo[2].c_str())) == 0) {
		side = SELL;
	} else {
		mStat.mCorruptMessage++;
		return;
	}

	if(strncasecmp(action, ADD_ACTION, strlen(action)) == 0 ) {
		addEntry(orderId,side,quantity,price);
	} else if (strncasecmp(action,REMOVE_ACTION, strlen(action)) == 0) {
		removeEntry(orderId,side,quantity,price);
	} else if (strncasecmp (action , MODIFY_ACTION, strlen(action)) == 0 ) {
		modifyEntry(orderId,side,quantity,price);
	} else {
		mStat.mCorruptMessage++;
		return;
	}
}

void Order::PrintCurrentOrderBook(std::ostream &os) const
{
	os << endl << "============================" << endl;
	os << "printing order book" << endl;
	os << "============================" << endl;
        for(auto itr = mOrderBook.begin(); itr != mOrderBook.end(); itr++) {
		order_info orderInfoEntry = (order_info) itr->second;
		if(orderInfoEntry.mSide == BUY) {
			cout << "Generated Order ID " << itr->first <<" to BUY "<< orderInfoEntry.mQuantity << " quantity at price " << orderInfoEntry.mPrice <<  endl;
		} else {
			cout << "Generated Order ID " << itr->first <<" to SELL "<< orderInfoEntry.mQuantity << " quantity at price " << orderInfoEntry.mPrice <<  endl;
		}
        }
}
