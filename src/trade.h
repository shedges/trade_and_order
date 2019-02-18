/******************************************
Module Name :	trade.cpp
Description :	Class represent last trade info.
                Provide functionality to print trading information based on most recent trade price.

Revision History:
Ver     Date            Who             Why
001     18 Feb 2019     Sagar Shedge    Created

*******************************************/

#ifndef _TRADE_H_
#define _TRADE_H_

#include <vector>
#include "common.h"

using namespace std;

struct tradeInfo 
{
	tradeInfo() {
		mPrice = 0;
		mQuantity =0;
	}
	double mPrice;
	unsigned int mQuantity;
};

class Trade 
{
	public:
		Trade() = default;
		~Trade();
		void ProcessMessage(const vector<std::string>);

	private:
		tradeInfo mLastTrade;
		err_stats mStat; 
};

#endif
