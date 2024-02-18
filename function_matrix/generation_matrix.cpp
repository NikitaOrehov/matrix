#include <iostream> //два раза подключается?
#include <random>

using namespace std;


double** create_matrix(int size){
    double** matrix = new double*[size];
    for (int i = 0; i < size; i++){
        matrix[i] = new double[size + 1];
    }
    return matrix;
}

void random_generation_matrix(double** matrix, int size){
    std::mt19937 gen;
    gen.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type>dist;
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size + 1; j++){
            matrix[i][j] = (int)(dist(gen) / 10000000);
        }
    }
}

void enter_matrix(double** matrix, int size){
    cout<<"Enter CLY"<<endl;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size + 1; j++){
            cin>>matrix[i][j];
        }
    }
}

