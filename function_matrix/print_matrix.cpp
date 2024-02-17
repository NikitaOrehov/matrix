#include <iostream>

using namespace std;

void print_matrix(double** matrix, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size + 1; j++){
            cout<<matrix[i][j];
            cout<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print_vector(double* vector, int size){
    for (int i = 0; i < size; i++){
        cout<<vector[i];
        cout<<endl;
    }
}