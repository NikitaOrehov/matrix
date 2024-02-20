#include "header.h"
#include "head.h"
#include <iostream>
using namespace std;

int main(){
    int size, answer = 0, error;
    cout<<"Enter size matrix"<<endl;
    cin>>size;
    double** matrix = create_matrix(size);
    double** matrix_origin = create_matrix(size);
    while(1){    
        cout<<"Enter CLY(1) or random generation(2)"<<endl;
        cin>>answer;
        if (answer != 1 && answer != 2){
            continue;
        }
        break;
    }
    if (answer == 2){
        random_generation_matrix(matrix, size);
    }
    else {
        enter_matrix(matrix, size);
    }
    cout<<endl;
    print_matrix(matrix, size);
    for (int i = 0; i < size; i++){//копирование матрицы
        for (int j = 0; j <= size; j++){
            matrix_origin[i][j] = matrix[i][j];
        }
    }
    while(1){
        cout<<"do you want change CLY?   yes(1)    no(0)"<<endl;
        cin>>answer;
        if (answer == 1){
            cout<<"Enter row, col, number"<<endl;
            int row, col;
            double number;
            cin>>row;
            cin>>col;
            cin>>number;
            matrix[row - 1][col - 1] = number;
            print_matrix(matrix, size);
            cout<<endl;
        }
        else break;
    }
    error = GAUSE_straight(matrix, size);
    if (error == 1){
        cout<<"Matrix error";
        return 0;
    }
    cout<<"Triangular view:";
    cout<<endl;
    print_matrix(matrix, size);
    double* vector = GAUSE_reverse(matrix, size);
    cout<<"answer vector: "<<endl;
    print_vector(vector, size);
    check_answer(matrix_origin, vector, size);
    delete [] vector;//удаление матрицы
    for (int i = 0; i < size; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    for (int i = 0; i < size; i++){
        delete [] matrix_origin[i];
    }
    delete [] matrix_origin;
    return 0;
}