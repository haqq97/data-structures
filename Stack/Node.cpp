#include "Node.h"

template<class Type>
SLinkedListNode<Type>::SLinkedListNode() : next(nullptr) {}

template<class Type>
SLinkedListNode<Type>::SLinkedListNode(Type data) : next(nullptr), elem(data) {}

template<class Type>
SLinkedListNode<Type>::~SLinkedListNode() { }



