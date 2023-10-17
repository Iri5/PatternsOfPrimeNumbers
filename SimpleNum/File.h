#pragma once
#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <filesystem>
#include "menu.h"

class FileWork {
	std::string m_path;
public:
	FileWork(std::string path);
	bool NameForbidden(void) const;
	std::string RewriteName(void);
	bool FileExist(void) const;
	bool SaveFileNormal(void) const;
	bool FileReadOnly() const;
	void Output(int** bools, int result);
	void SaveData(int& size);
	bool Input(int& usingText);
};


void WriteInFile(int& size);

void ReadFromFile(int& usingText);

#endif