#pragma once
#include <iostream>
using namespace std;

class weapon
{
public:
	weapon() //в конструкторе проводится инициализация свойст класса и прочие требуемые начальные действия;
	{
		weight = 3.5;
		cartridges = capacity;
		cout << "weapon()" << endl;
	}
private: //в private хранятся внутриклассовые характеристики, доступ к которым стороннего пользователя может повлечь нарушение работы объекта;
		 //поэтому с такими свойствами и методами работают с помощью публичных методов класса, обеспечивающих доп.проверки;
	int cartridges; // число оставшихся зарядов;
	int capacity; // ёмкость магазина;
public:
	double range = 1500;// дальность;
	double velocity; // начальная скорость;
	double weight; // вес;
	bool optics;
	bool loaded;

	void load() // перезарядка;
	{
		cartridges = capacity;
	}
	void weapon::play_animation();
	weapon::~weapon();
	void weapon::shot();


};

//void weapon::play_animation(); // метод, определяемый вне класса, начинается с имя_класса::


class assault_rifle : public weapon
{
public:
	assault_rifle()
		: weapon()
	{
		return;
	}
	double recoil; //сила отдачи;
};