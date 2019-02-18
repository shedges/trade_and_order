/******************************************
Module Name :	feedhandler.cpp
Description :	Class used to handle feed message.
                Provide functionality to divide message based on action either Order or trade.

Revision History:
Ver     Date            Who             Why
001     18 Feb 2019     Sagar Shedge    Created

*******************************************/

#ifndef _FEED_HANDLER_H_
#define _FEED_HANDLER_H_

#include <string.h>
#include "order.h"
#include "trade.h"

using namespace std;

class FeedHandler
{
public:
	FeedHandler() = default;

	void ProcessMessage(const string &line);
	void PrintCurrentOrderBook(ostream &os) const;

private:
	std::vector<std::string> split(const string &strToSplit, char delimeter);
	Order mOrder;
	Trade mTrade;
};

#endif
