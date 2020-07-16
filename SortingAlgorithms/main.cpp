#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "bubblesort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"

void reverseSortedNums(int *ptr, int size);

int main() {

	// string filename = "numbers.txt";
	// int sortingAlgorithm;
	// int n;
	// ifstream infile;

	// infile.open(filename);
	// if (!infile.is_open()) {
	// 	cout << "error opening " << filename;
	// 	return 1;
	// }
	// infile >> sortingAlgorithm;
	// infile >> n;
	// int *ptr = new int[n];
	// for (int i = 0; i < n; i++) {
	// 	infile >> ptr[i];
	// }
	// cout << "Before Sorting: \n";
	// print(ptr, n);
	// cout << "\nAfter sorting: \n";
	// if (sortingAlgorithm == 1) { //use bubble-sort
	// 	cout << "\n---------------USING BUBBLE-SORT---------------\n";
	// 	bubbleSort(ptr, n);
	// }
	// if (sortingAlgorithm == 2) { //use bubble-sort
	// 	cout << "\n---------------USING HEAP-SORT---------------\n";
	// 	heapSort(ptr, n);
	// }
	// if (sortingAlgorithm == 3) { //use merge-sort
	// 	cout << "\n---------------USING MERGE-SORT---------------\n";
	// 	mergeSort(ptr, n);
	// }
	// if (sortingAlgorithm == 4) { //use quick-sort
	// 	cout << "\n---------------USING QUICK-SORT---------------\n";
	// 	quickSort(ptr, n);
	// }
	// print(ptr, n);
	// ofstream outfile;
	// outfile.open("output.txt");
	// 	if (!outfile.is_open()) {
	// 	cout << "error opening output.txt";
	// 	return 1;
	// }
	// for (int i = 0; i < n; i++) {
	// 	outfile << ptr[i] << endl;
	// }
	// outfile.close();
	// delete ptr; 

	//TIMING THE IMPLEMENTATIONS:
	//--------------------BUBBLE-SORT--------------------
	//Sorted list
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 10000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		bubbleSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	
	//randomly sorted
	// srand(time(0));
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 10; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = rand() % size;
	// 	}
	// 	if (j % 1 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		bubbleSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	


	//reverse sorted
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 100; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	reverseSortedNums(arr, size);
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		bubbleSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	

	//--------------------HEAP-SORT--------------------
	//Sorted list
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 1000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		heapSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	
	//randomly sorted
	// srand(time(0));
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 1000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = rand() % size;
	// 	}
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		heapSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	


	//reverse sorted
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 1000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	reverseSortedNums(arr, size);
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		heapSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	

	//--------------------MERGE-SORT--------------------
	//Sorted list
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 1000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		mergeSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	
	//randomly sorted
	// srand(time(0));
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 1000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = rand() % size;
	// 	}
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		mergeSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	
	
	//reverse sorted
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 1000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	reverseSortedNums(arr, size);
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		mergeSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	
	//--------------------QUICK-SORT--------------------
	//Sorted list
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 100; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	if (j % 1 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		quickSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	
	//randomly sorted
	// srand(time(0));
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 1000; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = rand() % size;
	// 	}
	// 	if (j % 10 == 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		quickSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
		


	//reverse sorted
	// double elapsedTime = 0;
	// int size = 1000;
	// for (int j = 0; j < 100; j++) {
	// 	int *arr = new int[size];
	// 	for (int i = 0; i < size; i++) {
	// 		arr[i] = i;
	// 	}
	// 	reverseSortedNums(arr, size);
	// 	if (j % 1== 0) {
	// 		auto start = chrono::steady_clock::now();
	// 		bubbleSort(arr, size);
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// 	size+=1000;
	// 	delete arr; 
	// }
	

	return 0;
}

void reverseSortedNums(int *ptr, int size) {
	reverse(&ptr[0], &ptr[size]);
}

