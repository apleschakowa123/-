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
	cout << "������� �������� ����� ��� ����������: ";
	cin >> file_name;
	int a;
	a = 2;
	string name, country, sname, patr;
	int year;
	int wins;
	int size;
	if(a == 1){
		string fname;
		cout << "������� �������� ����� � �����������: ";
		cin >> fname;
		//��������� �� ����� ������ �������
		ifstream in("123.txt");
		if(!in){
		   in >> size;//��������� ���������� �������
		   player.setSize(size);
		   for(unsigned i = 0; i < size; ++i){
				in >> name >> sname >> patr >> year >> wins;
				player.attach(new Observer(country, name, sname, patr, year, wins), i);
		   }
		}
		else{
			cout << "������ ������ �����\n";
			system("pause");
			return 0;
		}
	}
	else{
	   cout << "������� ���������� �������: "; 
	   while(!(cin >> size)){
		  cout << "validation error!";
	     cin.ignore(numeric_limits<streamsize>::max(), '\n');
		 cin.clear();
		 cin.sync();
	   }
	   player.setSize(size);
	   for(unsigned i = 0; i < size; ++i){
				cout << "\n�����: " << i;
				do{
					cout << "\n������: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				   cin.clear();
				   cin.sync();
				}while(!(cin >> country));
				do{
					cout << "���: ";

					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
				}while(!(cin >> name));
				do{
					cout << "�������: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
				}while(!(cin >> sname));
				do{
					cout << "��������: ";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
				}while(!(cin >> patr));
				do{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
					cout << "��� ��������: ";
				}while(!(cin >> year));
				do{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				    cin.clear();
				    cin.sync();
					cout << "������: ";
				}while(!(cin >> wins));
				player.attach(new Observer(country, name, sname, patr, year, wins), i);
		   }
	}
	int b;
    do{
		cout << "�������� ������, ��� ������������";
		cout << "\n������� ����� �� 0 �� " << size - 1 << "\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		cin.sync();
	}while(!(cin >> b) || (b < 0 || b >= size));//������ �� ������������� �����
	BigTennis bt(&player, b);//��������� �����������
	cout << "������ ����\n";
	player.playGame();
	cout << "\n������ ����\n";
	player.playGame();
	cout << "\n������ ����\n";
	player.playGame();
	cout << "\n�������� ����\n";
	player.playGame();
	cout << "\n����� ����\n";
	player.playGame();
	cout << "\n\n";
	player.showResults();//������� ���������
	player.writeToFile(file_name);//��������� � ����
	cout << '\n';
	system("pause");
}