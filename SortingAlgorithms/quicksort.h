#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);

void quickSort(int *ptr, int size) {
	if (size > 1) {
		quickSort(ptr, 0, size - 1);
	}
}

/*recursively call quicksort until we have one element left
Quicksort on the right and left side of the partition Index*/
void quickSort(int *array, int start, int end) {
	if (start < end) {
		int partitionIndex = partition(array, start, end);
	 	quickSort(array, start, partitionIndex - 1);
	 	quickSort(array, partitionIndex + 1, end);
	}
}

/*rearrange the list such that all the elements less than or equal to pivot are 
on the left and the ones greater on the right*/
int partition(int *array, int start, int end) {
	int pivot = array[end]; 
	int partitionIndex = start;
	for (int i = start; i < end; i++) {
		if (array[i] <= pivot) {
			swap(array, i, partitionIndex);
			partitionIndex++;
		}
	}
	swap(array, partitionIndex, end);
	return partitionIndex;
}

#endif