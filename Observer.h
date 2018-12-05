#pragma once
#include <string>
#define cstr const std::string&
// "���������" ����������������, ��� �����������
class Observer {
	std::string country;//������
	std::string surname;//�������
	std::string name;//���
	std::string patronimyc;//��������
	int year;//��� ��������
	int wins;//���������� �����
	int speed;//��������
	int luck;//����� 
public:
	Observer(cstr country = "", cstr name = "", cstr surname = "", cstr patronimyc = "", int year = 0, int wins = 0);
	virtual void update(int score, int pos){}
	std::string& �ountry();
	std::string& Surname();
	std::string& Name();
	std::string& Patronimyc();
	int& Year();
	int& Wins();
	int& Speed();
	int& Luck();
};