#include "DoubleHashTable.h"


///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
DoubleHashTable::DoubleHashTable() {}

// destructor
DoubleHashTable::~DoubleHashTable() {}

// inserts the given string key
void DoubleHashTable::insert(string key, int val) {
	int hashCode = hash(key);
	if (table[hashCode].key == "0" || table[hashCode].key == "!") { //no collision
		table[hashCode].key = key; 
		table[hashCode].value = val; 
		size++;
	}
	else { //collision
		int i = 0;
		while (table[hashCode].key != "0" && table[hashCode].key != "!") {
			if (table[hashCode].key == key) {
				table[hashCode].value += val;
				return;
			}
			hashCode = (hashCode + i * secondHash(key)) % tableSize;
			i++;
		}
		table[hashCode].key = key; 
		table[hashCode].value += val;  //insert at next available index
		size++;
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(string key) {
	int hashCode = hash(key);
	if (table[hashCode].key == key) { //if key is found using first hash function
		int temp = table[hashCode].value;
		table[hashCode].key = "!";
		table[hashCode].value = 0;
		size--;
		return temp;
	}
	else {
		int i = 0;
		while (table[hashCode].key != "0") {
			if (table[hashCode].key == key) {
				int val = table[hashCode].value;
				table[hashCode].key = "!";
				table[hashCode].value = 0;
				size--;
				return val;
			}
			hashCode = (hashCode + i * secondHash(key)) % tableSize;
			i++;
		}
		throw EmptyCellException{};
	}
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) {
int hashCode = hash(key);
	if (table[hashCode].key == key) { //if key is found using first hash function
		return table[hashCode].value;
	}
	else {
		int i = 0;
		while (table[hashCode].key != "0") {
			if (table[hashCode].key == key) {
				return table[hashCode].value;
			}
			hashCode = (hashCode + i * secondHash(key)) % tableSize;
			i++;
		}
		throw EmptyCellException{};	
	}
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {
	ofstream outfile;
	outfile.open(filename);
	for (int i = 0; i < tableSize; i++) {
		if (table[i].key != "0" && table[i].key != "!")
		outfile << table[i].key << " " << table[i].value << endl;
	}
	outfile.close();
}

// helper functions 
int DoubleHashTable::secondHash(string s) {
	long long int hash = 0;
	int prime = 108959; //choosing a prime number less than the size of table
	for (int i = 0; i < s.length(); i++) {
		hash = 5 * hash + s[i]; 
	}
	hash = prime - (hash % prime);
	//cout << "hash2: " << hash << endl;
	return hash;
}
