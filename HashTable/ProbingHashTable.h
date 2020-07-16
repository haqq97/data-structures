#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "HashTable.h"

// Linear probing hash table class
class ProbingHashTable : public HashTable {
    private:
 
    // TODO: insert additional variables here
    //inherits variables from General HashTable

    public: 
    ProbingHashTable();
    ~ProbingHashTable(); 
    void insert(string key, int val); 
    int remove(string key); 
    int get(string key); 
    void printAll(string filename);
};

#endif