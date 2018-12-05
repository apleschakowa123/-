#include "Observer.h"

//элемент стека
struct Node{
	Observer *data;//значение
	Node *next;//ссылка на следующий элемент
	~Node();
}

class Stack{
	Node *head;
	unsigned _size;
public:
   Stack();
   ~Stack();
   void Add(Observer *data);//добавление нового элемента
   Node * Head();//указатель на конец стека
   unsigned size();//размер стека
}