#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <string>

using namespace std;

template<class Type>
class LinkedList {
private:
	SLinkedListNode<Type>* head;
	SLinkedListNode<Type>* tail;
	int t;

public:

	LinkedList();

	~LinkedList();

	int size();

	bool empty();

	Type top();

	Type pop();

	void push(Type e);
};



#endif
