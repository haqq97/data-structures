#include "ChainingHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() {
	table = new LinkedHashNode*[tableSize]; //create a pointer to an array of LinkedHashNode pointers
	for (int i = 0; i < tableSize; i++) {   //set every element to null
		table[i] = nullptr;                 
	}
}

// destructor
ChainingHashTable::~ChainingHashTable() { //visit every location in the array and delete every node in the list
	for (int i = 0; i < tableSize; i++) {
		if (table[i] != nullptr) {
			LinkedHashNode *prevNode = nullptr;
			LinkedHashNode *current = table[i];
			while (current != nullptr) {
				prevNode = current;
				current = current->getNext();
				delete prevNode;
			}
		}
	}
	delete [] table;   //delete the array table
}

// inserts the given string key
void ChainingHashTable::insert(string key, int val) {
	int hashCode = hash(key);
	if (table[hashCode] == nullptr) {  //if array location is empty, add a node to that location
		table[hashCode] = new LinkedHashNode(key, val);
		size++;
	}
	else {
		LinkedHashNode *newNode = table[hashCode];
		while (newNode->getNext() != nullptr) { //get to the last node of the linked list
			if (newNode->getKey() == key) {   //if key is already present, update the value of key
				newNode->setValue(newNode->getValue() + val);
				return;
			}
        	newNode = newNode->getNext();
        }
		if (newNode->getKey() == key) {   //if key is already present, update the value of key
			newNode->setValue(newNode->getValue() + val);
		} 
        else { //if key is not found, add key to the end of the list 
 			newNode->setNext(new LinkedHashNode(key, val));
 			size++;
        }
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(string key) {
	int hashCode = hash(key);
	if (table[hashCode] == nullptr) { //cannot remove from empty locations in array
		throw EmptyCellException{};
	} 
	else {
		LinkedHashNode *prevNode = nullptr;
		LinkedHashNode *current = table[hashCode];
		while (current->getNext() != nullptr && current->getKey() != key) {  //traverse until key is found/end of list
			prevNode = current;
			current = current->getNext();
		}
		if (current->getKey() == key) { //if key is found
			if (prevNode == nullptr) { //if there is only one node in the list
				LinkedHashNode *nextNode = current->getNext(); 
				int removedValue = current->getValue();
				delete current;
				size--;
				table[hashCode] = nextNode;
				return removedValue;
			}
			else { //if key is in the middle of the list
				LinkedHashNode *nextNode = current->getNext();
				int removedValue = current->getValue();
				delete current;
				size--;
				prevNode->setNext(nextNode);
				return removedValue;
			}
		}
		else {
			throw EmptyCellException{};
		}
	}
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(string key) {
	int hashCode = hash(key);
	if (table[hashCode] == nullptr) {
		throw EmptyCellException{};
	}
	else {
		LinkedHashNode *current = table[hashCode];
		while (current != nullptr && current->getKey() != key) {
			current = current->getNext();
		}
		if (current == nullptr) {
			throw EmptyCellException{};
		}
		else {
			return current->getValue();
		}
	}
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(string filename) {
	ofstream outfile;
	outfile.open(filename);
	for (int i = 0; i < tableSize; i++) {
		if (table[i] != nullptr) {
			LinkedHashNode *prevNode = nullptr;
			LinkedHashNode *current = table[i];
			while (current != nullptr) {
				prevNode = current;
				outfile << prevNode->getKey() << " " << prevNode->getValue() << endl;
				current = current->getNext();
			}
		}
	}
	outfile.close();
}

