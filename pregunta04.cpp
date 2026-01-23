#include<iostream>
using namespace std;

int sumaMaxima(int (*inicio)[5], int i1, int j1, int i2, int j2){

    int (*pi)[5] = (inicio + i1) + j1;
    int suma = 0;

    for(int i=i1; i<i2; i++){
        for(int j=j1; j<j2; j++){

            suma += *(*(pi + i) + j);
        }
    }
     return suma;
}

int main(){

    int Matriz[4][5] = {{-2,1,-3,4,-1},
                        {2,3,-2,1,-5},
                        {-1,4,2,-3,2},
                        {1,-2,3,4,-1}};

    
    int (*inicio)[5] = Matriz;

    int i1, j1;
    int i2, j2;

    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
                cout<< *(*(Matriz + i) + j) <<" ";
        }
        cout<<endl;
    }

    cout<<"Ingrese las coordenada de la esquina superior izquierda: ";
    cin>>i1;
    cin>>j1;

    cout<<"\nIngrese las coordenada de la esquina superior izquierda: ";
    cin>>i2;
    cin>>j2;

    int sum= sumaMaxima(inicio, i1, j1, i2, j2); 
    cout<<"La suma de la submatriz es "<<sum<<endl;

    return 0; 
}
