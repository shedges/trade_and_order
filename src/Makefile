CC=g++
CFLAGS=-c  -Wall -std=c++11 
LDFLAGS=-Wall
SOURCES=main.cpp feedhandler.cpp order.cpp trade.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=orderbook

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm  -f *.o

cleanall:
	rm  -f *.o $(EXECUTABLE)

rebuild: cleanall all
