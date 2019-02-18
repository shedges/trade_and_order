/******************************************
Module Name :	main.cpp
Description :	Provide functionality to read feed message from source and pass to feed handler to process each message.

Revision History:
Ver     Date            Who             Why
001     18 Feb 2019     Sagar Shedge    Created

*******************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include "feedhandler.h"

using namespace std;

void usage(char **argv)
{
	cout << "Usage : " << endl;
	cout << argv[0] << " message_file_name" << endl;
	cout << "message_file_name - file name containing sequence of messages. Each message should be on separate line" << endl;

}

int main(int argc, char **argv)
{
	string line;
	if(argc != 2 ) {
		usage(argv);
		return 1;
	}
	FeedHandler feed;
	const string filename(argv[1]);
	ifstream infile(filename.c_str(), ifstream::in);
	int counter = 0;
	while (getline(infile, line)) {
		feed.ProcessMessage(line);
		if (++counter % 10 == 0) {
			feed.PrintCurrentOrderBook(cerr);
		}
	}
	feed.PrintCurrentOrderBook(cout);
	return 0;
}



