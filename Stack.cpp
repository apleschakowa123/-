#include "Stack.h"

Node::~Node(){
	delete data;
}

Stack::Stack(){
	head = nullptr;
	_size = 0;
}

void Stack::Add(Observer *data){
	Node* tmp = new Node();
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	++_size;
}

Node * Stack::Head(){
	return head;
}

unsigned Stack::size(){ return _size; }

Stack::~Stack(){
	//удаляем элементы
	while(head != nullptr){
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
}