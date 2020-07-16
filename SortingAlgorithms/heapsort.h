#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "heap.h"

/*bottom up heap construction of heap is done using the array and all elements are 
removed in sorted order since this is a minHeap and inserted into the original array*/
void heapSort(int *ptr, int size) {
	Heap<int> h(ptr, size);
	for (int j = 0; j < size; j++) {
		ptr[j] = h.removeMin();
	}
}

#endif