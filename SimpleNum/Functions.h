#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include "math.h"
#endif

class Simple {
private:
	const int ALL = 0;
	const int SIMPLE = 1;
	const int PERCENT = 2;
	int m_size;
	int** m_array;
	int** m_bools;
	int* m_arrSimple;
	std::vector<std::vector<int>> m_rows_percent;
	std::vector<std::vector<int>> m_cols_percent;
	std::vector<std::vector<int>> simpleRows;//вектор строк {элементов, простых, процент}
	std::vector<std::vector<int>> simpleColumns;//вектор стобцов {элементов, простых, процент}
	//std::vector<std::vector<int>> diagLeft;
	//std::vector<std::vector<int>> diagRight;
public:
	
	int** GetArray();
	int** GetBools();
	int* GetArSimple();
	std::vector<std::vector<int>> GetRows();
	std::vector<std::vector<int>> GetCols();
	std::vector<std::vector<int>> GetRowsPercent();
	std::vector<std::vector<int>> GetColsPercent();
	//std::vector<std::vector<int>> GetLeft() { return diagLeft; };
	//std::vector<std::vector<int>> GetRight() { return diagRight; };

	Simple(int size);
	~Simple();
	void FillBool();
	void FillRowAndStrokePercents();
	void CountPercentsToPrint();
	void Print();
	void PrintPercents();
	
};