
CXXFLAGS=-c -std=c++0x -I.
LFLAGS=-lboost_system
scanner_test: details/Token.o details/Scanner.o utils/utils.o tests/scanner_test.o
	g++ $(LFLAGS) -o $@ $^

