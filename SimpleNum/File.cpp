#include <iostream>
#include <fstream>
#include <filesystem>
#include "file.h"


FileWork::FileWork(std::string path) {
	m_path = path;
}

bool FileWork::NameForbidden(void) const {
	try {
		bool isNameNormal = false;
		isNameNormal = std::filesystem::is_regular_file(m_path);
	}
	catch (std::exception&) {
		std::cout << "Недопустимое имя файла!" << std::endl;
		return true;
	}
	return false;
}

std::string FileWork::RewriteName(void) {
	m_path = GetInput<std::string>();
	while (NameForbidden()) {
		m_path = GetInput<std::string>();
	}
	return m_path;
}

bool FileWork::FileExist(void) const {
	std::ifstream checkFile;
	checkFile.open(m_path);
	if (checkFile.is_open()) {
		checkFile.close();
		return true;
	}
	else {
		return false;
	}
}

bool FileWork::SaveFileNormal(void) const {
	bool fileCreated = false;
	if (NameForbidden()) {
		return false;
	}
	if (FileExist()) {
		return true;
	}
	while (!fileCreated) {
		std::ofstream tryCreate;
		tryCreate.open(m_path);
		tryCreate << "check";
		tryCreate.close();
		std::ifstream tryOpen;
		tryOpen.open(m_path);
		if (tryOpen.is_open()) {
			tryOpen.close();
			remove(m_path.c_str());
			fileCreated = true;
		}
		else {
			tryOpen.close();
			fileCreated = false;
			std::cout << "Ошибка при создании файла. Проверьте имя файла" << std::endl;
			return false;
		}
	}
	return true;
}

bool FileWork::FileReadOnly(void) const {
	std::ofstream outputFile;
	outputFile.open(m_path);
	if (outputFile.is_open()) {
		outputFile.close();
		return false;
	}
	else {
		std::cout << "Файл доступен только для чтения" << std::endl;
		outputFile.close();
		return true;
	}
}

void FileWork::Output(int** bools, int size) {
	std::ofstream outputFile;
	outputFile.open(m_path);
	outputFile << "Исходный текст:" << std::endl;
	outputFile << size << std::endl;
	outputFile << "Количество символов в самой длинной последовательности цифр:" << std::endl;
	outputFile << size << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (bools[i][j] == 0) {
				outputFile << i * size + j + 1 << "\t";
			}
			else {
				outputFile << "(" << i * size + j + 1 << ")" << "\t";
			}
		}
		outputFile << std::endl;
	}
	outputFile.close();
}

void FileWork::SaveData(int& size) {
	std::ofstream dataFile;
	dataFile.open(m_path);
	dataFile << size << std::endl;
	dataFile.close();
}

bool FileWork::Input(int& size) {
	std::ifstream inputFile;
	std::string text;
	std::string data;
	inputFile.open(m_path);

	if (!inputFile.is_open()) {
		std::cout << "Файл не найден" << std::endl;
		return false;
	}
	while (!inputFile.eof()) {
		getline(inputFile, data);
		if (!data.empty()) {
			data += " ";
		}
		text += data;
	}


	if (text == "") {
		std::cout << "Файл пуст" << std::endl;
		inputFile.close();
		return false;
	}
	else {
		try {
			int a = std::stoi(text);
			size = a;
			inputFile.close();
			return true;
		} 
		catch (...) {
			std::cout << "Что-то не так с данными" << std::endl;
			inputFile.close();
			return false;
		}
		
	}
}






void WriteInFile(int& size) {
	std::string path;
	Menu rewrite = Menu::YES;
	std::cout << "Введите имя файла" << std::endl;
	path = GetInput<std::string>();
	FileWork inputSaveFile(path);
	while (!inputSaveFile.SaveFileNormal()) {
		std::cout << "Введите новое имя файла" << std::endl;
		path = inputSaveFile.RewriteName();
	}
	std::ifstream checkFile;
	checkFile.open(path);
	if (checkFile.is_open()) {
		rewrite = AskRewriteFile(path);
		checkFile.close();
		if (rewrite == Menu::YES) {
			std::string newFilePath = path;
			FileWork newInputSave(newFilePath);
			while (newFilePath == path) {
				std::cout << "Введите новое имя файла:" << std::endl;
				newFilePath = newInputSave.RewriteName();
				while (!newInputSave.SaveFileNormal()) {
					std::cout << "" << std::endl;
					newFilePath = newInputSave.RewriteName();
				}
			}
			FileWork file(newFilePath);
			file.SaveData(size);
		}
		else {
			while (inputSaveFile.FileReadOnly()) {
				std::cout << "Введите новое имя файла" << std::endl;
				path = inputSaveFile.RewriteName();
			}
			FileWork file(path);
			file.SaveData(size);
		}
	}
	else {
		checkFile.close();
		while (inputSaveFile.FileReadOnly()) {
			std::cout << "Введите новое имя файла" << std::endl;
			path = inputSaveFile.RewriteName();
		}
		FileWork file(path);
		file.SaveData(size);
	}

}



void ReadFromFile(int& size) {
	bool dataReaded = false;
	std::string path;
	std::cout << "Введите имя файла:" << std::endl;

	path = GetInput<std::string>();
	FileWork checkFile(path);

	while (checkFile.NameForbidden()) {
		std::cout << "Введите новое имя файла" << std::endl;
		path = checkFile.RewriteName();
	}
	FileWork input(path);
	dataReaded = input.Input(size);
	while (!dataReaded) {
		std::cout << "Введите новое имя файла" << std::endl;
		path = input.RewriteName();
		dataReaded = input.Input(size);
	}
}