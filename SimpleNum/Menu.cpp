#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>
#include "menu.h"
#include "tests.h"
#include "file.h"
#include "Functions.h"


void Greeting() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "Бовчурова Ирина группа 404" << std::endl;
	std::cout << "Лабораторная 2, вариант 4" << std::endl;
	std::cout << "Необходимо написать программу, которая отображает целые числа на плоскость" << std::endl;
	std::cout << "некоторым регулярным образом и отмечает на рисунке те места, где находятся простые числа." << std::endl;
	std::cout << "Вывести фоомулы, описывающие прямые линии на рисунке и напечаать те из них, которые" << std::endl;
	std::cout << "особенно изобилуют простыми числами. Также надо напечатать долю простых чисел на этих прямых." << std::endl;
}

bool RightMenuChoice(Menu choice) {
	if ((choice == Menu::NO) || (choice == Menu::YES)) {
		return true;
	}
	else {
		std::cout << "Используйте указанные варианты" << std::endl;
		return false;
	}
}

bool RightInputChoice(InputType choice) {
	if ((choice == InputType::KEYBOARD) || (choice == InputType::FILE)) {
		return true;
	}
	else {
		std::cout << "Используйте указанные варианты" << std::endl;
		return false;
	}
}

Menu AskTests(void) {
	std::cout << "Провести тестирование?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}
Menu AskRepeat(void) {
	std::cout << "Желаете ли выполнить программу повторно?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

InputType AskInput(void) {
	std::cout << "Как вы желаете ввести текст?" << std::endl;
	std::cout << "1 - Из файла" << std::endl;
	std::cout << "2 - С клавиатуры" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	InputType decision = static_cast<InputType>(GetInput<int>());
	while (!RightInputChoice(decision)) {
		decision = static_cast<InputType>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveInput(void) {
	std::cout << "Сохранить  данные в файл?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveResult(void) {
	std::cout << "Сохранить результат в файл?" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "2 - Нет" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}


Menu AskRewriteFile(std::string path) {

	Menu decision = Menu::NO;

	std::cout << "Файл с таким именем уже существует" << std::endl;
	std::cout << "1 - Создать новый" << std::endl;
	std::cout << "2 - Перезаписать существующий" << std::endl;
	std::cout << "Ваш выбор:" << std::endl;
	decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;

}




void MainFunction(void) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	auto wantTests = Menu::YES;
	auto wantContinue = Menu::YES;
	auto wantSave = Menu::YES;
	auto wantRewrite = Menu::YES;
	auto inputType = InputType::KEYBOARD;
	int size;
	std::string afterText;
	int result = 0;
	int** bools;
	do {
		std::string filePath = "nothing";
		wantTests = AskTests();
		if (wantTests == Menu::YES) {
			Tests();
		}

		inputType = AskInput();

		if (inputType == InputType::FILE) {
			//std::cout << "Ввод текста" << std::endl;
			ReadFromFile(size);
			std::cout << "Исходный текст:" << std::endl;
			std::cout << size << std::endl;
		}
		else {
			std::cout << "Введите размерность матрицы" << std::endl;
			//text = KeyboardInput();
			//getline(std::cin, size);
			size = (GetInput<int>());
			
		}
		Simple cl(size);
		cl.FillBool();
		cl.FillRowAndStrokePercents();
		cl.Print();
		cl.CountPercentsToPrint();
		cl.PrintPercents();
		bools = cl.GetBools();
		std::vector<std::vector<int>> rows_percent = cl.GetRowsPercent();
		std::vector<std::vector<int>> cols_percent = cl.GetColsPercent();


		if (inputType != InputType::FILE) {
			wantSave = AskSaveInput();
			if (wantSave == Menu::YES) {
				std::cout << "Сохранение исходного размера матрицы " << std::endl;
				WriteInFileSize(size);
			}
		}
		wantSave = AskSaveResult();
		if (wantSave == Menu::YES) {
			std::cout << "Сохранение результатов " << std::endl;
			WriteInFile(bools, size, rows_percent, cols_percent);
		}
		/*
		wantSave = AskSaveResult();
		if (wantSave == Menu::YES) {

			std::cout << "Введите имя файла:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "Введите новое имя файла" << std::endl;
				filePath = outputSaveFile.RewriteName();
			}
			/// <summary>
			while (outputSaveFile.FileReadOnly()) {
				std::cout << "Введите новое имя файла" << std::endl;
				filePath = outputSaveFile.RewriteName();
			}
			FileWork file(filePath);
			file.Output(bools, size, rows_percent, cols_percent);*/
			/// </summary>
			/// <param name=""></param>
			/*wantRewrite = AskRewriteFile(filePath);
			if (wantRewrite == Menu::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "Введите новое имя файла" << std::endl;
					newFilePath = newOutputSave.RewriteName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "Введите новое имя файла" << std::endl;
						newFilePath = newOutputSave.RewriteName();
					}
				}
				FileWork file(newFilePath);
				file.Output(bools, size, rows_percent, cols_percent);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "Введите новое имя файла" << std::endl;
					filePath = outputSaveFile.RewriteName();
				}
				FileWork file(filePath);
				file.Output(bools, size, rows_percent, cols_percent);
			}*/

		
		//}
		
		wantContinue = AskRepeat();
	} while (wantContinue == Menu::YES);
}