// SimpleNum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "math.h"
#include "Functions.h"
#include "Menu.h"
int main()
{
	Greeting();
	MainFunction();
	//Func(15);
	Simple cl(4);
	cl.FillBool();
	cl.FillRowAndStrokePercents();
	cl.Print();
	std::vector<std::vector<int>> simpleRows = cl.GetRows();
	std::vector<std::vector<int>> simpleCol = cl.GetCols();
	std::cout << "rows" << std::endl;
	for (int i = 0; i < simpleRows.size(); i++) {
		for (int j = 0; j < simpleRows[i].size(); j++) {
			std::cout << simpleRows[i][j] << "___";
		}
		std::cout << std::endl;
	}
	std::cout << "col" << std::endl;
	for (int i = 0; i < simpleCol.size(); i++) {
		std::cout << simpleCol[i][0] << "___" << simpleCol[i][1] << "___" << simpleCol[i][2] << std::endl;
	}
}

