// Data structure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<array>
#include<vector>
#include<map>
#include<list>
#include<cmath>
#include<exception>

using namespace std;

//STD - стандартная библиотека С++
//функции print_f, getchar, fopen, read - из данной библиотеки является связующим звеном между языком С++т и О.С.
//[C++] -> [STD] -> [OC]

//STL - standard template library (template - шаблон)
//это расширение STD, содержащее структуры данных
//и функции по работе в ними
//именно из stl подключаются потоки cout, cin, fstream, ifstream, ofstream
// контейнеры array, vector, list, map
// итераторы
// алгоритмы sort, copy, и т.д.

//std::array
//инкапсилирует массивы неизменной длины, является шаблоном

//std::vector

//std::list

//std::map

int main()
{
	std::array<double, 10> double_array1; //объект, построенный из шаблона std::array<>, инкапсулирующий массив
	double_array1[5] = 10.5;
	double_array1.fill(0.0);
	int array_lenght = double_array1.size();
	//double_array.swap() - функция для обмена между содержимым двух массивов
	std::sort(double_array1.begin(), double_array1.end());
	std::array<double, 20> double_array2 = { 0 };
	std::copy(double_array1.begin(), double_array1.end(), double_array2.begin());

	//для создания двумерных массивов
	std::array<std::array<int, 3>, 3> mat33 = { 0 };
	mat33[1][1] = 100;
	//итератор - объект, ссылающийся на элемент массива, вектора или списка
	//"улучшенный" вариант переменной-счетчика
	// нужен для связи шаблонов STL
	std::array<double, 10>::iterator array_iterator;

	//std::vector
	//инкапсулирует одномерный массив и предоставляют средства
	//для изменения его длины
	//очень близким к std::vector по функционалу является std::string
	//ОСНОВНОЙ НЕДОСТАТОК
	//однако каждый раз при увеличении длины вектор запрашивает у ОС новую область памяти
	//и копирует туда старую (старую освобождает)
	// ОСНОВНОЕ ПРЕИМУЩЕСТВО
	//доступ к элементам осуществляется напрямую по адресу
	//[адрес_1 + i]
	//ВЫВОД
	//доступ быстрый, а !!! медленный

	std::vector<long long> long_vector = { 10, 15, 20 };

	cout << "vector<> = ";
	for (long long value : long_vector)
		std::cout << '\t' << value;
	std::cout <<std::endl;
	 
	long_vector.push_back(25);
	long_vector.push_back(0);

	cout << "vector<> after push()";
	for (long long value : long_vector)
		cout << '\t' << value;
	std::cout << std::endl;

	//также у std::vector присутствует весь функционал std::array: размер, сортировка, итераторы, копирование, обмен и т.д.
	
	std::sort(long_vector.begin(), long_vector.end());
	cout << "vector<> after sort()";
	for (long long value : long_vector)
		cout << '\t' << value;
	std::cout << std::endl;

	long_vector[2] = 11;

	//вставка в вектор
	long_vector.insert(long_vector.begin() + 2, 100500/* c помощью шаблона можно встравить несколько значений*/);
		std::cout << "vector<> after insert()";
	for (long long value : long_vector)
		cout << '\t' << value;
	std::cout << std::endl;
	//std::list
	//все наоборот:вставка и увеличение списка производится быстрее, чем в vector,
	//а доступ - медленнее, причем чем дальше от 1-го элемента - тем МЕДЛЕННЕЕ
	//так как для доступа к i-му элементу (определены его адреса в ОП) необходимо
	//пройти по цепочке от 1-го элемента

	//в отличие от array and vector представлены отдельными объектами, связанными друг с другом
	//указателями, которые они хранят
	//[null|данные|указатель] <---> [указатель|данные|указатель]
	//                                              /
	//                                            /
	//                                          /
	//                                        /
	//                                      /
	//                           [указатель|данные|указатель] ---> [указатель|данные|null] 
	std::list<char> char_list = { 'b' };
	char_list.push_front('a');//вставка перед первым элементом
	char_list.push_back('c');//вставка после последнего
	for(char ch: char_list)
	{
		cout << ch << endl;
	}
	//если  класс прростой и не содержит динамических данных
	class sample_class
	{
		int a;
		double b;
	};
	//список можно составлять из объектов класса
	std::list<sample_class> obj_list1;
	//в противном случае из ууказателей на объекте
	std::list<sample_class> obj_list2;

	//std::map
	//состоит из пар "ключ" - "значение"
	//например "TU-154 - 5000, "B777" - 6000, "A320" - 6500
	std::map<std::string, double> plane_and_range = 
	{ {"TU-154", 5000}, { "B777", 6000 }, { "A320", 6500 } };
	plane_and_range.insert({ "A380", 10000.0 });

	cout << "The range of Boeing 777 is " << plane_and_range ["B777"] << endl;
	cout << "The range of A380 is " << plane_and_range["A380"] << endl;
	//plane_and_range.insert({"A380", 10000.0} );
	//cout << "The range of A380 is " << plane_and_range["A380"] << endl;

	double d_array[5] = { 1, 2, 3, 4, 5 };
	int i = 60000;
	try //в try помещается код, потенциально способный вызывать исключения:
		//функции, не получающие доступа к файлам, портам, устройствам и т.д.
		//функции, неправильно работающие с памятью
	{
		d_array[i] = 15;
	}
	catch (exception& ex)
	{
		cerr << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Error in \"d_array[i] = 15\"" << endl;
	}

	getchar();
	return 0;
}

// в курс не вошли темы, необходимые для штатной коммерческой разработке ПО, такие как 
// - юнит-тестирование(на каждый модуль или проект, создается проект, который производит тестирование, сборка и запуск sln/
//   настраивается таким образом, что в первую очередь собирается базовый проект, затем собирается код текста и запускается) 
// - технологии, процессы и шаблоны разработки (SCRUM, Waterfall, Agile, ...)
// - создание графических приложений
// - многопоточные и асинхронные приложения
// - обработка исключений и ошибок в блоке (tre{}catch(...){})