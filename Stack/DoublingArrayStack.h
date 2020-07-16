#ifndef DOUBLING_ARRAY_STACK_H
#define DOUBLING_ARRAY_STACK_H
#include <exception>
#include <iostream>
#include <string>

using namespace std;

template <class Type>
class DoublingArrayStack {
private:
	// data goes here
	int capacity;
	Type* arrayPtr;
	int t;

public:
	DoublingArrayStack();

	~DoublingArrayStack();

	bool isEmpty();

	int size();

	Type top();

	Type pop();

	void push(Type e);
};

#endif