//My name is Yamauni Lowe this is my own work
#ifndef SLL_H
#define SLL_H
#include <iostream>
#include <ostream>
#include <memory>
using namespace std;
template <class List>
class SLL {
	template <class Node>
	class SLLNode {
	public:
	//Node constructors
		SLLNode() {
			next = 0;
			int data;
		}
		SLLNode(int val, SLLNode *ptr = 0) {
			data = val;
			next = ptr;
		}
		//inserts value
		void insert(int val) {
			SLLNode* curr;
			SLLNode* p_curr;
			curr = p_curr = head;
			while (curr != 0 && curr->data < val) {
				p_curr = curr;
				curr = curr->next;
			}
			SLLNode* nn = new SLLNode(val);
			p_curr->next->prev = nn;
			nn->next = curr;
		}
		
	};
	
//Implementations for SLL Class	
private:
	//node pointer to head and tail of the list
	SLLNode* head; 
	SLLNode* tail;
public:
	//default constructor
	SLL() {
		head = 0;
		tail = 0;
	}
	//copy constructor
	SLL(SLL* aList) {
		if (aList->front == 0) {
			head = tail = 0;
		}
		else{
			SLLNode* curr = aList->front;
			while (curr != 0 && curr->data > 0) {
				SLLNode* nn = new SLLNode(curr->data);
				if (tail != 0) {
					tail->next = nn;
					tail = nn;
				}
				if (head == 0) {
					head = nn;
				}
				curr = curr->next;
			}
		}
	}

	//accesses first element
	int front() {
		return head->data;
	}

	//accesses last element
	int back() {
		return tail->data;
	}

	//inserts a value
	void insert(int val) {
		//make a node
		SLLNode* nn = new SLLNode(val);
		nn->data = val;
		nn->next = head;
		head = nn;	
	}

//	//removes front value
//	int pop_front() {
//		int i = head->data;
//		SLLNode* temp = head;
//		if (head == tail) {
//			head = tail = 0;
//		}
//		else {
//			head = head->next;
//		}
//		delete temp;
//		return i;
//	}
//
//	//removes back value
//	int pop_back() {
//		int i = tail->data;
//		if (head == tail) {
//			delete head;
//			head = tail = 0;
//		}
//		else {
//			SLLNode* temp;
//			for (temp = head; temp->next != tail; temp = temp->next) {
//				delete tail;
//				tail = temp;
//				tail->next = 0;
//
//			}
//		}
//		return i;
//	}
//
	//determines if empty
	bool empty() {
		SLLNode* temp = head;
		while (temp != 0 && !(temp->head == 0)) {
			return true;
		}
	}
//	////returns the number of elements
//	//int SLL::size() {
//
//	//}
//
//	////reverse order of elements in list
//	//list<T> SLL::reverse() {
//
//	//}
//
//	////merge with another ordered list
//	//list<T> SLL::merge(aList) {
//
//	//}
	friend ostream& operator <<(ostream& out, SLL& rhs) {
		SLL* curr = front;
		while (curr != NULL) {
			out << curr->head<< " ";
			curr = curr->head;
		}
	}
};
#endif


