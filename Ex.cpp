// Ex.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "exam.h"

using namespace std;

int main()
{
	exam str1_Dyn;
	while (1)
	{
		for (int i = 0; i < 10000; i++)
		{
			str1_Dyn.add('a');
		}
		str1_Dyn.print();
		cout << endl;
		str1_Dyn.clear();
	}
	str1_Dyn.add('m');
	str1_Dyn.print();

	str1_Dyn.add('n');
	str1_Dyn.print();

	system("pause");
    return 0;
}

