#include "Observer.h"
Observer::Observer(cstr country, cstr name, cstr surname, cstr patronimyc, int year, int wins):country(country),name(name), surname(surname),
patronimyc(patronimyc), year(year), wins(wins), speed(0), luck(0) 
{}
std::string& Observer::Ñountry(){ return country; }
std::string& Observer::Surname(){ return surname; }
std::string& Observer::Name(){ return name; }
std::string& Observer::Patronimyc(){ return patronimyc; }
int& Observer::Year(){ return year; }
int& Observer::Wins(){ return wins; }
int& Observer::Speed(){ return speed; }
int& Observer::Luck(){ return luck; }
