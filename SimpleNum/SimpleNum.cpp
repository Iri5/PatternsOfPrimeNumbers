// SimpleNum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "math.h"

int main()
{
    std::vector<int> simplei;
    std::vector<int> simplej;
    const int boundNumbers = 100;
    int columns = sqrt(boundNumbers);
    int rows = columns;
    int numOfElemInLastRow = 0;
    if ((rows * columns) < boundNumbers) {
        numOfElemInLastRow = boundNumbers - (rows * columns);
        rows++;
    }

    std::cout << columns << std::endl;
    const int row = rows;
    const int col = columns;
    int** array = new int* [row];
    int** bools = new int* [row];

    for (int i = 0; i < row; i++) {
        array[i] = new int [col];
        bools[i] = new int[col];
    }

    int arrSimple[boundNumbers];
    
    int newAr[boundNumbers];
    for (int i = 1; i <= boundNumbers; i++) {
        arrSimple[i - 1] = i;
        newAr[i - 1] = i;
       // std::cout << ar[i-1] << std::endl;
    }
 
    for (int i = 1; i < boundNumbers; i++) {
        if (arrSimple[i] != 0) {
            int temp = arrSimple[i];
            for (int j = i + arrSimple[i]; j < boundNumbers; j += arrSimple[i]) {
                arrSimple[j] = 0;
            }
        }
    }

    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
           
                array[i][j] = count;
                count++;
           
            
        }
    }
 
    for (int i = 0; i < rows; i++) {
        simplei.push_back(0);
        for (int j = 0; j < columns; j++) {
            if (i == 0) {
                simplej.push_back(0);
            }
            
            
            if ((i == rows - 1) && (numOfElemInLastRow != 0) && (j > numOfElemInLastRow-1)) {
                std::cout << "_"  << "\t";
                bools[i][j] = -1;
            } 
            else {
                if (newAr[i * columns + j] == arrSimple[i * columns + j]) {
                    std::cout << "(" << array[i][j] << ")" << "\t";
                    simplei[i]++;
                    simplej[j]++;
                    bools[i][j] = 1;
                }
                else {
                    std::cout << array[i][j] << "\t";
                    bools[i][j] = 0;
                }
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < simplei.size(); i++) {
        std::cout << simplei[i] << std::endl;
        
    }
    for (int i = 0; i < simplej.size(); i++) {
        if (i == 0) {
            std::cout <<"____" << std::endl;
        }
        std::cout << simplej[i] << std::endl;
        
    }

    for (int i = 0; i < rows; i++) {
      
        for (int j = 0; j < columns; j++) {
                    std::cout << bools[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::vector<int> diag;
    for (int i = 0; i < columns; i++) {
        diag.push_back(0);
        if ((i - 1) >= 0) {
            int j = 0;
            int curi = i;
            while (j <= i) {
                diag[i] += bools[curi][j];
                j++;
                curi--;
            }
            
        }
        else {
            diag[i] = bools[i][0];
        }
        std::cout << std::endl;
    }
    for (int j = 1; j <= columns-1; j++) {
        diag.push_back(0);
        int i = columns - 1;
        int curj = j;
            int curi = i;
            while (curj <= i) {
                diag[i+j] += bools[curi][curj];
                curj++;
                curi--;
            }

    }
    std::cout << "diag" << std::endl;
    for (int i = 0; i < diag.size(); i++) {
        std::cout << diag[i] << std::endl;
    }
}
