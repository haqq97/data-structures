#ifndef SORTED_PRIORITY_QUEUE_H
#define SORTED_PRIORITY_QUEUE_H

#include "PriorityQueue.h"

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

template <class Type>
class sortedPQ {

private: 
   list <Type> queue;

public:

   sortedPQ() { }

   ~sortedPQ() { queue.clear(); }

   bool isEmpty() { return queue.empty(); }

   int size() { return queue.size(); }

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ) {
  	if (isEmpty()) {
	   		queue.push_back(data);
	   	}
	   	else {
	   		bool inserted = false;
	   		list<int>::iterator it;
	   		for (it = queue.begin(); it != queue.end(); it++) {
	   			if (data <= *it && inserted == false) {
	   				queue.insert(it,data);
	   				inserted = true;
	   			}
	   		}
	   		if (inserted == false) {
	   			queue.push_back(data);
	   		}
	   	}
   }
 
   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin () {
      if (isEmpty()) {
         throw EmptyPQException{};
      }
      Type min = queue.front();
      queue.pop_front();     
      return min;
   }

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue () { 
       if (isEmpty()) {
         throw EmptyPQException{};
      }
      Type min = queue.front();
      return min;
   }
};
#endif