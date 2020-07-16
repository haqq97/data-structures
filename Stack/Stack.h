#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H
#include <exception>
#include <iostream>
#include <string>

using namespace std;

template <class Type>
class AbstractStack {
private:
	// data goes here
	int capacity;
	Type* arrayPtr;
	int t;

public:
	AbstractStack();

	~AbstractStack();

	bool isEmpty();

	int size();

	Type top();

	Type pop();

	void push(Type e);
};


#endif