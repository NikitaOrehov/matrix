#include <iostream>
#include "header.h"
#include "head.h"

using namespace std;

int main(){
    int size, answer = 0, error;
    cout<<"Enter size matrix"<<endl;
    cin>>size;
    double** matrix = create_matrix(size);
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
    delete [] vector;//удаление матрицы
    for (int i = 0; i < size; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}