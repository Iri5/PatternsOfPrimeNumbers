#include <iostream>
#include <string>
#include "functions.h"

bool Test1() {
	int size = 2;
	int rightAns[4]{ 1, 2 , 3, 0};
	Simple cl(size);
	int* currAns;
	
	currAns = cl.GetArSimple();
	for (int i = 0; i < size * size; i++) {
		if (currAns[i] != rightAns[i]) {
			std::cout << "Ошибка в выполнении первого теста" << std::endl;
			std::cout << "Исходные данные:" << std::endl;
			std::cout << size << std::endl;
			std::cout << "Ожидаемый ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << rightAns[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Полученный ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << currAns[i] << " ";
			}
			std::cout << std::endl;
			return false;
		}
	}
	return true;
	
}
bool Test2() {
	int size = 3;
	int rightAns[9]{ 1, 2, 3, 0, 5, 0, 7, 0, 0 };
	Simple cl(size);
	int* currAns;

	currAns = cl.GetArSimple();
	for (int i = 0; i < size * size; i++) {
		if (currAns[i] != rightAns[i]) {
			std::cout << "Ошибка в выполнении второго теста" << std::endl;
			std::cout << "Исходные данные:" << std::endl;
			std::cout << size << std::endl;
			std::cout << "Ожидаемый ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << rightAns[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Полученный ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << currAns[i] << " ";
			}
			std::cout << std::endl;
			return false;
		}
	}
	return true;

}
bool Test3() {
	int size = 1; 
	int rightAns[1]{ 1 };
	Simple cl(size);
	int* currAns;

	currAns = cl.GetArSimple();
	for (int i = 0; i < size * size; i++) {
		if (currAns[i] != rightAns[i]) {
			std::cout << "Ошибка в выполнении третьего теста" << std::endl;
			std::cout << "Исходные данные:" << std::endl;
			std::cout << size << std::endl;
			std::cout << "Ожидаемый ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << rightAns[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Полученный ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << currAns[i] << " ";
			}
			std::cout << std::endl;
			return false;
		}
	}
	return true;

}
bool Test4() {
	int size = 4;
	int rightAns[16]{ 1, 2, 3, 0, 5, 0, 7, 0, 0, 0, 11, 0, 13, 0, 0, 0 };
	Simple cl(size);
	int* currAns;

	currAns = cl.GetArSimple();
	for (int i = 0; i < size * size; i++) {
		if (currAns[i] != rightAns[i]) {
			std::cout << "Ошибка в выполнении четвертого теста" << std::endl;
			std::cout << "Исходные данные:" << std::endl;
			std::cout << size << std::endl;
			std::cout << "Ожидаемый ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << rightAns[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Полученный ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << currAns[i] << " ";
			}
			std::cout << std::endl;
			return false;
		}
	}
	return true;

}
bool Test5() {
	int size = 5;
	int rightAns[25]{ 1, 2, 3, 0, 5, 0, 7, 0, 0, 0, 11, 0, 13, 0, 0, 0, 17, 0, 19, 0, 0, 0, 23, 0, 0 };
	Simple cl(size);
	int* currAns;

	currAns = cl.GetArSimple();
	for (int i = 0; i < size * size; i++) {
		if (currAns[i] != rightAns[i]) {
			std::cout << "Ошибка в выполнении пятого теста" << std::endl;
			std::cout << "Исходные данные:" << std::endl;
			std::cout << size << std::endl;
			std::cout << "Ожидаемый ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << rightAns[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Полученный ответ:" << std::endl;
			for (int i = 0; i < size * size; i++) {
				std::cout << currAns[i] << " ";
			}
			std::cout << std::endl;
			return false;
		}
	}
	return true;

}


void Tests() {
	int trueTests = 0;
	if (Test1()) trueTests++;
	if (Test2()) trueTests++;
	if (Test3()) trueTests++;
	if (Test4()) trueTests++;
	if (Test5()) trueTests++;
	if (trueTests == 5) {
		std::cout << "Тестирование прошло успешно" << std::endl;
	}
}
