//My name is Yamauni Lowe and this my own work.
#include <list>
#include "SLL.h"
#include <iostream>
#include <ostream>
using namespace std;
struct Node;

int main() {
	SLL<int> list1;
	//checks constructor
	if (list1.empty() == true) {
		cout << "Constructor is operational" << endl;
	}

	//insert values into list
	list1.insert(3);
	list1.insert(5);
	list1.insert(6);
	list1.insert(14);
	cout << "The List1 is: " << list1 << endl;


	//checks insert()
	list1.empty();
	if (list1.empty() == true) {
		cout << "Insert function is opoerational" << endl;
	}
	
	//checks front() and back()
	cout << list1.front() << endl;
	cout << list1.back() << endl;

	//checks pop_front() and pop_back()
	cout << list1.pop_front() << endl;
	cout << list1.pop_back() << endl;

	//checks size()
	cout << "The size of this list is: " << list1.size() << endl;

	//checks reverse()
	cout << "The list reversed is: "; //<< list1.reverse() << endl

	//creating second list
	SLL<int> list2;
	list2.insert(4);
	list2.insert(5);
	list2.insert(7);
	list2.insert(15);
	cout << "List 2 is : " << list2 << endl;

	//checks merge
	cout << "The merged list is: "; //<< list1.merge(list2) << endl;

	return 0;
}

