//My name is Yamauni Lowe this is my own work
#ifndef SLL_H
#define SLL_H
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

template <class List>
class SLL {

	template <class Node>
	class SLLNode {
	public:
		int data;
		SLLNode* next;
		//Node constructors
		SLLNode() {
			int data;
			SLLNode* next;
		}
		SLLNode(int val, SLLNode* ptr = 0) {
			int data = val;
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
			p_curr->next = nn;
			nn->next = curr;
		}

	};

private:
	//node pointer to head and tail of the list
	SLLNode* head;
	SLLNode* tail;
	//Implementations for Singly LinkedList Class		
public:
	//default constructor
	SLL() {
		head = 0;
		tail = 0;
	}
	//copy constructor
	SLL(SLL* aList) {
		if (aList->head == 0) {
			head = tail = 0;
		}
		else {
			SLLNode* curr = aList->head;
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

	//removes front value
	int pop_front() {
		int i = head->data;
		SLLNode* temp = head;
		if (head == tail) {
			head = tail = 0;
		}
		else {
			head = head->next;
		}
		delete temp;
		return i;
	}

	//removes back value
	int pop_back() {
		int i = tail->data;
		if (head == tail) {
			delete head;
			head = tail = 0;
		}
		else {
			SLLNode* temp;
			for (temp = head; temp->next != tail; temp = temp->next) {
				delete tail;
				tail = temp;
				tail->next = 0;
			}
		}
		return i;
	}

	//inserts a value
	void insert(int val) {
		//make a node
		SLLNode* nn = new SLLNode(val);
		nn->head = val;
		nn->tail = head;
		head = nn;
	}

	//determines if empty
	bool empty() {
		SLLNode* temp = head;
		if (temp != 0) {
			return false;
		}
		else {
			return true;
		}
	}

	//returns the number of elements
	int size() {
		//initialize counting integer
		int ct = 0;
		SLLNode* curr = head;
		while (curr != NULL) {
			ct++;
			curr = curr->next;
		}
		return ct;
	}

	////reverse order of elements in list
	SLL reverse() {
		SLLNode* curr = head;
		SLLNode* prev = NULL, * next = NULL;
		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	//merge with another ordered list
	SLL merge(SLL aList) {
		SLL* result;
		SLLNode* Aptr, Bptr;
		SLL& rhs;
		Aptr = head->next;
		Bptr = rhs->head->next;
		while (Aptr != head && Bptr != rhs->head) {
			if (Aptr < Bptr) {
				//move Aptr
				//bypass node
				Bptr->head->next = Bptr->next;
				Bptr->next->head = Bptr->head;
				//hook Bptr into result
				Bptr->next = result;
				Bptr->head = result->head;
				//update surroundings
				result->next = Bptr;

			}
			
		}
		return result;
	}
	friend ostream& operator<<(ostream& out, SLL& lst) {
		SLLNode& curr = front;
		while (curr != nullptr) {
			out << lst.curr.head << " ";
			curr = lst.curr.tail;
		}
	}
};
#endif


