#pragma once
template <class Type>
class Node {
	Type info;
	Node<Type>* next;
	Node<Type>* previous;
public:
	Node() {
		this->next = 0;
		this->previous = 0;
	}
	Node(Type info) {
		this->next = 0;
		this->previous = 0;
		this->info = info;
	}
	Type getInfo() {
		return info;
	}
	Node<Type>* getNext() {
		return this->next;
	}
	void setNext(Node<Type>* next) {
		this->next = next;
	}
	void setPrev(Node<Type>* prev) {
		this->previous = prev;
	}
	void setInfo(Type info) {
		this->info = info;
	}
};
