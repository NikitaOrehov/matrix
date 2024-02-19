#include <iostream>

int swap_lens(double** matrix, int size, int i){
    int temp;
    for (int j = i + 1; j < size; j++){
        if (matrix[j][i] == 0) continue;
        for (int z = 0; z < size + 1; z++){
            temp = matrix[i][z];
            matrix[i][z] = matrix[j][z];
            matrix[j][z] = temp;
        }
        return 0;
    }
    return 1;
}


int GAUSE_straight(double** matrix, int size){
    int number2 = 0, error = 0;
    for (int i = 0; i < size; i++){
        if (matrix[i][i] != 1){
            if (matrix[i][i] == 0){
                error = swap_lens(matrix, size, i);
                if (error == 1) return 1;
            }
            number2 = matrix[i][i];
            for (int j = 0; j < size + 1; j++){
                matrix[i][j] /= number2;
            }
        }
        for (int z = i + 1; z < size; z++){
            if (matrix[z][i] != 0){
                double number = matrix[z][i];
                for (int j = 0; j < size + 1; j++){
                    matrix[z][j] -= (number * matrix[i][j]);
                }
            }
        }
    }
    return 0;
}

double* GAUSE_reverse(double** matrix, int size){
    double* vector = new double[size];
    vector[size - 1] = matrix[size - 1][size];
    for (int i = size - 2; i >= 0; i--){
        vector[i] = matrix[i][size];
        for (int j = size - 1; j > i; j--){
            vector[i] -= (matrix[i][j] * vector[j]);
        }
    }
    return vector;
}

void check_answer(double** matrix, double* vector, int size){
    std::cout<<std::endl;
    std::cout<<"pogreshnoct"<<std::endl;
    for (int i = 0; i < size; i++){
        double number = 0;
        for (int j = 0; j < size; j++){
            number += (vector[j] * matrix[i][j]);
        }
        std::cout<<matrix[i][size] - number<<std::endl;
    }
}