#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "UnsortedPQ.h"
#include "SortedPQ.h"
#include "HeapPQ.h"

int main() {

	//HeapPQ Testing:
	HeapPQ<int> h;
	// cout << "----Empty HeapPQ object---- \n";
	// cout << boolalpha;
	// cout << "Size: " << h.size() << endl;
	// cout << "Empty?: " << h.isEmpty() << endl;
	// cout << "\n----Insert 5 items (1 to 5)----\n";
	// h.insertItem(1);
	// h.insertItem(2);
	// h.insertItem(3);
	// h.insertItem(4);
	// h.insertItem(5);
	// cout << "New size: " << h.size() << endl;
	// cout << "Empty?: " << h.isEmpty() << endl;
	// cout << "Min Value: " << h.minValue() << endl;
	// cout << "\n----First Removal----\n";
	// cout << "Removing top element: " << h.removeMin() << endl;
	// cout << "New size: " << h.size() << endl;
	// cout << "New Min Value: " << h.minValue() << endl; 
	// cout << "\n----Second Removal----\n";
	// cout << "Removing top element: " << h.removeMin() << endl;
	// cout << "New size: " << h.size() << endl;
	// cout << "New Min Value: " << h.minValue() << endl; 
	// cout << "\n----Third Removal----\n";
	// cout << "Removing top element: " << h.removeMin() << endl;
	// cout << "New size: " << h.size() << endl;
	// cout << "New Min Value: " << h.minValue() << endl; 
	// cout << "\n----Fourth Removal----\n";
	// cout << "Removing top element: " << h.removeMin() << endl;
	// cout << "New size: " << h.size() << endl;
	// cout << "New Min Value: " << h.minValue() << endl; 
	// cout << "\n----Fifth Removal----\n";
	// cout << "Removing top element: " << h.removeMin() << endl;
	// cout << "New size: " << h.size() << endl;
	// cout << "Empty?: " << h.isEmpty() << endl; 
	// cout << "\n\n----Bottom Up Construction----\n";
	// cout << "Inserting an array of integers: [3,2,19,1,8,7,20]\n";
	vector<int> v {20, 14, 15, 1, 2, 3, 4};
	h.bottomUpConstruction(v);
	// cout << "How array looks after bottom up construction: \n";
	h.print();
	// cout << endl;

	// int version;
	// int n;
	// int element;
	// ifstream infile;
	// infile.open("numbers.txt");
	// if(!infile.is_open()) {
	// 	cout << "Error opening numbers.txt\n";
	// 	return 1;
	// }
	// infile >> version >> n;
	// if (version == 0) {
	// 	cout << "==========UnsortedPQ==========\n";
	// 	UnsortedPQ<int> pq;
	// 	for (int i = 0; i < n; i++) {
	// 		infile >> element;
	// 		pq.insertItem(element);
	// 	}

	// 	for (int i = 0; i < n; i++) {
	// 		cout << pq.removeMin() << endl;
	// 	}	
	// }
	// else if (version == 1) {
	// 	cout << "==========SortedPQ==========\n";
	// 	sortedPQ<int> pq;
	// 	for (int i = 0; i < n; i++) {
	// 		infile >> element;
	// 		pq.insertItem(element);

	// 	}
		
	// 	for (int i = 0; i < n; i++) {
	// 		cout << pq.removeMin() << endl;
	// 	}		
	// }	
	// else if (version == 2) {
	// 	cout << "==========HeapPQ==========\n";
	// 	HeapPQ<int> pq;
	// 	for (int i = 0; i < n; i++) {
	// 		infile >> element;
	// 		pq.insertItem(element);
	// 	}
	// 	for (int i = 0; i < n; i++) {
	// 		cout << pq.removeMin() << endl;
	// 	}	
	// }	
	// else {
	// 	cout << "invalid entry\n";
	// 	return 1;
	// }
	// infile.close();

	//FOR COLLECTING THE EXECUTION TIME FOR EACH IMPLEMENTATION:
	//UNSORTED PQ: 
	// srand(time(0));
	// int numbers = 0;
	// double elapsedTime = 0;
	// UnsortedPQ<int> pq;
	// // auto start = chrono::steady_clock::now();
	// for (int i=0; i < 10000; i++){
	// 	numbers = (rand() % RAND_MAX);
	// 	pq.insertItem(numbers);
	// 	if (i % 100 == 0){
	// 		// auto end = chrono::steady_clock::now();
	// 		// elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		// cout << elapsedTime << endl;
	// 	}
	// }
	// auto start = chrono::steady_clock::now();
	// for (int i=0; i < 10000; i++){
	// 	pq.removeMin();
	// 	if (i % 100 == 0){
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// }


	//SORTED PQ:
	// srand(time(0));
	// int numbers = 0;
	// double elapsedTime = 0;
	// sortedPQ<int> pq;
	// // auto start = chrono::steady_clock::now();
	// for (int i=0; i < 10000; i++){
	// 	numbers = (rand() % RAND_MAX);
	// 	pq.insertItem(numbers);
	// 	// if (i % 100 == 0){
	// 	// 	auto end = chrono::steady_clock::now();
	// 	// 	elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 	// 	cout << elapsedTime << endl;
	// 	// }
	// }

	// auto start = chrono::steady_clock::now();
	// for (int i=0; i < 1000; i++){
	// 	pq.removeMin();
	// 	if (i % 10 == 0){
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// }

	//HEAP PQ:
	// srand(time(0));
	// int numbers = 0;
	// double elapsedTime = 0;
	// HeapPQ<int> pq;
	// auto start = chrono::steady_clock::now();
	// for (int i=0; i < 100000; i++){
	// 	numbers = (rand() % RAND_MAX);
	// 	pq.insertItem(numbers);
	// 	if (i % 1000 ==0){
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::nanoseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// }

	return 0;
}