// SimpleNum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "math.h"

int main()
{
    
    const int SIMPLE = 0;
    const int ALL = 1;
    const int PERCENT = 2;
    
    std::vector<int> simplei;
    std::vector<int> simplej;
    const int boundNumbers = 16;
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
    std::vector<std::vector<int>> diag;
    for (int i = 0; i < columns; i++) {
        std::vector<int> stroke {0, 0};
        diag.push_back(stroke);
        if ((i - 1) >= 0) {
            int j = 0;
            int curi = i;
            while (j <= i) {
                if (!(bools[curi][j] == -1)) {
                    diag[i][SIMPLE] += bools[curi][j];
                    diag[i][ALL]++;
                }
                
                j++;
                curi--;
            }
            
        }
        else {
            if (!(bools[i][0] == -1)) {
                diag[i][SIMPLE] = bools[i][0];
                diag[i][ALL]++;
            }
            
        }
        std::cout << std::endl;
    }
    for (int j = 1; j <= columns-1; j++) {
        std::vector<int> stroke{ 0, 0 };
        diag.push_back(stroke);
        int i = columns - 1;
        int curj = j;
            int curi = i;
            while (curj <= i) {
                if (!(bools[curi][curj] == -1)) {
                    diag[i + j][SIMPLE] += bools[curi][curj];
                    diag[i + j][ALL]++;
                }
                
                curj++;
                curi--;
            }

    }
    std::cout << "diag" << std::endl;
    for (int i = 0; i < diag.size(); i++) {
        std::cout << diag[i][0] << std::endl;
    }

    std::vector<std::vector<int>> diagRight;
    for (int i = 0; i < columns; i++) {
        std::vector<int> stroke{ 0, 0};
        diagRight.push_back(stroke);
        int curj = 0;
        int curi = i;
        while (curj  < columns - i  ) {
            if (!(bools[curi][curj] == -1)) {
                diagRight[i][SIMPLE] += bools[curi][curj];
                diagRight[i][ALL]++;
            }
            
            curi++;
            curj++;

        }
        
    }
    for (int j = 1; j < columns; j++) {
        std::vector<int> stroke{ 0, 0 };
        diagRight.insert(diagRight.begin(), stroke);
        int curj = j;
        int i = 0;
        while (curj < columns) {
            if (!(bools[i][curj] == -1)) {
                diagRight[0][SIMPLE] += bools[i][curj];
                diagRight[0][ALL]++;
            }
            
            curj++;
            i++;
        }
    }
   
    std::cout << "diagRight" << std::endl;
    for (int i = 0; i < diagRight.size(); i++) {
        std::cout << diagRight[i][0] << std::endl;
    }
}
