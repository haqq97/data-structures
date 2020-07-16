#include "HashTable.cpp"
#include "ChainingHashTable.cpp"
#include "ProbingHashTable.cpp"
#include "DoubleHashTable.cpp"
#include <algorithm>
#include <chrono>
#include <vector>

int main () {
	//READ AND ANALYZE INPUT:
	ifstream infile;
	infile.open("dictionary.txt");
	string word;
	int numWords = 0;
	int maxWordSize = 0;
	int minWordSize = 10;
	int sum = 0;
	int maxASCII = 0;
	int sizes = 0;
	vector<string> vec;
	while (infile >> word) {
		for (int i = 0; i < word.size(); i++) {
			sum += word[i]; 
		}
		if (sum > maxASCII) {
			maxASCII = sum;
		}
		if (word.size() > maxWordSize) {
			maxWordSize = word.size();
		}
		if (word.size() < minWordSize) {
			minWordSize = word.size();
		}
		sum = 0;
		numWords++;
		vec.push_back(word);
	}
	vector<string> v = vec; //to be used later for testing
	sort(vec.begin(), vec.end());
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
	int uniqueCount = unique(vec.begin(), vec.end()) - vec.begin();
	for (int i = 0; i < vec.size(); i++) {
		word = vec[i]; 
		sizes = sizes + word.size();
	}
	infile.close();
	cout << "Total Number of words in file: " << numWords << endl;
	cout << "Total Number of unique words in file: " << uniqueCount << endl;
	cout << "Average length of a word: " << (double)sizes/uniqueCount << endl;
	cout << "Max Length of a word: " << maxWordSize << endl;
	cout << "Min Length of a word: " << minWordSize << endl;
	cout << "Max ASCII value: " << maxASCII << endl;

	//-------------------------CHAINING------------------------- 
	//TIMING AND POPULATING THE HASH TABLE
	HashTable *chaining = new ChainingHashTable;
	double elapsedTime1 = 0;
	auto start1 = chrono::steady_clock::now();
	for (int i = 0; i < 1000000; i++) {
		chaining->insert(v[i], 1);
		if (i % 10000 == 0) {
			auto end1 = chrono::steady_clock::now();
			elapsedTime1 = double (chrono::duration_cast <chrono::milliseconds>(end1 - start1).count());
			cout << elapsedTime1 << endl;
		}
	}
	//TESTING TO COMPARE WITH OUTPUT.TXT
	chaining->printAll("Chaining.txt");  
	infile.open("output.txt");
	string s1;
	int value1;
	while(!infile.eof()) {
		infile >> s1;
		infile >> value1;
		if (chaining->get(s1) != value1) { //if comparison failure
			cout << "expected: " << s1 << " " << value1 << endl;
			cout << "what i got: " << s1 << " " << chaining->get(s1) << endl;
			return -1;
		}
	}
	infile.close();
	cout << "Chaining test passed\n";

	//-------------------------LINEAR-PROBING------------------------- 
	//TIMING AND POPULATING THE HASH TABLE
	HashTable *probing = new ProbingHashTable;
	double elapsedTime2 = 0;
	auto start2 = chrono::steady_clock::now();
	for (int i = 0; i < 1000000; i++) {
		probing->insert(v[i], 1);
		if (i % 10000 == 0) {
			auto end2 = chrono::steady_clock::now();
			elapsedTime2 = double (chrono::duration_cast <chrono::milliseconds>(end2 - start2).count());
			cout << elapsedTime2 << endl;
		}
	}
	probing->printAll("Probing.txt");
	//TESTING TO COMPARE WITH OUTPUT.TXT
	infile.open("output.txt");
	string s2;
	int value2;
	while(!infile.eof()) {
		infile >> s2;
		infile >> value2;
		if (probing->get(s2) != value2) {//if comparison failure
			cout << "expected: " << s2 << " " << value2 << endl;
			cout << "what i got: " << s2 << " " << probing->get(s2) << endl;
			return -1;
		}
	}
	infile.close();
	cout << "Probing test passed\n";

	//-------------------------DOUBLE-HASHING-------------------------
	//TIMING AND POPULATING THE HASH TABLE 
	HashTable *doubleHash = new DoubleHashTable;
	double elapsedTime3 = 0;
	auto start3 = chrono::steady_clock::now();
	for (int i = 0; i < 1000000; i++) {
		doubleHash->insert(v[i], 1);
		if (i % 10000 == 0) {
			auto end3 = chrono::steady_clock::now();
			elapsedTime3 = double (chrono::duration_cast <chrono::milliseconds>(end3 - start3).count());
			cout << elapsedTime3 << endl;
		}
	}
	doubleHash->printAll("DoubleHashing.txt");
	//TESTING TO COMPARE WITH OUTPUT.TXT
	infile.open("output.txt");
	string s3;
	int value3;
	while(!infile.eof()) {
		infile >> s3;
		infile >> value3;
		if (doubleHash->get(s3) != value3) {//if comparison failure
			cout << "expected: " << s3 << " " << value3 << endl;
			cout << "what i got: " << s3 << " " << doubleHash->get(s3) << endl;
			return -1;
		}
	}
	infile.close();
	cout << "DoubleHashing test passed\n";
	
	return 0;
}