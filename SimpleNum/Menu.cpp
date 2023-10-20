#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>
#include "menu.h"
//#include "tests.h"
#include "file.h"
#include "Functions.h"


void Greeting() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "��������� ����� ������ 404" << std::endl;
	std::cout << "������������ 2, ������� 4" << std::endl;
	std::cout << "���������� �������� ���������, ������� ���������� ����� ����� �� ���������" << std::endl;
	std::cout << "��������� ���������� ������� � �������� �� ������� �� �����, ��� ��������� ������� �����." << std::endl;
	std::cout << "������� �������, ����������� ������ ����� �� ������� � ��������� �� �� ���, �������" << std::endl;
	std::cout << "�������� ��������� �������� �������. ����� ���� ���������� ���� ������� ����� �� ���� ������." << std::endl;
}

bool RightMenuChoice(Menu choice) {
	if ((choice == Menu::NO) || (choice == Menu::YES)) {
		return true;
	}
	else {
		std::cout << "����������� ��������� ��������" << std::endl;
		return false;
	}
}

bool RightInputChoice(InputType choice) {
	if ((choice == InputType::KEYBOARD) || (choice == InputType::FILE)) {
		return true;
	}
	else {
		std::cout << "����������� ��������� ��������" << std::endl;
		return false;
	}
}

Menu AskTests(void) {
	std::cout << "�������� ������������?" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "2 - ���" << std::endl;
	std::cout << "��� �����:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}
Menu AskRepeat(void) {
	std::cout << "������� �� ��������� ��������� ��������?" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "2 - ���" << std::endl;
	std::cout << "��� �����:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

InputType AskInput(void) {
	std::cout << "��� �� ������� ������ �����?" << std::endl;
	std::cout << "1 - �� �����" << std::endl;
	std::cout << "2 - � ����������" << std::endl;
	std::cout << "��� �����:" << std::endl;
	InputType decision = static_cast<InputType>(GetInput<int>());
	while (!RightInputChoice(decision)) {
		decision = static_cast<InputType>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveInput(void) {
	std::cout << "��������� �������� ������ � ����?" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "2 - ���" << std::endl;
	std::cout << "��� �����:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveResult(void) {
	std::cout << "��������� ��������� � ����?" << std::endl;
	std::cout << "1 - ��" << std::endl;
	std::cout << "2 - ���" << std::endl;
	std::cout << "��� �����:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}


Menu AskRewriteFile(std::string path) {

	Menu decision = Menu::NO;

	std::cout << "���� � ����� ������ ��� ����������" << std::endl;
	std::cout << "1 - ������� �����" << std::endl;
	std::cout << "2 - ������������ ������������" << std::endl;
	std::cout << "��� �����:" << std::endl;
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
		//wantTests = AskTests();
		//if (wantTests == Menu::YES) {
		//	Tests();
		//}

		//inputType = AskInput();

		//if (inputType == InputType::FILE) {
			//std::cout << "���� ������" << std::endl;
			//ReadFromFile(size);
			//std::cout << "�������� �����:" << std::endl;
			//std::cout << size << std::endl;
		//}
		//else {
			std::cout << "������� �����" << std::endl;
			//text = KeyboardInput();
			//getline(std::cin, size);
			size = (GetInput<int>());
			
		//}
		Simple cl(size);
		cl.FillBool();
		cl.FillRowAndStrokePercents();
		cl.Print();
		cl.CountPercentsToPrint();
		cl.PrintPercents();
		bools = cl.GetBools();
		std::vector<std::vector<int>> rows_percent = cl.GetRowsPercent();
		std::vector<std::vector<int>> cols_percent = cl.GetColsPercent();

		/*result = MaxNumSequense(size);
		std::cout << "����� ������������ ������������������ ����:" << std::endl;
		std::cout << result << std::endl;
		//��� ����������*/

		if (inputType != InputType::FILE) {
			wantSave = AskSaveInput();
			if (wantSave == Menu::YES) {
				std::cout << "���������� ��������� ������" << std::endl;
				WriteInFile(bools, size, rows_percent, cols_percent);
			}
		}
		/*
		wantSave = AskSaveResult();
		if (wantSave == Menu::YES) {

			std::cout << "������� ��� �����:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "������� ����� ��� �����" << std::endl;
				filePath = outputSaveFile.RewriteName();
			}
			/// <summary>
			while (outputSaveFile.FileReadOnly()) {
				std::cout << "������� ����� ��� �����" << std::endl;
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
					std::cout << "������� ����� ��� �����" << std::endl;
					newFilePath = newOutputSave.RewriteName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "������� ����� ��� �����" << std::endl;
						newFilePath = newOutputSave.RewriteName();
					}
				}
				FileWork file(newFilePath);
				file.Output(bools, size, rows_percent, cols_percent);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "������� ����� ��� �����" << std::endl;
					filePath = outputSaveFile.RewriteName();
				}
				FileWork file(filePath);
				file.Output(bools, size, rows_percent, cols_percent);
			}*/

		
		//}
		
		wantContinue = AskRepeat();
	} while (wantContinue == Menu::YES);
}