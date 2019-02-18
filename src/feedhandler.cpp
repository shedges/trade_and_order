/******************************************
Module Name :	feedhandler.cpp
Description :	Class used to handle feed message.
                Provide functionality to divide message based on action either Order or trade.

Revision History:
Ver     Date            Who             Why
001     18 Feb 2019     Sagar Shedge    Created

*******************************************/

#include <sstream>
#include "feedhandler.h"

vector<string> FeedHandler::split(const string &strToSplit, char delimeter)
{
    stringstream ss(strToSplit);
    string item;
    vector<string> splittedStrings;
    while (getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}


void FeedHandler::ProcessMessage(const string &line) 
{
	vector<string> tempSplitedString = split(line, ',');

	if(strncasecmp(tempSplitedString[0].c_str(), "t", strlen(tempSplitedString[0].c_str())) == 0) {
		mTrade.ProcessMessage(tempSplitedString);
	} else {
		mOrder.ProcessMessage(tempSplitedString);
	}
}

void FeedHandler::PrintCurrentOrderBook(ostream &os) const
{
	mOrder.PrintCurrentOrderBook(os);
}

