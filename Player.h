#pragma once
#include "Observer.h"

//сам игрок
class Player{
    // связь только базовым классом Observer 
    Observer **views;
	int *scores;//очки
	int *positions;//позиции игроков
	unsigned _size;
	void sort();//сортировка позиций и очков
	unsigned curretIndex(unsigned pos); //возвращает индекс очков игрока в массиве
public:
	Player();
	~Player();
	void setSize(unsigned _size);//задаём новый массив
    void attach(Observer *obs, unsigned pos);//добавление нового игрока
    void replace(Observer *obs, unsigned pos);//замена игрока
	void playGame();//играем каждый раз
	void showResults();//отображение результатов
	void writeToFile(cstr file_name);//сохранение результатов в файл
    void notify();//метод оповещения всех наблюдателей
};