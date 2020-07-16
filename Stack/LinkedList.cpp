#include "LinkedList.h"


template<class Type>
LinkedList<Type>::LinkedList() : head(nullptr), tail(nullptr), t(-1) { }


template<class Type>
LinkedList<Type>::~LinkedList() {
	SLinkedListNode<Type> *current = head;
	while (current != nullptr) {
		SLinkedListNode<Type> *nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = tail = nullptr;
}


template<class Type>
int LinkedList<Type>::size() { return t + 1; }


template<class Type>
bool LinkedList<Type>::empty() { return t < 0; }


template<class Type>
Type LinkedList<Type>::top() {
	if (empty()){
		throw string("Nothing on top since stack is empty");	
	}
	return head->elem;
}


template<class Type>
void LinkedList<Type>::push(Type e) {
	SLinkedListNode<Type> *newNode = new SLinkedListNode<Type>(e);
	if (size() == 0) {
		head = tail = newNode;
		t++;
	}
	else{
		newNode->next = head;
		head = newNode;
		t++;
	}
}


template<class Type>
Type LinkedList<Type>::pop() {
	if (empty()){
		throw string("Popping from an empty stack");
	}
	SLinkedListNode<Type> *temp = head;
	Type data = temp->elem;
	head = head->next;
	delete temp;
	t--;
	return data;
}

