//My name is Yamauni Lowe this is my own work
#ifndef SLL_H
#define SLL_H
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

template <class T>
class SLL {
	//<< overloader, Linera relationship O(n)
	friend ostream& operator <<(ostream& out, const SLL<T>& rhs) {
		SLLNode* curr;
		while (curr = rhs.head, curr != 0, curr = curr->next) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:
	class SLLNode {
	public:
		T data;
		SLLNode* next;
		//Node constructors, liners O(n)
		SLLNode() {
			T data;
			SLLNode* next;
		}
		SLLNode(T val, SLLNode* ptr = 0) {
			data = val;
			next = ptr;
		}
		//inserts value into node
		void insert(T val) {
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

	//Implementations for Singly LinkedList Class		
	//default constructor
	SLL() {
		head;
		tail;
	}
	//copy constructor; BigO Linear O(n)
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
	T front() {
		return head->data;
	}
	//accesses last element
	T back() {
		return tail->data;
	}
	//removes front value
	T pop_front() {
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
	T pop_back() {
		T i = tail->data;
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
	//Linear O(n)
	void insert(T val) {
		//make a node ptr
		SLLNode* curr = head;
		SLLNode* insrt = new SLLNode(val);
		//locates the node its inserting in behind of
		if (insrt == NULL && insrt->data >= curr->data) {
			insrt->next = curr;
			curr = insrt;
		}
		else {
			//locates node its inserting in front of 
			curr = insrt;
			while (curr->next != NULL && curr->next->data < insrt->data) {
				curr = curr->next;
			}
			insrt->next = curr->next;
			curr->next = insrt;
		}
	}

	//determines if empty
	//Linear O(n)
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
	//Linear O(n)
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

	//reverse order of elements in list
	//Linear O(n)
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
	//O(n) this is still linear iteration however
	//the output is double the size of n
	SLL merge(SLL aList) {
		SLL* result;
		SLLNode* Aptr, * Bptr;
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
				result->next->head = Bptr;


			}

		}
		return result;
	}

private:
	//node pointer to head and tail of the list
	SLLNode* head;
	SLLNode* tail;
};
#endif


