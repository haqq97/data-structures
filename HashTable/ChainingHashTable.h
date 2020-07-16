#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"
#include "LinkedHashNode.h"



// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
  	LinkedHashNode **table; 

    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(string key, int val); 
    int remove(string key); 
    int get(string key);
    void printAll(string filename);
};

#endif