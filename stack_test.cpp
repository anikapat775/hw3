#include <iostream>
#include "stack.h"
using namespace std;
int main(){
	Stack<int> stack;
	stack.push(1);
	cout << stack.size() << endl;
	cout << stack.top() << endl;
	stack.push(2);
	cout << stack.size() << endl;
	cout << stack.top() << endl;
	stack.pop();
	cout << stack.size() << endl; 
	cout << stack.top() << endl;
	//we should get an error
	stack.pop();
	stack.pop();
	return 0;
}