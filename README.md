# Order book example

This is a general trade and order book example to get current state of the order book.It provides a simple makefile to create executable.

# How to compile

Clean all .o and executable
$> make cleanall

Compile program and create executable
$> make

# Usage
$> ./orderbook
Usage :
./orderbook message_file_name
message_file_name - file name containing sequence of messages. Each message should be on separate line

# Example

Input file 
$> cat message.txt

A,100000,S,1,1075
A,100001,B,9,100.1000000000010
A,100002,B,30,975
A,100003,S,10,1050
A,100004,B,10,950
A,100005,S,2,1025
A,100006,B,1,1000
X,100004,B,10,950
A,100007,S,5,1025
A,100008,B,3,1050
T,2,1025
T,1,1025
X,100008,B,3,1050
X,100005,S,2,1025
M,100007,S,4,1025
A,100007,S,3,1000     <<< Invalid Entry
A,100007,B,3,1000     <<< Invalid Entry

# Output

$>./orderbook message.txt                                                                                                            
============================
printing order book
============================
Generated Order ID 100008 to BUY 3 quantity at price 1050
Generated Order ID 100007 to SELL 5 quantity at price 1025
Generated Order ID 100006 to BUY 1 quantity at price 1000
Generated Order ID 100005 to SELL 2 quantity at price 1025
Generated Order ID 100003 to SELL 10 quantity at price 1050
Generated Order ID 100002 to BUY 30 quantity at price 975
Generated Order ID 100001 to BUY 9 quantity at price 1000
Generated Order ID 100000 to SELL 1 quantity at price 1075

Trade occured at price 1025 with total quantity 2

Trade occured at price 1025 with total quantity 3

============================
printing order book
============================
Generated Order ID 100007 to SELL 4 quantity at price 1025
Generated Order ID 100006 to BUY 1 quantity at price 1000
Generated Order ID 100003 to SELL 10 quantity at price 1050
Generated Order ID 100002 to BUY 30 quantity at price 975
Generated Order ID 100001 to BUY 9 quantity at price 1000
Generated Order ID 100000 to SELL 1 quantity at price 1075

Trade Stats : corrupted message count - 0 invalid message count - 0

Order Stats : corrupted message count - 0, Duplicate message count - 2, Invalid entry count - 0

