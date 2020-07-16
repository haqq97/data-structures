#ifndef HASH_H
#define HASH_H

#include <string>
#include <fstream> //used for printing 
#include <iostream> 
#include <stdexcept>

using namespace std;

// const int tableSize = 10001;/145267; //table size for load factor < 0.5, 61069 was also used to test for smaller table size 

struct HashTableEntry {
	string key;
	int value;
};

// Chaining hash table class
class HashTable { 

	protected:
	HashTableEntry *table; //used for probing and doublehashing tables
	int size; 			   //number of elements in table
	// helper functions
	int hash(string s); 

	// TODO: insert necessary variables for your hash table here

	public: 

	HashTable();
	~HashTable(); 
	virtual void insert(string key, int val) = 0; 
	virtual int remove(string key) = 0; 
	virtual int get(string key) = 0; 
	virtual void printAll(string filename) = 0;
	bool isEmpty() const;  
};

class EmptyCellException : public exception {
public:
   virtual const char* what() const noexcept {
      return "EmptyCellException: Cannot perform this operation!";
   }
};
#endif