CXX_FLAG = --std=c++11 -g

all: testbst

testbst: intbst.o testbst.o
	g++ $(CXX_FLAG) -o testbst intbst.o testbst.o

testbst.o: testbst.cpp
	g++ -c $(CXX_FLAG) testbst.cpp

intbst.o: intbst.cpp
	g++ -c $(CXX_FLAG) intbst.cpp

clean:
	rm -f testbst intbst utility *.o