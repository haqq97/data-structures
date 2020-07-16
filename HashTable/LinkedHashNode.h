#ifndef LINKED_HASHNODE_H
#define LINKED_HASHNODE_H

//Linked List Node for Chaining 
class LinkedHashNode {
private:
	string key;
	int value;
	LinkedHashNode *next;

public:

	LinkedHashNode(string key, int value) {
        this->key = key;
        this->value = value;
		next = nullptr;
	}

    string getKey() { return key; }

	int getValue() { return value; }

    void setValue(int value) { this->value = value; }

    LinkedHashNode *getNext() { return next; }

    void setNext(LinkedHashNode *next) { this->next = next; }
};

#endif