CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes 

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.cpp llrec-test.cpp 
	$(CXX) $(CXXFLAGS) $^ -o llrec-test
stack-test: stack.h stack_test.cpp
	$(CXX) $(CXXFLAGS) $^ -o stack-test
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 