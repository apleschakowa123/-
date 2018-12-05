#pragma once
#include <string>
#define cstr const std::string&
// "Зависимая" функциональность, сам наблюдатель
class Observer {
	std::string country;//страна
	std::string surname;//фамилия
	std::string name;//имя
	std::string patronimyc;//отчество
	int year;//год рождения
	int wins;//количество побед
	int speed;//скорость
	int luck;//удача 
public:
	Observer(cstr country = "", cstr name = "", cstr surname = "", cstr patronimyc = "", int year = 0, int wins = 0);
	virtual void update(int score, int pos){}
	std::string& Сountry();
	std::string& Surname();
	std::string& Name();
	std::string& Patronimyc();
	int& Year();
	int& Wins();
	int& Speed();
	int& Luck();
};