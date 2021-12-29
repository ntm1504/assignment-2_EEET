#pragma once
#include "Node.h"

template<class Type>
class StackType {
	int maxSize;
	int size;
	Node<Type>* head;

public:
	StackType() {
		this->maxSize = 99; //default
		cout << "Creating stack..." << endl;
		system("pause");
		system("CLS");
		initializeStack();
	}
	StackType(const StackType<Type>* otherStack) {
		copyStack();
	}
	void initializeStack() {
		this->head = 0;
		size = 0;
	}
	void push(Type info) {
		if (this->size <= this->maxSize) {
			Node<Type>* temp = new Node<Type>();
			temp->setInfo(info);
			temp->setNext(this->head);
			this->head = temp;
			size++;
		}
		else {
			cout << "Stack is full..." << endl;
			system("pause");
		}
	}
	void push(Node<Type>* info) {
		if (this->size <= this->maxSize) {
			info->setNext(this->head);
			this->head = info;
			size++;
		}
		else {
			cout << "Stack is full..." << endl;
			system("pause");
		}
	}
	void pop() {
		if (this->head != NULL) {
			Node<Type>* temp = head;
			if (head->getNext() != NULL) {
				this->head = head->getNext();
			}
			else {
				this->head = 0;
			}
			size--;
		}
	}
	bool isFullStack() {
		if (this->size == this->maxSize) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}
	bool isEmptyStack() {
		if (this->size == 0) {
			return true;
		}
		return false;
	}
	int getSize() {
		return this->size;
	}
	int getMaxSize() {
		return this->maxSize;
	}
	Node<Type>* top() {
		return this->head;
	}
	void copyStack(StackType<Type>& otherStack) {
		int x = this->size;
		for (int i = 0; i < x; i++) {
			this->pop();
		}
		this->head = 0;
		this->size = otherStack.getSize();
		this->maxSize = otherStack.getMaxSize();
		Node<Type>* temp;
		temp = otherStack.top();
		this->head = temp;
	}
	StackType<Type>& operator=(StackType<Type>& oStack) {
		if (this == &oStack) {
			return *this;
		}
		copyStack(oStack);
	}
	void reverseStack(StackType<Type>& otherStack) {
		this->maxSize = otherStack.getMaxSize();
		for (int i = 0; i < this->size; i++) {
			this->pop();
		}
		for (int i = 0; i < otherStack.getSize(); i++) {
			Node<Type>* temp;
			Node<Type>* getInf;
			getInf = otherStack.top(); //getInfo holds the address of the otherstack's head
			for (int j = i; j > 0; j--) {
				getInf = getInf->getNext();
			}//this loop should run through the linked list of the other stack...
			temp = new Node<Type>(getInf->getInfo()); //creates a new ptr that holds the address of the info from the old ptr
			this->push(temp);
		}
	}
};
