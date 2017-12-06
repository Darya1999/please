#pragma once
#include <iostream>
using namespace std;
class WeaponClass1
{

public:

	WeaponClass1() {
		//в конструкторе проводится инициализация свойств класса и прочие требуемые начальные действия
		//возвращаемых параметров у конструктора быть не может
		weight = 3.5;
		cartridges = capacity;
		cout << "WeaponClass1" << endl;
	}
private:
	int cartridges; //число оставшихся зарядов
	int capacity = 30; //емкость магазина
public:
	double range = 1500; //дальность
	double velocity; //начальная скорость
	double weight; // вес
	bool optics;
	bool loaded;

	void load()//перезарядка
	{
		cartridges = capacity;
	}

	void play_animation();

	void shot();

	~WeaponClass1();
};
