#include "ArrayStack.h"


template<class Type>
ArrayStack<Type>::ArrayStack() {
	capacity = 1;
	arrayPtr = new Type[capacity];
	t = -1;
}

template<class Type>
ArrayStack<Type>::~ArrayStack() {
	delete[] arrayPtr;
	arrayPtr = nullptr;
}

template<class Type>
bool ArrayStack<Type>::isEmpty() { return t < 0; }

template<class Type>
int ArrayStack<Type>::size() { return t + 1; }

template<class Type>
Type ArrayStack<Type>::top() {
	if (isEmpty())
		throw string("Nothing on top since stack is empty");
	return arrayPtr[t];
}

template<class Type>
Type ArrayStack<Type>::pop() {
	if (isEmpty())
		throw string("Popping from an empty stack");
	else {
		return arrayPtr[t--];
	}
}

template<class Type>
void ArrayStack<Type>::push(Type e) {
	if (this->size() >= this->capacity) {
		this->capacity += 100;
		Type *temp=new Type[capacity];
		for (int i=0; i<this->size(); i++){
			temp[i]=arrayPtr[i];
		}
		delete[] arrayPtr;
		arrayPtr = temp;
		temp = nullptr;
		arrayPtr[++t] = e;
	}
	else {	 
		arrayPtr[++t] = e;
	}
}