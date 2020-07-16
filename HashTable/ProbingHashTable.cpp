#include "ProbingHashTable.h"


// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {}

// destructor
ProbingHashTable::~ProbingHashTable() {}

// inserts the given string key
void ProbingHashTable::insert(string key, int val) { 
	int hashCode = hash(key);
	if (table[hashCode].key == "0" || table[hashCode].key == "!") { //no collision
		table[hashCode].key = key; 
		table[hashCode].value = val; 
		size++;
	}
	else { //collision occurs
		while (table[hashCode].key != "0" && table[hashCode].key != "!") { 
			if (table[hashCode].key == key) { //if key is already present, update value
				table[hashCode].value += val;
				return;
			} 
			hashCode++;
			if (hashCode >= tableSize) { //keep checking within bounds
				hashCode = 0;
			}
		}//insert at next available index
		table[hashCode].key = key; 
		table[hashCode].value += val;  
		size++;
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(string key) {
	int hashCode = hash(key);
	if (table[hashCode].key == "0") { //key not found
		throw EmptyCellException{};
	}
	int lastCheck = hashCode; //last spot to check for key
	while (table[hashCode].key != "0") {
		if (table[hashCode].key == key) {
			int val = table[hashCode].value;
			table[hashCode].key = "!";
			size--;
			return val;
		}
		hashCode++;
		if (hashCode == lastCheck) {
			throw EmptyCellException{};
		}
		if (hashCode >= tableSize) {
			hashCode = 0;
		}
	}
		throw EmptyCellException{};
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(string key) {
	int hashCode = hash(key);
	if (table[hashCode].key == "0") {
		throw EmptyCellException{};
	}
	int lastCheck = hashCode; //last spot to check for key
	while (table[hashCode].key != "0") {
		if (table[hashCode].key == key) {
			int val = table[hashCode].value;
			return val;
		}
		hashCode++;
		if (hashCode == lastCheck) {
			throw EmptyCellException{};
		}
		if (hashCode >= tableSize) {
			hashCode = 0;
		}
	}
		throw EmptyCellException{};
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(string filename) {
	ofstream outfile;
	outfile.open(filename);
	for (int i = 0; i < tableSize; i++) {
		if (table[i].key != "0" && table[i].key != "!")
		outfile << table[i].key << " " << table[i].value << endl;
	}
	outfile.close();
}