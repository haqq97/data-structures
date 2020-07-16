#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

using namespace std;

//used by other sorting algorithms too
void swap(int *ptr, int i, int j) {
	int temp = ptr[i];
	ptr[i] = ptr[j];
	ptr[j] = temp;
}

//loop through the array and swap consecutive unsorted elements
//optimization: stop looping once the array is sorted
void bubbleSort(int *ptr, int size) {
bool sorted = false;
int unsortedPart = size - 1; 
	while (sorted == false) {
		sorted = true;
		for (int i = 0; i < unsortedPart; i++) { //only loop over unsorted part
			if (ptr[i] > ptr[i+1]) {
				swap(ptr, i, i+1);
				sorted = false;
			}
		}	
		unsortedPart--;
	}
}

//used everywhere in the program
void print(int *ptr, int size) {
	cout << "\n[ ";
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << " ";
	}
	cout << "]\n";
} 

#endif 