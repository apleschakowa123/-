#include "Observer.h"

//������� �����
struct Node{
	Observer *data;//��������
	Node *next;//������ �� ��������� �������
	~Node();
}

class Stack{
	Node *head;
	unsigned _size;
public:
   Stack();
   ~Stack();
   void Add(Observer *data);//���������� ������ ��������
   Node * Head();//��������� �� ����� �����
   unsigned size();//������ �����
}