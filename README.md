# Order book example

This is a general trade and order book example to get current state of the order book.It provides a simple makefile to create executable.

# How to compile

Go to src directory <br />
$> cd src<br />

Clean all .o and executable<br />
$> make cleanall<br />

Compile program and create executable<br />
$> make<br />

# Usage
$> ./orderbook<br />
Usage : <br />
./orderbook message_file_name<br />
message_file_name - file name containing sequence of messages. Each message should be on separate line<br />

# Input assumption<br />
Order and trade sequence will be received from file. <br />
Each message will be independent of other and parsed indivisually. Order book will be updated on every message.<br />
System integrity and automicity will be maintain by messages. This program will manage order book based on messages.<br />
Praogram will not modify ordr book on invalid entry. It will use stats to maintain invalid/corrupted messages.<br />
<br />
# Example<br />

# Input file <br />
$> cat message.txt<br />

A,100000,S,1,1075<br />
A,100001,B,9,1000<br />
A,100002,B,30,975<br />
A,100003,S,10,1050<br />
A,100004,B,10,950<br />
A,100005,S,2,1025<br />
A,100006,B,1,1000<br />
X,100004,B,10,950<br />
A,100007,S,5,1025<br />
A,100008,B,3,1050<br />
T,2,1025<br />
T,1,1025<br />
X,100008,B,3,1050<br />
X,100005,S,2,1025<br />
M,100007,S,4,1025<br />
A,100007,S,3,1000     <<< Invalid Entry<br />
A,100007,B,3,1000     <<< Invalid Entry<br />

# Output

$>./orderbook message.txt         <br />                                                                                                   
============================<br />
printing order book<br />
============================<br />
Generated Order ID 100008 to BUY 3 quantity at price 1050<br />
Generated Order ID 100007 to SELL 5 quantity at price 1025<br />
Generated Order ID 100006 to BUY 1 quantity at price 1000<br />
Generated Order ID 100005 to SELL 2 quantity at price 1025<br />
Generated Order ID 100003 to SELL 10 quantity at price 1050<br />
Generated Order ID 100002 to BUY 30 quantity at price 975<br />
Generated Order ID 100001 to BUY 9 quantity at price 1000<br />
Generated Order ID 100000 to SELL 1 quantity at price 1075<br />
<br />
Trade occured at price 1025 with total quantity 2<br />
<br />
Trade occured at price 1025 with total quantity 3<br />
<br />
============================<br />
printing order book<br />
============================<br />
Generated Order ID 100007 to SELL 4 quantity at price 1025<br />
Generated Order ID 100006 to BUY 1 quantity at price 1000<br />
Generated Order ID 100003 to SELL 10 quantity at price 1050<br />
Generated Order ID 100002 to BUY 30 quantity at price 975<br />
Generated Order ID 100001 to BUY 9 quantity at price 1000<br />
Generated Order ID 100000 to SELL 1 quantity at price 1075<br />
<br />
Trade Stats : corrupted message count - 0 invalid message count - 0<br />
<br />
Order Stats : corrupted message count - 0, Duplicate message count - 2, Invalid entry count - 0<br />
<br />
