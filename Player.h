#pragma once
#include "Observer.h"

//��� �����
class Player{
    // ����� ������ ������� ������� Observer 
    Observer **views;
	int *scores;//����
	int *positions;//������� �������
	unsigned _size;
	void sort();//���������� ������� � �����
	unsigned curretIndex(unsigned pos); //���������� ������ ����� ������ � �������
public:
	Player();
	~Player();
	void setSize(unsigned _size);//����� ����� ������
    void attach(Observer *obs, unsigned pos);//���������� ������ ������
    void replace(Observer *obs, unsigned pos);//������ ������
	void playGame();//������ ������ ���
	void showResults();//����������� �����������
	void writeToFile(cstr file_name);//���������� ����������� � ����
    void notify();//����� ���������� ���� ������������
};