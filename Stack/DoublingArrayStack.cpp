#include "DoublingArrayStack.h"

template<class Type>
DoublingArrayStack<Type>::DoublingArrayStack() {
	capacity = 1;
	arrayPtr = new Type[capacity];
	t = -1;
}

template<class Type>
DoublingArrayStack<Type>::~DoublingArrayStack() {
	delete[] arrayPtr;
	arrayPtr = nullptr;
}

template<class Type>
bool DoublingArrayStack<Type>::isEmpty() { return t < 0; }

template<class Type>
int DoublingArrayStack<Type>::size() { return t + 1; }

template<class Type>
Type DoublingArrayStack<Type>::top() {
	if (isEmpty())
		throw string("Nothing on top since stack is empty");
	return arrayPtr[t];
}

template<class Type>
Type DoublingArrayStack<Type>::pop() {
	if (isEmpty())
		throw string("Popping from an empty stack");
	else {
		return arrayPtr[t--];
	}
}

template<class Type>
void DoublingArrayStack<Type>::push(Type e) {
	if (this->size() >= this->capacity) {
		this->capacity *= 2;
		Type *temp = new Type[capacity];
		for (int i = 0; i < this->size(); i++){
			temp[i] = arrayPtr[i];
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