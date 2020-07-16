#ifndef DEQUE_H
#define DEQUE_H
#include "Node.h"

template <class Type>
class Deque {
private:
    int s;
	Node<Type> *firstNode;
	Node<Type> *lastNode;

public:
	Deque() { 
		s = 0; 
		firstNode = lastNode = nullptr;
	}

	~Deque() {
		Node<Type> *current = firstNode;
		Node<Type> *nextNode = current;
		while (current != nullptr) {
			nextNode = current->getNext();
			delete current;
			current = nextNode;
		}
		firstNode = lastNode = nullptr;
	}
	
	bool isEmpty() { return size() == 0; }

	int size() { return s; }

	Type first() { 
		if (size() == 0) {
			throw EmptyQueueException{};
		}
		return firstNode->getData(); 
	}

	Type last() { 
		if (size() == 0) {
			throw EmptyQueueException{};
		}
		return lastNode->getData(); 
	}

	void insertFirst(Type o) {
		Node<Type> *newNode = new Node<Type>(o);
		if (size()== 0){
			firstNode = lastNode = newNode;
			s++;
		}
		else {
			newNode->setNext(firstNode);
			firstNode->setPrev(newNode);
			firstNode = newNode;
			s++;
		}
	}

	void insertLast(Type o) {
		Node<Type> *newNode = new Node<Type>(o);
		if (size()== 0){
			firstNode = lastNode = newNode;
			s++;
		}
		else {
			lastNode->setNext(newNode);
			newNode->setPrev(lastNode);
			lastNode = newNode;
			s++;
		}
	}
	
	Type removeFirst() {
		if (size() == 0) {
			throw EmptyQueueException{};
		}
		Node<Type> *temp = firstNode;
		Type removed = temp->getData();
		firstNode = firstNode->getNext();
		delete temp;
		s--;
		return removed;
	}

	Type removeLast() { 
		if (size() == 0){
			throw EmptyQueueException{};
		}
		Node<Type> *temp = lastNode;
		Type removed = temp->getData();
		lastNode = lastNode->getPrev();
		delete temp;
		s--;
		return removed;
	}
};

#endif