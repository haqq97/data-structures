#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <exception>
#include <iostream>
#include <string>

using namespace std;

template <class Type>
class ArrayStack {
private:
	// data goes here
	int capacity;
	Type* arrayPtr;
	int t;

public:
	ArrayStack();

	~ArrayStack();

	bool isEmpty();

	int size();

	Type top();

	Type pop();

	void push(Type e);
};

#endif