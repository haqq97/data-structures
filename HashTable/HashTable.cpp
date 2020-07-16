#include "HashTable.h"
#include <cmath>
///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// default constructor
HashTable::HashTable() { //creates a table with sentinel 0 indicating the slots are empty
	table = new HashTableEntry[tableSize]; 
	size = 0;
	for (int i = 0; i < tableSize; i++) {
		table[i].key = "0";  
		table[i].value = 0;
	}
}

// destructor
HashTable::~HashTable() { delete [] table; }

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(std::string s) {
	long long int hash = 0;
	long long int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		//hash = hash + s[i]; //for testing collisions
		hash = 5 * hash + s[i]; 
	}
	hash = hash % tableSize;
	//cout << "hash1: " <<  hash << endl;
	return hash;
}

//returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const { return size == 0; } 
