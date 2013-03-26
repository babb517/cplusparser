
CXXFLAGS=-c -std=c++0x -I. -g3 -O0 -DDEBUG
LFLAGS= -lboost_system -lboost_filesystem
R2CFLAGS= -c
scanner_test: Location.o details/Token.o details/Scanner.o utils/utils.o tests/scanner_test.o
	g++ -o $@ $^ $(LFLAGS) 

.PHONY: clean
clean:
	@- rm Location.o
	@- rm details/Token.o
	@- rm details/Scanner.o
	@- rm utils/utils.o
	@- rm tests/scanner_test.o


%.cpp: %.re2c
	re2c $(R2CFLAGS) -o $@ $^
