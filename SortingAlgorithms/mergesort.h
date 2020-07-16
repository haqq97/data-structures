#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void mergeSort(int *originalArray, int firstIndex, int lastIndex, int size);
void merge(int *originalArray, int *leftArray, int leftSize, int *rightArray, int rightSize);


void mergeSort(int *originalArray, int size) {
	if (size > 1) {
		int firstIndex = 0;
		int lastIndex = size - 1;
		mergeSort(originalArray, firstIndex, lastIndex, size);
	}
}
/*find the midpoint of the original array and create right and left subarrays.
Recursively create subarrays until one element is left. Merge the subarrays together
by calling merge on the right and left arrays which will sort the parent array*/
void mergeSort(int *originalArray, int firstIndex, int lastIndex, int size) {
	if (size > 1) {
		int middle = (size)/2;
		int *leftArray = new int[middle];
		int *rightArray = new int[size - middle];
		for (int i = 0; i < middle; i++) {
			leftArray[i] = originalArray[i];
 		}
 		for (int i = middle; i < size; i++) {
			rightArray[i - middle] = originalArray[i];
 		}
		mergeSort(leftArray, firstIndex, middle - 1, middle);
		mergeSort(rightArray, middle, lastIndex, size - middle);
		merge(originalArray, leftArray, middle, rightArray, size - middle);
	}
}

/*merge elements of left and right arrays into the original array. 
Compare the unpicked elements of the right and left array and choose the smallest
element and insert it into the original array. The leftover elements are inserted directly*/
void merge(int *originalArray, int *leftArray, int leftSize, int *rightArray, int rightSize) {
	int leftIndex = 0; 
	int rightIndex = 0; 
	int originalIndex = 0;
	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (leftArray[leftIndex] <= rightArray[rightIndex]) {
			originalArray[originalIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else {
			originalArray[originalIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		originalIndex++;
	}
	while (leftIndex < leftSize) {
		originalArray[originalIndex] = leftArray[leftIndex];
		leftIndex++;
		originalIndex++;
	}
	while (rightIndex < rightSize) {
		originalArray[originalIndex] = rightArray[rightIndex];
		rightIndex++;
		originalIndex++;	
	}
}

#endif 