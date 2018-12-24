#include "BigTennis.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
int mistake_(int b,int a)
{
	int i = 0;
	while (1)
	{
		std::cin >> i;
		if (i == -1)
		{
			return i;
			break;
		}
		if ((std::cin.fail()) || (i < b) || (i > a))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\n\t\t\t\tUnknown\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return i;
			break;
		}
	}
}
using namespace std;

int main(){
	setlocale(LC_ALL,"");
	Player player;
	string file_name;
	cout << "Введите название файла для сохранения: ";
	cin >> file_name;
	int a;
	a = 2;
	string name, country, sname, patr;
	int year;
	int wins;
	int size;
	if(a == 1){
		string fname;
		cout << "Введите название файла с расширением: ";
		cin >> fname;
		//считываем из файла данные игроков
		ifstream in("123.txt");
		if(!in){
		   in >> size;//счиытваем количество игроков
		   player.setSize(size);
		   for(unsigned i = 0; i < size; ++i){
				in >> name >> sname >> patr >> year >> wins;
				player.attach(new Observer(country, name, sname, patr, year, wins), i);
		   }
		}
		else{
			cout << "Ошибка чтения файла\n";
			system("pause");
			return 0;
		}
	}
	else{
	   cout << "Введите количество игроков: "; 
	   while(!(cin >> size)){
		  cout << "validation error!";
	     cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 cin.clear();
		 cin.sync();
	   }
	   player.setSize(size);
	   for(unsigned i = 0; i < size; ++i){
				cout << "\nИгрок: " << i;
				do{
					cout << "\nСтрана: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				   cin.clear();
				   cin.sync();
				}while(!(cin >> country));
				do{
					cout << "Имя: ";

					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
				}while(!(cin >> name));
				do{
					cout << "Фамилия: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
				}while(!(cin >> sname));
				do{
					cout << "Отчество: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
				}while(!(cin >> patr));
				do{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
					cout << "Год рождения: ";
				}while(!(cin >> year));
				do{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
					cout << "Победы: ";
				}while(!(cin >> wins));
				player.attach(new Observer(country, name, sname, patr, year, wins), i);
		   }
	}
	int b;
    do{
		cout << "Выберите игрока, для отслеживания";
		cout << "\nВведите цифру от 0 до " << size - 1 << "\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		cin.sync();
	}while(!(cin >> b) || (b < 0 || b >= size));//защита от некорректного ввода
	BigTennis bt(&player, b);//добавляем наблюдателя
	cout << "Первая игра\n";
	player.playGame();
	cout << "\nВторая игра\n";
	player.playGame();
	cout << "\nТретья игра\n";
	player.playGame();
	cout << "\nЧетвёртая игра\n";
	player.playGame();
	cout << "\nПятая игра\n";
	player.playGame();
	cout << "\n\n";
	player.showResults();//выводим результат
	player.writeToFile(file_name);//заисываем в файл
	cout << '\n';
	system("pause");
}