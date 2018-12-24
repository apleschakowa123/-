#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>

Player::Player(){
	srand(time(0));//����������� ������
	_size = 0;
	views = nullptr;
	scores = nullptr;
	positions = nullptr;
}
Player::~Player(){
	if(views != nullptr){
		for(unsigned i = 0; i < _size; ++i){
			delete views[i];
		}
	}
	delete[] scores;
	delete[] positions;
	delete[] views;
}


void Player::attach(Observer *obs, unsigned pos) {
	if(pos < _size){
		delete views[pos]; 
		views[pos] = obs;
	}
}

void Player::setSize(unsigned _size){
	if(views != nullptr){
		for(unsigned i = 0; i < _size; ++i){
			delete views[i];
		}
	}
	delete[] scores;
	delete[] positions;
	delete[] views;
	this->_size = _size;
	views = new Observer*[_size];
	positions = new int[_size];
	scores = new int[_size];
	for(unsigned i = 0; i < _size; ++i){
		views[i] = nullptr;
		positions[i] = i;
		scores[i] = 0;
	}
}

void Player::replace(Observer *obs, unsigned pos){
	if(pos < _size){
		//�������� ������
		if(views[pos] != nullptr){
			obs->�ountry() = views[pos]->�ountry();
			obs->Name() = views[pos]->Name();
			obs->Patronimyc() = views[pos]->Patronimyc();
			obs->Surname() = views[pos]->Surname();
			obs->Year() = views[pos]->Year();
		}
		delete views[pos]; 
		views[pos] = obs;
	}
}


void Player::notify(){
  // ��������� ������������
  for (unsigned i = 0; i < _size; ++i){
	 unsigned pos = curretIndex(i);
    views[i]->update(scores[pos], positions[pos]);
  }
}


void Player::sort(){
	//��������� ���������
    for (unsigned i = 0; i < _size; ++i){
        for (unsigned j = 0; j < _size - 1; ++j) {
            if (scores[j + 1] > scores[j]) {
                unsigned temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;

				temp = positions[j];
                positions[j] = positions[j + 1];
                positions[j + 1] = temp;
            }
        }
    }
}

unsigned Player::curretIndex(unsigned pos){ //���������� ������ ����� ������ � �������
	for (unsigned i = 0; i < _size; ++i){
		if(positions[i] == pos)
			return i;
	}
	return 0;
}

void Player::showResults(){
	std::cout << "�����" << std::setw(10)
				  << "���" << std::setw(10)
				  << "�������" << std::setw(10)
				  << "��������" << std::setw(10)
				  << "������" << std::setw(10)
				  << "������" << std::setw(10)
				  << "����";

	for (unsigned i = 0; i < _size; ++i){ 
		std::cout << '\n' << i + 1 << std::setw(10)
				  << views[positions[i]]->Name() << std::setw(10)
				  << views[positions[i]]->Surname() << std::setw(10)
				  << views[positions[i]]->Patronimyc() << std::setw(10)
				  << views[positions[i]]->Wins() << std::setw(10)
				  << views[positions[i]]->�ountry() << std::setw(10)
				  << scores[i];
	}
}

void Player::writeToFile(cstr file_name){
   std::ofstream out(file_name);
   out << "�����" << std::setw(10)
				  << "���" << std::setw(10)
				  << "�������" << std::setw(10)
				  << "��������" << std::setw(10)
				  << "������" << std::setw(10)
				  << "������" << std::setw(10)
				  << "����";

	for (unsigned i = 0; i < _size; ++i){ 
		out << '\n' << i + 1 << std::setw(10)
				  << views[positions[i]]->Name() << std::setw(10)
				  << views[positions[i]]->Surname() << std::setw(10)
				  << views[positions[i]]->Patronimyc() << std::setw(10)
				  << views[positions[i]]->Wins() << std::setw(10)
				  << views[positions[i]]->�ountry() << std::setw(10)
				  << scores[i];
	}
	out.close();
}

void Player::playGame(){
	 //����������� ����� � ��������
	 for (unsigned i = 0; i < _size; ++i){
		views[i]->Luck() = rand()% 100 + 1;
		views[i]->Speed() = rand()% 10 + 1;
	 }
	 //������
	 for (unsigned i = 0; i < _size; ++i){
		 for (unsigned j = 0; j < _size; ++j){
			 //���� ����� �����
			 if(i != j && views[i]->Luck() + views[i]->Speed() > views[j]->Luck() + views[j]->Speed()){
				 unsigned pos = curretIndex(i);
				 scores[pos] += 2;//����������� ��� ����
			 }
		 }
	 }
	 sort();//�������� ������� �������
	 notify();//��������� ���� ������������
}