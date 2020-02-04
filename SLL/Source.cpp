//My name is Yamauni Lowe and this my own work.
#include <list>
#include "SLL.h"
#include <iostream>
#include <ostream>
using namespace std;

int main() {
	SLL<int> list1;
	list1.insert(3);
	list1.insert(4);
	list1.insert(6);
	list1.insert(14);
	cout << "The List1 is: " << list1 << endl;


	//determines if the list is empty
	list1.empty();
	if (list1.empty() == true) {
		cout << "List is empty." << endl;
	}
	else {
		cout << "List is not empty." << endl;
		return 1;
	}
	return 0;
}

