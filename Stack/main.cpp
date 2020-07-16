#include "ArrayStack.cpp"
#include "DoublingArrayStack.cpp"
#include "LinkedList.cpp"
#include "Node.cpp"
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

int main() {
	//FOR TESTING THE FUNCTIONS FOR EACH IMPLEMENTATION:
	// try{
	// cout << "Testing ArrayStack....\n\n";	
	// ArrayStack<int> *s1 = new ArrayStack<int>;
	// s1->push(1);
	// cout << "Pushed 1 onto the stack\n";
	// s1->push(2);
	// cout << "Pushed 2 onto the stack\n";
	// cout << "Displaying the top: " << s1->top() << endl;
	// cout << "Popping from the stack: " << s1->pop() << endl;
	// cout << "New top element: " << s1->top() << endl;
	// cout << "Popping another element: " << s1->pop() << endl;
	// cout << "Popping another should give an exception: " << s1->pop() << endl;
	// delete s1;
	// }
	// catch(string &message) {
	// 	cout << message << endl;
	// }

	// cout << "\n=================\n";

	// try{
	// cout << "Testing DoublingArrayStack....\n\n";	
	// DoublingArrayStack<int> *s2 = new DoublingArrayStack<int>;
	// s2->push(1);
	// cout << "Pushed 1 onto the stack\n";
	// s2->push(2);
	// cout << "Pushed 2 onto the stack\n";
	// cout << "Displaying the top: " << s2->top() << endl;
	// cout << "Popping from the stack: " << s2->pop() << endl;
	// cout << "New top element: " << s2->top() << endl;
	// cout << "Popping another element: " << s2->pop() << endl;
	// cout << "Popping another should give an exception: " << s2->pop() << endl;
	// delete s2;
	// }
	// catch(string &message) {
	// 	cout << message << endl;
	// }

	// cout << "\n=================\n";

	try{
	cout << "Testing LinkedList....\n\n";	
	LinkedList<int> *s3 = new LinkedList<int>;
	s3->push(1);
	cout << "Pushed 1 onto the stack\n";
	s3->push(2);
	cout << "Pushed 2 onto the stack\n";
	cout << "Displaying the top: " << s3->top() << endl;
	cout << "Popping from the stack: " << s3->pop() << endl;
	cout << "New top element: " << s3->top() << endl;
	cout << "Popping another element: " << s3->pop() << endl;
	cout << "Popping another should give an exception: " << s3->pop() << endl;
	delete s3;
	}
	catch(string &message) {
		cout << message << endl;
	}

	//FOR COLLECTING THE EXECUTION TIME FOR EACH IMPLEMENTATION:
	// double elapsedTime = 0;
	// ArrayStack<int> *s1 = new ArrayStack<int>;
	// auto start = chrono::steady_clock::now();
	// for (int i=0; i < 1000000; i++){
	// 	s1->push(1);
	// 	if (i % 10000 ==0){
	// 		auto end = chrono::steady_clock::now();
	// 		elapsedTime = double (chrono::duration_cast <chrono::milliseconds>(end - start).count());
	// 		cout << elapsedTime << endl;
	// 	}
	// }
	// delete s1;


	
	// double elapsedTime = 0;
	// auto start = chrono::steady_clock::now();
	// DoublingArrayStack<int> *s = new DoublingArrayStack<int>;
	// for (int i=0; i < 1000000; i++){
	// 	s->push(1);
	// 	if (i % 10000 ==0){
	// 	auto end = chrono::steady_clock::now();
	// 	elapsedTime = double (chrono::duration_cast <chrono::milliseconds> (end - start).count());
	// 	cout << elapsedTime << endl;
	// 	}
	// }
	// delete s;

	
	// double elapsedTime = 0;
	// auto start = chrono::steady_clock::now();
	// LinkedList<int> *s = new LinkedList<int>;
	// for (int i=0; i < 1000000; i++){
	// 	s->push(1);
	// 	if (i % 10000 ==0){
	// 	auto end = chrono::steady_clock::now();
	// 	elapsedTime = double (chrono::duration_cast <chrono::milliseconds> (end - start).count());
	// 	cout << elapsedTime << endl;
	// 	}
	// }
	// delete s;	
	return 0;
}