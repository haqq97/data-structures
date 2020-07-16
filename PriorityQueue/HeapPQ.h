#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include "PriorityQueue.h"
#include <vector>
#include <cmath>
#include <iostream>
/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class HeapPQ {

private: 
   //data members
   vector<Type> vec;
   int insertionIndex;
   
   //private helper functions
   int getParentIndex(int childIndex) { return floor( (childIndex-1)/2 ); }

   int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }

   int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }

   bool hasLeftChild(int index) { return (getLeftChildIndex(index) < size()); }

   bool hasRightChild(int index) { return (getRightChildIndex(index) < size()); }

   bool hasParent(int index) { return getParentIndex(index) >= 0 ; }

   Type getParent(int index) { return vec[floor( (index - 1)/2 )]; }

   Type getLeftChild(int index) { return vec[(2 * index + 1)]; }

   Type getRightChild(int index) { return vec[2 * index + 2]; }

   void swap(int index1, int index2) {
      Type temp = vec[index1];
      vec[index1] = vec[index2];
      vec[index2] = temp;
   }

   void upHeap(int index) {
      while (hasParent(index) && getParent(index) > vec[index] ) {
         swap(index, getParentIndex(index));
         index = getParentIndex(index);
      }
   }

   void downHeap(int index) {
      while (hasLeftChild(index)) {
         int smallerChildIndex = getLeftChildIndex(index);
         if (hasRightChild(index) && getRightChild(index) < getLeftChild(index) ) {
            smallerChildIndex = getRightChildIndex(index);
         }
         if (vec[index] < vec[smallerChildIndex]) {
            break;
         }
         else {
            swap(index, smallerChildIndex);
         }
         index = smallerChildIndex;
      }
   }
      
   

public:
   //for testing:
   void print () {
      for (int i = 0; i < vec.size(); i++ ) {
         cout << vec[i] << " ";
      }
   }

   HeapPQ() { insertionIndex = 0; }

   ~HeapPQ() { vec.clear(); }

   bool isEmpty() { return (vec.size()==0); }

   int size() { return vec.size(); }

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ) {
      vec.insert(vec.begin() + insertionIndex, data);
      insertionIndex++;
      upHeap(size() - 1);
   }

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin () {
      if (isEmpty()) {
         throw EmptyHeapException{};
      }
      Type min = vec.front();
      vec[0] = vec[size() - 1];
      vec.erase(vec.begin() + size() - 1);
      insertionIndex--;
      downHeap(0);
      return min;
   }

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue () { 
      if (isEmpty()) {
         throw EmptyHeapException{};
      }
      return vec.front();
   }

   void bottomUpConstruction(vector<Type> v) {
      for (int i = 0; i < v.size(); i++) {
          vec.insert(vec.begin() + insertionIndex, v[i]);
          insertionIndex++;
      }
      int start = size() - 1;
      while ( hasParent(start) && getParentIndex(start) > -2 ) {
         downHeap(getParentIndex(start));
         start--;
      }
   }
};

#endif