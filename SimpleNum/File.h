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
	void Output(int** bools, int result, std::vector<std::vector<int>> m_rows_percent, std::vector<std::vector<int>> m_cols_percent);
	void OutputSize(int size);
	void SaveData(int& size);
	bool Input(int& usingText);
};


void WriteInFile(int** bools, int size, std::vector<std::vector<int>> rows_percent, std::vector<std::vector<int>> cols_percent);
void WriteInFileSize(int size);
void ReadFromFile(int& usingText);

#endif