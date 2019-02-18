/******************************************
Module Name :	trade.cpp
Description :	Class represent last trade info.
                Provide functionality to print trading information based on most recent trade price.

Revision History:
Ver     Date            Who             Why
001     18 Feb 2019     Sagar Shedge    Created

*******************************************/

#include <iostream>
#include <string.h>
#include "trade.h"

Trade::~Trade()
{
	cout << "Trade Stats : corrupted message count - "<< mStat.mCorruptMessage << " invalid message count - " << mStat.mInvalidEntry << endl;
}

void Trade::ProcessMessage(const std::vector<std::string> messageInfo)
{
	unsigned int quntity;
	double price;

	if(messageInfo.size() != 3) {
		mStat.mCorruptMessage++;
		return;
	}

	if(!convertStrToUINT(messageInfo[1], quntity)) {
		mStat.mInvalidEntry++;
		return;
	}

	if(!convertStrToDouble(messageInfo[2], price)) {
		mStat.mInvalidEntry++;
		return;
	}


	if(mLastTrade.mPrice == price) {
		mLastTrade.mQuantity += quntity;
	} else {
		mLastTrade.mPrice = price;
		mLastTrade.mQuantity = quntity;
		
	}
	cout << endl << "Trade occured at price "<< mLastTrade.mPrice << " with total quantity " << mLastTrade.mQuantity << endl;
}
