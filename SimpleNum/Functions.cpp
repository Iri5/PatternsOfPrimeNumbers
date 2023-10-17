#include <iostream>
#include <vector>
#include "math.h"
#include "Functions.h"


int** Simple::GetArray() { return m_array; }
int** Simple::GetBools() { return m_bools; }
int* Simple::GetArSimple() { return m_arrSimple; };
std::vector<std::vector<int>> Simple::GetRows() { return simpleRows; };
std::vector<std::vector<int>> Simple::GetCols() { return simpleColumns; };
//std::vector<std::vector<int>> GetLeft() { return diagLeft; };
//std::vector<std::vector<int>> GetRight() { return diagRight; };

Simple::Simple(int size) {
	m_size = size;
	m_array = new int* [m_size];
	m_bools = new int* [m_size];
	m_arrSimple = new int[m_size * m_size];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = new int[m_size];
		m_bools[i] = new int[m_size];
	}
	int boundNumbers = m_size * m_size;
	//заполнение массивов числами
	for (int i = 0; i < boundNumbers; i++) {
		m_arrSimple[i] = i + 1;
	}
	//формирование массива, состоящего из простых чисел и 0
	for (int i = 1; i < boundNumbers; i++) {
		if (m_arrSimple[i] != 0) {
			int temp = m_arrSimple[i];
			for (int j = i + m_arrSimple[i]; j < boundNumbers; j += m_arrSimple[i]) {
				m_arrSimple[j] = 0;
			}
		}
	}
	int count = 1;
	//формирование двумерного массива с числами
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			m_array[i][j] = count;
			count++;
		}
	}
}
Simple::~Simple() {

}
void Simple::FillBool() {
	for (int i = 0; i < m_size; i++) {
		std::vector<int> line{ m_size,0,0 };
		simpleRows.push_back(line);
		for (int j = 0; j < m_size; j++) {
			if (i == 0) {
				simpleColumns.push_back(line);
			}
			if (m_array[i][j] == m_arrSimple[i * m_size + j]) {
				simpleRows[i][SIMPLE]++;
				simpleColumns[j][SIMPLE]++;
				m_bools[i][j] = 1;
			}
			else {
				m_bools[i][j] = 0;
			}
		}
	}
}
void Simple::FillRowAndStrokePercents() {
	double tempSimple = 0;
	double tempAll = m_size;
	int tempPercent = 0;
	//Расчет процентов по строкам
	for (int i = 0; i < simpleRows.size(); i++) {
		tempSimple = simpleRows[i][SIMPLE];
		tempPercent = tempSimple / tempAll * 100;
		simpleRows[i][PERCENT] = tempPercent;
	}
	//Расчет процентов по столбцам
	for (int i = 0; i < simpleColumns.size(); i++) {
		tempSimple = simpleColumns[i][SIMPLE];
		tempPercent = tempSimple / tempAll * 100;
		simpleColumns[i][PERCENT] = tempPercent;
	}
}
void Simple::CountPercentsToPrint() {
	
	std::vector<int> elem{ 0,0 };
	int sumRow = 0;
	double averRow = 0;
	for (int i = 0; i < simpleRows.size(); i++) {
		sumRow += simpleRows[i][PERCENT];
	}
	averRow = sumRow / simpleRows.size();
	int sumCol = 0;
	double averCol = 0;
	for (int i = 0; i < simpleColumns.size(); i++) {
		sumCol += simpleColumns[i][PERCENT];
	}
	averCol = sumCol / simpleColumns.size();
	for (int i = 0; i < simpleRows.size(); i++) {
		if (simpleRows[i][PERCENT] > averRow) {
			elem[0] = i;
			elem[1] = simpleRows[i][PERCENT];
			m_rows_percent.push_back(elem);
		}
	}
	for (int i = 0; i < simpleColumns.size(); i++) {
		if (simpleColumns[i][PERCENT] > averCol) {
			elem[0] = i;
			elem[1] = simpleColumns[i][PERCENT];
			m_cols_percent.push_back(elem);
		}
	}
}
void Simple::PrintPercents() {
	std::cout << "Уравнения прямых с наибольшим количеством простых чисел" << std::endl;
	for (int i = 0; i < m_rows_percent.size(); i++) {
		
		std::cout << "y = " << -m_rows_percent[i][0] << "\t" << m_rows_percent[i][1] << " %" << std::endl;
	}
	for (int i = 0; i < m_cols_percent.size(); i++) {

		std::cout << "x = " << m_cols_percent[i][0] << "\t" << m_cols_percent[i][1] << " %" << std::endl;
	}
}
void Simple::Print() {
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (m_bools[i][j] == 0) {
				std::cout << i * m_size + j + 1 << "\t";
			}
			else {
				std::cout << "(" << i * m_size + j + 1 << ")" << "\t";
			}
		}
		std::cout << std::endl;
	}
}



